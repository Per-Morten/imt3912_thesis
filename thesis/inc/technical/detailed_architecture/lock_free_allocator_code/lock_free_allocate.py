allocate(size):
    desired = null
    memory = null
    owning_memory = false

    while memory == null:
        expected = first_free
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
