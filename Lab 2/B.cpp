#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(string x) {
        data = x;
        next = prev = nullptr;
    }
};

struct dll {
private:
    Node* head;
    Node* tail;
    int len;

public:
    dll() {
        head = tail = nullptr;
        len = 0;
    }

    void insert(string value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        len++;
    }

    void cyclic_left(int k) {
        if (len == 0 || k % len == 0) return;

        k = k % len;  
        Node* newTail = head;
        for (int i = 0; i < k - 1; i++) {
            newTail = newTail->next;
        }

        Node* newHead = newTail->next;

        newHead->prev = nullptr;
        tail->next = head;
        head->prev = tail;
        newTail->next = nullptr;
        tail = newTail;
        head = newHead;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    dll poem;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        poem.insert(word);
    }

    poem.cyclic_left(k);
    poem.print();

    return 0;
}