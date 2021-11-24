#include <iostream>
#include <string>
using namespace std;

struct   Book  //  Student – це є новий ТИП даних, метадані.
{
    string  Title;
    int Price; // певна інформативна частина
    Book* next;// вказівникна наступну структуру-вузол у списку
    Book* prev;
};

int i = 1;//!!!- об'явлена глобально!- буде одне й теж у всіх функціях

Book* head = NULL; // вказівник на голову списку, спочатку 
Book* tail = NULL;// указатель на конец списка, хвост

/*void print(Student* head)
{
    Student* print_st = head;
    while (print_st != NULL)
    {
        cout << i << ". Name=" << print_st->Name;
        cout << "   mark=" << print_st->mark << endl;
        print_st = print_st->next;
        i++;
    }
}*/

void printInvers(Book* tail)
{
    Book* invPrint = tail;
    while (invPrint != NULL)
    {
        cout << i << ". Title=" << invPrint->Title;
        cout << "   mark=" << invPrint->Price << endl;
        invPrint = invPrint->prev;
        i++;
    }
}

void insertToEnd(const string Title, int mark, Book*& ptr_st)
{
    Book* newBook = new Book;
    newBook->Title = Title;
    newBook->Price = mark;
    ptr_st->next = newBook;
    newBook->prev = ptr_st;
    newBook->next = NULL;
    tail = newBook;
    ptr_st = newBook;
}

int main()
{
    Book* book;
    // СТВОРИМО ПЕРШИЙ ЕЛЕМЕНТ – запросимо память під  структуру типу  Student
    book = new Book; // Запросили пам’ять під ТИП Book під новий 
    book->Title = "Harry Potter";
    book->Price = 70;
    book->next = NULL;
    book->prev = NULL;
    head = tail;
    i = 1;

    insertToEnd("50 Days Before My Suicide", 95, book);
    insertToEnd("The Subtle Art Of Not Giving A F*ck", 80, book);
    insertToEnd("Every Thing Is F*cked", 75, book);
    insertToEnd("The Wolf Of The Wall Street", 83, book);
    insertToEnd("Moby Dick", 42, book);
    insertToEnd("Beaty And The Beast", 40, book);
    insertToEnd("Master And Margarita", 63, book);
    //print(head);
    printInvers(tail);
    delete book;
    return 0;
}