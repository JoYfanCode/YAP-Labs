#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Node
{
public:
    T Data;
    Node<T>* Left;
    Node<T>* Right;

public:
    Node(T Data)
    {
        this->Data = Data;
        this->Left = NULL;
        this->Right = NULL;
    }
};

template <typename T>
class BinaryTree
{
private:
    Node<T>* Root;
    int Length;

public:
    BinaryTree()
    {
        this->Root = NULL;
        this->Length = 0;
    }
    ~BinaryTree()
    {
        delete_tree(Root);
    }

    void delete_tree(Node<T>* node)
    {
        if (node) {
            delete_tree(node->Left);
            delete_tree(node->Right);
            delete node;
        }
    }

    void append(T Data)
    {
        if (isEmpty()) { // First node
            Root = new Node<T>(Data);
            Length++;
            return;
        }

        Node<T>* node = Root;
        while (node && node->Data != Data) {
            if (node->Data < Data && node->Left == NULL) { // left is free
                node->Left = new Node<T>(Data);
                Length++;
                return;
            }
            if (node->Data > Data && node->Right == NULL) { // right is free
                node->Right = new Node<T>(Data);
                Length++;
                return;
            }

            if (node->Data < Data)
                node = node->Left;
            else
                node = node->Right;
        }
    }

    void erase(T key)
    {
        Node<T>* node = Root;
        Node<T>* parent = NULL;

        while (node && node->Data != key) { // try to find node
            parent = node;
            if (node->Data < key)
                node = node->Left;
            else
                node = node->Right;
        }

        if (!node) return;

        if (node->Left == NULL) { // left node is free
            if (parent && parent->Left == node)
                parent->Left = node->Right;
            else if (parent && parent->Right == node)
                parent->Right = node->Right;

            Length--;
            delete node;
            return;
        }
        else if (node->Right == NULL) { // right node is free
            if (parent && parent->Left == node)
                parent->Left = node->Left;
            else if (parent && parent->Right == node)
                parent->Right = node->Left;

            Length--;
            delete node;
            return;
        }

        Node<T>* replace = node->Right; // left and right nodes arent free
        while (replace->Left)
            replace = replace->Left;
        T replaceValue = replace->Data;
        erase(replaceValue);
        node->Data = replaceValue;
    }

    bool findKey(T key)
    {
        Node<T>* node = Root;

        while (node && node->Data != key) {
            if (node->Data > key)
                node = node->Left;
            else
                node = node->Right;
        }

        return node != NULL;
    }

    bool isEmpty()
    {
        return (Length == 0) ? true : false;
    }

    int getLength()
    {
        return Length;
    }

    void print(ofstream& out) 
    {
        print_tree(out, Root);
    }

    void print_tree(ofstream& out, Node<T>* node)
    {
        if (node) {
            out << node->Data << " ";
            print_tree(out, node->Left);
            print_tree(out, node->Right);
        }
    }
};

int main()
{
    BinaryTree<double> tree;

    ifstream in;
    ofstream out;

    in.open("input.txt");
    if (!in.is_open())
    {
        out << "Error! File cannot be opened" << endl;
        return 0;
    }

    double tmp;
    while (in >> tmp)
        tree.append(tmp); // input data

    out.open("output.txt");
    out.precision(15);

    tree.print(out); // output data

    in.close();
    out.close();

    return 0;
}
