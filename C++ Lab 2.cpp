#include <iostream>
using namespace std;

struct Tree
{
    int data;
    Tree* left;
    Tree* right;
};

void print(Tree*, int);
void insert(Tree* root, int data);
Tree* find(Tree*, int);

int main(int argc, char** argv)
{
    int mas[] = { 21,5,6,10,50,30,35,9,1,2 };
    Tree* root = new Tree;
    root->data = mas[0];
    root->right = NULL;
    root->left = NULL;
    for (int i = 0; i < 10; i++)
    {
        insert(root, mas[i]);
    }
    Tree* ptrT;
    int pr = 1;
    int x;
    while (pr)
    {
        cout << "----------------------------" << endl;
        cout << " 1. Vvesty elementu" << endl;
        cout << "----------------------------" << endl;
        cout << " 2. Vyvesty spisok" << endl;
        cout << "----------------------------" << endl;
        cout << " 3. Nayti element" << endl;
        cout << "----------------------------" << endl;
        cout << " 4. Delete" << endl;
        cout << "----------------------------" << endl;
        cout << " 5. Exit" << endl;
        cout << "----------------------------" << endl;
        cout << " Vvedite kod operatsii " << endl;
        cin >> x;
        int elem;
        if (x == 1)
        {
            cout << "Vvedite elem " << endl;
            cin >> elem;
            insert(root, elem);
        }
        else if (x == 2)
        {
            print(root, 0);
        }
        else if (x == 3)
        {
            cout << " Kakoy elem nayti?" << endl;
            cin >> elem;
            find(root, elem);
        }
        else if (x == 4)
        {
            cout << " Funk v razrabotke" << endl;
        }
        else if (x == 5)
        {
            break;
        }
        else
        {
            cout << " Vveden ne verniy kod" << endl;
        }
    }
    //print(root, 0);
    //find(root, 50);
    delete(root);
    return 0;
}

void insert(Tree* root, int data) {
    Tree* ptrT;
    ptrT = root;
    Tree* parent;
    while (ptrT)
    {
        parent = ptrT;
        if (data < ptrT->data)
        {
            ptrT = ptrT->left;
        }
        else
        {
            ptrT = ptrT->right;
        }
    }
    Tree* newT = new Tree;
    newT->data = data;
    newT->left = 0;
    newT->right = 0;
    if (data < parent->data)
    {
        parent->left = newT;
    }
    else
    {
        parent->right = newT;
    }
}

void print(Tree* ptrT, int h)
{
    if (ptrT)
    {
        print(ptrT->left, h + 1);
        for (int i = 0; i < h; i++)
        {
            cout << " ";
        }
        cout << ptrT->data << endl;
        print(ptrT->right, h + 1);
    }
}

Tree* find(Tree* root, int data)
{
    Tree* ptrT;
    ptrT = root;
    Tree* parent;
    int pr = 0;
    while (ptrT) {
        parent = ptrT;
        if (data == ptrT->data)
        {
            cout << "Find" << endl;
            return ptrT;
        }
        else
        {
            ptrT = ptrT->right;
        }
    }
    ptrT = NULL;
    cout << "Not Find" << endl;
    return ptrT;
}