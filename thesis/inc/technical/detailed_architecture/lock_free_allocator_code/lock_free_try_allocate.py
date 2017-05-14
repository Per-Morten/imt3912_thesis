try_allocate(block, size):
    expected = block.used
    desired = 0

    do:
        desired = expected + size
        if desired > MAX_SIZE:
            return null
    while !cas(block.used, expected, desired)

    return &block.memory[desired]
