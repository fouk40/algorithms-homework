﻿#include  <iostream>		//для использования потоков ввода/вывода
#include <cmath>

int nTwin=1;			//глобальная переменная
namespace TwinSpace{ int nTwin=2;}	//переменная объявлена в
						//пространстве имен - TwinSpace

#define stop do {} while (0);

using namespace std;

int main()
{
	
 //**********************************************************
	// ********************************************************
	//Задание 9. Циклы.

	//Задание 9.1 Напишите фрагмент кода, который реализует с помощью for
	//следующую логику: найти сумму заданного диапазона целых чисел.
	//Введите границы с помощью потока ввода или с помощью средств отладки.
	//Предусмотрите защиту от ввода нижней границы больше, чем верхней.
	{
		
		//сформироыать границы диапазона
		int a, b;
		do {
			cout << "Enter a: ";
			cin >> a;
			cout << "Enter b: ";
			cin >> b;
		//проверить корректность значений
		} while (a > b);

		// вычислить сумму
		int sum = 0;
		for (int i = a; i <= b; i++) {
			sum += i;
		}

		// проверить в отладчике значение
		stop
	}


	//Задание 9.2 Напишите фрагмент кода, который реализует с помощью do-while
	//следующую логику: на каждой итерации цикла ввести с консоли целое значение
	// и покинуть цикл, если значение удовлетворяет условию: 
	// значение больше или равно 10 и четное.
	//Замечание: проверка на четность с использованием операции остатка от деления
	//нацело генерирует очень неэффективный код. Попробуйте реализовать альтернативный
	//вариант.
	
	{	
		int n;
		do {
			cout << "Enter integer: ";
			cin >> n;
		} while (n < 10 || n & 1);
	}

	//Задание 9.3 Напишите фрагмент кода, который реализует с помощью while
	//следующую логику: исходно int x = 0; 
	//на каждой итерации x=x+1, sum=sum+1/x
	//найти значение x, при котором sum>1.7
	{
		int x = 0;
		double sum = 0;
		while (sum <= 1.7) {
			x += 1;
			sum += 1/static_cast<double>(x);
		}
	}
	return 0;//код завершения приложения
}	// Конец функции main()
