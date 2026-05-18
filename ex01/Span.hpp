#pragma once

#define _END		"\033[0m"
#define _BLACK		"\033[0;30m"
#define _RED		"\033[0;31m"
#define _GREEN		"\033[0;32m"
#define _YELLOW		"\033[0;33m"
#define _BLUE		"\033[0;34m"
#define _PURPLE		"\033[0;35m"
#define _CYAN		"\033[0;36m"

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxNumbers;
		Span(void);

	public:
		Span(unsigned int N);
		Span(const Span &toCopy);
		~Span();

		Span &operator=(const Span &toCopy);

		long		longestSpan();
		long		shortestSpan();
		void		addNumber(int newNumber);
		void		addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class	LimitMaxNumberException : public std::exception {
			virtual const char *what() const throw();
		};

		class	LimitLowNumberException : public std::exception {
			virtual const char *what() const throw();
		};
};
