//---------------------------------------------------------------------
// 2024.3.7 ��		                                        (1�� / 2��)
// 
// C++ ����
//---------------------------------------------------------------------

#include <iostream>
#include "save.h"
using namespace std;

// [����] main()�� �����ϸ� �ȵȴ�. �Լ� change()�� �����ϰ� �����϶�

class Dog;	// ���� ����,forward declaration

template<class T>
void change(T&, T&);

class Dog {
public:
	Dog(int a) : num{ a } {};
	// Dog(const Dog& other) -> special �Լ� (�����Ϸ� �ڵ�����)

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
	cout << a << ", " << b << endl;    // [���] 2,1

	save("FileName.cpp");
}

template<class T>
void change(T& a, T& b)
{
	T temp{ a };  // copy construction
	a = b;
	b = temp;
}
