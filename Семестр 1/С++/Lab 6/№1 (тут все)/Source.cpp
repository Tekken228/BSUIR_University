#include <iostream>


int main()
{
	setlocale(LC_ALL, "ru");
	printf("���� ������ ��������, ��������� �� ����, ����������� ���������. ������� ������ ����� ���� ������.\n");
	printf("��������: ������ ������ ���������(������ 253505)\n");
	int x = 1;
	while (x == 1)
	{
		printf("������� �������� �������: ");
		char arr[81]{};
		int ind = -1, n = 0;
		char string[100]{};
		char proverka;
		while (true)
		{
			bool goOut = 1, probelms = 1;
			for (int i = 0; i < 100; i++)
			{
				proverka = getchar();
				if (proverka == '\n' && i == 0 || proverka >= '9')
				{
					if (proverka >= '9')
					{
						std::cout << "� ������ ��� ����(��������)\n";
						std::cout << "���������� �����:\n";
						std::cin.ignore(INT_MAX, '\n');
					}
					goOut = 0;
				//	std::cout << "\n� ������ ��� ���� \n";
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
					std::cout << "\n������ �������� �� ����, ����� ���������!\n";
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
		n = strlen(string);
		printf("������ ����� �������: ");
		for (int i = 0; i < n; i++)     // ������� �� ����������� ����� ���� ��� % 2 == 0
		{
			if (string[i] == ' ')
			{
				if (ind != -1 && arr[ind] % 2 == 0)
				{
					for (int j = 0; j <= ind; j++) {
						if (arr[j] >= '0' && arr[j] <= '9' || arr[j] == '-')
						{
							std::cout << arr[j];
						}
					}
					std::cout << " ";
				}
				ind = -1;
			}
			else
			{
				arr[++ind] = string[i];
			}
		}
		if (ind != -1 && arr[ind] % 2 == 0)           // ������� ��������� ����� ���� ��� % 2 == 0
		{
			for (int j = 0; j <= ind; j++) {
				if (arr[j] >= '0' && arr[j] <= '9' || arr[j] == '-')
				{
					std::cout << arr[j];
				}
			}
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
}