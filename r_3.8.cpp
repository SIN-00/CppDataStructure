#include <iostream>
#include <string>
using namespace std;

template <typename T>
class DLinkedList;  // Forward declaration

template <typename T>
class DNode {
private:
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

// 비었는지 확인
template <typename T>
bool DLinkedList<T>::empty() const {
    return (header->next == trailer);
}

template <typename T>
const T& DLinkedList<T>::front() const {
    return header->next->elem;
}

template <typename T>
const T& DLinkedList<T>::back() const {
    return trailer->prev->elem;
}

template <typename T>
void DLinkedList<T>::add(DNode<T>* v, const T& e) {
    DNode<T>* u = new DNode<T>;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

template <typename T>
void DLinkedList<T>::addFront(const T& e) {
    add(header->next, e);
}

template <typename T>
void DLinkedList<T>::addBack(const T& e) {
    add(trailer, e);
}

template <typename T>
void DLinkedList<T>::remove(DNode<T>* v) {
    DNode<T>* u = v->prev;
    DNode<T>* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

template <typename T>
void DLinkedList<T>::removeFront() {
    remove(header->next);
}

template <typename T>
void DLinkedList<T>::removeBack() {
    remove(trailer->prev);
}

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

// 리스트 뒤집기 함수
template <typename T>
void listReverse(DLinkedList<T>& L) {
    DLinkedList<T> Tlist;
    while (!L.empty()) {
        T elem = L.front();
        L.removeFront();
        Tlist.addFront(elem);
    }
    while (!Tlist.empty()) {
        T elem = Tlist.front();
        Tlist.removeFront();
        L.addBack(elem);
    }
}

// main 함수
int main() {
    DLinkedList<string> a;

    a.addFront("Korea");
    a.display();
    a.addBack("Japan");
    a.display();
    a.addBack("China");
    a.display();
    a.addFront("UK");
    a.display();
    a.addFront("France");
    a.display();
    a.addFront("Spain");
    a.display();
    a.removeBack();
    a.display();
    a.removeFront();
    a.display();

    listReverse(a);
    a.display();

    DLinkedList<int> b;
    b.addFront(1);
    b.addBack(2);
    b.addBack(3);
    b.display();

    return 0;
}
