template<class T>
MetaInformation
createMetaInformation(const TypeIdentifier& typeIdentifier)
{
    MetaInformation info;
    // initialize other info.

    info.update = [](Component* first,
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
    };

    return info;
}
