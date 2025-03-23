#include <iostream>
#include <stdexcept>  

using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};
    
    int index;
    cout << "인덱스 입력 (1~5)" << endl;
    cin >> index;

    try {
        if (index < 0 || index >= SIZE) {
            throw out_of_range("out of range");
        }
        cout << "인덱스 " << index << "의 값: " << arr[index] << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;  
    }

    return 0;
}
