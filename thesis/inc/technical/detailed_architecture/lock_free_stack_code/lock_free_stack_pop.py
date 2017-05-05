try_pop(out_value&): # 1
    expected = head
    if expected == null:
        return false

    while !cas(head, expected, expected.next):
        ; # empty body

    out_value = expected.value
    ~node(expected)
    allocator.deallocate(expected)

    return true

# 1: Value is sent as an out parameter, to make it easier
#    to use the try_pop function in a loop.
