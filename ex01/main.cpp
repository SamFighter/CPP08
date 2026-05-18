#include "Span.hpp"
#include <ctime>

int main()
{
	std::cout << _YELLOW << "_________________ Subject main _________________" << _END << std::endl;
	std::cout << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << _YELLOW << "\n_________________ shortestSpan() & longestSpan() tests _________________" << _END << std::endl;
	std::cout << std::endl;

	std::cout << _BLUE << "No numbers stored:" << _END << std::endl;
	{
		Span sp = Span(0);
		try 
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << _BLUE << "Not enough numbers stored:" << _END << std::endl;
	{
		Span	sp = Span(1);
		sp.addNumber(5);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			  std::cerr << _RED << e.what() << _END << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << _BLUE << "Negative value only:" << _END << std::endl;
	{
		Span	sp = Span(5);

		sp.addNumber(-8);
		sp.addNumber(-48298);
		sp.addNumber(-214748364);
		sp.addNumber(-21);
		sp.addNumber(-72);

		std::cout << _PURPLE << "Value stored & sorted: { -8, -21, -72, -48298, -214748364 }" << _END << std::endl;
		try
		{
			std::cout << _GREEN << "shortestSpan() = " << sp.shortestSpan() << _END << std::endl;
			std::cout << _GREEN << "longestSpan() = "<< sp.longestSpan() << _END << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
		std::cout << "{   Explanation :   }"<< std::endl;
		std::cout << _CYAN << "-8 - (-21)        =  " << _END << -8 - (-21) << std::endl;
		std::cout << _CYAN <<"-214748364 - (-8) =  " << _END << -214748364 - (-8) << std::endl;
	}
	std::cout << std::endl;
	std::cout << _BLUE << "Negative & positive value:" << _END << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(-21);
		sp.addNumber(14);
		sp.addNumber(67);
		sp.addNumber(69);
		sp.addNumber(-244);

		std::cout << _PURPLE << "Value stored & sorted: { -244, -21, 14, 67, 69 }" << _END << std::endl;
		try
		{
			std::cout << _GREEN << "shortestSpan() = " << sp.shortestSpan() << _END << std::endl;
			std::cout << _GREEN << "longestSpan() = "<< sp.longestSpan() << _END << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << _BLUE << "INT_MIN & INT_MAX:" << _END << std::endl;
	{
		Span sp = Span(2);

		sp.addNumber(-2147483648);
		sp.addNumber(2147483647);
		std::cout << _PURPLE << "Value stored & sorted: { -2147483648, 2147483647 }" << _END << std::endl;
		try
		{
			std::cout << _GREEN << "shortestSpan() = " << sp.shortestSpan() << _END << std::endl;
			std::cout << _GREEN << "longestSpan() = "<< sp.longestSpan() << _END << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << _YELLOW << "_________________ addManyNumbers() tests _________________" << _END << std::endl;
	std::cout << std::endl;

	std::cout << _BLUE << "addManyNumbers basic test:" << _END << std::endl;
	{
		Span sp = Span(5);
		std::vector<int> v;
		v.push_back(10);
		v.push_back(3);
		v.push_back(77);
		v.push_back(42);
		v.push_back(1);
		std::cout << _PURPLE << "Value stored: { 10, 3, 77, 42, 1 }" << _END << std::endl;
		try
		{
			sp.addManyNumbers(v.begin(), v.end());
			std::cout << _GREEN << "shortestSpan() = " << sp.shortestSpan() << _END << std::endl;
			std::cout << _GREEN << "longestSpan() = " << sp.longestSpan() << _END << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << _BLUE << "addManyNumbers exceeds max capacity:" << _END << std::endl;
	{
		Span sp = Span(3);
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::cout << _PURPLE << "Span max = 3, trying to add 5 numbers" << _END << std::endl;
		try
		{
			sp.addManyNumbers(v.begin(), v.end());
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << _BLUE << "addManyNumbers partially filled then exceed:" << _END << std::endl;
	{
		Span sp = Span(4);
		sp.addNumber(99);
		sp.addNumber(50);
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		std::cout << _PURPLE << "Span max = 4, already 2 numbers, trying to add 3 more" << _END << std::endl;
		try
		{
			sp.addManyNumbers(v.begin(), v.end());
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << _YELLOW << "_________________ 10 000 numbers randomizer test _________________" << _END << std::endl;
	std::cout << std::endl;
	{
		std::cout << _BLUE << "Filling Span with 10 000 random numbers:" << _END << std::endl;
		Span sp = Span(10000);
		std::vector<int> v;
		v.reserve(10000);
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
			v.push_back(rand());
		try
		{
			sp.addManyNumbers(v.begin(), v.end());
			std::cout << _GREEN << "shortestSpan() = " << sp.shortestSpan() << _END << std::endl;
			std::cout << _GREEN << "longestSpan() = " << sp.longestSpan() << _END << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << _BLUE << "Filling Span with 10 001 random numbers (exceed max):" << _END << std::endl;
	{
		Span sp = Span(10000);
		std::vector<int> v;
		v.reserve(10001);
		srand(time(NULL));
		for (int i = 0; i < 10001; i++)
			v.push_back(rand());
		try
		{
			sp.addManyNumbers(v.begin(), v.end());
		}
		catch (std::exception &e)
		{
			std::cerr << _RED << e.what() << _END << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}
