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
    cout << "coord0 x1=" << coord0.getX() << endl; // стороны до суммирования, а1
    cout << "coord0 y1=" << coord0.getY() << endl; // б1
    cout << "coord1 x2=" << coord1.getX() << endl; // а2
    cout << "coord1 y2=" << coord1.getY() << endl; // б2
    Point coord2 = simY(coord0, coord1); // суммирование определенны сторон
    cout << "friend simY  " << endl;
    cout << "coord2 x1 + x2 =" << coord2.getX() << endl; // а1 + б1
    cout << "coord2 y1 + y2 =" << coord2.getY() << endl;// а2 + б2
    int S = coord2.getX() * coord2.getY();
    cout << "S = " << S << endl;
    cin.get();
    return 0;
}
int addCoord(Point& p)
{
    return  (p.x + p.y);
}
Point simY(Point p, Point p1) // Дружественная функция
{
    Point pcoord(0, 0);
    pcoord.x = p.x + p1.x; // а1 + б1
    pcoord.y = p.y + p1.y;// а2 + б2
    return pcoord;
}