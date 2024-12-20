/*************************************************************
	Практическое занятие №2. Побитовые операторы.
							Директивы препроцессора.
							Указатели.
*************************************************************/

#include <iostream>
#include <tchar.h>
#include <cmath>
#include <string>

//#define	  stop __asm nop	//с помощью директивы препроцессора задаем
							//макроподстановку

#define stop do{ } while(0)

/***************************************************************
Задания, отмеченные * , не являются обязательными!
***************************************************************/

int main()
{
// ********************************************************

	//Задание 4. Указатели
	//Объявите объекты разных типов и проинициализируйте их.
	//Объявите указатели соответствующих типов и проинициализируйте их
	//адресами заданных объектов. 
	//Выполняя задание, с помощью отладчика посмотрите, какие значения
	//будут присвоены переменным-указателям и на что эти указатели
	//"указывают"
	{
		bool b = true;
		char c = 'q';
		short s = 12000;
		int i = 100000;
		float f = 17.0;
		double d = 18.12343434;

		bool *pB = &b; // true
		char *pC = &c; // 113 'q'
		short *pS = &s; // 12000
		int *pI = &i; // 100000
		float *pf = &f; // 17
		double *pD = &d; // 8.1212534600800742e-318

		stop;
	}


	//Задание 4а. Объявите указатель на тип char и проинициализируйте
	//его адресом строкового литерала. Присвойте переменной типа char значение
	//любого элемента строки.
	//Проверьте - возможно ли присвоить какое-либо значение по адресу,
	//задаваемому указателем?
	{
		const char* str = "Hello";
		char c = str[1]; // содержит 2-й элемент (счет с 0-го) строкового литерала str - 101 'e'
		//str[2] = 'A'; Нельзя изменить значение, используя указатель, т.к. строковый литерал находится в
						//памяти, доступной только для чтения

		stop;
	}

	//Задание 5. Арифметика указателей. Операция разыменования указателя.
	//Выполняя задание, следите за изменением значений
	//указателей и значений объектов, на которые они указывают.
	//Интерпретируте наблюдаемые результаты
	{
		int nAr[3] = {1,3}; // 2-й элемент массива (счет с 0-го) равен 0, т.к. его значение при инициализации не дано программистом
		int* pn = &nAr[0]; // pn содержит адрес 0-го элемента массива nAr
		(*pn)++;	// 0-й элемент массива nAr увеличился на 1, т.к. указатель pn содержал адрес 0-го элемента
		pn++;	// указатель сдвинулся на следующий элемент (1-й, если считать с 0-го элемента)

		char cAr[]={'A','B','C','D'};
		char* pc = &cAr[0]; // pc содержит адрес 0-го элемента массива cAr
		(*pc)=(*pc)+5;	// взятие значения по адресу pc 'A' (65) и увеличение его на 5, 
						// в результате получается значение 'F' (70), которое будет записано 
						// по адресу pc вместо 0-го элемента
		pc=pc+3;	// указатель указывает на 3-й элемент массива cAr (счет с 0-го)
	
		double dAr[3]={1.0,2.0}; // 2-й элемент массива (счет с 0-го) равен 0, т.к. его значение при инициализации не дано программистом
		double* pd1 = &dAr[0]; // pd1 содержит адрес 0-го элемента массива dAr
		double* pd2 = pd1;
		(*pd2)+=2; // pd2 - указывает на 0-й элемент массива dAr. После разыменования и прибавления 2,
				   // значение 0-го элемента изменится на 3.0. 
		pd2+=2; // указатель pd2, теперь указывает на 2-й элемент (счет с 0-го)

		//Объясните результат выполнения операции
		//вычитания двух указателей
		pd1 = &dAr[0]; // pd1 содержит адрес 0-го элемента массива dAr
		pd2 = &dAr[1]; // pd2 содержит адрес 1-го элемента массива dAr
		int nNumber=pd2 - pd1; // операция вычитания указателей имеет смысл для определения 
							   // количества элементов между двумя указателями в рамках одного массива
							   // nNumber = 1

		//Сравните указатели pd2 и pd1 и с помощью cout
		//выведите результаты сравнения.
		std::cout << "5. Compare result is: " << (pd2 > pd1 ? "true" : "false") << std::endl; // true

		stop;
	}

	return 0;
}