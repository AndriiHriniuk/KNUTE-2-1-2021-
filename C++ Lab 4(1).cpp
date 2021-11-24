#include <iostream> 
using namespace std;

struct Tree
{
    int data;
    Tree* left;
    Tree* right;
    Tree* parentT;
};

void insert(Tree* root, int data)
{
    Tree* ptrT;
    ptrT = root;
    Tree* parent;
    parent = NULL;
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
    newT->parentT = parent;
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

void insertChild(Tree* root, Tree* ptr_st1, int data) {
    if (!ptr_st1) { return; }
    Tree* ptrT = root;
    Tree* parent;
    ptrT = root;
    if (!ptr_st1) {
        return;
    }
    while (ptrT) {
        parent = ptrT;
        if (data < ptrT->data) {
            ptrT = ptrT->left;
        }
        else {
            ptrT = ptrT->right;
        }

        if (ptr_st1->data < parent->data) {
            parent->left = ptr_st1;
            ptr_st1->parentT = parent;
        }
        else {
            parent->right = ptr_st1;
            ptr_st1->parentT = parent;
        }
    }
}

Tree* find(Tree* root, int data)
{
    Tree* ptrT = root;
    while (ptrT)
    {
        if (data == ptrT->data)
        {
            cout << "Find" << endl;
            return ptrT;
        }
        if (data < ptrT->data)
        {
            ptrT = ptrT->left;
        }
        else
        {
            ptrT = ptrT->right;
        }
    }
    cout << "Not find" << endl;
    ptrT = NULL;
    return ptrT;
}

void Delete(Tree* root, int data)
{
    Tree* ptr_st = NULL;
    Tree* pParent = NULL;
    ptr_st = find(root, data);
    if (ptr_st == NULL)
    {
        cout << "eror" << endl; return;
    }
    if (ptr_st == root)
    {
        cout << "eror" << endl; return;
    }
    if ((ptr_st->left == NULL) && (ptr_st->right == NULL))
    {
        Tree* pParent = NULL;
        pParent = ptr_st->parentT;
        if (ptr_st->data < pParent->data)
            pParent->left = NULL;
        else pParent->right = NULL;
        return;
    }

    Tree* ptr_left = NULL;
    Tree* ptr_right = NULL;
    ptr_left = ptr_st->left;
    ptr_right = ptr_st->right;
    pParent = ptr_st->parentT;
    if (ptr_st->data < pParent->data)
    {
        pParent->left = NULL;
    }
    else
    {
        pParent->right = NULL;
    }
    insertChild(root, ptr_left, ptr_left->data);
    insertChild(root, ptr_right, ptr_right->data);
}

int main(int argc, char** argv)
{
    int mas[] = { 20, 2, 3, 14, 15, 18, 7, 9, 1, 5 };
    Tree* ptr_st = NULL;
    Tree* ptr_left = NULL;
    Tree* ptr_right = NULL;
    Tree* root = new Tree;
    root->data = mas[0];
    root->left = NULL;
    root->right = NULL;
    for (int i = 1; i < 10; i++)
    {
        insert(root, mas[i]);
    }

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
            cout << " Kakoy elem udalit?" << endl;
            cin >> elem;
            Delete(root, elem);
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

    delete (root);
    return 0;
}