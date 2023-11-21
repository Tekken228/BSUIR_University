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
long double proverka1() {
	long double a;
	while (true) {
		std::cin >> a;
		if (std::cin.peek() == '\n')
			break;
		std::cout << "Error" << '\n';
		std::cin.clear();
		std::cin.ignore(50000, '\n');

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
	setlocale(LC_ALL, "ru");
	int n, vibor{};
	srand(time(NULL));
	std::cout << "������ ���������� �������������� ������ �� n ��������� � ����������, ����������� �� ��, �� ���� �������� �� �� ������ ������ � ����� �������" << '\n';
	std::cout << "��������: ������ ������ ���������(������ 253505)" << '\n';
	std::cout << "������� 10" << '\n';
	std::cout << "������� ���������� ��������� ";
	n = proverka();
	double a[1000]{};
	std::cout << "������� 1, ����� ������ �������� ������\n������� 2, ����� ������ �������� ����� ������\n������� 0, ����� ��������� ���������\n";
	vibor = proverka3();
	if (vibor == 0)
		exit(0);
	else if (vibor == 1)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << "������� a[" << i << "]: ";
			a[i] = proverka1();
		}
	}
	else if (vibor == 2)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 10;
		}
	}

	for (int j = 0; j < n; j++)
	{
		std::cout << "a[" << j << "]: " << a[j] << '\n';
	}
	for (int i = 0; i < (n / 2); i++)
		if (a[i] != a[n - i - 1])
		{
			std::cout << "�� �������� ������������" << '\n';
			return 0;
		}
	std::cout << "�������� ������������" << '\n';
	return 0;
}