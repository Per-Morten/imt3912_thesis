allocate(size):
    desired = null # 1
    memory = null  # 2
    owning_memory = false # 3

    while memory == null:
        expected = first_free           # 4
        memory = try_allocate(expected)
        if memory != null:
            if owning_memory:
                delete desired
            return memory

        if !owning_memory:
            desired = expected.next
            if desired == null
                desired = new block;
                owning_memory = true

        prev = expected

        if cas(first_free, expected, desired):
            prev.next = desired
            memory = try_allocate(desired, size)
            owning_memory = false

    return memory

# 1: Variables that needs to be remembered through the iterations of the loop.
# 2: The memory to return
# 3: Used to indicate if deallocation of memory is needed.
# 4: Load the first free block
# 5: See if it is possible to allocate
