#ifndef VECTORITER_HPP
# define VECTORITER_HPP

#include "iterator.hpp"

namespace ft{

template < typename T > class VecIter : public ft::iterator<std::random_access_iterator_tag, T>{

	public:

		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::ptrdiff_t						difference_type;
		typedef std::random_access_iterator_tag		iterator_catregory;
		
	private:

		pointer _p;

	public:

		VecIter(): _p(nullptr){}
		VecIter(pointer n): _p(n){}
		~VecIter(){}

		reference operator*( void ) const {
			return *_p;
		}

		pointer operator->() const {
			return _p;
		}

		VecIter operator++( value_type ){
			return _p++;
		}

		VecIter& operator++( void ){
			++_p;
			return *this;
		}
		
		VecIter operator--( value_type ){
			return _p--;
		}

		VecIter& operator--( void ){
			--_p;
			return *this;
		}

		bool operator!=( const VecIter<value_type>& other ){
			return(_p != other._p);
		}

		bool operator==( const VecIter<value_type>& other ){
			return(_p == other._p);
		}

		bool operator>=( const VecIter<value_type>& other ){
			return(_p >= other._p);
		}

		bool operator<=( const VecIter<value_type>& other ){
			return(_p <= other._p);
		}

		bool operator>( const VecIter<value_type>& other ){
			return(_p > other._p);
		}

		bool operator<( const VecIter<value_type>& other ){
			return(_p < other._p);
		}
};

} //end namepsace

#endif