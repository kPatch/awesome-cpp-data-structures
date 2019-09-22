#define MAX 1000

class StackLL {
    int top;

    public:
        int a[MAX];
        Stack() { top = 1; }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};