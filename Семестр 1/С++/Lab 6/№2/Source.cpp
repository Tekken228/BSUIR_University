#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "ru");
	printf("� ������ ����� � ������� �� ����� ����� ������������ � ����������� �����.\n");
	printf("��������: ������ ������ ���������(������ 253505)\n");
	int x = 1;
	while (x == 1)
	{
		/*
		char arr[81];
		std::cout << "������� �����: ";
		std::cin.getline(arr, 80);
		*/
		char string[100];
		char proverka;
		long long minDlina = 0, index = 1;
		std::cout << "������� �����:\n";
		while (true)
		{
			bool goOut = 1, probelms = 1;
			for (int i = 0; i < 100; i++)
			{
				proverka = getchar();
				if (proverka == '\n' && i == 0 || proverka <= '9' && proverka >= '0')
				{
					if (proverka <= '9' && proverka >= '0')
					{
						std::cout << "� ������ ��� ����\n";
						std::cout << "���������� �����:\n";
						std::cin.ignore(INT_MAX, '\n');
					}
					goOut = 0;
				//	std::cout << "\nffff� ������ ��� ����\n";
				//	std::cout << "���������� �����:\n";
					std::cin.clear();
				//	std::cin.ignore(INT_MAX, '\n');
					break;

				}

				if (proverka == '\n')
				{
					string[i] = '\0';
					break;
				}

				if (probelms && proverka == ' ')
				{
					// i--;
					continue;
				}
				else
				{
					probelms = false;
				}
				string[i] = proverka;

				if (ispunct(proverka))  // �������� �� ������ �����
				{
					std::cout << "\n������ �������� �� ���� � ����, ����� ���������!\n";
					std::cout << "���������� �����:\n";
					rewind(stdin);
					goOut = 0;
					for (int i = 0; i < 100; i++)
					{
						string[i] = '\0';
					}
					break;
				}
			}
			if (goOut == 1)
			{
				break;
			}
		}
		char* NUL = NULL;
		char* slovo = strtok_s(string, " ", &NUL);
		char* wordmax = NULL;
		char* wordmin = NULL;
		long long length = strlen(slovo), count = 0, minLen = 10000, maxLen = 0;
		char mas[100];
		while (slovo != NULL) // ���� ���� �����
		{
			length = strlen(slovo);
			if (maxLen < length)
			{
				maxLen = length;
				wordmax = slovo;
			}
			std::cout << '\n';
			if (minLen >= length)
			{
				minLen = length;
				wordmin = slovo;
			}
			count++;
			slovo = strtok_s(NULL, " ", &NUL);  //��������� �����
		}
		if (count == 1)
		{
			std::cout << "� ������ ���� �����: " << wordmax;
		}
		else
		{
			std::cout << "����� ������� �����: " << wordmax << '\n' << "����� �������� �����: " << wordmin;
		}
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
}s