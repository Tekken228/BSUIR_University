#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	long double x1, y1, r, x2, y2, R, L;
	std::cout << "������� ����� ����� M1(x1; y2) � ��� ������" << '\n';
	std::cin >> x1 >> y1 >> r;
	if (r <= 0) {
		std::cout << "������ �����";
		return 0;
	}
	std::cout << "������� ����� ����� M2(x2; y2) � ��� ������" << '\n';
	std::cin >> x2 >> y2 >> R;
	if (R <= 0) {
		std::cout << "������ �����";
		return 0;
	}
	L = sqrtl(powl(x1 - x2, 2) + powl(y1 - y2, 2));
	if (R >= L + r) {
		std::cout << "��";
		return 0;
	}
	else if (r >= L + R) {
		std::cout << "��, �� ����������� �������� ��� ���� �����";
		return 0;
	}
	else if (L <= R + r) {
		std::cout << "������ ������������";
		return 0;
	}
	else {
		std::cout << "�� ���� ������� �� ���������";
		return 0;
	}
	return 0;
}