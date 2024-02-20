#ifndef FILES_H_
#define FILES_H_

	#include <iostream> // Для работы ввода вывода
	#include <fstream>	// Для работы с файловой системой 
	#include <string>	// Для работы со строками 
	using namespace std;
	struct
	{
		int gArray [100000001];
	} 
	mas;
	void Write ( int *array, const unsigned int size, const string name_file ) // Функция записи в файл
	{
		fstream file; // 
		file.open ( name_file, fstream :: out ); // Открытие файла для записи 
		if ( file.is_open () ) // Открытие файла 
		{
			for ( unsigned int i = 0; i < size; i++ ) // Цикл для записи
			{
				file << array [ i ] << ' '; // Запись даннах в файл
			}
			file.close ( ); // Закрытие файла 
		}
	}
	void Read ( const string name_file ) // Функция чтение данных из файла
	{
		fstream file;
		unsigned int b = 0;
		int a = 0;
		file.open ( name_file, fstream :: in ); // Открытие файла для чтение 
		if ( file.is_open ( ) )
		{
			while ( !file.eof() )
			{
				file >> a;
				mas.gArray [ b ] = a;
				b++;
			}
		}	
		file.close ( );
	}
	void quickSort(int *array, unsigned int low, unsigned int high) // Функция быстрой сортировки 
	{
		int i = low;
		int j = high;
		int pivot = array[(i + j) / 2];
		int temp;
		while (i <= j)
		{
			while (array[i] < pivot)
				i++;
			while (array[j] > pivot)
				j--;
			if (i <= j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				i++;
				j--;
			}
		}
			if (j > low)
				quickSort(array, low, j);
			if (i < high)
				quickSort(array, i, high);
	}
#endif /*FILES_H_*/