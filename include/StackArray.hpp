#define MAX 1000

class StackArray {
    int top;

    public:
        int a[MAX];
        StackArray() { top = 1; }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};