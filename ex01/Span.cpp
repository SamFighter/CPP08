#include "Span.hpp"


//################### Constructor/Destructor
Span::Span(unsigned int N)
{
	this->_maxNumbers = N;
	return ;
}

Span::Span(const Span &toCopy)
{
	*this = toCopy;
	return ;
}

Span::~Span()
{
	return ;
}

//################### Overload Operator
Span	&Span::operator=(const Span &toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->_maxNumbers = toCopy._maxNumbers;
	this->_numbers = toCopy._numbers;
	return (*this);
}

//################### public Method
long	Span::shortestSpan()
{
	long					actualSmaller;
	unsigned int 			len = this->_numbers.size();

	if (len == 0 || len == 1)
		throw LimitLowNumberException();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	actualSmaller = this->_numbers[1] - this->_numbers[0];
	for (unsigned int i = 0; i < len - 1; i++)
	{
		long	tmpSmaller = this->_numbers[i + 1] - this->_numbers[i];
		if (tmpSmaller < actualSmaller)
			actualSmaller = tmpSmaller;
	}
	return (actualSmaller);
}

long	Span::longestSpan()
{
	unsigned int			len = this->_numbers.size();

	if (len == 0 || len == 1)
		throw LimitLowNumberException();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	return (this->_numbers[len - 1] - this->_numbers[0]);
}

void	Span::addNumber(int newNumber)
{
	if (this->_numbers.size() == this->_maxNumbers)
		throw LimitMaxNumberException();
	this->_numbers.push_back(newNumber);
	return ;
}

void	Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_numbers.size() + std::distance(begin, end) > this->_maxNumbers)
		throw LimitMaxNumberException();
	this->_numbers.insert(this->_numbers.end(), begin, end);
	return ;
}

//################### Exception
const char	*Span::LimitMaxNumberException::what() const throw()
{
	return ("[Error] : Maximum number of integers reached.");
}

const char	*Span::LimitLowNumberException::what() const throw()
{
	return ("[Error] : Number of integers lacking.");
}

