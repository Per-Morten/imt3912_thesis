class TypeIdentifier
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Creates a TypeIdentifier with a given numerical
    ///        value, this value is not hashed!
    ///        User can pre_hash if wanted.
    ///
    /// \param identifier The numerical value used to identify
    ///                   this type.
    ////////////////////////////////////////////////////////////
    TypeIdentifier(std::size_t identifier);

    ////////////////////////////////////////////////////////////
    /// \brief Creates a TypeIdentifier with a numerical value
    ///        based on std::hash<std::string>.
    ///
    /// \param identifier The string used to create a 
    ///                   hash value identifying this type.
    ////////////////////////////////////////////////////////////
    TypeIdentifier(const std::string& identifier);

    ////////////////////////////////////////////////////////////
    /// \brief Returns the underlying numerical value.
    ////////////////////////////////////////////////////////////
    std::size_t value() const;
};

////////////////////////////////////////////////////////////////
/// \brief Convenience overload allowing for easy comparing.
////////////////////////////////////////////////////////////////
bool operator==(const TypeIdentifier& lhs, 
                const TypeIdentifier& rhs);

////////////////////////////////////////////////////////////////
/// \brief Convenience overload allowing for easy comparing.
////////////////////////////////////////////////////////////////
bool operator!=(const TypeIdentifier& lhs, 
                const TypeIdentifier& rhs);
