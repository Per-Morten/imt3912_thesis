// Function is not overloaded, signature of Component::func
// is same as U::func
template<class T, class U, class OperationType, class Operation>
typename std::enable_if<std::is_same<T, U>::value, OperationType>::type
getOperation(T, U, OperationType, Operation)
{
    return nullptr;
}

// Function is overloaded, signature of Component::func
// is not same as U::func
// U::func will hide Component::func if it is declared,
template<class T, class U, class OperationType, class Operation>
typename std::enable_if<!std::is_same<T, U>::value, OperationType>::type
getOperation(T, U, OperationType, Operation operation)
{
    return operation;
}

template<class T>
MetaInformation
createMetaInformation(const TypeIdentifier& typeIdentifier)
{
    MetaInformation info;
    // initialize info

    info.update =
        getOperation(&Component::update,
                     &T::update,
                     info.update,
                     [](Component* first,
                        Component* last,
                        const nox::Duration& deltaTime)
                        {
                            auto begin = static_cast<T*>(first);
                            auto end = static_cast<T*>(last);

                            while (begin != end)
                            {
                                begin->update(deltaTime);
                                ++begin;
                            }
                        });

    return info;
}

