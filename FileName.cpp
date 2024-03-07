//---------------------------------------------------------------------
// 2024.3.7 목		                                        (1주 / 2일)
// 
// C++ 복습
//---------------------------------------------------------------------

#include <iostream>
#include "save.h"
using namespace std;

// [문제] main()을 변경하면 안된다. 함수 change()를 선언하고 정의하라

class Dog;	// 전방 선언,forward declaration

template<class T>
void change(T&, T&);

class Dog {
public:
	Dog(int a) : num{ a } {};
	// Dog(const Dog& other) -> special 함수 (컴파일러 자동생성)

	/*friend ostream& operator<<(ostream& os, const Dog& dog) {
		return os << dog.num;
	}*/

	operator int() {
		return num;
	}

private:
	int num;
};




int main()
{
	Dog a{ 1 }, b{ 2 };

	change(a, b);
	cout << a << ", " << b << endl;    // [출력] 2,1

	save("FileName.cpp");
}

template<class T>
void change(T& a, T& b)
{
	T temp{ a };  // copy construction
	a = b;
	b = temp;
}
