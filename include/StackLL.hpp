#define MAX 1000

class StackLL {
    public:
        int data;
        StackLL* next; // Next NODE
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};