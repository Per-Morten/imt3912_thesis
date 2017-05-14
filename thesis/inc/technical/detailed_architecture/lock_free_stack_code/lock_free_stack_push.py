push(data):
    memory = allocator.allocate(sizeof(node))
    new_head = new (memory) node(data)

    new_head.next = head

    # 1
    while !cas(head, new_head.next, new_head):
        ; # empty body

# 1: new_head.next is constantly being updated to the
#    correct value when the cas fails.
