#ifndef MY_CIRCULAR_QUEUE
#define MY_CIRCULAR_QUEUE

#include <cassert>

template <typename T>
class Queue {
    const int MAX_CAPACITY = 100;
    private:
        T q[MAX_CAPACITY];
        int head, tail;

    public:
        /**
         * Default constructor.
         * Initializes pointer to invalid index (-1),
         * to denote nothing has been stored.
         */
        Queue():head(-1), tail(-1){};

        /**
         * isEmpty, is both the head and tail pointers,
         * are invalid indices.
         */
        bool isEmpty() {
            return head == -1 && tail == -1;
        }

        /**
         * isFull, if we increment the tail pointer,
         * and we reach the head pointer.
         */
        bool isFull() {
            return (tail + 1) % MAX_CAPACITY == head;
        }

        /**
         * Queue, push to the tail
         */
        void push(const T& item){
            assert(!isFull());
            if(isEmpty()) {         // 1. If the queue is empty
                head = tail = 0;    // 2. Initialize the pointers
            }

            q[tail] = item;         // 3. Allocate the item
            tail = (tail + 1) % MAX_CAPACITY;   //4. Advance the tail pointer
        }

        /**
         * Queue, is FIFO
         * Two cases:
         * (1) We remove from a list of more than 1 items
         * (2) We remove from a list with 1 item
         */
        T pop() {
            assert(!isEmpty());
            T result = q[head];
            if(head == tail) {      // 1. Only 1 item in the queue
                head = tail = -1;   // 2. Reset pointers
            } else {
                head = (head + 1) % MAX_CAPACITY;
            }
            return restult;
        }

        // NOTE: No 'delete[]' is required
        // since 'T q[MAX_CAPACITY]' was created on the stack,
        // not on the heap using the keyword 'new'.
        // Hence, not need for destructor.
        // ~Queue() { }
};

#endif