#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

int findMaxSum(int n, Node* head) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    
    while (head != nullptr) {
        current_sum += head->data;
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        
        if (current_sum < 0) {
            current_sum = 0;
        }
        
        head = head->next;
    }
    
    return max_sum;
}

int main() {
    int n;
    cin >> n;

    Node *head = nullptr, *tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node *cur = new Node(x);

        if (head == nullptr) {
            head = tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    cout << findMaxSum(n, head) << "\n";
    return 0;
}