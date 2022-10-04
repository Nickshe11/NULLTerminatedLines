#include <iostream>
#include<Windows.h>
using namespace std;
//#define EXAMPLE_1
#define EXAMPLE_2

int StringLength(const char str[]);
void upper_case(char str[]);
void lower_case(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);

void main()
{
	setlocale(LC_ALL, "");
#ifdef EXAMPLE_1
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	char str[] = "Hello";
	//str[] - строковая переменная
	//"Hello" - строковая константа
	cout << str << endl;
	cout << typeid(str).name() << endl;
	cout << typeid("Hello").name() << endl;
#endif // EXAMPLE_1
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866); // в моей версии выводит и без этой строки
	cout << str << endl;
	//cout << "Длина строки " << StringLength(str) << endl;
	//cout << "Длина строки " << strlen(str) << endl; //встроенная функция для определения длины строки
	//cout << "Длина строки в байтах: " << sizeof(str) << endl;
	//upper_case(str);
	//cout << str << endl;
	//lower_case(str);
	//cout << str << endl;
	//shrink(str);
	//cout << str << endl;
	cout <<"Строка "<< (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом." << endl;
}
int StringLength(const char str[])
{
	int i = 1;
	/*while(str[i-1]!=0)
	{
		i++;
	}
	return i;*/
	for (; str[i]; i++);
	return i;
}
void upper_case(char str[])
{
	int i = 0;
	for (; str[i]; i++)
	{
		//if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';//ASCII код знака пробел - 32
		//if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
		//if (str[i] == 'ё')str[i] = 'Ё';//у букв ё и Ё свои значения аски символов, вне этих диапазонов
		str[i] = toupper(str[i]); //Функция toupper (char s) принимает букву и возвращает такую же заглавную букву
	}
}
void lower_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	lower_case(buffer);
	remove_symbol(buffer, ' ');
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[]buffer;
			return false;
		}
	}
	return true;
}