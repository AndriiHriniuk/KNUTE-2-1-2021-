#include <iostream>
#include <string>
using namespace std;

struct Stack
{
    int id;
    string Name;
    int rate;
};

int i = 20;
Stack mas[20];
int tail = 0;

void print(Stack mas[])
{
    for (int j = 0; j < tail; j++) 
    {

        cout << mas[j].id << "." << " Name=" << mas[j].Name;
        cout << " rate=" << mas[j].rate << endl;
    }
}

void push(int id, const string Name, int rate, int i)
{
    mas[i].id = id;
    mas[i].Name = Name;
    mas[i].rate = rate;
    tail++;
}

int main()
{
    push(1, "Harry Potter", 70, 5);
    push(2, "50 Days Before My Suicide", 95, 0);
    push(3, "The Subtle Art Of Not Giving A F*ck", 80, 4);
    push(4, "Every Thing Is F*cked", 75, 6);
    push(5, "The Wolf Of The Wall Street", 83, 2);
    push(6, "Master And Margarita", 63, 3);
    push(8, "Beaty And The Beast", 40, 1);

    print(mas);
    return 0;
}