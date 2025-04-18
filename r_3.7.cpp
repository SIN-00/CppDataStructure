
#include <iostream>
#include <string>

using namespace std;

template <typename E>
struct SNode {						// singly linked list node
    E elem;							// linked list element value
    SNode<E>* next;					// next item in the list
};

template <typename E>
class SLinkedList {					// a singly linked list
public:
    SLinkedList();					// empty list constructor
    ~SLinkedList();					// destructor
    bool empty() const;				// is list empty?
    const E& front() const;			// return front element
    void addFront(const E& e);		// add to front of list
    void removeFront();				// remove front item list
    void display() const;
    SNode<E>* findPenultimate() const;
private:
    SNode<E>* head;					// head of the list
  };

template <typename E>
SLinkedList<E>::SLinkedList()				// constructor
    : head(NULL) { }

template <typename E>
bool SLinkedList<E>::empty() const			// is list empty?
    { return head == NULL; }

template <typename E>
const E& SLinkedList<E>::front() const		// return front element
    { return head->elem; }

template <typename E>
SLinkedList<E>::~SLinkedList()				// destructor
    { while (!empty()) removeFront(); }

template <typename E>
void SLinkedList<E>::addFront(const E& e) {	// add to front of list
    SNode<E>* v = new SNode<E>;				// create new node
    v->elem = e;							// store data
    v->next = head;							// head now follows v
    head = v;								// v is now the head
}

template <typename E>
void SLinkedList<E>::removeFront() {		// remove front item
    SNode<E>* old = head;					// save current head
    head = old->next;						// skip over old head
    delete old;								// delete the old head
}

template <typename E>
void SLinkedList<E>::display() const {
        SNode<E>* temp = head;
        while (temp != NULL) {
            cout << temp->elem << " ";
            temp = temp->next;
        }
        cout << endl;
};

template <typename E>
SNode<E>* SLinkedList<E>::findPenultimate() const {
    if (head == NULL || head->next == NULL) {
        return NULL; 
    }

    SNode<E>* cur = head;
    while (cur->next->next != NULL) {
        cur = cur->next;
    }

    return cur; 
}

// Example usage
int main() {
    SLinkedList<int> a;
    a.addFront(1);
    a.addFront(2);
    a.addFront(3); 
    a.display();
    cout << a.findPenultimate()->elem;
    
    

    return 0;
}
