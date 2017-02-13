////////////////////////////////////////////////////////////////
/// Look at function definitions on cppreference.com, as these
/// functions are not entirely correct.
/// the interface should mimic the std::unique_ptr interface,
/// regarding dereferencing it etc.
////////////////////////////////////////////////////////////////
template<class T>
class SmartHandle
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor. 
    ///        Handle is not valid unless constructed 
    ///        with parameters.
    ////////////////////////////////////////////////////////////
    SmartHandle() = default;

    ////////////////////////////////////////////////////////////
    /// \brief Proper constructor, the only one that leaves
    ///        a smart handle in valid form.
    ///
    /// \param object The object to reference.
    /// \param generation The generation the reference 
    ///        was created.
    /// \param MetaInformation Pointer the MetaInformation
    ///        of the component type.
    ////////////////////////////////////////////////////////////
    SmartHandle(T* object, 
                 std::size_t generation, 
                 MetaInformation* meta_info);

    ////////////////////////////////////////////////////////////
    /// \brief Gets the underlying pointer to the object.
    ///        Access is constant if not pointer is not
    ///        invalidated.
    ///
    /// \return Pointer to the object. 
    ///         nullptr if object was not found.
    ////////////////////////////////////////////////////////////
    T* get() const;

    ////////////////////////////////////////////////////////////
    /// \brief Convenience function for get.
    ///
    /// \return Pointer to the object.
    ///
    /// \see get
    ////////////////////////////////////////////////////////////
    T* operator*() const;

    ////////////////////////////////////////////////////////////
    /// \brief Convenience function for get.
    ///
    /// \return Pointer to the object.
    ///
    /// \see get
    ////////////////////////////////////////////////////////////
    T* operator->() const;
};
