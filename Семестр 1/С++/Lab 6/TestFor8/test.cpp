#include "pch.h"

int count(std::string string1, std::string string2)
{
	int proverka = 0;
	int size = string1.size();
	for (int i = 0; i < size; i++)
	{
		std::string dop1 = string1.substr(0, i + 1);   // ������� ��������� �� 0 � ������� ����� �������
		std::string dop2 = string1.substr(0, i);         // ������� ��������� �� 0 � ������� ����� �������
		reverse(dop2.begin(), dop2.end());           // ������ ������� ��������� �� ������ �� �����
		dop1 += dop2;                  // �������� ������   
		int otvet = dop1.find(string2);      // otvet = -1, ���� �� ��������, otvet = 0, ���� ��������
		if (otvet != -1)                  // string2 ���������� �� ���� ������
		{
			proverka = 1;
			break;
		}
		else
		{
			proverka = 0;
			break;
		}
	}

	return proverka;
}

TEST(TestCaseName1, TestName1)
{
	std::string string1 = "abcdef";
	std::string string2 = "cdedcb";
	ASSERT_EQ(count(string1, string2), 0);
}


TEST(TestCaseName2, TestName2)
{
	std::string string1 = "ba";
	std::string string2 = "baa";
	ASSERT_EQ(count(string1, string2), 0);
}



TEST(TestCaseName3, TestName3)
{
	std::string string1 = "abcdef";
	std::string string2 = "abcdef";
	ASSERT_EQ(count(string1, string2), 0);
}

