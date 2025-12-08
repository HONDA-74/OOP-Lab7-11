#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Geoshape
{
protected:
    float dim1=0;
    float dim2=0;
public:
    Geoshape() = default;
    Geoshape(float d) { dim1 = dim2 = d ; }
    Geoshape(float d1, float d2) { dim1 = d1; dim2 = d2; }

    //virtual float area() { return 0; }
    virtual float area() = 0; // pure virtual
    // virtual float preimeter() { return 0; }
    virtual float preimeter() = 0; 
    // virtual void printShape() { cout << "Area: " << area() << endl << "Perimeter: " << preimeter() << endl; }
    virtual void printShape() = 0;

    Geoshape& operator=(const Geoshape& other) {
        if (this != &other) {
            dim1 = other.dim1;
            dim2 = other.dim2;
        }
        return *this;
    }

private:
    float getDim1() { return dim1; }  
    float getDim2() { return dim2; }
    void setDim1(float dim1) { this->dim1 = dim1; }
    void setDim2(float dim2) { this->dim2 = dim2; }
};

class Rectangle : public Geoshape
{
public:
    Rectangle() : Geoshape() {};
    Rectangle(float l, float w) : Geoshape(l, w) {}
    float area() { return dim1 * dim2; }
    float preimeter() { return 2 * (dim1 + dim2); }
    float getLength() { return dim1; }
    float getWidth() { return dim2; }
    void setLength(float length) { dim1 = length; }
    void setWidth(float width) { dim2 = width; }
    void printShape() { cout << "Area: " << area() << endl << "Perimeter: " << preimeter() << endl; }
};
//protected
class Square : public Rectangle
{
public:
    Square() : Rectangle() {};
    Square(float s) : Rectangle(s, s) {}
    // float area() { return dim1 * dim2; }
    // float preimeter() { return 4 * dim1; }
    float getSide() { return dim1; }
    void setSide(float side) { dim1 = dim2 = side; }
};

class Circle : public Geoshape
{
public:
    Circle() : Geoshape() {};
    Circle(float r) : Geoshape(r) {}
    float area() { return 3.14 * dim1 * dim1; }
    float preimeter() { return 2 * 3.14 * dim1; }
    float getRadius() { return dim1; }
    void setRadius(float radius) { dim1 = dim2 = radius; }
    void printShape() { cout << "Area: " << area() << endl << "Perimeter: " << preimeter() << endl; }
};

// class Tringle : public Geoshape
// {
// public:
//     Tringle() : Geoshape() {};
//     Tringle(float b, float h) : Geoshape(b, h) {}
//     float area() { return 0.5 * dim1 * dim2; }
//     float preimeter() { return dim1 + dim2 + sqrt(dim1 * dim1 + dim2 * dim2); } // only for right tringle
//     float getBase() { return dim1; }
//     float getHeight() { return dim2; }
//     void setBase(float base) { dim1 = base; }
//     void setHeight(float height) { dim2 = height; }
// };

class Triangle : public Geoshape
{
private:
    float s=0;
protected:
    float dim3 = 0;
public:
    Triangle() : Geoshape() {};
    Triangle(float d1, float d2 , float d3) : Geoshape(d1, d2) {dim3 = d3;}
    float preimeter() { return dim1 + dim2 + dim3; }
    float area() 
    {
        s = (dim1 + dim2 + dim3) / 2;
        return sqrt(s * (s - dim1) * (s - dim2) * (s - dim3));
    }
    float getSide1() { return dim1; }
    float getSide2() { return dim2; }
    float getSide3() { return dim3; }
    void setSide1(float side1) { dim1 = side1; }
    void setSide2(float side2) { dim2 = side2; }
    void setSide3(float side3) { dim3 = side3; }
    void printShape() { cout << "Area: " << area() << endl << "Perimeter: " << preimeter() << endl; }

    Triangle& operator=(const Triangle& other) {
        if (this != &other) {
            Geoshape::operator=(other); // copy dim1 + dim2
            dim3 = other.dim3; // copy dim3
        }
        return *this;
    }
};
//protected
class Cube : public Square
{
public:
    Cube() : Square() {};
    Cube(float s) : Square(s) {}
    float area() { return 6 * dim1 * dim1; }
    float preimeter() { return 12 * dim1; }
    float volume() { return dim1 * dim1 * dim1; }
    // float getSide() { return dim1; }
    // void setSide(float side) { dim1 = dim2 = side; }
    void printShape() { cout << "Area: " << area() << endl << "Perimeter: " << preimeter() << endl << "Volume: " << volume() << endl; }
};

class Rhombus : public Geoshape
{
private:
    float side = 0;
public:
    Rhombus() : Geoshape() {};
    Rhombus(float d1, float d2) : Geoshape(d1, d2) {}
    float area() { return 0.5 * dim1 * dim2; }
    float preimeter() 
    {   
        side = sqrt( pow(dim1/2, 2) + pow(dim2/2, 2) );
        return 4 * side;
    }
    float getDiagonal1() { return dim1; }
    float getDiagonal2() { return dim2; }
    void setDiagonal1(float d1) { dim1 = d1; }
    void setDiagonal2(float d2) { dim2 = d2; }
    void printShape() { cout << "Area: " << area() << endl << "Perimeter: " << preimeter() << endl; }
};

bool compareArea( Geoshape *a, Geoshape *b) {
    return a->area() > b->area();
}

void sortArea(vector<Geoshape*>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareArea(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}



int main() {
    Geoshape *p ;

    Rectangle r1(3, 4);
    cout << r1.area() << endl;
    Circle c1(3);
    cout << c1.area() << endl;
    Triangle t1(3, 4, 5);
    cout << t1.area() << endl;
    Cube c2(3);
    cout << c2.area() << endl;
    Rhombus r2(3, 4);
    cout << r2.area() << endl;

    Square s1(5);
    Square s2(10);
    Square s3(3);

    cout << "==========================================="<< endl;

    cout << compareArea( &s1 , &c1 ) << endl;

    cout << "==========================================="<< endl;

    vector<Geoshape*> shapes = {&s1, &s2, &s3 , &r1, &c1, &t1, &c2, &r2};

    
    sortArea(shapes);
    for (Geoshape* s : shapes) {
        cout << s->area() << endl;
    }

    cout << "==========================================="<< endl;
    for (int i = shapes.size() - 1; i >= 0; i--) {
        cout << shapes[i]->area() << endl;
    }

    cout << "==========================================="<< endl;
    Square* sq1 = new Square(5);
    Square* sq2 = new Square(10);
    sq1=sq2;

    sq1->printShape();
    return 0;
};
