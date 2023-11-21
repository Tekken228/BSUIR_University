#include <iostream>


extern "C" __declspec(dllexport) long long proverka()
{
	long long a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
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
extern "C" __declspec(dllexport) long long proverka1()
{
	long double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
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
extern "C" __declspec(dllexport) void privetstvie()
{
	printf("��� ��������� ����������� ������� B �� N ��������� ����� ���������� ��������� �������, ��� ������� ����������� �������\n(cosBi2>0)^(Bi<0). ����������� ������� ��������� ������ ��� �������� ��� ������ ����� ������� � ��� ��������� ����� (2/3) �������. ����������� ������ �����������, ����� ��������� ������ ���� ��� ��� ��������.\n");
	printf("��������: ������ ������ ���������(������ 253505)\n");
	printf("������� ���������� ��������� �������: ");
}
extern "C" __declspec(dllexport) long double* massive(long double* arr, long long N)
{
	printf("������� �������� �������: ");

	for (int i = 0; i < N; i++)
		arr[i] = proverka1();

	return arr;

}
extern "C" __declspec(dllexport) void iznachalniy(long double* arr, long long N)
{
	printf("����������� ������\n\n");
	for (int i = 0; i < N; i++)
	{
		//	arr[i] = -rand();
		std::cout << arr[i] << " ";
	}
	printf("\n");

}
extern "C" __declspec(dllexport) long double summa(long long i, long double* arr, long long num)
{
	if (i == num - 1)
	{
		return 0;
	}
	else
	{
		if (cos(arr[i] * arr[i]) > 0 && arr[i] < 0)
		{
			return summa(i + 1, arr, num) + 1;
		}
		else
		{
			return summa(i + 1, arr, num);
		}
	}
}
extern "C" __declspec(dllexport) void other(long double* arr, long long N)
{
	long long sum1 = 0, sum2 = 0, T;
	T = N / 3;
	if (N < 3)
	{
		sum1 = summa(0, arr, N);
		std::cout << "\n����������: " << sum1;
	}
	else
	{

		sum1 = summa(0, arr, T);
		sum2 = summa(T + 1, arr, N);
		std::cout << '\n';
		std::cout << "\n����������: " << sum1 + sum2;
	}
}
extern "C" __declspec(dllexport) void destroyer(long double* arr)
{
	delete[] arr;
}