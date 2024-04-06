#include <iostream>
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

    void print()
    {
        cout << endl;
        print_tree(Root);
        cout << endl;
    }

    void print_tree(Node<T>* node)
    {
        if (node) {
            print_tree(node->Left);
            cout << node->Data << " ";
            print_tree(node->Right);
        }
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

    void append(T Data)
    {
        if (isEmpty()) {
            Root = new Node<T>(Data);
            Length++;
            return;
        }

        Node<T>* node = Root;
        while (node && node->Data != Data) {
            if (node->Data > Data && node->Left == NULL) {
                node->Left = new Node<T>(Data);
                Length++;
                return;
            }
            if (node->Data < Data && node->Right == NULL) {
                node->Right = new Node<T>(Data);
                Length++;
                return;
            }

            if (node->Data > Data)
                node = node->Left;
            else
                node = node->Right;
        }
    }

    void erase(T key)
    {
        Node<T>* node = Root;
        Node<T>* parent = NULL;

        while (node && node->Data != key) {
            parent = node;
            if (node->Data > key)
                node = node->Left;
            else
                node = node->Right;
        }
        if (!node) return;

        if (node->Left == NULL) {
            if (parent && parent->Left == node)
                parent->Left = node->Right;
            else if (parent && parent->Right == node)
                parent->Right = node->Right;

            Length--;
            delete node;
            return;
        }
        else if (node->Right == NULL) {
            if (parent && parent->Left == node)
                parent->Left = node->Left;
            else if (parent && parent->Right == node)
                parent->Right = node->Left;

            Length--;
            delete node;
            return;
        }

        Node<T>* replace = node->Right;
        while (replace->Left)
            replace = replace->Left;
        T replace_value = replace->Data;
        erase(replace_value);
        node->Data = replace_value;
    }

    bool isEmpty()
    {
        return (Length == 0) ? true : false;
    }

    int getLength()
    {
        return Length;
    }
};

int main()
{
    BinaryTree<int> tree;

    tree.append(10);
    tree.append(6);
    tree.append(3);
    tree.append(8);
    tree.append(13);

    tree.print();

    tree.erase(8);

    tree.print();

    return 0;
}
