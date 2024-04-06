#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class Node
{
public:
    T Data;
    Node<T>* Next;

public:
    Node(T Data)
    {
        this->Data = Data;
        this->Next = NULL;
    }
};

template <typename T>
class СyclicalOneLinkedList
{
private:
    Node<T>* Head;
    Node<T>* Tail;
    int Length;

public:
    СyclicalOneLinkedList()
    {
        this->Head = NULL;
        this->Tail = NULL;
        this->Length = 0;
    }

    ~СyclicalOneLinkedList()
    {
        while (!isEmpty()) pop_front();
    }

    void push_front(T data)
    {
        Node<T>* node = new Node<T>(data);
        node->Next = Head;
        Head = node;

        if (Tail == NULL)
            Tail = node;

        Tail->Next = Head;
        Length++;
    }

    void push_back(T Data)
    {
        Node<T>* node = new Node<T>(Data);

        if (Head == NULL) 
            Head = node;
        else
            Tail->Next = node;

        Tail = node;

        Tail->Next = Head;
        Length++;
    }

    T pop_front()
    {
        if (isEmpty()) 
            return 0;

        if (Length == 1) 
        {
            T Data = Head->Data;
            delete Head;
            Length--;
            return Data;
        }
        else 
        {
            T Data = Head->Data;
            Node<T>* node = Head;
            Head = Head->Next;
            Tail->Next = Head;
            delete node;
            Length--;
            return Data;
        }
    }

    T pop_back()
    {
        if (isEmpty()) 
            return 0;

        if (Length == 1) 
        {
            T Data = Tail->Data;
            delete Tail;
            Length--;
            return Data;
        }
        else 
        {
            T Data = Tail->Data;
            Node<T>* node = Head;
            for (; node->Next != Tail; node = node->Next);
            node->Next = NULL;
            delete Tail;
            Tail = node;
            Tail->Next = Head;
            Length--;
            return Data;
        }
    }

    Node<T>* getAt(int k)
    {
        if (k < 0) return NULL;

        Node<T>* node = Head;
        int n = 0;
        while (node && n != k && node->Next) {
            node = node->Next;
            n++;
        }

        return (n == k) ? node : NULL;
    }

    void insert(int k, T Data)
    {
        Node<T>* left = getAt(k);
        if (left == NULL) return;

        Node<T>* right = left->Next;

        Node<T>* node = new Node<T>(Data);

        left->Next = node;
        node->Next = right;

        if (right == NULL) Tail = node;

        Tail->Next = Head;
        Length++;
    }

    T earse(int k)
    {
        if (k < 0) return 0;
        if (k == 0) return pop_front();

        Node<T>* left = getAt(k - 1);
        Node<T>* node = left->Next;
        T Data = node->Data;
        if (node == NULL) return 0;
        Node<T>* right = node->Next;

        left->Next = right;
        if (node == Tail) Tail = left;
        delete node;

        Tail->Next = Head;
        Length--;
        return Data;
    }

    void Swap(Node<T>* node1, Node<T>* node2)
    {
        Node<T>* temp1 = node1;
        Node<T>* temp2 = node2;

        T tempData = temp1->Data;
        temp1->Data = temp2->Data;
        temp2->Data = tempData;
    }

    void bubbleSort()
    {
        for (int i = 0; i < Length; i++) {
            Node<T>* node = Head;
            for (int j = 0; j < Length - 1; j++) {
                if (node->Data > node->Next->Data) {
                    Swap(node, node->Next);
                }
                node = node->Next;
            }
        }
    }

    void quickSort()
    {
        quickSortRecursive(0, Length - 1);
    }

    void quickSortRecursive(int l, int r)
    {
        if (l < r) {
            T x = getAt((l + r) / 2)->Data;
            int i = l;
            int j = r;

            while (i <= j) {
                while (getAt(i)->Data < x) i++;
                while (getAt(j)->Data > x) j--;
                if (i <= j) Swap(getAt(i++), getAt(j--));
            }

            quickSortRecursive(l, j);
            quickSortRecursive(i, r);
        }
    }

    void print()
    {
        ofstream out;
        out.open("output.txt");

        Node<T>* node = Head;
        for (int i = 0; i < Length; i++) {
            out << node->Data << " ";
            node = node->Next;
        }

        out.close();
    }

    void doublePrint()
    {
        ofstream out;
        out.open("output.txt");

        Node<T>* node = Head;
        for (int i = 0; i < 2*Length; i++) {
            out << node->Data << " ";
            node = node->Next;
        }

        out.close();
    }

    bool isEmpty()
    {
        return (Length == 0) ? true : false;
    }

    int getLength()
    {
        return Length;
    }

    T& operator[] (int i)
    {
        if (i < 0 || i >= Length) 
            exit(1);

        return getAt(i);
    }
};

int main()
{
    СyclicalOneLinkedList<double> list;

    ifstream in;
    
    in.open("input.txt");

    bool flagSort;;
    in >> flagSort;

    int element;
    while (in >> element)
        list.push_back(element); // Add elements
    in.close();

    if (list.getLength() == 0)
        return 0;

    if (flagSort == 0) // Sort
    {
        list.bubbleSort();
        list.print();
    }
    else
    {
        list.quickSort();
        list.print();
    }

    return 0;
}