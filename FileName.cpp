//---------------------------------------------------------------------
// 2024.3.25 월		                                        (4주 / 1일)
// 
// free store에 할당된 객체
// 
// 앞으로 C++에서 사용하지 말 것
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

// [문제] "FileName.cpp"의 모든 영문자를 대문자로 바꿔 "FileName대문자.txt"에 저장하시오.

int main()
{
	string_view name{ "FileName.cpp" };
	ifstream in{ name.data() };
	if (!in) {
		std::cout << "파일을 열지 못함" << '\n';
		exit(-1);
	}
	std::ofstream out("FileNam대문자.txt");
	
	char c;
	in >> noskipws;
	while (in >> c) {
		out << static_cast<char>(toupper(c));
	}
	save("FileName.cpp");
}
