#include <iostream>
using namespace std;
template<typename T>


class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data)[
        this->data = data;
        this->next = NULL;
};

int main(){

    Node<string> *n1 = new Node<string>("Hello");

    return 0;
}