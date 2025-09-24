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

Node* deleteK(Node* head, int k) {
    if (head == nullptr || k <= 0) 
        return head;

    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;

    while (curr != nullptr) {
        count++;

        if (count % k == 0) {
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

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    
    cin >> n;
    k = 2;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    head = deleteK(head, k);
    printList(head);
    
    return 0;
}