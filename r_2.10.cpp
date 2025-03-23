
#include <iostream>

using namespace std;

class Progression { 				// a generic progression
public:
	Progression(long f = 0) 		// constructor
	: first(f), cur(f) { }
	virtual ~Progression() { };		// destructor
	void printProgression(int n); 	// print the first n values
protected:
	virtual long firstValue(); 		// reset
	virtual long nextValue(); 		// advance
protected:
	long first; 					// first value
	long cur; 						// current value
};

class GeomProgression : public Progression { 	// geometric progression
public:
	GeomProgression(long b = 2); 				// constructor
protected:
	virtual long nextValue(); 					// advance
protected:
	long base; 									// base value
};

void Progression::printProgression(int n) { 		// print n values
	cout << firstValue(); 							// print the first
	for (int i = 2; i <= n; i++) 					// print 2 through n
		cout << ' ' << nextValue();
	cout << endl;
}

long Progression::firstValue() { 					// reset
	cur = first;
	return cur;
}

long Progression::nextValue() {						// advance
	return ++cur;
}


GeomProgression::GeomProgression(long b) 			// constructor (Geometric Progression)
	: Progression(1), base(b) { }

long GeomProgression::nextValue() { 				// advance by multiplying
		cur *= base;
		return cur;
}




/** Test program for the progression classes */
int main() {

    Progression* p = new GeomProgression(); // GeomProgression 객체를 Progression* 포인터에 저장
    // cout << p->firstValue() << endl; //접근 지정자 오류(protected)
    delete p;
    return 0;

	return EXIT_SUCCESS; // successful execution
}
