//---------------------------------------------------------------------
// 2024.3.25 ��		                                        (4�� / 1��)
// 
// free store�� �Ҵ�� ��ü
// 
// ������ C++���� ������� �� ��
// raw        wrapping
// char*   -> string
// T [N]   -> array<T,N>
// T*      -> unique_ptr, shared_ptr
//---------------------------------------------------------------------

#include <iostream>
#include <string_view>
#include <fstream>
#include <vector>
#include "save.h"
using namespace std;

// [����] "FileName.cpp"�� ��� �����ڸ� �빮�ڷ� �ٲ� "FileName�빮��.txt"�� �����Ͻÿ�.

int main()
{
	string_view name{ "FileName.cpp" };
	ifstream in{ name.data() };
	if (!in) {
		std::cout << "������ ���� ����" << '\n';
		exit(-1);
	}
	std::ofstream out("FileNam�빮��.txt");
	
	char c;
	in >> noskipws;
	while (in >> c) {
		out << static_cast<char>(toupper(c));
	}
	save("FileName.cpp");
}
