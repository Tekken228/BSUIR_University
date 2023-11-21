#include <iostream>
#include <string>

int proverka()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0 || a > 240)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		{
			printf("������������ ����\n");
			printf("���������� �����: ");
		}
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "��������� ����������� ����� � ������� 5 slaves\n";
	std::cout << "��������� ������ �������� (������ 253505)\n\n";
	int x = 1;
	while (x == 1)
	{
		std::cout << "������� ����� ����������� �����(1 - 240): ";
		int otravlenaya;
		otravlenaya = proverka();
		std::cout << '\n';
		std::string troichka;
		int i = 0, Num;
		while (otravlenaya != 0)
		{
			troichka.resize(i + 1);
			Num = otravlenaya % 3 + 48;
			troichka[i] = Num;
			otravlenaya /= 3;
			i++;
		}
		std::reverse(troichka.begin(), troichka.end());
		int length = troichka.length();
		std::cout << "��������� ����� ����������� ����� � �������� �������: ";
		while (length < 5)
		{
			troichka.insert(0, 1, '0');
			length++;
		}
		for (int i = 0; i < length; i++)		// O(N)
		{
			std::cout << troichka[i];
		}
		std::cout << "\n\n����������, ����� ����� � ���������� ������� ��������� �� ��������, ��� ������ ������ - ������ ���, ������\n������ - ������, � ��� �����.\n";
		std::cout << "0 - ��� �� ����\n1 - ��� ���� � ������ ����\n2 - ��� ���� �� ������ ����\n";
		std::cout << "��������, ������� ������ ���� �����. 00001 - ����� ��� ���� � ������ ����, ��������� ����, 00002 - ����� ��� ���� ��\n������ ����, 00010 - ������ ��� ���� � ������ ����, 00020 - ��������� ��� ���� �� ������ ����, 00100 - ������ ��� ���� �\n������ ����. � ��� �� 240 ������������.";
		std::cout << "\n";
		std::cout << "� ����� ������:\n";
		for (int i = 0; i < length; i++)					// O(N)
		{
			if (troichka[i] == '0')
			{
				std::cout << i + 1 << "-� ��� �� ����\n";
			}
			if (troichka[i] == '1')
			{
				std::cout << i + 1 << "-� ��� ���� � ������ ����\n";
			}
			if (troichka[i] == '2')
			{
				std::cout << i + 1 << "-� ��� ���� �� ������ ����\n";
			}
		}

		int t = length - 1;
		int sum = 0;
		int h = 0;
		while (t != -1)					// 0(N)
		{
			if (troichka[t] == '1')
			{
				sum += powl(3, h);
				h++;
				t--;
			}
			else if (troichka[t] == '2')
			{
				sum += 2 * powl(3, h);
				h++;
				t--;
			}
			else
			{
				h++;
				t--;
			}
		}
		std::cout << "\n����� ����� ����������� �����: " << sum;
		std::cout << "\n\n";
		printf("\n��������� ��������� �� �����? (0 - ���, 1 - ��): ");
		while ((x != 0 && x != 1) || !(std::cin >> x) || (std::cin.peek() != '\n'))
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
