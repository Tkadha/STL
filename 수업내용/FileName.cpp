//---------------------------------------------------------------------
// 2024.3.28 ��		                                        (4�� / 2��)
// 
// callable type -> ���� �������� ����(qsort���� sort��)
// generic �Լ� : � �ڷ����̵� ����� �� �ִ� �Լ�
//---------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <print>
#include <random>
#include <array>
#include "save.h"
using namespace std;

// [����] int 100���� ������ ������ Ȯ���϶�.
// int 100���� [1, 99'999]  (1�̻� 99'999���� ()�� �ʰ� �̸� ) ������ ���������� �����϶�
// qsort()�� ����Ͽ� ������������ �����϶�.
// ���ĵ� int���� �� �ٿ� 10�� �� ����϶�

uniform_int_distribution<int> uid{ 1, 99999 };
default_random_engine dre;

array<int, 100> arr;

// int ���Ĺ�� (const void*,const void*);
// �Լ� �̸� -> �Լ� ������
int cmp(const void* a, const void* b) 
{ 
	int x = *(int*)a;	// int �����ͷ� ��ȯ�� �� �� ����
	int y = *(int*)b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0;
}


int main()
{
	for (int& num : arr)
		num = uid(dre);
	
	int (*�Լ�)(const void*,const void*) = cmp;	// cmp�� ����Ű�� �ִ� �����͸� �Լ��� ����Ŵ

	
	// qsort(���� ����, ó���ؾ��� ����, �Ѱ��� ũ��, ���� ���(code) - type: �Լ� ������) - c�Լ������� generic �Լ�
	qsort(arr.data(), arr.size(), sizeof(int), �Լ�);
	// �޸𸮰� contiguous(������) �ؾ���.
	
	for (int num : arr)
		print("{:8}", num);	// �԰��� 80x25�� �߱⶧���� ���ٿ� 10���� ��µȴ�.

	(*save)("FileName.cpp"); //�Լ������Ͱ� �ƴ� ��¥ �Լ� ȣ�� 
}
