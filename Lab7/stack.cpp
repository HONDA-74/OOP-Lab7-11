#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;
    static int count;

    public:
    Stack() {
        arr = new int[10];
        capacity = 10;
        top = 0;
        count++;
    }

    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = 0;
        count++;
    }

    Stack& push(int value) {
        if (top == capacity) {
            cout << "Cannot push " << endl;
        } else {
            arr[top] = value;
            top++;
        }
        return *this;
    }

    Stack& pop() {
        if (!top) {
            cout << "Nothing to pop" << endl;
        } else {
            cout << "Popped: " << arr[top-1] << endl;
            top--;
        }
        return *this;
    }

    void showElements() const {
        if (!top) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static int getCount() {
        return count;
    }

    ~Stack() {
        delete[] arr;
        count--;
    }
};

int Stack::count = 0;

int main() {
    Stack s1;
    s1.push(10).push(20).push(30);
    s1.showElements();
    s1.pop().pop();
    s1.showElements();

    Stack s2(5);
    s2.push(100).push(200);
    s2.showElements();

    cout << "Total Stack instances: " << Stack::getCount() << endl;

    return 0;
}