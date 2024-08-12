class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

void MyStack ::push(int x)
{
    top = top + 1;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if (top == -1)
    {
        return -1;
    }
    int element = arr[top];
    top = top - 1;
    return element;
}