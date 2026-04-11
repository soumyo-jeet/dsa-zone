#include <iostream>
using namespace std;

typedef struct StackWithArray
{
    int *arr;
    int top;
    int size;
} Stack;

// push
int push(Stack *s, int p)
{
    s->top++;
    if (s->top >= s->size)
    {
        return 0;
    }
    s->arr[s->top] = p;
    return 1;
}

// pop
int pop(Stack *s)
{
    if (s->top < 0)
        return 0;
    s->top--;
    return 1;
}


// size
int size(Stack *s)
{
    return s->top + 1;
}


// isEmpty
int isEmpty(Stack *s) {
    if(s->top == -1) return 1;
    return 0;
}

// top
int top(Stack *s)
{
    return s->arr[s->top];
}

// showStack
void showStack(Stack s)
{
    int top = s.top, *arr = s.arr;
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] <<" ";
    }
    cout<< endl;
}

int main()
{
    Stack s;
    int n, p, flag = 1;

    cout << "Size of the stack: ";
    cin >> n;
    s.size = n;
    s.top = -1;
    s.arr = new int[n];

    while (flag)
    {
        int f;
        cout << "1 -> Push" << endl
             << "2 -> Pop" << endl
             << "3 -> Top" << endl
             << "4 -> Size" << endl
             << "5 -> IsEmpty" << endl
             << "6 -> Exit" << endl;

        cin >> f;
        switch (f)
        {
        case 1:
        {
            int p;
            cout << "Push element: ";
            cin >> p;
            int res = push(&s, p);
            if (res)
                showStack(s);
            else
                cout << "Stack overflow" << endl;
            break;
        }

        case 2:
        {
            int res = pop(&s);
            if (res)
                showStack(s);
            else
                cout << "Stack underflow" << endl;
            break;
        }

        case 3:
        {
            int sig = isEmpty(&s);
            if(sig) {
                cout << "Stack is empty" << endl;
                break;
            }

            int res = top(&s);
            cout << "Top: " << res << endl;
            break;
        }

        case 4:
        {
            int res = size(&s);
                cout << "Size: " << res << endl;
            break;
        }

        case 5:
        {
            int res = isEmpty(&s);
                cout << "isEmpty: " << res << endl;
            break;
        }

        case 6:
            flag = 0;
            break;

        default:
            flag = 0;
        }
    }

    delete[] s.arr;

    return 0;
}