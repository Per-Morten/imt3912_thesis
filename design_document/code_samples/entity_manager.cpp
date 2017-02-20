class EntityManager 
    : public nox::event::IListener
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Sets up the entity manager in require fashion,
    ///        does not preallocate space for component types.
    ////////////////////////////////////////////////////////////
    EntityManager() = default;

    ////////////////////////////////////////////////////////////
    /// \brief Sets up the entity manager in the 
    ///        required fashion.
    ///        Preallocates space for the component types.
    ///
    /// \param numberOfComponentTypes 
    ///        The number of different component types 
    ///        that will exist.
    ////////////////////////////////////////////////////////////
    EntityManager(std::size_t numberOfComponentTypes);

    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;
    EntityManager(EntityManager&&) = delete;
    EntityManager& operator=(EntityManager&&) = delete;
    ~EntityManager();

    ////////////////////////////////////////////////////////////
    /// \brief Registers a component and meta information, 
    ///        basically telling the entity manager 
    ///        that this is a type of component that
    ///        can be created.
    ///
    /// \param metaInformation the extra information 
    ///        needed to process the component.
    ///
    /// \see MetaInformation.
    ////////////////////////////////////////////////////////////
    void 
    registerComponent(const MetaInformation& metaInformation);

    ////////////////////////////////////////////////////////////
    /// \brief Sets up the entity manager, 
    ///        sorting the different 
    ///        components based on their thread access data etc.
    /// 
    /// \warning Must be run after register components!
    ////////////////////////////////////////////////////////////
    void
    configureComponents();

    ////////////////////////////////////////////////////////////
    /// \brief Creates a new entity, 
    ///        does no allocation or creates any components, 
    ///        it just creates a new id.
    ///        This id can again be used to 
    ///        assign components to.
    ///
    /// \return The id of the newly created entity.
    ////////////////////////////////////////////////////////////
    EntityId
    createEntity();

    ////////////////////////////////////////////////////////////
    /// \brief Creates a new entity with the components 
    ///        from the given json object.
    ///
    /// \return The id of the newly created entity.
    ////////////////////////////////////////////////////////////
    EntityId
    createEntity(const Json::Value& value);

    ////////////////////////////////////////////////////////////
    /// \brief Assigns a component to the given entity.
    ///
    /// \param id the entity to assign the component to.
    /// \param identifier of the type that will be added.
    ////////////////////////////////////////////////////////////
    void
    assignComponent(const EntityId& id,
                    const TypeIdentifier& identifier);

    ////////////////////////////////////////////////////////////
    /// \brief Assigns a component to the given entity,
    ///        and initializes it with the given value.
    /// 
    /// \param id the entity to assign the component to.
    /// \param identifier of the type that will be added.
    /// \param value Json value to initialize the component
    ///              with.
    ////////////////////////////////////////////////////////////
    void
    assignComponent(const EntityId& id,
                    const TypeIdentifier& identifier,
                    const Json::Value& value);

    ////////////////////////////////////////////////////////////
    /// \brief Gets a handle to the specified components 
    ///        belonging to the specified entity.
    ///
    /// \param id the id of the entity owning the component.
    /// \param identifier the identifier of the component 
    ///        type to get.
    ///
    /// \return Handle to the specified component.
    ///
    /// \see SmartHandle
    ////////////////////////////////////////////////////////////
    SmartHandle<IComponent>
    getComponent(const EntityId& id,
                 const TypeIdentifier& identifier);

    ////////////////////////////////////////////////////////////
    /// \brief Removes the component specified by the
    ///        identifier and id.
    ///
    /// \param id the id of the entity that the component 
    ///        belongs to.
    /// \param identifier the type identifier of the component.
    ///
    /// \warning This will destroy the component.
    ////////////////////////////////////////////////////////////
    void
    removeComponent(const EntityId& id,
                    const TypeIdentifier& identifier);

    ////////////////////////////////////////////////////////////
    /// \brief Removes all the components of the entity
    ///        specified by the id.
    ///
    /// \warning This will destroy all components that belongs
    ///          to the entity.
    ////////////////////////////////////////////////////////////
    void
    removeEntity(const EntityId& id);

    ////////////////////////////////////////////////////////////
    /// \brief Starts the update loop, running through 
    ///        the different stages of the batched updates.
    ///        This includes running onEvents and 
    ///        onComponentEvent onto the components.
    /// 
    /// \param deltaTime time since last update.
    ////////////////////////////////////////////////////////////
    void
    step(const nox::Duration& deltaTime);

    ////////////////////////////////////////////////////////////
    /// \brief Applies a function to an entire range,
    ///        this function is not intended for things like
    ///        update, but rather for sorting functionality, 
    ///        etc.
    ///
    /// \param identifier the identifier of the type to do the
    ///                   operation on.
    ///
    /// \param rangedOperation the operation to carry out on 
    ///                        said type.
    ///
    /// \warning This function will invalidate all handles,
    ///          even if no positions are changed!
    ///
    /// \warning It is the callers responsibility to cast the
    ///          parameters to rangedOperation to correct type,
    ///          casting to incorrect type probably introduce
    ///          bugs!
    ////////////////////////////////////////////////////////////
    void
    applyToAll(const TypeIdentifier& identifier,
               RangedOperation rangedOperation);

    ////////////////////////////////////////////////////////////
    /// \brief Broadcasts a given event to an entity.
    ///
    /// \param id the id of entity that will receive the 
    ///        event.
    /// \param event the event to broadcast.
    ////////////////////////////////////////////////////////////
    void
    broadcastComponentEvent(const EntityId& id,
                            const ComponentEvent* event);

    ////////////////////////////////////////////////////////////
    /// \brief Sends an event to a specified component
    ///        belonging to an entity.
    ///
    /// \param id the id of the entity that will receive the
    ///        event.
    /// \param identifier the receiver component type.
    /// \param event the event to send.
    ////////////////////////////////////////////////////////////
    void
    sendComponentEvent(const EntityId& id,
                       const TypeIdentifier& identifier,
                       const ComponentEvent* event);

    ////////////////////////////////////////////////////////////
    /// \brief Returns the logic context of EntityManager.
    ////////////////////////////////////////////////////////////
    nox::logic::IContext*
    getLogicContext();

    ////////////////////////////////////////////////////////////
    /// \brief Used to interact with the other parts of the
    ///        engine that uses events. 
    ///        i.e. These are not entity events.
    ////////////////////////////////////////////////////////////
    virtual void 
    onEvent(const std::shared_ptr<event::Event>& event) override;
};
