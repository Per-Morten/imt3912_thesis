#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

#define DEBUG(fmt, ...)                     \
std::fprintf(stdout, fmt, ##__VA_ARGS__);   \
std::fflush(stdout);

struct event_t
{
    std::string text{"event"};
};

struct actor_event_t
{
    std::string text{"actor_event"};
};

struct i_component
{
    int id;
};

using Create = void(*)(i_component*, int id);
using Function = void(*)(i_component*, i_component*);
using Construct = i_component*(*)(i_component*);
using Destruct = void(*)(i_component*);
using OnEvent = void(*)(i_component*, const event_t*);
using OnActorEvent = void(*)(i_component*, const actor_event_t*);

class component1
    : public i_component
{
public:
    component1() = default;
    component1(const component1&) = delete;
    component1& operator=(const component1&) = delete;
    component1(component1&& other) = default;
    component1& operator=(component1&& other) = default;

    void create(int id_)
    {
        id = id_;
    }

    void update()
    {
        DEBUG("Component: id %d \n", this->id);
    }

    void on_event(const event_t* event)
    {
        if (event)
        {
            DEBUG("Event: %s\n", event->text.c_str());
        }
    }

    void on_actor_event(const actor_event_t* event)
    {
        if (event)
        {
            DEBUG("Event: %s\n", event->text.c_str());
        }
    }

private:
    int variable = 42;
    std::string var{"component 1:"};
};

class component2
    : public i_component
{
public:
    static void update(i_component* first, i_component* last)
    {
        auto begin = (component2*)first;
        auto end = (component2*)last;
        while (begin != end)
        {
            DEBUG("%s: id %d \n", begin->var.c_str(), begin->id);
            ++begin;
        }
    }

private:
    std::string var{"component 2:"};
};

void create(i_component* item, int id_)
{
    item->id = id_;
}

struct component3
    : public i_component
{
    std::string var{"component 3:"};
};

void update_component_3(i_component* first, i_component* last)
{
    auto begin = (component3*)first;
    auto end = (component3*)last;

    while (begin != end)
    {
        DEBUG("%s: id %d\n", begin->var.c_str(), begin->id);
        ++begin;
    }
}



class memory_range
{
public:
    memory_range(std::size_t size_in_bytes)
    {
        m_data = (char*)std::malloc(size_in_bytes);
        m_next_ready = m_data;
    }

    ~memory_range()
    {
        std::free(m_data);
    }

    template<class T>
    T* begin()
    {
        return static_cast<T*>(m_data);
    }

    template<class T>
    T* end()
    {
        return static_cast<T*>(m_next_ready);
    }

    std::size_t size()
    {
        return std::distance(m_data, m_next_ready);
    }

private:

    char* m_data{};
    char* m_next_ready{};
};

struct meta_information
{
    std::size_t size;
    Create create;
    Function update;
    Construct construct;
    Destruct destruct;
    OnEvent on_event;
    OnActorEvent on_actor_event;
};

template<class T>
meta_information
create_meta_information(const T& value,
                        Function update_function,
                        Create create_function,
                        OnEvent event_function,
                        OnActorEvent actor_event_function)
{
    meta_information info;
    info.create = create_function;
    info.construct = [](i_component* thing) { new(thing)T(); return thing; };
    info.update = update_function;
    info.destruct = [](i_component* thing) { ((T*)thing)->~T(); };
    info.size = sizeof(T);
    info.on_event = event_function;
    info.on_actor_event = actor_event_function;

    return info;
}

template<class T>
meta_information
create_meta_information(const T& value)
{
    const auto update_lambda = [](i_component* first, i_component* last)
    {
        auto begin = static_cast<T*>(first);
        auto end = static_cast<T*>(last);

        while (begin != end)
        {
            begin->update();
            ++begin;
        }
    };

    const auto create_lambda = [](i_component* item, int id)
    {
        ((T*)item)->create(id);
    };

    const auto on_event_lambda = [](i_component* thing, const event_t* event)
    {
        ((T*)thing)->on_event(event);
    };

    const auto on_actor_event_lambda = [](i_component* thing, const actor_event_t* event)
    {
        ((T*)thing)->on_actor_event(event);
    };

    return create_meta_information(value,
                                   update_lambda,
                                   create_lambda,
                                   on_event_lambda,
                                   on_actor_event_lambda);
}

template<std::size_t number_of_component_types>
class entity_manager
{
public:
    template <class T>
    void
    register_component(std::size_t index, T&& component)
    {
        m_components[index].information = create_meta_information(component);
    }

    void
    register_component(std::size_t index, meta_information information)
    {
        m_components[index].information = information;
    }

    void
    create_component(std::size_t index)
    {
        auto ptr = (i_component*)(m_components[index].next_free_block);
        m_components[index].next_free_block += m_components[index].information.size;
        m_components[index].information.construct(ptr);
        m_components[index].information.create(ptr, m_id++);
        m_components[index].size++;
    }

    void
    update_all()
    {
        for (auto& pair : m_components)
        {
            auto begin = (i_component*)pair.memory_block;
            auto end = (i_component*)pair.next_free_block;
            pair.information.update(begin, end);
        }

        event_t event;
        for (auto& pair : m_components)
        {
            if (pair.information.on_event == nullptr)
            {
                continue;
            }
            
            auto begin = pair.memory_block;
            auto end = pair.next_free_block;
            while (begin != end)
            {
                auto ptr = (i_component*)begin;
                pair.information.on_event(ptr, &event);
                begin += pair.information.size;
            }
        }

        actor_event_t actor_event;
        for (auto& pair : m_components)
        {
            if (pair.information.on_actor_event == nullptr)
            {
                continue;
            }
            
            auto begin = pair.memory_block;
            auto end = pair.next_free_block;
            while (begin != end)
            {
                auto ptr = (i_component*)begin;
                pair.information.on_actor_event(ptr, &actor_event);
                begin += pair.information.size;
            }
        }

    }

    ~entity_manager()
    {
        for (const auto& pair : m_components)
        {
            auto begin = pair.memory_block;
            auto end = pair.next_free_block;
            while (begin != end)
            {
                auto ptr = (i_component*)begin;
                pair.information.destruct(ptr);
                begin += pair.information.size;
            }
        }
    }

    // Not made for processing, but for sorting. Will invalidate references,
    // leading to a new lookup.
    template<class T, class Function>
    void sort(std::size_t index, Function function)
    {

        char* block = m_components[index].memory_block;

        auto begin = (T*)block;
        auto end = (T*)(m_components[index].next_free_block); // * sizeof(component1));

        //std::sort(begin, end,
        //          [](const i_component& lhs, const i_component& rhs)
        //{
        //    return lhs.id < rhs.id;
        //});
        DEBUG("Before\n");
        function(begin, end);
        DEBUG("After\n");

    }

private:
    struct component_pair
    {
        std::size_t generation = 0;
        meta_information information;
        char memory_block[512];
        char* next_free_block{memory_block};
        std::size_t size;
    };

    std::array<component_pair, number_of_component_types> m_components;
    int m_id = 0;

};

template<class T>
class smart_handle
{
public:
    smart_handle(T* value) 
    : m_value(value)
    {

    }

    template<class U>
    smart_handle(const smart_handle<U>& u)
    : m_value((T*)u.get())
    {

    }

    T* get() const
    {
        return m_value;
    }
private:
    T* m_value;
};


int
main(int argc, char** argv)
{
    entity_manager<3> e;
    e.register_component(0, component1());

    const auto info = create_meta_information(component2(), component2::update, create, nullptr, nullptr);
    e.register_component(1, info);

    const auto info2 = create_meta_information(component3(), update_component_3, create, nullptr, nullptr);
    e.register_component(2, info2);

    e.create_component(0);
    DEBUG("Created\n");
    e.create_component(0);
    DEBUG("Created\n");
    e.create_component(0);
    DEBUG("Created\n");
    e.create_component(0);
    DEBUG("Created\n");
    e.create_component(1);
    DEBUG("Created\n");
    e.create_component(1);
    DEBUG("Created\n");
    e.create_component(2);
    DEBUG("Created\n");
    e.create_component(2);
    DEBUG("Created\n");

    for (int i = 0; i < 10; ++i)
    {
        DEBUG("Start\n");
        e.update_all();

        auto sort = [](auto begin, auto end)
        {
            std::sort(begin, end,
                      [](const auto& lhs, const auto& rhs)
                      {
                        return lhs.id < rhs.id;
                      });
        };
        e.sort<component1>(0, sort);
        e.sort<component2>(1, sort);
        e.sort<component3>(2, sort);
    }

    i_component* comp = new component1;
    smart_handle<i_component> test(comp);
    smart_handle<component1> t2 = test;

    delete comp;

    return 0;
}
