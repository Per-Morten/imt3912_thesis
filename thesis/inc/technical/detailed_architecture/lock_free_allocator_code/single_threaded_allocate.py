allocate(size):
    if first_free.used + size > MAX_SIZE:
        new_block = (first_free.next != null) ? first_free.next
                                              : new block
        first_free.next = new_block
        first_free = new_block

    prev_size = first_free.used
    first_free.used += size
    return &first_free.memory[prev_size]
