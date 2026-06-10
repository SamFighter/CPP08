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
long Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw LimitLowNumberException();
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    std::vector<int> diffs(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
    return *std::min_element(diffs.begin() + 1, diffs.end());
}

long Span::longestSpan()
{
    if (_numbers.size() <= 1)
        throw LimitLowNumberException();
    return (*std::max_element(_numbers.begin(), _numbers.end()) 
            - *std::min_element(_numbers.begin(), _numbers.end()));
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

