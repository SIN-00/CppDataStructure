#include <iostream>
using namespace std;

void hanoi(int n, char from, char temp, char to) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }

    hanoi(n - 1, from, to, temp);   
    cout << "Move disk " << n << " from " << from << " to " << to << endl; 
    hanoi(n - 1, temp, from, to);                   
}

int main() {
    int n = 3; 
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
