#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>

namespace ft{

//all this can be found in <iterator> source code xD

struct input_iterator_tag  {};
struct output_iterator_tag {};
struct forward_iterator_tag       : input_iterator_tag         {};
struct bidirectional_iterator_tag : forward_iterator_tag       {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

template<typename Iterator> struct iterator_traits{

    typedef typename Iterator::difference_type		difference_type;
    typedef typename Iterator::value_type			value_type;
    typedef typename Iterator::pointer				pointer;
    typedef typename Iterator::reference			reference;
    typedef typename Iterator::iterator_category	iterator_category;
};

template<typename T> struct iterator_traits<T*>{

	typedef ptrdiff_t					difference_type;
	typedef T							value_type;
	typedef T* 							pointer;
	typedef T&							reference;
	typedef random_access_iterator_tag	iterator_category;
};

template<typename Category, typename T, typename Distance = std::ptrdiff_t,
		typename Pointer = T*, typename Reference = T&>
struct iterator{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};



template <typename Iter>
class reverse_iterator : iterator< 
		typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference >{

	protected:

		Iter current;

	public:

		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::reference			reference;
		typedef typename iterator_traits<Iter>::pointer				pointer;

		reverse_iterator() : current(iterator_type()) {}
		reverse_iterator(iterator_type x) : current(x) {}

		template <typename U>
		reverse_iterator(const reverse_iterator<U>& other) : current(other.base()) {}

		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ){
			current = other.base();
			return *this;
		}

		iterator_type base() const {
			return current;
		}

		reference operator*() const {
			Iter tmp = current;
			return *--tmp;
		}

		pointer operator->() const {
			return addressof(operator*());
		}

		reverse_iterator& operator++() {
			--current;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmp(*this);
			--current;
			return tmp;
		}

		reverse_iterator& operator--() {
			++current;
			return *this;
		}

		reverse_iterator operator--(int) {
			reverse_iterator tmp(*this); 
			++current; return tmp;
		}

		reverse_iterator& operator+=(difference_type n) {
			current -= n;
			return *this;
		}

		reverse_iterator& operator-=(difference_type n) {
			current += n;
			return *this;
		}

		reference operator[](difference_type n) const {
			return base()[-n-1];
		}
};

template < typename Iterator1, typename Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
	return lhs.base() != rhs.base();
}

template < typename Iterator1, typename Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
	return lhs.base() == rhs.base();
}

template < typename Iterator1, typename Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
	return lhs.base() <= rhs.base();
}

template < typename Iterator1, typename Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
	return lhs.base() >= rhs.base();
}

template < typename Iterator1, typename Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
	return lhs.base() < rhs.base();
}

template < typename Iterator1, typename Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs){
	return lhs.base() > rhs.base();
}

template < typename Iter >
reverse_iterator<Iter> 
operator+(typename reverse_iterator<Iter>::difference_type n, 
		const reverse_iterator<Iter>& it )
{
	return reverse_iterator<Iter>(it.base() - n);
}

template < typename Iterator >
typename reverse_iterator<Iterator>::difference_type
operator-( const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs )
{
	return rhs.base() - lhs.base();
}

} //end namepsace

#endif