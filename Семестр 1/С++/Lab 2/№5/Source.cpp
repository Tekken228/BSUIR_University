#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	long double K, X, Y;
	cin >> K >> X >> Y;
	cout << setprecision(22);
	if (K > 0) {
		if (X <= K && X > 0 && Y > K) {         // ������ ����
			cout << fabs(Y - K);
			return 0;
		}
		else if (X <= K && X > 0 && Y < 0) {        // ����� �����
			cout << fabs(Y);
			return 0;
		}
		else if (X == K && Y == K or X == 0 && Y == 0) { // �� ��������
			cout << "0";
			return 0;
		}
		else if (X <= K && X < 0 && Y > 0) {            // ����� �������
			cout << fabs(X);
			return 0;
		}
		else if (X >= K && Y <= K && Y > 0) {  // ������ �����
			cout << fabs(X - K);
			return 0;
		}
		else if (X == 0 && Y > 0 && Y > K) {   // ������ ����
			cout << Y - K;
			return 0;
		}
		else if (X == 0 && Y < 0 && Y < K) {            // ����� �����
			cout << fabs(Y);
			return 0;
		}
		else if (X > K && X > 0 && Y > K && Y > 0) {     // ������� ������ �����   FDFDFFDFFD
			cout << sqrt((X - K) * (X - K) + (Y - K) * (Y - K));
			return 0;
		}
		else if (X > K && X > 0 && Y < K && Y < 0) {    // ������� ������ ����
			cout << sqrt((X - K) * (X - K) + Y * Y);
			return 0;
		}
		else if (X < K && X < 0 && Y < K && Y < 0) {    // ������� ����� �����
			cout << sqrt(X * X + Y * Y);
			return 0;
		}
		else if (X < K && X < 0 && Y > K && Y > 0) {    // ������� ������ �����
			cout << sqrt(X * X + (Y - K) * (Y - K));
			return 0;
		}
		else if (X < K && Y < K && X > 0 && Y > 0 && ((K - X == 1) || (K - Y == 1))) {  // ������
			cout << "1";
			return 0;
		}

		else if (X < K && Y < K && X > 0 && Y > 0 && (K - X) < (K - Y)) {  // ������
			cout << Y;
			return 0;
		}
		else if (X < K && Y < K && X > 0 && Y > 0 && (K - Y) < (K - X)) {  // ������
			cout << X;
			return 0;
		}
		else if (X == 0 && Y <= K && Y > 0) {  // ������
			cout << "0";
			return 0;
		}
		else if (Y == 0 && X <= K && X > 0) {  // ������
			cout << "0";
			return 0;
		}

	}


	if (K < 0) {

		if (X < 0 && Y > 0 && X >= K) {         // ������ ����
			cout << fabs(Y);
			return 0;
		}
		else if (X < 0 && Y < 0 && X >= K && Y < K) {        // ����� �����
			cout << fabs(Y - K);
			return 0;
		}
		else if (X == K && Y == K or X == 0 && Y == 0) { // �� ��������
			cout << "0";
			return 0;
		}
		else if (X < 0 && Y < 0 && Y >= K && X < K) {            // ����� �������
			cout << fabs(X - K);
			return 0;
		}
		else if (X > 0 && Y < 0 && Y >= K) {  // ������ �����
			cout << fabs(X);
			return 0;
		}
		else if (X > 0 && Y > 0 && Y > K && Y > 0) {     // ������� ������ �����
			cout << sqrt(X * X + Y * Y);
			return 0;
		}
		else if (X > 0 && Y < 0 && Y < K) {    // ������� ������ ����
			cout << sqrt(X * X + (Y - K) * (Y - K));
			return 0;
		}
		else if (X < 0 && Y < 0 && X < K && Y < K) {    // ������� ����� �����
			cout << sqrt((X - K) * (X - K) + (Y - K) * (Y - K));
			return 0;
		}
		else if (X < 0 && Y > 0 && X < K) {    // ������� ������ �����
			cout << sqrt((X - K) * (X - K) + Y * Y);
			return 0;
		}
		else if (X == 0 && Y < K && Y < 0) {  // C���� �����
			cout << fabs(Y - K);
			return 0;
		}
		else if (X == 0 && Y > 0) {       // C����� ����
			cout << Y;
			return 0;
		}
		else if (Y == 0 && X < K && X < 0) {   // ����� �����
			cout << fabs(X - K);
			return 0;
		}
		else if (Y == 0 && X > 0) {  // ������ �����
			cout << X;
			return 0;
		}
		else if (X > K && Y > K && X < 0 && Y < 0 && ((-K - X == 1) || (-K - Y == 1))) {  // ������
			cout << "1";
			return 0;
		}
		else if (X > K && Y > K && X < 0 && Y < 0 && fabs(X - K) < fabs(Y - K)) {  // ������
			cout << fabs(X - K);
			return 0;
		}
		else if (X > K && Y > K && X < 0 && Y < 0 && fabs(Y - K) < fabs(X - K)) {  // ������
			cout << fabs(Y - K);
			return 0;
		}
		else if (X == 0 && Y >= K && Y < 0) {  // ������
			cout << "0";
			return 0;
		}
		else if (Y == 0 && X >= K && X < 0) {  // ������
			cout << 0;
		}

	}

	return 0;
}