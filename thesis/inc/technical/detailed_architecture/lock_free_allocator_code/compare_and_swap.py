cas(atomic, expected, desired):
    if atomic == expected:
        atomic = desired
        return true

    expected = atomic
    return false
