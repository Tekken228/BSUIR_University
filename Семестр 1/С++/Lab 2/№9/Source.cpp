#include <iostream>
#include <cmath>

int main() {
	setlocale(LC_ALL, "ru");
	long double a, b, z, y, x, f;

	std::cout << "������� �, b, z" << '\n';
	std::cin >> a >> b >> z;
	int fuctrion;
	std::cout << "������� �������" << '\n';
	std::cin >> fuctrion;
	switch (fuctrion) {
	case 1:
		std::cout << "������ f(x) = 2x" << '\n';
		if (z < -1) {
			std::cout << "��� z < -1 �����" << '\n';
			x = -z / 3;
			f = 2 * x;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		else {
			std::cout << "��� z >= -1 �����" << '\n';
			x = fabs(z);
			f = 2 * x;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		break;
	case 2:
		std::cout << "������ f(x) = x^3" << '\n';
		if (z < -1) {
			std::cout << "��� z < -1 �����" << '\n';
			x = -z / 3;
			f = x * x * x;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		else {
			std::cout << "��� z >= -1 �����" << '\n';
			x = fabs(z);
			f = x * x * x;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		break;
	case 3:
		std::cout << "������ f(x) = x/3" << '\n';
		if (z < -1) {
			std::cout << "��� z < -1 �����" << '\n';
			x = -z / 3;
			f = x / 3;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		else {
			std::cout << "��� z >= -1 �����" << '\n';
			x = fabs(z);
			f = x / 3;
			y = a * f - log(x + 2.5) + b * (exp(x) - exp(-x));
			std::cout << y;
			return 0;
		}
		break;
	default:
		std::cout << "�������� ����";
		break;
	}

	return 0;
}