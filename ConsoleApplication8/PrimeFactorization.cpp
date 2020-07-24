// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <fstream>
#include "Storage.h"
#include <cstring>
using namespace std;
class IntegerAsPrimes
{
public:
	IntegerAsPrimes();
	~IntegerAsPrimes();
	int *primes = (int*)malloc(sizeof(int[1]));
	int size = sizeof(int[1]);
	int length = size / sizeof(primes[0]);

	void resize() {
		size = size + sizeof(int[1]);
		primes = (int *)realloc(primes, size);
		length = size / sizeof(primes[0]);
	}

	IntegerAsPrimes(int num) // Конструктор с параметрами
	{
		if (num > 0)
		{
			int i = 2;
			int j = 0;
			while (num != 1)
			{	
				if ((num % i) == 0 ) {
					num = num / i;
					j++;
					if (j == length) {
						resize();
						primes[j-1] = i;
					}
					else {
						primes[j] = i;
					}
				}
				else
				{
					i++;
				}
			}
			cout << "constrsparam" << endl;
			cout << "Number of element:" << this << endl;
		}
		else {
			cout << "Ноль(" << endl;
		}
		
	}

	IntegerAsPrimes(const IntegerAsPrimes &obj) // Конструктор копирования
	{
		primes = obj.primes;
		size = obj.size;
		length = obj.length;
		cout << "constrcopir" << endl;
		cout << "Number of element:" << this << endl;
		
	}

	IntegerAsPrimes operator + (IntegerAsPrimes &c2) { // Переопределение оператора +
		int a = multiplication();
		int b = c2.multiplication();
		int c = a + b;
		IntegerAsPrimes returned;
		returned.fill(c);
		return returned;
	}

	IntegerAsPrimes operator - (IntegerAsPrimes &c2) { // Переопределение оператора -
		int a = multiplication();
		int b = c2.multiplication();
		int c = a - b;
		IntegerAsPrimes returned;
		returned.fill(c);
		return returned;
	}

	IntegerAsPrimes operator / (IntegerAsPrimes &c2) { // Переопределение оператора /
		int a = multiplication();
		int b = c2.multiplication();
		int c = a / b;
		IntegerAsPrimes returned;
		returned.fill(c);
		return returned;
	}

	IntegerAsPrimes operator * (IntegerAsPrimes &c2) { // Переопределение оператора *
		int a = multiplication();
		int b = c2.multiplication();
		int c = a * b;
		IntegerAsPrimes returned;
		returned.fill(c);
		return returned;
	}

	

	friend ostream& operator << (ostream &out, IntegerAsPrimes &c1) { // Переопределение оператора вывода
		int i = 0;
		out << c1.size << " " << c1.length << "";
		out << "";
		while (i != c1.length - 1)
		{
			out << " " << c1.primes[i];
			i++;
		}
		out << "" << endl;
		return out;
	}

	friend istream& operator >> (istream &in, IntegerAsPrimes &c1) { // Переопределение оператора ввода
		int i = 0;
		in >> c1.size >> c1.length;
		c1.primes = (int *)realloc(c1.primes, c1.size);
		while (i != c1.length - 1)
		{
			in >> c1.primes[i];
			i++;
		}
		return in;
	}


	int multiplication() { // Перемножение простых множителей
		int i = 0;
		int mult = 1;
		while (i != length - 1)
		{
			mult = mult * primes[i];
			i++;
		}
		return mult;
	}
private:
	void fill(int num) { // Заполнение полей класса
		int i = 2;
		int j = 0;
		if (num > 0) {
			while (num != 1)
			{
				if ((num % i) == 0) {
					num = num / i;
					j++;
					if (j == length) {
						resize();
						primes[j - 1] = i;
					}
					else {
						primes[j] = i;
					}
				}
				else
				{
					i++;
				}
			}
		}
		else {
			cout << "Ноль(" << endl;
		}
	}
};

IntegerAsPrimes::IntegerAsPrimes() // Конструктор поумолчанию
{
	cout << "constrpoumolch" << endl;
	cout << "Number of element:" << this << endl;
}

IntegerAsPrimes::~IntegerAsPrimes() // Деструктор
{
	cout << "destr" << endl;
	cout << "Number of element:" << this << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Storage<IntegerAsPrimes> storage1;
	int input;
	int primeCount = 0;
	int num_pack[MAX_RAZLOJENIY];
	bool end = true;
	cout << "1. Создать разложение\n";
	cout << "2. Вывести все разложения\n";
	cout << "3. Вывести конкретное разложение\n";
	cout << "4. Exit\n";
	cout << "5. +\n";
	cout << "6. -\n";
	cout << "7. /\n";
	cout << "8. *\n";
	cout << "9. Сохранить\n";
	cout << "0. Загрузить\n";
	cout << "10. Удалить разложение\n";
	cout << "11. Создать n рандомных разложений\n";
	while (end) {
		cout << "Selection: ";
		cin >> input;
		switch (input) {
		case 1:
			int num1;
			int chislo;
			cout << "Номер разложения: ";
			cin >> num1;
			cout << "Число для разложения: ";
			cin >> chislo;
			if (chislo > 0) {
				storage1.take(num1, IntegerAsPrimes(chislo));
			}
			else
			{
				cout << "Ничего не добавленно" << endl;
			}
			num_pack[primeCount] = num1;
			primeCount++;
			break;
		case 2:
			cout << "Формат вывода: " << endl << "Index: Номер разложения" << endl << "Element: Первое число - size Второе число - length Все последующие числа - простые множетили." << endl << endl;
			storage1.showAll();
			break;
		case 3:
			int num3;
			cout << "Номер разложения: ";
			cin >> num3;
			storage1.show(num3);
			break;
		case 4:
			end = false;
			break;
		case 5:
			int firs5;
			int second5;
			cout << "Номер разложения1: ";
			cin >> firs5;
			cout << "Номер разложения2: ";
			cin >> second5;
			storage1.sum(firs5, second5);
			break;
		case 6:
			int firs6;
			int second6;
			cout << "Номер разложения1: ";
			cin >> firs6;
			cout << "Номер разложения2: ";
			cin >> second6;
			storage1.vich(firs6, second6);
			break;
		case 7:
			int firs7;
			int second7;
			cout << "Номер разложения1: ";
			cin >> firs7;
			cout << "Номер разложения2: ";
			cin >> second7;
			storage1.del(firs7, second7);
			break;
		case 8:
			int firs8;
			int second8;
			cout << "Номер разложения1: ";
			cin >> firs8;
			cout << "Номер разложения2: ";
			cin >> second8;
			storage1.ymn(firs8, second8);
			break;
		case 9:
			if (primeCount != 0) {
				storage1.save(num_pack, primeCount);
			}
			else {
				cout << "Сохранение возможно только для разложений созданных в ручную" << endl;
			}
			break;
		case 0:
			storage1.read();
			break;
		case 10:
			int num10;
			cout << "Номер разложения: ";
			cin >> num10;
			storage1.dell(num10);
			break;
		case 11:
			int kolvoRazlojeni;
			cout << "Сколько разложений создать? ";
			cin >> kolvoRazlojeni;
			storage1.createMnogo(kolvoRazlojeni);
			break;
		default:
			cout << "Error, bad input\n";
			break;
		}
	}
} 