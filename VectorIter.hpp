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

		mutable pointer _p;

	public:

		VecIter(): _p(0){}
		VecIter(pointer n): _p(n){}
		~VecIter(){}

		T* base() const{return this->_p;}

		reference operator*( void ) {
			return *_p;
		}

		pointer operator->() {
			return _p;
		}

		const reference operator*( void ) const {
			return *_p;
		}

		const T* operator->() const {
			return _p;
		}

		VecIter operator++( int ){
			return _p++;
		}

		VecIter& operator++( void ){
			++_p;
			return *this;
		}

		const VecIter operator++( int )const{
			return _p++;
		}

		const VecIter& operator++( void )const{
			++_p;
			return *this;
		}
		
		VecIter operator--( int ){
			return _p--;
		}

		VecIter& operator--( void ){
			--_p;
			return *this;
		}

		const VecIter operator--( int )const {
			return _p--;
		}

		const VecIter& operator--( void )const{
			--_p;
			return *this;
		}

		difference_type operator-(const VecIter<value_type>& rhs)  {
			return _p - rhs._p;
		}

		difference_type operator+(const VecIter<value_type>& rhs)  {
			return _p + rhs._p;
		}

		difference_type operator-(const VecIter<value_type>& rhs) const {
			return _p - rhs._p;
		}

		difference_type operator+(const VecIter<value_type>& rhs) const {
			return _p + rhs._p;
		}

		VecIter& operator+=(difference_type n) {
			_p += n;
			return *this;
		}

		const VecIter& operator+=(difference_type n) const{
			_p += n;
			return *this;
		}

		VecIter& operator-=(difference_type n) {
			_p -= n;
			return *this;
		}

		const VecIter& operator-=(difference_type n) const {
			_p -= n;
			return *this;
		}

		VecIter operator-(difference_type rhs){
			return VecIter(_p - rhs);
		}

		const VecIter operator-(difference_type rhs) const {
			return VecIter(_p - rhs);
		}

		VecIter operator+(difference_type rhs){
			return VecIter(_p + rhs);
		}

		const VecIter operator+(difference_type rhs) const {
			return VecIter(_p + rhs);
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

template< typename Iter >
VecIter<Iter> operator+( typename VecIter<Iter>::difference_type n, const VecIter<Iter>& it ){
	return VecIter<Iter>(it.base() + n);
}

} //end namepsace

#endif