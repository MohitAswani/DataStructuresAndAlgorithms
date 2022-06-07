# Applications of queue :

* Single resource and multiple consumers. (This is what happens in computer, there is a single resource processor and multiple proccess want to use it. So we need to use queue to handle this situation.)

* Synchronizations between slow and fast devices.

* In operating systems (semaphores,FCFS scheduling,spooling,buffers for devices like keyboards).
    * Semaphores : sleeping processes waiting in a queue and whenever a resource becomes available one of these processes wakes up and uses the resource.

    * FCFS : first come first serve CPU scheduling algorithm.

    * Spooling : used in printers , since a printer can print only a single page at a time so there is a queue of tasks to print.

    * Buffers : used in devices like keyboards, since a keyboard can only type one character at a time so there is a queue of tasks to type.Eg: stdin,stdout.

* In computer networks (routers/switches and mail queues)

* Variations : deque, priority queue and doubly ended priority queue.
    * Deque : queue that supports adding and removing items from both ends.

    * Priority queue : queue that supports adding and removes of items based on a value called priority.

    * Doubly ended priority queue : queue that supports adding and removes of items based on a value called priority using the highest as well lowest priority.