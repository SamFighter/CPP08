#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
	std::cout << _BLUE << "######### easyfind with std::vector #########" << _END << std::endl;
	try {
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(42);
		v.push_back(5);
		std::cout << _YELLOW << "Vector : { 1 2 3 42 5 } - Searching for 42..." << _END << std::endl;
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << _GREEN << "Found 42 at position : " << std::distance(v.begin(), it) << _END << std::endl;
	}
	catch (std::exception &ex) {
		std::cerr << _RED << ex.what() << _END << std::endl;
	}
	try {
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		std::cout << _YELLOW << "\nVector : 1 2 3" << _END << std::endl;
		std::cout << _YELLOW << "Searching for 99..." << _END << std::endl;
		easyfind(v, 99);
	}
	catch (std::exception &ex) {
		std::cerr << _RED << ex.what() << _END << std::endl;
	}

	std::cout << _BLUE << "\n######### easyfind with std::list #########" << _END << std::endl;
	try {
		std::list<int> l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(30);
		l.push_back(40);
		std::cout << _YELLOW << "List : 10 20 30 40" << _END << std::endl;
		std::list<int>::iterator it = easyfind(l, 30);
		std::cout << _GREEN << "Found : " << *it << _END << std::endl;
	}
	catch (std::exception &ex) {
		std::cerr << _RED << ex.what() << _END << std::endl;
	}
	try {
		std::list<int> l;
		l.push_back(10);
		l.push_back(20);
		std::cout << _YELLOW << "\nList : 10 20" << _END << std::endl;
		std::cout << _YELLOW << "Searching for 99..." << _END << std::endl;
		easyfind(l, 99);
	}
	catch (std::exception &ex) {
		std::cerr << _RED << ex.what() << _END << std::endl;
	}

	std::cout << _BLUE << "\n######### easyfind with std::deque #########" << _END << std::endl;
	try {
		std::deque<int> d;
		d.push_back(5);
		d.push_back(15);
		d.push_back(25);
		d.push_back(35);
		std::cout << _YELLOW << "Deque : 5 15 25 35" << _END << std::endl;
		std::deque<int>::iterator it = easyfind(d, 5);
		std::cout << _GREEN << "Found : " << *it << " at position : " << std::distance(d.begin(), it) << _END << std::endl;
	}
	catch (std::exception &ex) {
		std::cerr << _RED << ex.what() << _END << std::endl;
	}
	try {
		std::deque<int> d;
		d.push_back(5);
		d.push_back(15);
		std::cout << _YELLOW << "\nDeque : 5 15" << _END << std::endl;
		std::cout << _YELLOW << "Searching for 99..." << _END << std::endl;
		easyfind(d, 99);
	}
	catch (std::exception &ex) {
		std::cerr << _RED << ex.what() << _END << std::endl;
	}

	return 0;
}
