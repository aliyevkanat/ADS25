#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* inserts(Node* head, int x, int p) {
    Node* newNode = new Node(x);
    
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }
    
    Node* current = head;
    for (int i = 0; i < p - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* current = head;
    for (int i = 0; i < p - 1; i++) {
        current = current->next;
    }
    
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    return head;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << endl;
        return;
    }
    
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head;
    
    Node* current = head;
    Node* prev1 = nullptr;
    for (int i = 0; i < p1; i++) {
        prev1 = current;
        current = current->next;
    }
    Node* node1 = current;
    
    if (prev1 == nullptr) {
        head = head->next;
    } else {
        prev1->next = node1->next;
    }
    
    if (p2 == 0) {
        node1->next = head;
        return node1;
    }
    
    current = head;
    for (int i = 0; i < p2 - 1; i++) {
        current = current->next;
    }
    
    node1->next = current->next;
    current->next = node1;
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

Node* cyclic_left(Node* head, int x) {
    if (head == nullptr || x == 0) return head;
    
    Node* tail = head;
    int length = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }
    
    x = x % length;
    if (x == 0) return head;
    
    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) {
        newTail = newTail->next;
    }
    
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    
    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (head == nullptr || x == 0) return head;
    
    Node* tail = head;
    int length = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }
    
    x = x % length;
    if (x == 0) return head;
    
    int steps = length - x;
    Node* newTail = head;
    for (int i = 0; i < steps - 1; i++) {
        newTail = newTail->next;
    }
    
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    
    return newHead;
}

int main() {
    Node* head = nullptr;
    int command;
    
    while (cin >> command) {
        if (command == 0) {
            break;
        }
        else if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = inserts(head, x, p);
        }
        else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        }
        else if (command == 3) {
            print(head);
        }
        else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5) {
            head = reverse(head);
        }
        else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    
    return 0;
}