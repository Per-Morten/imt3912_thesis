worker_function(this):
    while this.should_continue.load():

        wait_pred = [this, task]
        { return this.tasks.pop(task) || !this.should_continue }

        this.cv.wait_for(this.lock,
                         250ms, // # 1
                         wait_pred)

        this.lock.unlock

        if task:
            invoke(task)
            task_count--

// # 1: Waiting 250ms here, to ensure that all threads wake up at some
//      point, as condition variables don't "stay open", after being
//      notified.
//      250ms was chosen just because it is short enough that a human
//      won't notice, however it should be long enough to avoid constant
//      wakeup of the thread.
