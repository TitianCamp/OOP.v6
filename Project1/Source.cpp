#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
		#include <functional>
#include <numeric>

using namespace::std;

template<typename T> class Functor {
public:
	/*T operator()(T a, T b, plus<T>$) { return plus<T>()(a, b); }*/
	
	T plus(T a, T b) { return a + b; }
	T addition(T a, T b) { return a - b; }
	T times(T a, T b) { return a * b; }
	T divides(T a, T b) { if (b) { return a / b; } else throw "Incorrect b"; }
	T modulus(T a, T b) { return (int)a % (int)b; }
	T negate(T a) { return a * (-1); }

	bool equal_to(T a, T b) { return a == b; }
	bool not_equal_to(T a, T b) { return a != b; }
	bool greater(T a, T b) { return a > b; }
	bool less(T a, T b) { return a < b; }
	bool greater_equal(T a, T b) { return a >= b; }
	bool less_equal(T a, T b) { return a <= b; }

	bool logical_and(T a, T b) { return a && b; }
	bool logical_or(T a, T b) { return a || b; }
	bool logical_not(T a) { return !a; }
};

void printNumber(int x) { cout << x << endl; }

void main() {
	Functor<float> functor;
	srand(time(NULL));

	vector<int> numbers;
	for (int i = 0; i < rand() % 20; i++) {
		numbers.push_back(rand() % 1000);
	}

	sort(numbers.begin(), numbers.end());
	for_each(numbers.begin(), numbers.end(), printNumber);

	cout << endl;
	sort(numbers.begin(), numbers.end(), greater<int>());
	for_each(numbers.begin(), numbers.end(), printNumber);

	cout << endl;
	reverse(numbers.begin(), numbers.end());
	for_each(numbers.begin(), numbers.end(), printNumber);

	cout << "Sum of array: " << accumulate(numbers.begin(), numbers.end(), 0) << endl;
	
	vector<int>::iterator iter = numbers.begin();
	cout << "Iterator: " << *iter << endl;

	numbers.clear();
	cout << numbers.empty() << endl;

	/*cout << functor(2, 4, plus<int>());*/

	/*cout << functor.plus(2, 5) << endl;
	cout << functor.addition(2, 5) << endl;
	cout << functor.times(2, 5) << endl;
	cout << functor.divides(2, 5) << endl;
	cout << functor.modulus(5, 2) << endl;
	cout << functor.negate(2) << endl;

	cout << functor.equal_to(2, 5) << endl;
	cout << functor.not_equal_to(2, 5) << endl;
	cout << functor.greater(2, 5) << endl;
	cout << functor.less(2, 5) << endl;
	cout << functor.greater_equal(2, 5) << endl;
	cout << functor.less_equal(2, 5) << endl;

	cout << functor.logical_and(1, 0) << endl;
	cout << functor.logical_or(1, 0) << endl;
	cout << functor.logical_not(1) << endl;*/
}