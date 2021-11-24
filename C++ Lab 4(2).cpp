#include <iostream>
using namespace std;

class Square      // privat ptotected pyblic
{
private:
    int a;
public:
    Square()
    {
        cout << "construct" << endl;
        a = 0;
    }
    Square(int a1);
    void setSquare(int a1)
    {
        a = a1;
    }
    int getSquare();
    int permSquare() // поиск пиримера
    {
        return a * 4;
    }

    int ssSquare() //поиск площади
    {
        return a * a;
    }

    ~Square()
    {
        cout << "destruction" << endl;
    }
};
Square::Square(int a1)
{
    a = a1;
    cout << "construct" << endl;
}

int Square::getSquare()
{
    return a;
}

int main()
{
    Square sq1;
    Square sq2(7);
    cout << "a1 = " << sq1.getSquare() << endl;
    cout << "a2 = " << sq2.getSquare() << endl;
    sq1.setSquare(5);

    cout << "a1 = " << sq1.getSquare() << endl;
    cout << "a2 = " << sq2.getSquare() << endl;
    cout << "p1 = " << sq1.permSquare() << endl;
    cout << "p2 = " << sq2.permSquare() << endl;

    cout << "S1 = " << sq1.ssSquare() << endl;
    cout << "S2 = " << sq2.ssSquare() << endl;
}