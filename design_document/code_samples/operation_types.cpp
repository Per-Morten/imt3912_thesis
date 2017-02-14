using LogicEvent = std::shared_ptr<nox::logic::event::Event>;

////////////////////////////////////////////////////////////////
/// \brief Function applied to a range of elements,
///        functions in an iterator like manner.
///
/// \param first pointer to first element in the range.
/// \param last past-the-end pointer of the range,
///             used for checking if the end has been reached.
///
/// \warning It is the implementors responsibility to cast to
///          correct type.
////////////////////////////////////////////////////////////////
using RangedOperation = void(*)(IComponent* first,
                                IComponent* last);

////////////////////////////////////////////////////////////////
/// \brief Function applied to a single element.
///
/// \param component the component to apply the function to.
///
/// \warning It is the implementors responsibility to cast to
///          correct type.
////////////////////////////////////////////////////////////////
using SingleOperation = void(*)(IComponent* component);

////////////////////////////////////////////////////////////////
/// \brief Function to be called on events coming from the 
///        NOX event system.
///
/// \param first pointer to first element in the range.
/// \param last past-the-end pointer of the range.
/// \param event the event to respond to.
///
/// \warning It is the implementors responsibility to cast to
///          correct type.
////////////////////////////////////////////////////////////////
using LogicEventOperation = void(*)(IComponent* first,
                                    IComponent* last,
                                    const LogicEvent& event);

////////////////////////////////////////////////////////////////
/// \brief Function to be called on inter component 
///        communication.
///
/// \param component pointer to the component that shall
///                  receive the event.
/// \param event the event to respond to.
///
/// \warning It is the implementors responsibility to cast to
///          correct type.
////////////////////////////////////////////////////////////////
using ActorEventOperation = void(*)(IComponent* component,
                                    const ActorEvent* event); 
