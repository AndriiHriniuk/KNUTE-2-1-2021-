#include <iostream>
#include <math.h>
using namespace std;


class Square      // privat ptotected pyblic
{
private:
    int r;
    int R;
public:
    Square()
    {
        cout << "construct" << endl;
        r = 0;
        R = 0;
    }
    Square(int r1, int R1);
    void setSquare(int r1, int R1)
    {
        r = r1;
        R = R1;
    }
    int getSquare();
    float permSquare() // поиск пиримера
    {
        float p = 3.14159;
        return  2 * p * r + 2 * p * R;
    }

    float ssSquare() //поиск площади
    {
        float p = 3.14159;
        return p * pow(R, 2) - p * pow(r, 2);
    }

    ~Square()
    {
        cout << "destruction" << endl;
    }
};
Square::Square(int r1, int R1)
{
    r = r1;
    R = R1;
    cout << "construct" << endl;
}

int Square::getSquare()
{
    cout << " r = " << r << endl;
    return R;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "              ------------" << endl;
    cout << "               11 Вариант" << endl;
    cout << "              ------------" << endl;
    Square sq1;
    sq1.setSquare(2, 8);

    cout << " R = " << sq1.getSquare() << endl;
    cout << "\n P = п * R * 2 + п * r * 2" << "         S = п * R ^ 2 - п * r ^ 2" << endl;
    cout << " P = " << sq1.permSquare();
    cout << "                       S = " << sq1.ssSquare() << endl;
}