#include <iostream>
#include <cmath>  // sqrt() 사용을 위한 헤더

using namespace std;

//double형으로 바꿈
class Progression {
public:
    Progression(double f = 0) 
        : first(f), cur(f) { }
    virtual ~Progression() {} 
    void printProgression(int n); 
protected:
    virtual double firstValue();  
    virtual double nextValue();   
protected:
    double first; 
    double cur;   
};

// RootProgression (제곱근 수열) 클래스 정의
class RootProgression : public Progression {
public: 
    RootProgression() : Progression(65536.0) {} // 기본값 65536
    RootProgression(double d) : Progression(d) {} // 사용자가 지정한 시작값
protected: 
    virtual double nextValue(); // 제곱근 계산
};

// RootProgression의 nextValue() 구현 (제곱근 계산)
double RootProgression::nextValue() {
    cur = sqrt(cur);
    return cur;
}

// Progression의 firstValue() 구현
double Progression::firstValue() {
    cur = first;
    return cur;
}


double Progression::nextValue() {
    return ++cur;
}


void Progression::printProgression(int n) {
    cout << firstValue();
    for (int i = 2; i <= n; i++)
        cout << " " << nextValue();
    cout << endl;
}

int main() {
    Progression* prog;
    prog = new RootProgression();
    prog->printProgression(5); 
    delete prog;

    Progression* prog2;
    prog2 = new RootProgression(25);
    prog2->printProgression(4); 
    delete prog2;

    return EXIT_SUCCESS;
}
