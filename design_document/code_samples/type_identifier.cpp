class TypeIdentifier
{
public:
    TypeIdentifier(std::size_t identifier);
    TypeIdentifier(const std::string& identifier);

    std::size_t value() const;
};
