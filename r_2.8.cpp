/*
R-2.8 Give a short fragment of C++ code 
that uses the progression classes from Section 2.2.3 
to find the 7th value of a Fibonacci progression that starts with 3 and 4 as its first two values
*/


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

class FibonacciProgression : public Progression {	// Fibonacci progression
public:
	FibonacciProgression(long f = 0, long s = 1); 	// constructor
protected:
	virtual long firstValue(); 						// reset
	virtual long nextValue(); 						// advance
protected:
	long second; 									// second value
	long prev; 										// previous value
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

FibonacciProgression::FibonacciProgression(long f, long s)
	: Progression(f), second(s), prev(second - first) { }

long FibonacciProgression::firstValue() { 				// reset
	cur = first;
	prev = second - first; 								// create fictitious prev
	return cur;
}

long FibonacciProgression::nextValue() { 				// advance
	long temp = prev;
	prev = cur;
	cur += temp;
	return cur;
}


/** Test program for the progression classes */
int main() {

	Progression* prog;
	
    prog = new FibonacciProgression(3, 4);
	prog->printProgression(7);

	return EXIT_SUCCESS; // successful execution
}
