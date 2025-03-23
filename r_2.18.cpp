#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}

    void print() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int, string> p1(10, "ten");
    Pair<double, char> p2(10.1, 'A');
    Pair<string, bool> p3("String", true);
    Pair<float, long> p4(10.12f, 100000L);
    Pair<char, int> p5('X', 20);
    p1.print();
    p3.print();
    p4.print();
    p5.print();

    return 0;
}
