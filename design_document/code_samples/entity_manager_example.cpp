int main()
{
    // omitted ...
    EntityManager e;

    // Configuring the EntityManager
    e.registerComponent(createMetaInformation<C1>("C1"));
    e.registerComponent(createMetaInformation<C2>("C2"));
    e.configureComponents();

    EntityId eID = e.createEntity();

    // A feature we want to get in place is implicit conversion,
    // within the smart handles, so that this is possible,
    // and so we don't need so much casting.
    e.assignComponent(eID, "C1");

    // Create a component of type 2 and assign it to the entity
    // with EntityId eID.
    e.assignComponent(eID, "C2");

    // Erasing a component
    e.removeComponent(eID, "C2");

    // omitted ...
    // Update loop
    while (true)
    {
        // omitted ...
        e.updateAll(deltaTime);
        SmartHandle<C1> c1Component = e.getComponent(eID, "C1");
        c1Component->someFunction();
        // omitted ...
    }
    
    // Will remove all the components, including "C1"
    // This is not needed if all the components have been removed.
    // its just a convenience for saying: 
    // Delete everything related to eID
    e.removeEntity(eID);

    return 0;
}
