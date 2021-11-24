#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point() 
    {
        x = 0; y = 0;
    }

    Point(int x, int y) 
    {
        this->x = x;
        this->y = y;
    }

    Point(const Point& pxy) 
    {
        x = pxy.x;
        y = pxy.y;
        cout << "constructor copy 1" << endl;
    }

    Point(const Point& pxy, int i) 
    {
        if (i == 0) 
        {
            x = 60; y = 88; 
        }
        else {
            x = pxy.x;
            y = pxy.y;
        }
        cout << "constructor copy 2" << endl;
    }

    Point(const Point& pxy, int i1, int i2) 
    {
        if (i1 == 0 & i2 == 0) 
        { 
            x = 22; y = 90; 
        }
        else 
        {
            x = pxy.x;
            y = pxy.y;
        }
        cout << "constructor copy 3" << endl;
    }

    void setX(int x) 
    {
        this->x = x;
    }
    void setY(int y) 
    {
        this->x = y;
    }
    void setXY(int, int);
    void print();
    int getX() 
    {
        return x;
    }
    int getY() 
    {
        return y;
    }

    ~Point() {

    };
};

void Point::setXY(int x, int y) 
{
    this->x = x; this->y = y;
}
void Point::print() 
{
    cout << " x=" << this->x << " " << " y=" << this->y << endl;
}

int main() 
{
    Point p1;
    Point p2(3, 4);
    p1.print();
    p2.print();
    p1 = p2;
    p1.print();
    p1.setXY(7, 8);
    p2.setXY(9, 10);
    p1.print();
    p2.print();
    Point p3 = p1;
    p3.print();
    Point p4 = p2;
    p4.print();
    Point p5 = Point(p2, 0);
    p5.print();
    Point p6 = Point(p2, 0, 0);
    p6.print();

    return 0;
}