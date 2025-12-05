#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;
    static int count;

public:
    Stack() = delete;

    Stack(int size = 5) : arr(new int[size]), top(0), capacity(size) {
        count++;
        cout << "Parameterized Constructor called (size = " << size << ")\n";
    }

    // stack x;   stack y=x;
    Stack(const Stack& other) : arr(new int[other.capacity]) , top(other.top) , capacity(other.capacity) {
        for (int i = 0; i < top; i++)
            arr[i] = other.arr[i];
        count++;
        cout << "Copy Constructor called\n";
    }

    // stack x;   stack y=std::move(x);
    Stack(Stack&& other) noexcept : arr(other.arr), top(other.top), capacity(other.capacity) {
        other.arr = nullptr;
        other.top = 0;
        other.capacity = 0;
        count++;
        cout << "Move Constructor called\n";
    }

    // stack x; stack y;  y=x;
    Stack& operator=(const Stack& other) {
        cout << "Copy Assignment Operator called\n";
        if (this != &other) { // self-assignment
            delete[] arr;
            capacity = other.capacity;
            top = other.top;
            arr = new int[capacity];
            for (int i = 0; i < top; i++)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    // stack x(); stack y;  y=std::move(x);
    Stack& operator=(Stack&& other) noexcept {
        cout << "Move Assignment Operator called\n";
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            capacity = other.capacity;
            top = other.top;

            other.arr = nullptr;
            other.top = 0;
            other.capacity = 0;
        }
        return *this;
    }

    Stack& push(int value) {
        if (top == capacity) {
            cout << "Stack is full, cannot push!\n";
        } else {
            arr[top++] = value;
        }
        return *this;
    }

    Stack& pop() {
        if (top == 0) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Popped: " << arr[top - 1] << endl;
            top--;
        }
        return *this;
    }

    void showElements() const {
        if (top == 0) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top - 1; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    int operator[](int index) const {
        if (index < 0 || index >= top) {
            cout << "Index out of range!\n";
            return -1;
        }
        return arr[index];
    }

    static int getCount() {
        return count;
    }

    ~Stack() {
        cout << "Destructor called for Stack (capacity = " << capacity << ")\n";
        delete[] arr;
        arr = nullptr;
        count--;
    }
};

int Stack::count = 0;

int main() {
    //Stack s0; default constructor
    Stack s1(4);
    s1.push(10).push(20).push(30);
    s1.showElements();


    Stack s2 = s1;
    s2.showElements();

    Stack s3 = std::move(s1);
    s3.showElements();

    Stack s4(2);
    s4 = s2;
    s4.showElements();

    Stack s5(3);
    s5 = std::move(s3);

    cout << "Element at index 1 in s5: " << s5[1] << endl;

    cout << "\nActive Stacks: " << Stack::getCount() << endl;

    return 0;
}
