//---------------------------------------------------------------------
// 2024.3.18 월		                                        (3주 / 1일)
// 
// 실행 파일의 메모리 영역 - STACK, DATA, CODE, free store(heap)
//---------------------------------------------------------------------

#include <iostream>
#include <array>
#include <string>
#include "save.h"
using namespace std;

char gc;	
int gnum;

int main()
{
	array<int, 10> a;
	string s{ "안녕하세요" };
	double* p = new double[10];
	save("FileName.cpp");
}
