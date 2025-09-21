#include <iostream>
#include <deque>
using namespace std;

int main() {
deque<int> boris, nursik;
for (int i = 0; i < 5; i++) {
    int card;
    cin >> card;
    boris.push_back(card);
}

for (int i = 0; i < 5; i++) {
    int card;
    cin >> card;
    nursik.push_back(card);
}

int moves = 0;
int max_moves = 1000000;

while (moves < max_moves && !boris.empty() && !nursik.empty()) {
    int b_card = boris.front();
    int n_card = nursik.front();
    boris.pop_front();
    nursik.pop_front();
    
    bool boris_win = false;
    
    if (b_card == 0 && n_card == 9) {
        boris_win = true;
    } else if (b_card == 9 && n_card == 0) {
        boris_win = false;
    } else if (b_card > n_card) {
        boris_win = true;
    } else {
        boris_win = false;
    }
    
    if (boris_win) {
        boris.push_back(b_card);
        boris.push_back(n_card);
    } else {
        nursik.push_back(b_card);
        nursik.push_back(n_card);
    }
    
    moves++;
}

if (boris.empty()) {
    cout << "Nursik " << moves;
} else if (nursik.empty()) {
    cout << "Boris " << moves;
} else {
    cout << "blin nichya";
}

return 0;
}