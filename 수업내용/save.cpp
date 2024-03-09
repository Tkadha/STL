//-----------------------------------------------------------
// save.cpp		�� �б� ���Ǹ� �����Ѵ�.
// 
// 2024.03.07
//-----------------------------------------------------------
#include <string_view>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

#include "save.h"


void save(std::string_view filename)
{
	// ���� ������ ����
	std::ifstream in{ filename.data() };

	if (!in) {
		std::cout << "������ ���� ����" << '\n';
		exit(0);
	}

	// �� ������ �����̱� ���� ����

	std::ofstream out("2024 1 ��56��78 ��������.txt", std::ios::app);

	// ����� �ð��� ���Ͽ� ����Ѵ�

	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now); // utc �ð����� ��ȯ
	auto lt = localtime(&time);		// ���� �ð����� ��ȯ
	auto old = out.imbue(std::locale("ko_KR"));
	out << '\n' << '\n';
	out << "====================================================" << '\n';
	out << filename << std::put_time(lt, ", ���� �ð�: %x %A %X") << '\n';
	out << "====================================================" << '\n';
	out.imbue(old);
	out << std::endl;
	// ���� ������ ��� ������ �о� �� ���Ͽ� �����δ�.

	std::vector<char> v{ std::istreambuf_iterator<char>{in},{} };

	copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{out});
}