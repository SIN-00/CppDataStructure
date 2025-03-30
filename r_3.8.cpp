#include <iostream>
#include <string>
using namespace std;

template <typename T>
class DLinkedList;  // Forward declaration

template <typename T>
class DNode {
public:
    T elem;
    DNode<T>* prev;
    DNode<T>* next;
    friend class DLinkedList<T>;  // 템플릿 인자 명시 필수!
};

template <typename T>
class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const T& front() const;
    const T& back() const;
    void addFront(const T& e);
    void addBack(const T& e);
    void removeFront();
    void removeBack();
    void display() const;
    DNode<T>* findCenter();  // 중앙 노드 찾기

private:
    DNode<T>* header;
    DNode<T>* trailer;

protected:
    void add(DNode<T>* v, const T& e);
    void remove(DNode<T>* v);
};

// 생성자
template <typename T>
DLinkedList<T>::DLinkedList() {
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    trailer->prev = header;
}

// 소멸자
template <typename T>
DLinkedList<T>::~DLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

// 리스트 비었는지 확인
template <typename T>
bool DLinkedList<T>::empty() const {
    return (header->next == trailer);
}

// 첫 번째 요소
template <typename T>
const T& DLinkedList<T>::front() const {
    return header->next->elem;
}

// 마지막 요소
template <typename T>
const T& DLinkedList<T>::back() const {
    return trailer->prev->elem;
}

// 노드 추가 (기본 유틸)
template <typename T>
void DLinkedList<T>::add(DNode<T>* v, const T& e) {
    DNode<T>* u = new DNode<T>;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

// 앞에 추가
template <typename T>
void DLinkedList<T>::addFront(const T& e) {
    add(header->next, e);
}

// 뒤에 추가
template <typename T>
void DLinkedList<T>::addBack(const T& e) {
    add(trailer, e);
}

// 노드 삭제 (기본 유틸)
template <typename T>
void DLinkedList<T>::remove(DNode<T>* v) {
    DNode<T>* u = v->prev;
    DNode<T>* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

// 앞 제거
template <typename T>
void DLinkedList<T>::removeFront() {
    remove(header->next);
}

// 뒤 제거
template <typename T>
void DLinkedList<T>::removeBack() {
    remove(trailer->prev);
}

// 출력
template <typename T>
void DLinkedList<T>::display() const {
    DNode<T>* v = header->next;
    cout << "Output: ";
    while (v != trailer) {
        cout << v->elem << " ";
        v = v->next;
    }
    cout << endl;
}

// 중앙 노드 찾기 (링크 따라가며)
template <typename T>
DNode<T>* DLinkedList<T>::findCenter() {
    DNode<T>* forward = header->next;
    DNode<T>* backward = trailer->prev;

    while (forward != backward && forward->next != backward) {
        forward = forward->next;
        backward = backward->prev;
    }
    return forward;
}

// 메인 함수
int main() {
    DLinkedList<string> list1;
    list1.addBack("A");
    list1.addBack("B");
    list1.addBack("C");
    list1.addBack("D");
    list1.addBack("E");
    list1.display();
    DNode<string>* center1 = list1.findCenter();
    cout << "[홀수] 중앙 노드: " << center1->elem << endl;

    DLinkedList<string> list2;
    list2.addBack("1");
    list2.addBack("2");
    list2.addBack("3");
    list2.addBack("4");
    list2.display();
    DNode<string>* center2 = list2.findCenter();
    cout << "[짝수] 중앙 노드: " << center2->elem << endl;

    return 0;
}
