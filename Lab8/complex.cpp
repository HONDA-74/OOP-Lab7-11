#include <iostream>
#include <cmath>
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

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);
    Complex c3(c1);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "Addition: " << c1 + c2 << endl;
    cout << "Subtraction: " << c1 - c2 << endl;
    cout << "Multiplication: " << c1 * c2 << endl;
    cout << "Division: " << c1 / c2 << endl;

    cout << "Prefix ++: " << ++c1 << endl;
    cout << "Postfix ++: " << c1++ << endl;
    cout << "After postfix: " << c1 << endl;

    cout << "Cast of c1: " << float(c1) << endl;

    cout << "(c1 > c2): " << (c1 > c2 ? "True" : "False") << endl;

    Complex::showCounter();

    return 0;
}
