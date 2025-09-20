#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* deleteEverySecond(Node* head) {
    if (head == nullptr) 
        return head;

    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;

    while (curr != nullptr) {
        count++;
        if (count % 2 == 0) {
            if (prev != nullptr) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    head = deleteEverySecond(head);
    
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
    
    return 0;
}