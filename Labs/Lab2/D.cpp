#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

void Modes(Node*head){
    Node *current = head;
    map<int,int> m;
    while(current != nullptr){
        m[current->data]++;
        current = current->next;
    }
    map <int, int> :: reverse_iterator it;
        int maxi = 0;
        for(it = m.rbegin(); it!=m.rend(); ++it){
            if(it->second > maxi){
                maxi = it->second;
            }
        }
        for(it = m.rbegin(); it != m.rend(); it++){
            if(maxi==it->second){
                cout << it->first << ' ';
            }
        }
}




int main(){

    Node *head = nullptr;
    Node *tail = nullptr;
    int n;
    cin >> n;
    int x;
    for(int i = 0;i < n;i++){
        cin >> x;
    Node *new_node = new Node(x);
    if(head == nullptr){
        head = tail = new_node;
    }else{
        tail->next = new_node;
        tail = new_node;
    }

    }
    

    Modes(head);

    return 0;
}