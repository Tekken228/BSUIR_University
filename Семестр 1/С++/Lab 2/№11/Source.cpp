#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	long double R, P, r, Q, S, Q;
	std::cout << "������� ������ ����, ������� �����, ��� ����" << '\n';
	std::cin >> R >> P >> Q;
	if (R <= 0 || P <= 0 || sin(Q) == 1.0 || 0 >= sin(Q) ) {
		std::cout << "������ �����";
		return 0;
	}
	S = P * P * sin(Q);
	r = S / 2 * P;
	if (r >= R)
		std::cout << "������";
	else
		std::cout << "�� ������";

	return 0;
}