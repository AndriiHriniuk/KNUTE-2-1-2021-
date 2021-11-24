#include <iostream>
using namespace std;
class Point 
{
private:
    int x, y;
public:
    Point(int x, int y) 
    { 
        this->x = x; this->y = y; 
    }
    int getX() 
    {
        return x; 
    }
    int getY() 
    { 
        return y; 
    }
    friend Point simY(Point, Point);
    friend int addCoord(Point&);
};
int main(int argc, char* argv[])
{
    Point coord0(5, 9);
    Point coord1(2, 1);
    cout << "coord0 x=" << coord0.getX() << endl;
    cout << "coord0 y=" << coord0.getY() << endl;
    cout << "friend addCoord coord0.x+ coord0.y= " << addCoord(coord0) << endl;
    cout << "coord0 x=" << coord0.getX() << endl;
    cout << "coord0 y=" << coord0.getY() << endl;
    cout << "coord1 x=" << coord1.getX() << endl;
    cout << "coord1 y=" << coord1.getY() << endl;
    Point coord2 = simY(coord0, coord1);
    cout << "friend simY  " << endl;
    cout << "coord2 x=" << coord2.getX() << endl;
    cout << "coord2 y=" << coord2.getY() << endl;
    cin.get();
    return 0;
}
int addCoord(Point& p)
{
    return  (p.x + p.y);
}
Point simY(Point p, Point p1)
{
    Point pcoord(0, 0);
    pcoord.x = p.x + p1.x;
    pcoord.y = -(p.y + p1.y);
    return       pcoord;
}