

#include <iostream>

using namespace std;
int main() {
	setlocale(0, "Russian");
	int intData;
	short shortData;
	long longData;
	float floatData;
	double doubleData;
	long double longDoubleData;
	char charData;
	bool boolData;
	
	cout << "Задание 1:\n";
	cout << sizeof(intData) << " " << sizeof(shortData) << " " << sizeof(longData)
		<< " " << sizeof(floatData) << " " << sizeof(doubleData) << " " << sizeof(longDoubleData) << " " << sizeof(floatData)
		<< " " << sizeof(charData) << " " << sizeof(boolData) << '\n';


	int intValue;
	cout << "Введите целое число: \n"
	cin >> intValue;
	int order_int = sizeof(int) * 8;
	unsigned int mask_int = 1 << (order_int - 1);

	cout << "Двоичное представление числа: ";
	for (int i = 0; i < order_int; i++) {
		if (intValue & (mask_int >> i)) {
			cout << "1";
		}
		else {
			cout << "0";
		}
		if (i == 0) {
			cout << " ";
		}
	}
	cout << "\n";

	float floatValue;
	cout << "Введите вещественное число: \n"
	cin >> floatValue;

	union {
		float floatUnion;
		unsigned int intUnion;
	} convertionFloat;

	convertionFloat.floatUnion = floatValue;
	int order_float = sizeof(float) * 8;
	unsigned int mask_float = 1 << (order_float - 1);
	cout << "Двоичное представление числа: ";
	for (int i = 0; i < order_float; i++) {
		if (convertionFloat.intUnion & (mask_float >> i)) {
			cout << "1";
		}
		else {
			cout << "0";
		}
		if (i == 0 || i == 8) {
			cout << " ";
		}

	}
	cout << "\n";

	double doubleValue;
	cout << "Введите число double: \n"
	cin >> doubleValue;

	union {
		double doubleElement;
		unsigned int partOfDouble[2];
	} divOfDouble;


	divOfDouble.doubleElement = doubleValue;
	int order_double = sizeof(double) * 8;
	unsigned int mask_double = 1 << (order_double - 1);
	cout << "Двоичное представление числа: ";
	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < order_double/2; j++) {
			if (divOfDouble.partOfDouble[i] & (mask_double >> j)) {
				cout << "1";
			}
			else {
				cout << "0";
			}
			if ((j == 0 || j == 11)&&(i == 1)){
				cout << " ";
			}
		}
	} 

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
