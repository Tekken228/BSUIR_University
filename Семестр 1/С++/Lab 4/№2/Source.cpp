#include <iostream>

int proverka() {
	int a;
	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	while (a <= 0)
	{
		std::cout << "Error" << '\n';
		std::cin >> a;
	}
	return a;
}
int proverka1() {
	int a;
	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	return a;
}


int proverka3()
{
	int a;

	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	}
	while (a < 0 || a > 2)
	{
		std::cout << "Error" << '\n';
		std::cin >> a;
	}
	return a;

}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	std::cout << "���������������� ��� ���������� �������������� ��������� ������ ����� ����� �������� N*M. ����� ����������� ����� ���������, ������� ���� ������� ���������" << '\n';
	std::cout << "��������: ������ ������ ���������(������ 253505)" << '\n';
	std::cout << "������� 10" << '\n';
	std::cout << "������� ���������� ���������(������� ������, ����� �������): ";
	int vibor, n, m;
	int a[100][100]{};
	n = proverka();
	m = proverka();
	std::cout << "������� 1, ����� ������ �������� ������\n������� 2, ����� ������ �������� ����� ������\n������� 0, ����� ��������� ���������\n";
	vibor = proverka3();
	if (vibor == 0)
		exit(0);
	else if (vibor == 1)
	{
		std::cout << "������� �������� �������: ";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = proverka1();
			}
		}
	}
	else if (vibor == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = rand() % 10;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << '\t' << '\n';
	}
	int min = a[1][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (i < m ? i : m); j++)
			if (a[i][j] < min)
				min = a[i][j];
	}
	std::cout << "����������� ������� ���� ������� ���������� : " << min;
	return 0;
}