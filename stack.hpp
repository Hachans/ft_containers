#ifndef STACK_HPP
# define STACK_HPP

#include "Utils.hpp"
#include "vector.hpp"


namespace ft{

template< typename T, typename Container = vector<T> > class stack{
	public:
		typedef Container									container_type;
		typedef typename Container::value_type						value_type;
		typedef typename Container::size_type						size_type;
		typedef typename Container::reference						reference;
		typedef typename Container::const_reference					const_reference;
	
	protected:
		container_type c;
	public:

		explicit stack( const Container& cont = Container()): c(cont){}
		~stack(){}
		stack& operator=( const stack& other ){
			this->c = other.c;
			return *this;
		}
		reference top(){ return c.back(); }
		const_reference top() const{ return c.back(); }
		bool empty() const{return c.empty(); }
		size_type size() const{ return c.size(); }
		void push( const value_type& value ){ c.push_back(value); }
		void pop(){ c.pop_back(); }

		friend bool operator==( const stack& lhs, const stack& rhs ){
			return (lhs.c == rhs.c);
		}

		friend bool operator!=( const stack& lhs, const stack& rhs ){
			return !(lhs.c == rhs.c);
		}

		friend bool operator<( const stack& lhs, const stack& rhs ){
			return (lhs.c < rhs.c);
		}

		friend bool operator<=( const stack& lhs, const stack& rhs ){
			return !(lhs.c >= rhs.c);
		}

		friend bool operator>( const stack& lhs, const stack& rhs ){
			return !(lhs.c < rhs.c);
		}

		friend bool operator>=( const stack& lhs, const stack& rhs ){
			return (rhs.c >= lhs.c);
		}
};

} //namespace end

#endif