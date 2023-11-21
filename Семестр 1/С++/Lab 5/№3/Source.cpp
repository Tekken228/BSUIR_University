#include <iostream>


// >0
int naturalCheck()
{
	char arr[10000];
	int b = 0;
	while (true)
	{
		std::cin.getline(arr, 10000);
		while (arr[b] != '\0')
		{
			b++;

		}
		int x = 0;
		for (int i = 0; i < b; i++)
		{
			if (arr[i] >= '0' && arr[i] <= '9')
			{
				x++;
			}
		}
		if (b > 9)
		{
			std::cout << "������������ ����\n��������� ������� " << '\n';
			x = 0; b = 0;
			continue;
		}
		if (arr[0] == '0' || arr[0] == '\0')
		{
			//std::cout << "������������ ����\n��������� ������� " << '\n';
			x = 0; b = 0;
			continue;
		}
		else if (x == b)
		{
			// cout << "b = " << b << "\n" << "x = " << x << "\n";
			return atoi(arr);
		}
		else
		{
			std::cout << "������������ ����\n��������� ������� " << '\n';
			x = 0;
			b = 0;
		}
	}
}

// ����� int
int intCheck()
{
	char arr[10000];
	int b = 0;

	while (true)
	{
		std::cin.getline(arr, 10000);
		while (arr[b] != '\0')
		{
			b++;

		}
		int x = 0;
		for (int i = 0; i < b; i++)
		{
			if (i != 0 && arr[i] == '-' || arr[0] == '-' && arr[1] == '0')
			{
				x = 0;
			}
			if ((arr[i] >= '0' && arr[i] <= '9') || (arr[i] == '-' && arr[i + 1] >= '0' && arr[i + 1] <= '9'))
			{
				x++;
			}
		}
		if (b > 9)
		{
			std::cout << "������������ ����\n��������� ������� " << '\n';
			x = 0; b = 0;
			continue;
		}
		if (arr[0] == '\0')
		{
			std::cout << "������������ ����\n��������� ������� " << '\n';
			x = 0; b = 0;
			continue;
		}
		else if (x == b)
		{
			// cout << "b = " << b << "\n" << "x = " << x << "\n";
			return atoi(arr);
		}
		else
		{
			std::cout << "������������ ����\n��������� ������� " << '\n';
			x = 0;
			b = 0;
		}
	}
}

// �������
double doubleCheck()
{
	char arr[10000];
	int b = 0;
	bool k = false;

	while (true)
	{
		std::cin.getline(arr, 1000);
		while (arr[b] != '\0')
		{
			b++;
			// cout << "b = " << b << "\n";

		}
		if (arr[0] == '\0' || arr[0] == '.')  // �������� �� ������ ��� �����
		{
			std::cout << "������������ ����\n��������� ������� " << '\n';
			b = 0;
			continue;
		}
		if (arr[b - 1] == '.')  //����� � �����.
		{
			std::cout << "������������ ����\n��������� ������� " << '\n';
			b = 0;
			continue;
		}
		if (arr[0] == '0' && arr[1] != '.' && b != 1)  // �����, ������������ � ����, �� ��� �����
		{
			std::cout << "������������ ����\n��������� ������� " << '\n';
			b = 0;
			continue;
		}
		int x = 0;
		for (int i = 0; i < b; i++)   // ���� �� �������� ������ ����� ����� 
		{
			if (arr[i] == '.')
			{
				x++;
			}
		}
		if (x > 1)
		{
			std::cout << "������������ ����\n��������� ������� " << '\n'; // �������� ������ ����� ����� 
			x = b = 0;
			continue;
		}
		int ko = 0;
		for (int i = 0; i < b; i++)
		{
			if (i != 0 && arr[i] == '-' || arr[0] == '-' && arr[1] == '0')
			{
				ko = 0;
			}
			if ((arr[i] >= '0' && arr[i] <= '9' || arr[i] == '.') || (arr[i] == '-' && arr[i + 1] >= '0' && arr[i + 1] <= '9'))
			{
				ko++;
			}
		}
		if (ko != b)  // ���� ���� ������
		{
			std::cout << "������������ ����\n��������� �������" << '\n';
			x = b = ko = 0;
			continue;
		}
		int size = 0;
		for (int i = 0; i < b; i++)    // ��� ���������� �����
		{
			if (arr[i] == '.')
			{
				k = true;
				arr[i] = ',';
				break;
			}
			size++;
		}
		if (size > 200)    // ���� ������ ������� ���
		{
			std::cout << "������������ ����\n��������� �������" << '\n';
			x = b = ko = size = 0;
			continue;
		}
		int qwe;
		for (int as = size + 1; as < b; as++)  // ������ ������� ����� �����
		{
			if (k)
			{
				qwe = as;
				std::cout.precision(qwe);
			}
		}

		return  atof(arr); // ������� atof() ����������� ������ � �������� ���� double. 
	}
}

long long amount(long long** arr, long long n, long long k, long long amount)
{
	for (int i = 0, j = 0; i < n && j < k; i++, j++)
	{
		if (arr[i][j] % 2 == 0)
		{
			amount++;
		}
	}
	return amount;
}
long long** massive(long long n, long long k)
{
	long long** arr = new long long* [n];
	for (long long i = 0; i < n; i++)
		arr[i] = new long long[k];

	for (long long i = 0; i < n; i++)
		for (long long j = 0; j < k; j++)
			arr[i][j] = intCheck();

	return arr;

}
void iznachalniy(long long** arr, long long n, long long k)
{
	printf("����������� ������\n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		printf("\n");
	}
}
long long* noviy_mass(long long** arr, long long n, long long k)
{
	long long* mas = new long long[n];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (i == j && arr[i][j] % 2 == 0)
			{
				count++;
				mas[i] = arr[i][j];
			}
		}
	}
	if (count == 0)
	{
		std::cout << "�� ������� ��������� ��� ������ �����";
		return 0;
	}
	std::cout << "������ ����� �� ������� ���������: ";
	long long x = 1;
	for (int i = 0; i < count; i++)
	{
		if (mas[i] % 2 != 0)
		{
			count++;
			continue;
		}
		x *= mas[i];
		std::cout << mas[i] << " ";
	}

	std::cout << '\n' << "������������ �����: " << x;
	return mas;
}
void destroyer(long long** arr, long long n)
{
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
void destroyer1(long long* mas)
{
	delete[] mas;
}

int main()
{
	setlocale(LC_ALL, "ru");
	printf("������� ������������ ������ �� ���������, ������������� �� ������� ��������� ������� � ������� ������ ��������.\n��������� ������������ ��������� ������������� �������. ��������� ������ � ��������� ������������ ������� �� �����.\n");
	printf("��������: ������ ������ ���������(������ 253505)\n");
	int x = 1;
	while (x == 1)
	{
		printf("������� ���������� ���������(������� ������, ����� �������): ");
		long long** arr;
		long long* mas;
		long long n, k;
		n = naturalCheck();
		k = naturalCheck();
		printf("������� �������� �������\n");
		arr = massive(n, k);
		iznachalniy(arr, n, k);
		printf("\n");
		mas = noviy_mass(arr, n, k);
		printf("\n");
		destroyer(arr, n);
		destroyer1(mas);
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
