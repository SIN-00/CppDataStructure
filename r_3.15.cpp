#include <iostream>

using namespace std;

template <typename T>
class CircleList;						// forward declaration

template <typename T>
class CNode {							// circularly linked list node
private:
    T elem;								// linked list element value
    CNode<T>* next;						// next item in the list

    friend class CircleList<T>;			// provide CircleList access
};

template <typename T>
class CircleList {						// a circularly linked list
public:
    CircleList();						// constructor
    ~CircleList();						// destructor
    bool empty() const;					// is list empty?
    const T& front() const;				// element at cursor
    const T& back() const;				// element following cursor
    void advance();						// advance cursor
    void add(const T& e);				// add after cursor
    void remove();						// remove node after cursor
    void display() const;
private:
    CNode<T>* cursor;					// the cursor
};

template <typename T>
CircleList<T>::CircleList()				// constructor
    : cursor(NULL) { }

template <typename T>
CircleList<T>::~CircleList()			// destructor
    { while (!empty()) remove(); }

template <typename T>
bool CircleList<T>::empty() const		// is list empty?
    { return cursor == NULL; }

template <typename T>
const T& CircleList<T>::back() const	// element at cursor
    { return cursor->elem; }

template <typename T>
const T& CircleList<T>::front() const	// element following cursor
    { return cursor->next->elem; }

template <typename T>
void CircleList<T>::advance()			// advance cursor
    { cursor = cursor->next; }

template <typename T>
void CircleList<T>::add(const T& e) {	// add after cursor
    CNode<T>* v = new CNode<T>;			// create a new node
    v->elem = e;
    if (cursor == NULL) {				// list is empty?
      v->next = v;						// v points to itself
      cursor = v;						// cursor points to v
    }
    else {								// list is nonempty?
      v->next = cursor->next;			// link in v after cursor
      cursor->next = v;
// 	  cursor = cursor->next;			// add a statement *** important
    }
}

template <typename T>
void CircleList<T>::remove() {			// remove node after cursor
    CNode<T>* old = cursor->next;		// the node being removed
    if (old == cursor) 					// removing the only node?
      cursor = NULL;					// list is now empty
    else
      cursor->next = old->next;			// link out the old node
    delete old;							// delete the old node
}

template <typename T>
void CircleList<T>::display() const {
    if (cursor == NULL) {
        cout << "Output : []" << endl;
        return;
    }

    CNode<T>* v = cursor->next;

    cout << "Output : [";
    while ( v != NULL ) {
        cout << v->elem;
        if (v == cursor) break;
        cout << ", ";
        v = v->next;
    }
    cout << "*]" << endl;
}

// Example usage
int main() {
    CircleList<string> playList;				// []
    playList.add("Stayin Alive");				//[Stayin Alive*]
    playList.display();
    playList.add("Le Freak");					//[Le Freak, Stayin Alive*]
    playList.display();
    playList.add("Jive Talkin");				//[Jive Talkin, Le Freak, Stayin Alive*]
    playList.display();

    playList.advance();						//[Le Freak, Stayin Alive, Jive Talkin*]
    playList.display();
    playList.advance();						//[Stayin Alive, Jive Talkin, Le Freak*]
    playList.display();
    playList.remove();						//[Jive Talkin, Le Freak*]
    playList.display();
    playList.add("Disco Inferno");			//[Disco Inferno, Jive Talkin, Le Freak*]
    playList.display();

    CircleList<string> a;

    a.add("Korea");
    a.display();
    a.add("Japan");
    a.display();
    a.add("USA");
    a.display();
    a.add("Austrailia");
    a.display();
    a.add("German");
    a.display();
    a.add("Norway");
    a.display();
    a.advance();
    a.display();
    a.advance();
    a.display();
    a.remove();
    a.display();
    a.remove();
    a.display();

    return EXIT_SUCCESS;
}
