#include <iostream> 
#include <string>
#include <algorithm>

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
			return proverka;
		}
		else
		{
			proverka = 0;
			return proverka;
		}
	}
}

int main()
{
	int povtorenie, j = 0;
	std::cin >> povtorenie;
	while (j < povtorenie)
	{
		std::string string1, string2;
		std::cin >> string1 >> string2;
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
		}
		if (proverka == 1)
		{
			std::cout << "YES" << '\n';
		}
		else
		{
			std::cout << "NO" << '\n';
		}
		j++;
	}

	return 0;
}