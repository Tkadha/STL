//---------------------------------------------------------------------
// 2024.3.11 ��		                                        (2�� / 1��)
// 
// C++ ����
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"
using namespace std;

// ���� - ���� "intõ��.txt"���� int�� 1000���� ���ڰ� �״�� ��ϵǾ� �ִ�.
// ���� ���� �������� ������ �ִ�.
// ���� ū ���� ã�� ȭ�鿡 ����϶�

int main()
{
	ifstream in("intõ��.txt");
	if (!in)
		exit(0);
	cout << "�ִ��� " << *max_element(istream_iterator<int>{in}, {});
	save("FileName.cpp");
}

