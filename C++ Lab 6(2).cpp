#include <iostream>
#include <string>
using namespace std;
class Arr 
{
private:
    int n;
    int* mas;
public:
    
    Arr() 
    {

    };
    Arr(int n1) 
    {
        n = n1; mas = new int[n];
        for (int i = 0; i < n1; i++) { mas[i] = i + 2 * i; }
    }
    // Arr(const Arr &arr){ 
 // konstr copy
    //                      }  
    void showArr(int);
    void elemArr(int i, int ielem) 
    { 
        mas[i] = ielem; 
    }
    Arr(const Arr& arr)
    {
        n = arr.n;
        mas = new int[n];
        for (int i = 0; i < n; i++)
        {
            mas[i] = arr.mas[i];
        }
    }
    ~Arr() 
    { 
        delete[] mas; 
    }
};

void Arr::showArr(int k) 
{
    cout << "mass" << k << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << this->mas[i] << " "; cout << endl;
    }
}


int main() 
{
    Arr ar1(4);
    ar1.showArr(1);
    Arr ar2 = ar1;
    ar2.showArr(2);
    ar2.elemArr(1, 1);
    ar2.elemArr(2, 1);
    ar1.showArr(1);

    return 0;
}