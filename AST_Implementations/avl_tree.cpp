#include <iostream>
#include <max>
using namespace std;

template <class T>
struct Node{
    Node<T>* Left;
    Node<T>* Right;
    Node<T>* Parent;
    T Value;
    int Height;
    Node(T init){Value=init;};
};


template <class T>
class AVL_Tree
{
    Node<T> Root*;

    AVL_Tree(){Root = NULL;};
    AVL_Tree(T init){Root = new Node<T>(init);};

    void insert(T value){
        Node<T>* index = Root;
        Node<T>* index = Parent;

        while (index != NULL){
            if (value < index->Value)
                index = index->Left;
            else{
                index = index->Right;
            }
        }
    }

    int updateHeight(Node<T>* Node)
    {
        if (Node->Left!=NULL && Node->Right!=NULL) {
            return (max(Node->Left.Height,Node->Right.Height));
        } else {
        }
    }

    /**The Node's right child becomes the root, with its left pointer pointing to the passed node
     */
    int rotateLeft(Node<T>* Node)
    {
    }

    int rotateRight(Node<T>* Node)
    {
    }
}

int main()
{
}
