#include <iostream>

class Base {
public:
    virtual void show() {  // 가상 함수 → 동적 바인딩 활성화
        std::cout << "Base class show()\n";
    }
};

class Derived : public Base {
public:
    void show() override {  // 오버라이딩
        std::cout << "Derived class show()\n";
    }
};

int main() {
    Base* ptr = new Derived();  // 다형성 적용
    ptr->show();  // "Derived class show()" 출력됨 (동적 바인딩)

    delete ptr;  // 메모리 해제 (Base의 소멸자는 virtual이어야 함)
    return 0;
}
