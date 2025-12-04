#include <iostream>
using namespace std;

class Complex {
    float real=0.0;
    float imag=0.0;
    static int count;

    public:
    Complex() = default;//cant increment count

    Complex(float r) {
        real = r;
        imag = 0.0;
        count++;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
        count++;
    }

    static void showCounter() {
        cout << "Active Complex objects: " << count << endl;
    }

    void printComplex() {
        if(imag ==0 && real ==0) {
            cout << "0" << endl;
        } 
        else if(imag == 0) {
            cout << real << endl;
        } 
        else if (real == 0) {
            if (imag == 1)
                cout << "i" << endl;
            else if (imag == -1)
                cout << "-i" << endl;
            else
                cout << imag << "i" << endl;
        } 
        else if(imag == 1) {
            cout << real << "+i" << endl;
        } 
        else if(imag == - 1) {
            cout << real << "-i" << endl;
        }
        else if(imag < 0) {
            cout << real << imag << "i" << endl;
        } 
        else {
            cout << real << "+" << imag << "i" << endl;
        }
    }

    ~Complex() {
        count--;
    }
};

int Complex::count = 0;

int main() {
    Complex c1;
    Complex c2(5 , 7);
    Complex c3(-3, -3);
    Complex c4(0, -8);
    Complex c5(0, 8);
    Complex c6(-9, 3);
    Complex c7(8, 1);
    Complex c8(-9, 0);

    c1.printComplex();
    c2.printComplex();
    c3.printComplex();
    c4.printComplex();
    c5.printComplex();
    c6.printComplex();
    c7.printComplex();
    c8.printComplex();

    cout << "\n";

    Complex::showCounter();

    return 0;
}