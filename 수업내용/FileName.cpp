//---------------------------------------------------------------------
// 2024.3.18 ��		                                        (3�� / 1��)
// 
// ���� ������ �޸� ���� - STACK, DATA, CODE, free store(heap)
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
	string s{ "�ȳ��ϼ���" };
	double* p = new double[10];
	save("FileName.cpp");
}
