try_pop(out_value&): # 1
    expected = head
    if expected == null:
        return false

    while !cas(head, expected, expected.next):
        ; # empty body

    out_value = expected.value
    ~node(expected) # 2

    return true

# 1: Value is sent as an out parameter, to make it easier
#    to use the try_pop function in a loop.
# 2: Note that we are not deallocating here, just destroying
#    the node.
#    The stack will have its memory properly deallocated
#    when the clear function is called.
