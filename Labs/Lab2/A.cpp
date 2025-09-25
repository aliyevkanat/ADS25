#include <iostream>
#include <cmath>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

int nearest_number(int x,Node*head){
if(head == nullptr) return -1;

    int nearest_index = 0;
    Node *current = head;
    int index = 0;
    int min_diff = abs(head->data-x);
    while(current != nullptr){
        
    int curr_diff = abs(current->data-x);

    if(curr_diff < min_diff){
        min_diff = curr_diff;
        nearest_index = index;
        }
        current = current->next;
        index++;
    }
    return nearest_index;
}

int main(){

Node *head = nullptr;
Node *tail = nullptr;

int n;
cin >> n;
for(int i = 0;i < n;i++){
    int x;
    cin >> x;
    Node *new_node = new Node(x);
    if(head == nullptr){
        head = tail = new_node;
    }else{
        tail->next = new_node;
        tail = new_node;
    }

}
int k;
cin >> k;

int result = nearest_number(k,head);
cout << result << endl;

    return 0;
}