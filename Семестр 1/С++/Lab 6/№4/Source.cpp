#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "������� ����������� �����\n";
	cout << "��������: ������ ������ (������ 253505)\n";
	std::string povtor;
	do
	{
		string mainstring, dopstring;
		cout << "������� �����: ";
		while (true)
		{
			getline(cin, mainstring);
			if ((mainstring[0] == '\n') || (mainstring[0] == '\0'))
			{
				break;
			}
			std::cout << "����� ��: " << mainstring;
			string str = "ksKsfFzZuUiI";
			long long size = mainstring.size();
			for (int i = 0; i < size; i++)
			{
				// ������ � ����� e, i, y � � ������ �������
				dopstring = mainstring[i];

				if (mainstring[i] == 'c')
				{
					if (mainstring[i + 1] == 'e' || mainstring[i + 1] == 'i' || mainstring[i + 1] == 'y' || mainstring[i + 1] == 'E' || mainstring[i + 1] == 'I' || mainstring[i + 1] == 'Y')
					{
						mainstring[i] = 's';
					}
					else
					{
						mainstring[i] = 'k';
					}
				}

				// ������ �
				if (mainstring[i] == 'C')
				{
					if (mainstring[i + 1] == 'e' || mainstring[i + 1] == 'i' || mainstring[i + 1] == 'y' || mainstring[i + 1] == 'E' || mainstring[i + 1] == 'I' || mainstring[i + 1] == 'Y')
					{
						mainstring[i] = 'S';
					}
					else
					{
						mainstring[i] = 'K';
					}
				}

				// ������ q �� k, � qu �� kv
				if (mainstring[i] == 'q')
				{
					if (mainstring[i + 1] == 'u' || mainstring[i + 1] == 'U')
					{
						mainstring[i] = 'k';
						mainstring[i + 1] = 'v';
					}
					else if (mainstring[i + 1] != 'u')
					{
						mainstring[i] = 'k';
					}
				}

				// ������ Q �� �
				if (mainstring[i] == 'Q')
				{
					if (mainstring[i + 1] == 'u')
					{
						mainstring[i] = 'K';
						mainstring[i + 1] = 'v';
					}
					else if (mainstring[i + 1] == 'U')
					{
						mainstring[i] = 'K';
						mainstring[i + 1] = 'V';
					}
					else if (mainstring[i + 1] != 'u' || mainstring[i + 1] != 'U')
					{
						mainstring[i] = 'K';
					}
				}

				// ������ x �� ks
				if (mainstring[i] == 'x')
				{
					size++;
					mainstring.insert(i + 1, str, 0, 2);
					mainstring.erase(i, 1);
				}

				// ������ � �� KS
				else if (mainstring[i] == 'X')
				{
					size++;
					mainstring.insert(i + 1, str, 2, 2);
					mainstring.erase(i, 1);
				}

				// ������ w �� v
				if (mainstring[i] == 'w')
				{
					mainstring[i] = 'v';
				}

				// ������ X �� V
				if (mainstring[i] == 'X')
				{
					mainstring[i] = 'V';
				}


				// th �� z
				if (mainstring[i] == 't' && mainstring[i + 1] == 'h' || mainstring[i] == 't' && mainstring[i + 1] == 'H')
				{
					size--;
					mainstring.insert(i + 2, str, 6, 1);
					mainstring.erase(i, 2);
				}

				// TH �� Z
				if (mainstring[i] == 'T' && mainstring[i + 1] == 'H' || mainstring[i] == 'T' && mainstring[i + 1] == 'h')
				{
					size--;
					mainstring.insert(i + 2, str, 7, 1);
					mainstring.erase(i, 2);
				}

				// ph �� f
				if (mainstring[i] == 'p' && mainstring[i + 1] == 'h' || mainstring[i] == 'p' && mainstring[i + 1] == 'H')
				{
					size--;
					mainstring.insert(i + 2, str, 4, 1);
					mainstring.erase(i, 2);
				}

				// PH �� F
				if (mainstring[i] == 'P' && mainstring[i + 1] == 'H' || mainstring[i] == 'P' && mainstring[i + 1] == 'h')
				{
					size--;
					mainstring.insert(i + 2, str, 5, 1);
					mainstring.erase(i, 2);
				}

				// you � oo �� u
				if (mainstring[i] == 'y' && mainstring[i + 1] == 'o' && mainstring[i + 2] == 'u' || mainstring[i] == 'o' && mainstring[i + 1] == 'o')
				{
					if (mainstring[i] == 'y' && mainstring[i + 1] == 'o' && mainstring[i + 2] == 'u')
					{
						size -= 2;
						mainstring.insert(i + 3, str, 8, 1);
						mainstring.erase(i, 3);
					}
					else
					{
						size--;
						mainstring.insert(i + 2, str, 8, 1);
						mainstring.erase(i, 2);
					}
				}

				// YOU � OO �� U
				if (mainstring[i] == 'Y' && mainstring[i + 1] == 'O' && mainstring[i + 2] == 'U' || mainstring[i] == 'O' && mainstring[i + 1] == 'O')
				{
					if (mainstring[i] == 'Y' && mainstring[i + 1] == 'O' && mainstring[i + 2] == 'U' || mainstring[i] == 'Y' && mainstring[i + 1] == 'o' && mainstring[i + 2] == 'u')
					{
						size -= 2;
						mainstring.insert(i + 3, str, 9, 1);
						mainstring.erase(i, 3);
					}
					else
					{
						size--;
						mainstring.insert(i + 2, str, 9, 1);
						mainstring.erase(i, 2);
					}
				}

				// ee �� i
				if (mainstring[i] == 'e' && mainstring[i + 1] == 'e' || mainstring[i] == 'e' && mainstring[i + 1] == 'E')
				{
					size--;
					mainstring.insert(i + 2, str, 10, 1);
					mainstring.erase(i, 2);
				}

				// EE �� I
				if (mainstring[i] == 'E' && mainstring[i + 1] == 'E' || mainstring[i] == 'E' && mainstring[i + 1] == 'e')
				{
					size--;
					mainstring.insert(i + 2, str, 10, 1);
					mainstring.erase(i, 2);
				}
			}
			string str1 = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxZz";	
			int length = mainstring.size();
			for (int i = 0; i < length; i++) {
				int a = 0, b = i + 1;
				while ((int)mainstring[i] == (int)mainstring[b] || (int)mainstring[i] == (int)mainstring[b] - 32 || (int)mainstring[i] - 32 == (int)mainstring[b]) 
				{
					a++;
					b++;
				}
				if (a) {
					mainstring.replace(i, a + 1, 1, mainstring[i]);
					length -= a;
				}
			}
			std::cout << "\n����� �����: " << mainstring << "\n";
			std::cout << "��� ���������� ����� �������� ������� ��� ������,��� ������ ������� 0: ";
			std::cin >> povtor;
			if (povtor == "0")
			{
				return 0;
			}
		}
	} while (povtor != "0");

	return 0;
}




//ThthththththththththththththththThtH





/*
			int povtorenie{};
			do
			{
				povtorenie = 0;
				int length = mainstring.size();
				for (int j = 0; j < length; j++)
				{
					if (mainstring[j] == 'a' || mainstring[j] == 'A' || mainstring[j] == 'E' || mainstring[j] == 'e' || mainstring[j] == 'o' || mainstring[j] == 'O' || mainstring[j] == 'i' || mainstring[j] == 'I' || mainstring[j] == 'y' || mainstring[j] == 'Y' || mainstring[j] == 'u' || mainstring[j] == 'U')
					{
						break;
					}
					if ((str1.find(mainstring) == string::npos) && (toupper(mainstring[j]) == toupper(mainstring[j + 1])))
					{
						(mainstring).erase(j + 1, 1);
						j--;
						length--;
						povtorenie = 1;
					}
				}
			} while (povtorenie == 1);
			*/