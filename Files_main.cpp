#include <iostream>
#include <locale> 
#include <string>
#include <ctime> // Библеотека для работы с RTC
#include "Files.h"
using namespace std;

void Write_files_data ( const  string name, const unsigned int size, int *a, int *b ); // Прототип функции

int main ( void )
{
	setlocale ( LC_ALL, "RU" );
	srand(time(nullptr));
	const unsigned int size = ( 100000000 ); // Выдиление пмяти в куче 
	int *array = new int [ size ];
	int *a = new int ( -10 );
	int *b = new int ( 5 );
///////////////////////////////////////////////////////////////////////////////////////////////
	string  f1 = "File_1.txt"; // Задаётся имена файлов 
	string  f2 = "File_2.txt";
	string  f3 = "File_3.txt";
	string  f4 = "File_4.txt";
	string  Shared = "Shared_file.txt";
///////////////////////////////////////////////////////////////////////////////////////////////
	// Запись данных в текстовые файлы
	Write_files_data ( f1, size, a, b ); // Запись данных в файл
	Write_files_data ( f2, size, a, b );
	Write_files_data ( f3, size, a, b );
	Write_files_data ( f4, size, a, b );
	///////////////////////////////////////////////////////////////////////////////////////////
	// Чтение, сортировака и запись сортированных данных в файлы обратно 
	unsigned int n = sizeof(mas.gArray) / sizeof(mas.gArray[0]); // Получение данных о размере массива
	///////////////////////////////////// Файл 1
	Read( f1 );
	quickSort ( mas.gArray, 0, n );
	Write ( mas.gArray, size, f1 );
	///////////////////////////////////// Файл 2
	Read ( f2 );
	quickSort ( mas.gArray, 0, n );
	Write ( mas.gArray, size, f2 );
	///////////////////////////////////// Файл 3
	Read ( f3 );
	quickSort ( mas.gArray, 0, n );
	Write(mas.gArray, size, f3 );
	///////////////////////////////////// Файл 4
	Read ( f4 );
	quickSort(mas.gArray, 0, n);
	Write(mas.gArray, size, f4 );
	///////////////////////////////////////////////////////////////////////////////////////////
	// Объединение фалов
	ifstream file1(f1);
	ifstream file2(f2);
	ifstream file3(f3);
	ifstream file4(f4);
	ofstream out(Shared);

	if (!file1.is_open() || !file2.is_open() || !file3.is_open() || !file4.is_open() || !out.is_open()) { return -1; }
	std::string str;
	while (getline(file1, str)) { out << str; }
	while (getline(file2, str)) { out << str; }
	while (getline(file3, str)) { out << str; }
	while (getline(file4, str)) { out << str; }
///////////////////////////////////////////////////////////////////////////////////////////////
	delete [ ] array; // Очистка выдиленной памяти
	delete a;
	delete b;
	return 0;
}
void Write_files_data ( const string name, const unsigned int size, int *a, int *b ) // Объявление функции 
{
	int *arr = new int [size] ; // Выдиление пмяти в куче 
	for ( unsigned int i = 0; i < size; i++ ) // Цикла для записи в массив данных 
	{
		arr [ i ] = *a + rand() % ( *a + *b % 2  ); // Запись произвольныйх значений массив
	}
	Write ( arr, size, name ); // Данных в текстовый файл
	delete [ ] arr; // Очистка памяти
}