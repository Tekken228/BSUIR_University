#include <iostream> 

int main()
{
	setlocale(LC_ALL, "ru");
	printf("������ ������ �����. ��� ������ ������ ���������, �������� ��� ����������� ��� ���.\n");
	printf("��������: ������ ������ ���������(������ 253505)\n");
	while (true)
	{
		char str[81][81]{}, str2[81][81]{};
		long long i, t, j, n, k = 0, count[100]{}, N[255]{};
		std::cout << "������� ������ ����� ENTER, ����� ��������� �������, ������� ������ ENTER: ";
		for (t = 0; t < 81; t++)
		{
			gets_s(str[t]);
			if (!*str[t])
			{
				break;
			}
		}
		for (int i = 0; i < t; i++)
		{
			n = strlen(str[i]);
			for (int k = 0; k < n; k++)
			{
				if (str[i][k] == ' ')
				{
					continue;
				}
				else
				{
					str2[i][k] = str[i][k];
				}
			}
		}
		for (int i = 0; i < t; i++)
		{
			N[i] = strlen(str[i]);
			count[i] = 0;
			for (int j = 0; j < N[i]; j++)
			{
				if (str2[i][j] == str2[i][N[i] - j - 1])
				{
					count[i]++;
				}

			}
		}
		for (int i = 0; i < t; i++)
		{
			std::cout << "������ " << (i + 1);
			if (count[i] == N[i])
			{
				std::cout << " ��� ���������\n";
			}
			else
			{
				std::cout << " ��� �� ���������\n";
			}
		}
		printf("\n��������� ��������� �� �����? (0 - ���, ����� ����� - ��): ");
		/*
		while (!(std::cin >> x) || (std::cin.peek() != '\n') || (x != 0 && x != 1))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			{
				printf("������������ ����\n");
				printf("���������� �����: ");
			}
		}
		*/
		gets_s(str[0]);
		std::cout << '\n';
		if (str[0][0] == '0' && str[0][1] == '\0')
		{
			break;
		}
	}

	return 0;
}