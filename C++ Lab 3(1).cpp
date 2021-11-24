#include <iostream>
#include <string>
using namespace std;

struct Stack 
{
    int id;
    string Name;
    int rate;
    Stack* next;
    Stack* prev;
};
Stack* head = NULL;
Stack* tail = NULL;
 
void print(Stack* temp) 
{
    Stack* new_value;
    new_value = temp;
    while (new_value != NULL) 
    {
        cout << new_value->id << "." << " Name=" << new_value->Name;
        cout << "  rate=" << new_value->rate << endl;
        new_value = new_value->next;
    }
}

void print1(Stack* ptr_st)
{
    Stack* newstack1;
    newstack1 = ptr_st;
    while (newstack1 != NULL) 
    {
        cout << newstack1->id << "." << " Name=" << newstack1->Name;
        cout << "  rate=" << newstack1->rate << endl;
        newstack1 = newstack1->prev;
    }
}

void push(int id, const string Name, int rate, Stack*& ptr_st)
{
    Stack* newstack1 = new Stack; //add new node
    newstack1->id = id;
    newstack1->Name = Name;
    newstack1->rate = rate;
    if (head != NULL)
    {
        newstack1->next = ptr_st->next;
        newstack1->prev = ptr_st;
        ptr_st->next = newstack1;
        ptr_st = newstack1;
        tail = newstack1;
    }
    else 
    {
        newstack1->next = NULL;   //head = null - first node
        newstack1->prev = NULL;
        ptr_st = newstack1;
        head = newstack1;
        tail = newstack1;
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    Stack* stack1 = new Stack;
    push(1, "Harry Potter", 70, stack1);
    push(2, "50 Days Before My Suicide", 95, stack1);
    push(3, "The Subtle Art Of Not Giving A F*ck", 80, stack1);
    push(4, "Every Thing Is F*cked", 75, stack1);
    push(5, "The Wolf Of The Wall Street", 83, stack1);
    push(6, "Master And Margarita", 63, stack1);
    cout << "Полный список" << endl;
    print(head);
    push(7, "Moby Dick", 42, stack1);
    push(8, "Beaty And The Beast", 40, stack1);
    cout << "Список с начала" << endl;
    print(head);
    cout << "Списк с конца" << endl;
    print1(tail);
    delete stack1;
    return 0;
}