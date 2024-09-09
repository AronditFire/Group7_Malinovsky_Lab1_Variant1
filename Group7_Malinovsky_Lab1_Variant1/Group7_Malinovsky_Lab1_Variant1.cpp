#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

bool isDouble(const string& str)
{
	istringstream check_Is_Double(str);
	double num;

	return (check_Is_Double >> num) && (check_Is_Double.eof());
}

bool isInteger(const string& str) 
{
	istringstream check_Is_Int(str);
	int num;
	return (check_Is_Int >> num) && (check_Is_Int.eof());
	
}

int getChoice()
{
	string input;

	while (true)
	{
		cout << "Введите верно 1 или 2: ";
		getline(cin, input);

		if (isInteger(input))
		{
			if (stoi(input) == 1 || stoi(input) == 2)
			{
				return stoi(input); // string to integer
			}
			else 
			{
				cout << "Ошибка! Введите корректное целое число.\n";
			}
		}
		else
		{
			cout << "Ошибка! Введите корректное целое число.\n";
		}
	}
}

int getInput()
{
	string input;

	while (true)
	{
		cout << "Введите верно целое число: ";
		getline(cin, input);

		if (isInteger(input))
		{
			return stoi(input); // string to integer
		}
		else
		{
			cout << "Ошибка! Введите корректное целое число.\n";
		}
	}
}

double getDouble()
{
	string input;

	while (true)
	{
		cout << "Введите верно вещественное число: ";
		getline(cin, input);

		if (isDouble(input))
		{
			return stod(input); //string to double
		}
		else
		{
			cout << "Ошибка! Введите вещественное целое число.\n";
		}
	}
}

template <typename T, typename TT>

void rand_and_check_output(T& s, T& t, TT& x)
{
	s = rand() % 100;
	t = rand() % 100;
	x = rand() % 100;

	while (!((x > 0) && (t * log10(x + s) != 0) && (x + s > 0) && (cos(x * x) != 0)))
	{
		return rand_and_check_output(s, t, x);
	}

}


int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int s, t, choice;
	double x;
	double result;

	cout << "Программа вычисляет фунцкию ((tan(x * x) + sqrt(x)) / (t * log10(x + s))).\n";
	cout << "Введите \'1\' если хотите ввести переменные сами." << endl;
	cout << "Введите \'2\' если хотите использовать рандомные переменные." << endl;

	choice = getChoice();

	switch (choice)
	{
	case 1:
		cout << "ОДЗ: x^2 != PI/2, (x+s) > 0, t*lg(x+s) != 0, x > 0" << endl << endl;

		cout << "Переменная s." << endl;
		s = getInput();

		cout << "Переменная t." << endl;
		t = getInput();

		cout << "Переменная x." << endl;
		x = getDouble();


		while (!((x > 0) && (t * log10(x + s) != 0) && (x + s > 0) && (cos(x * x) != 0)))
		{
			cout << "Вы пренебрегли ОДЗ. Введите данные ещё раз." << endl;

			cout << "ОДЗ: x^2 != pi/2, (x+s) > 0, t*lg(x+s) != 0, x > 0" << endl;

			cout << "Переменная s." << endl;
			s = getInput();

			cout << "Переменная t." << endl;
			t = getInput();

			cout << "Переменная x." << endl;
			x = getDouble();

		}

		result = ((tan(x * x) + sqrt(x)) / (t * log10(x + s)));
		cout << "Result: " << result << endl;
		break;
	case 2:

		rand_and_check_output(s, t, x);
		result = ((tan(x * x) + sqrt(x)) / (t * log10(x + s)));
		cout << "Random result: " << result << endl;
		break;

	default:
		cout << "Я не знаю как, но вы сломали программу. Congratz!" << endl;
		break;
	}

	return 0;
}