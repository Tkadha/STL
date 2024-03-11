//---------------------------------------------------------------------
// 2024.3.11 월		                                        (2주 / 1일)
// 
// C++ 복습
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"
using namespace std;

// 문제 - 파일 "int천개.txt"에는 int값 1000개가 숫자값 그대로 기록되어 있다.
// 값과 값은 공백으로 떨어져 있다.
// 가장 큰 값을 찾아 화면에 출력하라

int main()
{
	ifstream in("int천개.txt");
	if (!in)
		exit(0);
	cout << "최댓값은 " << *max_element(istream_iterator<int>{in}, {});
	save("FileName.cpp");
}

