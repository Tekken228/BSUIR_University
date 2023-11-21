#include <iostream>
#include <string>
#include <bitset>

int checking()
{
	int number;
	std::cout << "������� �����:\n";
	while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() != ' ') || number < 0 || number >= INT_MAX)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			std::cout << "\n�������� ����!\n";
			std::cout << "���������� �����: ";
		}
	}
	return number;
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "���������, ��������� ��������� �������� ��������� ��������� ���������� ����� �� 3, 47, 197\n";
	std::cout << "��������: ������ ������(������ 253505)\n\n";
	int x = 1;
	while (x)
	{
		int number, dop = 0;
		bool check = false;
		number = checking();
		int number_3 = number, number_47 = number, number_197 = number;
		while (number_3 > 2)		// nlogn
		{
			if (number_3 == 3)
			{
				check = true;
				break;
			}
			if (number_3 & 1)
			{
				dop = 2;
			}
			else
			{
				dop = 0;
			}
			number_3 >>= 1;
			if (number_3 + dop == 3)
			{
				check = true;
				break;
			}
			number_3 += dop;
		}
		if (check)
		{
			std::cout << "������ ����� ������� �� 3" << '\n';
		}
		else
		{
			std::cout << "������ ����� �� ������� �� 3" << '\n';
		}

		//��������� ������� �� �� 47
		check = false;
		while (number_47 > 46)		// nlogn
		{
			if (number_3 == 47)
			{
				check = true;
				break;
			}
			if (number_47 & 1)
			{
				dop = 24;
			}
			else
			{
				dop = 0;
			}
			number_47 >>= 1;
			if (number_47 + dop == 47)
			{
				check = true;
				break;
			}
			number_47 += dop;
		}
		if (check)
		{
			std::cout << "������ ����� ������� �� 47" << '\n';
		}
		else
		{
			std::cout << "������ ����� �� ������� �� 47" << '\n';
		}

		//��������� ��������� �� 197
		check = false;
		while (number_197 > 196)		// nlogn
		{
			if (number_3 == 197)
			{
				check = true;
				break;
			}
			if (number_197 & 1)
			{
				dop = 99;
			}
			else
			{
				dop = 0;
			}
			number_197 >>= 1;
			if (number_197 + dop == 197)
			{
				check = true;
				break;
			}
			number_197 = number_197 + dop;
		}
		if (check)
		{
			std::cout << "������ ����� ������� �� 197" << '\n';
		}
		else
		{
			std::cout << "������ ����� �� ������� �� 197" << '\n';
		}
		std::cout << "\n";
		printf("\n��������� ��������� �� �����? (0 - ���, 1 - ��): ");
		while (!(std::cin >> x) || (std::cin.peek() != '\n') || (x != 0 && x != 1))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				printf("������������ ����\n");
				printf("���������� �����: ");
			}
		}
	}
	return 0;
}