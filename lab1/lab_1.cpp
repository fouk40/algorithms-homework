﻿#include  <iostream>		//для использования потоков ввода/вывода
#include  <intrin.h> //для NOP
using namespace std;

int nTwin=1;			//глобальная переменная
namespace TwinSpace{ int nTwin=2;}	//переменная объявлена в
						//пространстве имен - TwinSpace

int main()
{

 //**********************************************************
	//Задание 1. Работа с отладчиком. Базовые типы данных. Выполняя программу по шагам, 
	//следите за значениями переменных и интерпретируйте результат (помните, что 
	//количество байт, отводимых под int, системо-зависимо).
	//Обратите внимание на разную интерпретацию отладчиком signed и unsigned целых типов 
	//данных, а также на внутреннее представление отрицательных целых чисел.

	
	char cByte = 'A'; // Присваивает символ 'А', код ASCII 65
	cByte    = 0x42; // Присваивает символ 'B' по шестнадцатеричному коду, код ASCII 66 
	cByte    = 66; // Присваивает символ 'B' по ASCII-коду
	cByte    = -1; // Даётся значение, по которому невозможно присвоить известный символ   

	unsigned char ucByte = 0x41; // Присваивает символ 'A' по шестнадцатеричному коду код ASCII 65
	ucByte   = 'B'; // Присваивает символ 'B'
	ucByte   =	-1; // Возможно давать только неотрицательные числа, поэтому -1 меняется на 255 и присваивается символ по ASCII-коду

	int iInt =  0xffffffff; // Присваивается -1 из-за нехватки диапазона положительных чисел

	unsigned int uiInt = 0xffffffff; // Призваивается 4294967295

	float fFloat = 1.f;  // Присваивается 1, тип float
	double dDouble = 1.; // Присваивается 1, тип double

	// Выполните фрагмент, приведенный далее. В комментариях отразите,
	// что реально заносится в переменную. Объясните разницу между этим 
	// значением и инициализатором.

	double d = 0.1234567890123456789123456789; // Заносится 0.12345678901234568, т.к. точность типа double составляет 15-17
	// знаков после запятой. Компилятор округлил значение
	float  f = 0.1234567890123456789123456789; // Заносится 0.123456791, т.к. точность типа float составляет 6-9 цифр

	d	=	1.; // Заносится 1, т.к. после . значение 0
	d	=	0.999999999999999999999999999999999; // Заносится 1, т.к. количество знаков после запятой превышает
	// допустимое для типа double значение. Компилятор округлил значение

	
	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф';
	size_t n = sizeof(cw); // 2 байта


// **************************************************************
	//Задание 2a. Неявное приведение типов данных.
	//Объясните разницу результата при выполнении (1) и (2):
	//Покажите явно (напишите в коде) преобразования, которые неявно выполняет компилятор

	iInt=1;
	double dDouble1=iInt/3;		// (1) В результате 0
	// double dDouble2 = static_cast<double>(iInt / 3.);
	// Справа от знака присваивания результат выражения имеет тип int, у которого не может быть чисел после запятой,
	// поэтому то, что могло быть за знаком, теряется.
	double dDouble2=iInt/3.;	// (2) В результате 0.33333333333333331
	// double dDouble2 = static_cast<double>(iInt) / 3.;
	// Делитель (3.) имеет тип double, поэтому всё выражение (1/3.) приводится к этому типу.


	// Ассоциативность операторов.
	// Синтаксис языка C допускает "цепочечное" присваивание
	// (как в строках (1) и (2)). Посмотрев результаты выполнения строк (1) и (2)
	// (значения переменных dDouble, fFloat, nInt, sShort, cByte), определите порядок 
	// выполения присваиваний при цепочечной записи и объясните результат.
	// Расставте скобки, явно определяющие порядок выполнения, как это сделал бы компилятор.
	// Объясните (в комментариях) предупреждения (warnings) компилятора.

	short sShort;
	(dDouble=(fFloat=(iInt=(sShort=(cByte=(3.3/3))))));			// (1)
	// warning C4244 : '=' : conversion from 'double' to 'char', possible loss of data
	// Предупреждает о том, что при присваивании double к char возможна потеря данных
	// warning C4244: '=' : conversion from 'int' to 'float', possible loss of data
	// Т.к. в 64-х битных системах тип int может содержать больше байт данных, в отличие от float,
	// компиллятор предупреждает о возможной потере данных
	
	(cByte=(sShort=(iInt=(fFloat=(dDouble=(3.3/3))))));			// (2)
	// warning C4244: '=' : conversion from 'double' to 'float', possible loss of data
	// приведение типа float к типу double может привести к потере данных, 
	// т.к. тип double имеет размер 8 байт, а float - 4.
	// warning C4244: '=' : conversion from 'float' to 'int', possible loss of data
	// приведение типа float к типу int может привести к потере данных, т.к.
	// тип float может иметь знаки после запятой, в отличие от int
	// warning C4244: '=' : conversion from 'short' to 'char', possible loss of data
	// тип short имеет размер 2 байта, а тип char - 1 байт, 
	// следовательно, возможна потеря данных

	//ниже Вам дан пример "небрежного" использования неявного приведения типов, что может 
	// привести к нежелательным результатам - объясните (в комментариях), к каким?
	// Напишите явно преобразования, которые неявно выполняет компилятор

	iInt	=	257;
	cByte	=	iInt; // 257 - это 000100000001 в двоичной СС. Здесь число приводится к типу char,
	// который может хранить только 1 байт, т.е. 0001 "отсекается" и остается 00000001

	unsigned char cN1=255, cN2=2, cSum;
	cSum = cN1 + cN2; // Максимальное значение для unsigned char в десятичноЙ СС - 255
	// При сложении получается 257, в двоичном формате это 000100000001
	// 0001 "отсекается", и остаётся 00000001

	//Сравните предыдущую строчку с приведенной ниже. Объясните (в комментариях),
	//почему в следующей строке не происходит выход за разрядную сетку
	// Напишите явно преобразования, которые неявно выполняет компилятор
	int iSum = cN1+cN2; // Сумма cN1 и cN2 приводится к значению int

	//Напишите, почему при сложении одинаковых значений (одинаковых в двоичной системе) 
	// в строках (1) и (2) получаются разные результаты
	// Напишите явно преобразования, которые неявно выполняет компилятор и объясните,
	// что при этом происходит
	char c1=0xff, c2=2;
	unsigned char uc1=0xff, uc2=2;
	int iSum1= c1 + c2;   //(1) Результат 1, потому что переменные типа char имеют
	// значения c1 = -1 и c2 = 2, и их сумма равна 1
	int iSum2= uc1 + uc2; //(2) Здесь uc1 = 255 (т.к. беззнаковый тип). 255 + 2 = 257


	
// ***********************************************************
	//Задание 2b. Явное приведение типов данных.
	//Проинтерпретируйте результат (значения переменной dDouble) в строке (3)
	// Напишите явно преобразования, которые неявно выполняет компилятор
	int nTmp=100, nn=3;
	dDouble=3.3 + nTmp / nn; // (3) Компилятор сначала считает nTmp / nn, равное 33.
	// nTmp, nn - переменные типа int, поэтому дробная часть отбрасывается.
	// Далее компилятор считает 3.3 + 33, выражение приводится к типу double. В результате получается 36.3

	//Получите результат без потери точности с помощью оператора явного
	//приведения типа
//	double dDouble3=...		// (4)
	double dDouble3 = static_cast<double>(nTmp) / nn + 3.3;



	return 0;
}