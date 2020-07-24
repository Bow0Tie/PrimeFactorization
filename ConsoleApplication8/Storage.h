#include <iostream>
#include "BinaryTree.h"
using namespace std;
const int MAX_RAZLOJENIY(100); //������������ ���������� ����� ������� ����� �������� � ������

template <class T> class Storage 
{
public:

	BinaryTree<T> treeOfprimes;
	Storage() {}
	~Storage() {}

	void take(int num, T obj) { // ���������� ��������
		treeOfprimes.insert(num, obj);
	}

	void dell(int num) { // �������� ��������
		treeOfprimes.deleteElem(num); 
	}
	
	void showAll() { // ����� ���� ���������
		treeOfprimes.printAll();
	}

	void show(int num) { // ������� ���������� �������
		T data = treeOfprimes.find(num);
		cout << data << endl;
	}

	void sum(int num1, int num2) { // �������� ���� ���������
		T data1 = treeOfprimes.find(num1);
		T data2 = treeOfprimes.find(num2);
		T data3 = data1 + data2;
		cout << data1.multiplication() << " + " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl;
	}

	void vich(int num1, int num2) { // ��������� ���� ���������
		T data1 = treeOfprimes.find(num1);
		T data2 = treeOfprimes.find(num2);
		T data3 = data1 - data2;
		if (data3.multiplication() != 1)
		{
			cout << data1.multiplication() << " - " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl;
		}
		else
		{
			cout << data1.multiplication() << " - " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl << "�������� ����� ���������� � ���������� �������� �� ���������� ���������� ( ������������ ��� ����� 0 )" << endl;
		}
	}

	void ymn(int num1, int num2) { // ��������� ���� ���������
		T data1 = treeOfprimes.find(num1);
		T data2 = treeOfprimes.find(num2);
		T data3 = data1 * data2;
		if (data3.multiplication() != 1)
		{
			cout << data1.multiplication() << " * " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl;
		}
		else
		{
			cout << data1.multiplication() << " * " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl << "�������� ����� ���������� � ���������� �������� �� ���������� ���������� ( ������������ ��� ����� 0 )" << endl;
		}
	}

	void del(int num1, int num2) { // ������� ���� ���������
		T data1 = treeOfprimes.find(num1);
		T data2 = treeOfprimes.find(num2);
		T data3 = data1 / data2;
		if (data3.multiplication() != 1)
		{
			cout << data1.multiplication() << " / " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl;
		}
		else
		{
			cout << data1.multiplication() << " / " << data2.multiplication() << " = " << data3.multiplication() << endl << data3 << endl << "�������� ����� ���������� � ���������� �������� �� ���������� ���������� ( ������������ ��� ����� 0 )" << endl;
		}
	}

	void save(int num_pack[MAX_RAZLOJENIY], int primeCount) { // ���������� � ����
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

	void read() { // ������ �� �����
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

	void createMnogo(int kolvo) { // �������� ���������� ���������
		for (int i = 0; i < kolvo; i++) {
			int rnum = rand();
			int rchislo = rand();
			take(rnum, IntegerAsPrimes::IntegerAsPrimes(rchislo));
		}
	}
};