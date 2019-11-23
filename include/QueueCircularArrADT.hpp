#ifndef MY_CIRCULAR_QUEUE
#define MY_CIRCULAR_QUEUE

#include <iostream> // Only needed to test with print statement
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
         * isEmpty, if both the head and tail pointers,
         * are invalid indices (-1).
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
            if(isEmpty()) {         // 1. If the queue is empty
                head = tail = 0;    // 2. Initialize the pointers
                q[tail] = item;
            } else {
                assert(!isFull());
                tail = (tail + 1) % MAX_CAPACITY;   //3. Advance the tail pointer
                q[tail] = item;                     // 4. Allocate the item 
            }
        }

        /**
         * Queue, is FIFO - First In First Out
         * Means pop from head.
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
            return result;
        }

        void printList() {
            int i = head;
            while(i != tail) {
                std::cout << q[i] << std::endl;
                i = (i + 1) % MAX_CAPACITY;
            }
        }

        // NOTE: No 'delete[]' is required
        // since 'T q[MAX_CAPACITY]' was created on the stack,
        // not on the heap using the keyword 'new'.
        // Hence, no need for destructor.
        // ~Queue() { }
};

#endif