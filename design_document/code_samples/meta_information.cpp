struct MetaInformation
{
    ////////////////////////////////////////////////////////////
    /// \brief Used to identify the type of the components
    ///        belonging to this MetaInformation.
    ////////////////////////////////////////////////////////////
    TypeIdentifier typeIdentifier;

    ////////////////////////////////////////////////////////////
    /// \brief Contains the size of the object in bytes.
    ///        Used for memory allocation, and potentially
    ///        pointer arithmetic.
    ////////////////////////////////////////////////////////////
    std::size_t sizeInBytes;

    ////////////////////////////////////////////////////////////
    /// \brief Used for construction if the class in question.
    ///
    /// \detail This defaults to the correct constructor of 
    ///         the class with in-place construction.
    ///         Constructor must be parameterless.
    ///         Should not be overloaded in most cases.
    ////////////////////////////////////////////////////////////
    SingleOperation constructor;

    ////////////////////////////////////////////////////////////
    /// \brief Used for destruction if the class in question.
    ///
    /// \detail This defaults to the correct destruction of 
    ///         the class with in-place construction.
    ///         Constructor must be parameterless.
    ///         Should not be overloaded in most cases.
    ////////////////////////////////////////////////////////////
    SingleOperation destructor;

    ////////////////////////////////////////////////////////////
    /// \brief Used for initializing the component with a json
    ///        object.
    ///
    /// \detail After an object has been constructed, 
    ///         but before it is awakened.
    ////////////////////////////////////////////////////////////
    InitializationOperation initialize;
    
    ////////////////////////////////////////////////////////////
    /// \brief Called on a newly created object.
    ///        Created objects are not updated before they are
    ///        activated.
    ////////////////////////////////////////////////////////////
    SingleOperation onAwake;

    ////////////////////////////////////////////////////////////
    /// \brief Called when an object is requested to 
    ///        be activated.
    ///        See lifecycle section.
    ////////////////////////////////////////////////////////////
    SingleOperation onActivate;

    ////////////////////////////////////////////////////////////
    /// \brief Called when an object is requested to be
    ///        deactivated.
    ///        See lifecycle section.
    ////////////////////////////////////////////////////////////
    SingleOperation onDeactivate;

    ////////////////////////////////////////////////////////////
    /// \brief Called when an object is going to be destroyed.
    ///        Only deactivated objects can be destroyed.
    ///        
    ////////////////////////////////////////////////////////////
    SingleOperation onHibernate;

    ////////////////////////////////////////////////////////////
    /// \brief The update function that will be on each
    ///        component type once per frame.
    ////////////////////////////////////////////////////////////
    RangedOperation onUpdate;

    ////////////////////////////////////////////////////////////
    /// \brief What sort of data access does the update
    ///        function do?
    ///        See multi-threading section.
    ////////////////////////////////////////////////////////////
    DataAccess onUpdateDataAccess;

    ////////////////////////////////////////////////////////////
    /// \brief The function that will be run on each component
    ///        type per event from other parts of the engine.
    ///        i.e. The NOX Event system.
    ////////////////////////////////////////////////////////////
    RangedOperation onLogicEvent;

    ////////////////////////////////////////////////////////////
    /// \brief What sort of data access does the onLogicEvent
    ///        function do.
    ///        See multi-threading section.
    ////////////////////////////////////////////////////////////
    DataAccess onLogicEventDataAccess;

    ////////////////////////////////////////////////////////////
    /// \brief This function is called on components when an
    ///        ActorEvent targeted them occurs.
    ///        This is with the "new" 
    ////////////////////////////////////////////////////////////
    RangedOperation onActorEvent;

    ////////////////////////////////////////////////////////////
    /// \brief What sort of data access does the onActorEvent
    ///        function do.
    ///        See multi-threading section.
    ////////////////////////////////////////////////////////////
    DataAccess onActorEventDataAccess;
};

////////////////////////////////////////////////////////////////
/// \brief Various convenience create functions will be made,
///        to ensure that the user won't have to write much
///        boilerplate unless opt-ing out of a lot of stuff to
///        improve performance.
////////////////////////////////////////////////////////////////
template<class T>
MetaInformation
createMetaInformation(const T& value);
