#include <iostream>
using namespace std;

class Complex {
    float real = 0.0;
    float imag = 0.0;
    static int count ;

public:
    Complex() = default; //cant increment count

    Complex(float r) : real(r), imag(0.0) { count++; }
    Complex(float r, float i) : real(r), imag(i) { count++; }

    Complex(const Complex& c) {
        real = c.real;
        imag = c.imag;
        count++;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real , imag * other.imag);
    }

    Complex operator/(const Complex& other) const {
        if(other.real == 0 || other.imag == 0) {
            cout << "Error: Division by zero" << endl;
            return Complex(0.0, 0.0);
        }
        return Complex(real / other.real, imag / other.imag);
    }

    bool operator<(const Complex& other) const {
        return (real < other.real) && (imag < other.imag);
    }

    bool operator>(const Complex& other) const {
        return (real > other.real) && (imag > other.imag);
    }


    Complex& operator++() { // prefix
        real++;
        return *this;
    }

    Complex operator++(int) { // postfix
        Complex temp = *this;
        real++;
        return temp;
    }

    Complex& operator--() { // prefix
        real--;
        return *this;
    }

    Complex operator--(int) { // postfix
        Complex temp = *this;
        real--;
        return temp;
    }

    operator float() const {
        return real ;
    }

    void printComplex() const {
        if(imag ==0 && real ==0) 
            { cout << "0" << endl; } 
        else if(imag == 0) { cout << real << endl; } 
        else if (real == 0) { 
            if (imag == 1) cout << "i" << endl; 
            else if (imag == -1) cout << "-i" << endl; 
            else cout << imag << "i" << endl; 
        } 
        else if(imag == 1) { cout << real << "+i" << endl; } 
        else if(imag == - 1) { cout << real << "-i" << endl; } 
        else if(imag < 0) { cout << real << imag << "i" << endl; } 
        else { cout << real << "+" << imag << "i" << endl; }
    }

    static void showCounter() {
        cout << "Active Complex objects: " << count << endl;
    }

    ~Complex() { count--; }

    friend ostream& operator<<(ostream& cout, const Complex& c);
    friend istream& operator>>(istream& cin, Complex& c);
};

int Complex::count = 0;

ostream& operator<<(ostream& cout, const Complex& c) {
    if(c.imag ==0 && c.real ==0) 
        { cout << "0" << endl; } 
    else if(c.imag == 0) { cout << c.real << endl; } 
    else if (c.real == 0) { 
        if (c.imag == 1) cout << "i" << endl; 
        else if (c.imag == -1) cout << "-i" << endl; 
        else cout << c.imag << "i" << endl; 
    } 
    else if(c.imag == 1) { cout << c.real << "+i" << endl; } 
    else if(c.imag == - 1) { cout << c.real << "-i" << endl; } 
    else if(c.imag < 0) { cout << c.real << c.imag << "i" << endl; } 
    else { cout << c.real << "+" << c.imag << "i" << endl; }
    return cout;
}

istream& operator>>(istream& cin, Complex& c) {
    cout << "Enter real part: ";
    cin >> c.real;
    cout << "Enter imaginary part: ";
    cin >> c.imag;
    return cin;
}


template <class T>
class Stack {
    int top;
    int capacity;
    T* data;

    static int counter ;

public:

    Stack() : top(0), capacity(10) {
        data = new T[capacity];
        counter++;
    }

    Stack(int c) : top(0), capacity(c) {
        data = new T[capacity];
        counter++;
    }

    Stack(const Stack& other) {
        top = other.top;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < top; i++)
            data[i] = other.data[i];
        counter++;
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] data;
            top = other.top;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < top; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    ~Stack() {
        delete[] data;
        counter--;
    }

    static int showCounter() { return counter; }

    bool isEmpty() { return top == 0; }
    bool isFull()  { return top == capacity; }

    void push(T value) {
        if (isFull())
            cout << "Stack is full!\n";
        else
            data[top++] = value;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }
        top--;
        return data[top];
    }
};

template <class T>
T mySum(const T a, const T b) {
    return a + b;
}


template<class T>
int Stack<T>::counter = 0;
//==============================================


class Base {
protected:
    int a, b;

public:
    Base() : a(0), b(0) {}
    Base(int n) : a(n), b(n) {}
    Base(int n1, int n2) : a(n1), b(n2) {}

    void setA(int n) { a = n; }
    void setB(int n) { b = n; }

    int getA() { return a; }
    int getB() { return b; }

    int calcSum() { return a + b; }
};

class Derived : public Base {
    int c;

public:
    Derived() : Base() , c(0) {}
    Derived(int n) : Base(n), c(n) {}
    Derived(int n1, int n2, int n3) : Base(n1, n2), c(n3) {}

    void setC(int n) { c = n; }
    int getC() { return c; }

    int calcSum() {
        return Base::calcSum() + c;
    }
};

int main() {
    cout << "===== TEMPLATE STACK =====\n";

    Stack<int> si(5);
    si.push(10);
    si.push(20);

    Stack<float> sf(5);
    sf.push(1.5);
    sf.push(2.5);

    Stack<char> sc(5);
    sc.push('X');
    sc.push('Y');

    cout << "Pop int: " << si.pop() << endl;
    cout << "Pop float: " << sf.pop() << endl;
    cout << "Pop char: " << sc.pop() << endl;

    cout << "Number of int stacks: " << Stack<int>::showCounter() << endl;
    cout << "Number of char stacks: " << Stack<char>::showCounter() << endl;

    cout << "\n===== TEMPLATE SUM FUNCTION =====\n";
    cout << "Sum int: " << mySum(5, 9) << endl;
    cout << "Sum float: " << mySum(2.5f, 3.1f) << endl;
    cout << "Sum double: " << mySum(4.5, 1.2) << endl;
    cout << "Sum complex: " << mySum(Complex(1, 2), Complex(3, 4)) << endl; // + operator of complex 


    cout << "\n===== INHERITANCE =====\n";

    Derived d1;
    d1.setA(5);
    d1.setB(3);
    d1.setC(2);

    Derived d2(5);
    Derived d3(5, 6, 4);
    Base b(4, 8);

    cout << "Sum d1: " << d1.calcSum() << endl;
    cout << "Sum d2: " << d2.calcSum() << endl;
    cout << "Sum d3: " << d3.calcSum() << endl;
    cout << "Sum base b: " << b.calcSum() << endl;

    return 0;
}
