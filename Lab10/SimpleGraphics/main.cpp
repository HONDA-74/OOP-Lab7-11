#include "SimpleGraphics.h"
#include "simpleGraphics.cpp"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Point {
    int x, y;
public:
    Point(int a=0, int b=0): x(a), y(b) {}
    int getX() const { return x; }
    int getY() const { return y; }
};

class Rect {
    Point ul, lr;
public:
    Rect(int x1,int y1,int x2,int y2): ul(x1,y1), lr(x2,y2) {}
    void draw() { drawRect(ul.getX(), ul.getY(), lr.getX(), lr.getY()); }
};

class Circle {
    Point center;
    int radius;
public:
    Circle(int x,int y,int r): center(x,y), radius(r) {}
    void draw() { drawCircle(center.getX(), center.getY(), radius); }
};

class Triangle {
    Point p1, p2, p3;
public:
    Triangle(Point a, Point b, Point c): p1(a), p2(b), p3(c) {}
    void draw() { drawTriangle(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY()); }
};

class Ellipse {
    Point center;
    int rx, ry;
public:
    Ellipse(int x,int y,int a,int b): center(x,y), rx(a), ry(b) {}
    void draw() {
        for(int y=center.getY()-ry; y<=center.getY()+ry; y++)
            for(int x=center.getX()-rx; x<=center.getX()+rx; x++)
                if(
                    pow(x-center.getX(),2)/double(rx*rx)
                    +pow(y-center.getY(),2)/double(ry*ry)<=1.0
                ) // y^2/a^2 + x^2/b^2 <= 1 // check if point is in ellipse
                    putPixel(x,y);
    }
};

class Line { 
    Point p1, p2; 
public: 
    Line(int x1, int y1, int x2, int y2): p1(x1,y1), p2(x2,y2) {} 
    void draw() { drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY()); } 
};

class Picture {
    Circle** circles; int cNum{};// pointer of pointers
    Rect** rects; int rNum{};
    Triangle** tris; int tNum{};
    Ellipse** ellipses; int eNum{};
    Line** lines; int lNum{};

public:
    Picture(): circles(nullptr), rects(nullptr), tris(nullptr), ellipses(nullptr) , lines(nullptr), cNum(0), rNum(0), tNum(0), eNum(0) {}
    ~Picture() {
        for(int i=0;i<cNum;i++) delete circles[i];
        for(int i=0;i<rNum;i++) delete rects[i];
        for(int i=0;i<tNum;i++) delete tris[i];
        for(int i=0;i<eNum;i++) delete ellipses[i];
        for (int i=0;i<lNum;i++) delete lines[i];
        delete[] circles; delete[] rects; delete[] tris; delete[] ellipses; delete[] lines;
    }

    void setCircles(int n, Circle** arr) { cNum=n; circles=arr; }
    void setRects(int n, Rect** arr) { rNum=n; rects=arr; }
    void setTris(int n, Triangle** arr) { tNum=n; tris=arr; }
    void setEllipses(int n, Ellipse** arr) { eNum=n; ellipses=arr; }
    void setLines(int n, Line** arr) { lNum=n; lines=arr; }

    void paint() {
        for(int i=0;i<cNum;i++) circles[i]->draw();
        for(int i=0;i<rNum;i++) rects[i]->draw();
        for(int i=0;i<tNum;i++) tris[i]->draw();
        for(int i=0;i<eNum;i++) ellipses[i]->draw();
        for (int i=0;i<lNum;i++) lines[i]->draw();
    }
};

class PictureStatic {
    Rect rect;
    Circle circle;
    Triangle tri;
    Ellipse ellipse;
    Line line;
public:
    PictureStatic(Rect r, Circle c, Triangle t, Ellipse e , Line l): rect(r), circle(c), tri(t), ellipse(e) , line(l) {}
    void paint() {
        rect.draw();
        circle.draw();
        tri.draw();
        ellipse.draw();
        line.draw();
    }
};


int main() {
    initScreen();
    Picture pic;

    int rw,rh, cr, ellRx, ellRy , trx1 , try1 , trx2 , try2 , trx3 , try3 , lx1 , ly1 , lx2 , ly2;

    cout << "Enter rectangle width and height: ";
    cin >> rw >> rh;
    cout << "Enter circle radius: ";
    cin >> cr;
    cout << "Enter ellipse rx ry: ";
    cin >> ellRx >> ellRy;
    cout << "Enter triangle first point: ";
    cin >> trx1 >> try1;
    cout << "Enter triangle second point: ";
    cin >> trx2 >> try2;
    cout << "Enter triangle third point: ";
    cin >> trx3 >> try3;
    cout << "Enter line Start point: ";
    cin >> lx1 >> ly1;
    cout << "Enter line End point: ";
    cin >> lx2 >> ly2;

    // --- Dynamic allocation ---
    Rect** rects = new Rect*[1];
    rects[0] = new Rect(10,5,10+rw,5+rh);

    Circle** circles = new Circle*[1];
    circles[0] = new Circle(60,10,cr);

    Ellipse** ellipses = new Ellipse*[1];
    ellipses[0] = new Ellipse(80,15,ellRx,ellRy);

    Triangle** tris = new Triangle*[1];
    tris[0] = new Triangle(Point(trx1,try1),Point(trx2,try2),Point(trx3,try3));

    Line** lines = new Line*[1];
    lines[0] = new Line(lx1,ly1,lx2,ly2);

    pic.setRects(1,rects);
    pic.setCircles(1,circles);
    pic.setEllipses(1,ellipses);
    pic.setTris(1,tris);
    pic.setLines(1,lines);

    pic.paint();
    renderScreen();

    // --- Static allocation ---
    Rect r(10,5,10+rw,5+rh);
    Circle c(60,10,cr);
    Ellipse e(80,15,ellRx,ellRy);
    Triangle t(Point(trx1,try1),Point(trx2,try2),Point(trx3,try3));
    Line l(lx1,ly1,lx2,ly2);

    PictureStatic pic1(r,c,t,e ,l);
    pic1.paint();
    renderScreen();

    return 0;
}
