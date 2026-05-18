#pragma once

#define _END		"\033[0m"
#define _BLACK		"\033[0;30m"
#define _RED		"\033[0;31m"
#define _GREEN		"\033[0;32m"
#define _YELLOW		"\033[0;33m"
#define _BLUE		"\033[0;34m"
#define _PURPLE		"\033[0;35m"
#define _CYAN		"\033[0;36m"

#include <list>
#include <stack>
#include <iostream>

template <typename T>
class	MutantStack : public std::stack<T> {

	public:
		MutantStack(void) {};
		MutantStack(const MutantStack &toCopy) {
			*this = toCopy;
			return ;
		};

		~MutantStack(void) {};

		MutantStack &operator=(const MutantStack &toCopy) {
			if (this == &toCopy)
				return (*this);
			this->std::stack<T>::operator=(toCopy);
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator	begin(void) {
			return (this->c.begin());
		}

		const_iterator	begin(void) const {
			return (this->c.begin());
		}

		iterator	end(void) {
			return (this->c.end());
		}

		const_iterator	end(void) const {
			return (this->c.end());
		}
};
