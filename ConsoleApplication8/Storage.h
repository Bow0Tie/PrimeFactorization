#include <iostream>
#include "BinaryTree.h"
using namespace std;
const int MAX_RAZLOJENIY(100); //Максимальное количество чисел которые можно добавить в ручную

template <class T> class Storage 
{
public:

	BinaryTree<T> treeOfprimes;
	Storage() {}
	~Storage() {}

	void take(int num, T obj) { // Добавление элемента
		treeOfprimes.insert(num, obj);
	}

	void dell(int num) { // Удаление элемента
		treeOfprimes.deleteElem(num); 
	}
	
	void showAll() { // Вывод всех элементов
		treeOfprimes.printAll();
	}

	void show(int num) { // Вывести конкретный элемент
		T data = treeOfprimes.find(num);
		cout << data << endl;
	}

	void sum(int num1, int num2) { // Сложение двух элементов
		T data1 = treeOfprimes.find(num1);
		T data2 = treeOfprimes.find(num2);
		T data3 = data1 + data2;
		cout << data1.multiplication() << " + " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl;
	}

	void vich(int num1, int num2) { // Вычитание двух элементов
		T data1 = treeOfprimes.find(num1);
		T data2 = treeOfprimes.find(num2);
		T data3 = data1 - data2;
		if (data3.multiplication() != 1)
		{
			cout << data1.multiplication() << " - " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl;
		}
		else
		{
			cout << data1.multiplication() << " - " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl << "Возможно число полученное в результате операции не поддаается разложению ( отрицательно или равно 0 )" << endl;
		}
	}

	void ymn(int num1, int num2) { // Умножение двух элементов
		T data1 = treeOfprimes.find(num1);
		T data2 = treeOfprimes.find(num2);
		T data3 = data1 * data2;
		if (data3.multiplication() != 1)
		{
			cout << data1.multiplication() << " * " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl;
		}
		else
		{
			cout << data1.multiplication() << " * " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl << "Возможно число полученное в результате операции не поддаается разложению ( отрицательно или равно 0 )" << endl;
		}
	}

	void del(int num1, int num2) { // Деление двух элементов
		T data1 = treeOfprimes.find(num1);
		T data2 = treeOfprimes.find(num2);
		T data3 = data1 / data2;
		if (data3.multiplication() != 1)
		{
			cout << data1.multiplication() << " / " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl;
		}
		else
		{
			cout << data1.multiplication() << " / " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl << "Возможно число полученное в результате операции не поддаается разложению ( отрицательно или равно 0 )" << endl;
		}
	}

	void save(int num_pack[MAX_RAZLOJENIY], int primeCount) { // Сохранение в файл
		T data;
		ofstream fiel("c:\\Users\\Ivan\\Desktop\\123\\Tut.txt");
		if (fiel.is_open())
		{
			for (int i = 0; i < primeCount; i++) {
				data = treeOfprimes.find(num_pack[i]);
				fiel << num_pack[i] << " " << data;
			}
		}
		
	}

	void read() { // Чтение из файла
		ifstream fiel("c:\\Users\\Ivan\\Desktop\\123\\Tut.txt");
		if (fiel.is_open())
		{
			int num;
			T data;
			while (fiel >> num >> data)
			{
				treeOfprimes.insert(num, data);
			}
		}
		
	}

	void createMnogo(int kolvo) { // Создание нескольких элементов
		for (int i = 0; i < kolvo; i++) {
			int rnum = rand();
			int rchislo = rand();
			take(rnum, IntegerAsPrimes::IntegerAsPrimes(rchislo));
		}
	}
};