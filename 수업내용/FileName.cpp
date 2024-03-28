//---------------------------------------------------------------------
// 2024.3.28 목		                                        (4주 / 2일)
// 
// callable type -> 정렬 예제에서 시작(qsort에서 sort로)
// generic 함수 : 어떤 자료형이든 사용할 수 있는 함수
//---------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <print>
#include <random>
#include <array>
#include "save.h"
using namespace std;

// [문제] int 100개를 저장할 공간을 확보하라.
// int 100개의 [1, 99'999]  (1이상 99'999이하 ()는 초과 미만 ) 사이의 랜덤값으로 설정하라
// qsort()를 사용하여 오름차순으로 정렬하라.
// 정렬된 int값을 한 줄에 10개 씩 출력하라

uniform_int_distribution<int> uid{ 1, 99999 };
default_random_engine dre;

array<int, 100> arr;

// int 정렬방법 (const void*,const void*);
// 함수 이름 -> 함수 포인터
int cmp(const void* a, const void* b) 
{ 
	int x = *(int*)a;	// int 포인터로 변환한 후 값 꺼냄
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
	
	int (*함수)(const void*,const void*) = cmp;	// cmp가 가르키고 있는 포인터를 함수도 가르킴

	
	// qsort(시작 번지, 처리해야할 갯수, 한개당 크기, 정렬 방법(code) - type: 함수 포인터) - c함수이지만 generic 함수
	qsort(arr.data(), arr.size(), sizeof(int), 함수);
	// 메모리가 contiguous(연속적) 해야함.
	
	for (int num : arr)
		print("{:8}", num);	// 규격을 80x25로 했기때문에 한줄에 10개씩 출력된다.

	(*save)("FileName.cpp"); //함수포인터가 아닌 진짜 함수 호출 
}
