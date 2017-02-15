// This enum thinks in terms of non thread safe access.
// if a function accesses data that is thread protected, 
// it can be seen as independent.
// Unless otherwise specified READ_MODIFY_WRITE is assumed
enum class DataAccess
{
    // Function works in complete isolation, embarrassingly parallel.
    // OR 
    // Does operations on a thread safe system/structure.
    INDEPENDENT,

    // Function reads from other components/systems.
    READ,

    // Function reads and changes other components/systems.
    // That are NOT thread safe.
    READ_MODIFY_WRITE,
};
