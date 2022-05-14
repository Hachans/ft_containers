#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "VectorIter.hpp"

namespace ft{

template < typename T, typename Alloc = std::allocator<T> > class VectorClass{
	public:

		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename Alloc::pointer						pointer;
		typedef typename Alloc::const_pointer				const_pointer;
		typedef VecIter<value_type>							iterator;
		typedef VecIter<value_type>							const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:

		pointer			_vec;
		size_type		_limit;
		size_type		_size;
		allocator_type	_alloc;

	public:

		// VectorClass() : _limit(0), _size(0), _vec(nullptr){
		// }

		explicit VectorClass( const allocator_type& alloc = allocator_type()) :
			_limit(0),
			_size(0),
			_alloc(alloc){
			_vec = _alloc.allocate(0); // myb replace with _vec(nullptr)
		}

		explicit VectorClass( size_type count, const value_type& value = value_type(),
						const allocator_type& alloc = allocator_type()) :
			_limit(count), _size(0), _alloc(alloc){

			_vec = _alloc.allocate(count);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(&_vec[i], value);
		}

		template< class InputIt >
		VectorClass( InputIt first, InputIt last, const allocator_type& alloc = allocator_type());

		~VectorClass(){
			this->_alloc.deallocate(this->_vec, this->capacity());
		}

		VectorClass(const VectorClass<T>& other) :
			_limit(other._limit),
			_size(other._size),
			_alloc(other._alloc){
			this->_vec = _alloc.allocate(this->_size);
			for (size_type i = 0; i < this->_size; i++)
				_alloc.construct(&this->_vec[i], other._vec[i]);
		}

		VectorClass& operator=(const VectorClass<T>& other){
			this->_size = other._size;
			this->_limit = other._limit;
			this->_alloc = other._alloc;
			this->_vec = _alloc.allocate(this->_size);
			for (size_type i = 0; i < this->_size; i++)
				_alloc.construct(&this->_vec[i], other._vec[i]);

			return *this;
		}

		void assign( size_type count, const T& value );
		template< typename InputIt > void assign( InputIt first, InputIt last );

		allocator_type get_allocator() const {
			 return this->_alloc;
		}

		reference front() {
			return this->_vec[0];
		}

		const_reference front() const{
			return this->_vec[0];
		}

		reference back() {
			return this->_vec[size() - 1];
		}

		const_reference back() const{
			return this->_vec[size() - 1];
		}

		T* data(){
			return this->_vec;
		}

		const T* data() const{
			return this->_vec;
		}

		iterator begin(){ return (iterator(this->_vec));}
		const_iterator cbegin() const { return (const_iterator(this->_vec));}

		iterator end(){ return (iterator(this->_vec + this->_size));}
		const_iterator cend() const{ return (const_iterator(this->_vec + this->_size));}

		reverse_iterator rbegin(){ return (reverse_iterator(this->_vec + this->_size));}
		const_reverse_iterator crbegin(){ return (const_reverse_iterator(this->_vec + this->_size));}

		reverse_iterator rend(){ return (reverse_iterator(this->_vec));}
		const_reverse_iterator crend(){ return (const_reverse_iterator(this->_vec));}

		bool empty( void ) const {
			return this->_size > 0 ? false : true;
		}

		size_type size( void ) const {
			return this->_size;
		}

		size_type max_size() const {
			return std::numeric_limits<difference_type>::max();
		}

		void reserve( size_type new_cap ){
			if (new_cap <= this->_limit)
				return ;
			else if (new_cap > max_size())
				throw (std::length_error("vector::reserve"));
			this->_limit = new_cap;
			VectorClass<value_type> tmp(*this);
			for (size_type i = 0; i < this->_size; i++){
				tmp._alloc.construct(tmp._vec + i, this->_vec[i]);
			}
			swap(tmp);
		}

		size_t capacity( void ) const {
			return this->_limit;
		}

		void clear(){
			while(this->_size !=0)
				pop_back();
		}

		// iterator insert( iterator pos, const T& value );
		// void insert( iterator pos, size_type count, const T& value );
		// template< typename InputIt >
		// void insert( iterator pos, InputIt first, InputIt last );
		// iterator erase( iterator pos );
		// iterator erase( iterator first, iterator last );
		
		void push_back( const value_type& value){
			if (this->_size==0 && this->_limit==0)
				reserve(1);
			else
				reserve(this->_limit * 2);
			this->_alloc.construct(this->_vec + this->_size, value);
			this->_size++;
		}

		void pop_back(){
			if (this->_size){
				this->_alloc.destroy(this->_vec + this->_size - 1);
				this->_size--;
			}
		}

		void resize( size_type count, value_type value = value_type()){
			if (this->_size > count)
				for (size_type i = this->_size; i > count; i--)
					pop_back();
			else{
				reserve(count);
				for (size_type i = this->_size; i < count; i++)
					push_back(value);
			}
		}

		void swap( VectorClass& other ){
			value_type	size = this->_size;
			value_type	limit = this->_limit;
			pointer	vec = this->_vec;

			this->_size = other._size;
			this->_limit = other._limit;
			this->_vec = other._vec;

			other._size = size;
			other._limit = limit;
			other._vec = vec;
		}

		reference at( size_type pos ){
			if (pos > this->_size - 1)
				throw std::out_of_range("Index out of range");
			return (this->_vec[pos]);
		}

		const_reference at( size_type pos ) const{
			if (pos > this->_size - 1)
				throw std::out_of_range("Index out of range");
			return (this->_vec[pos]);
		}

		reference operator[]( size_type pos ){
			return *(this->_vec + pos);
		}

		const_reference operator[]( size_type pos ) const{
			return *(this->_vec + pos);
		}
};
} //namespace end

#endif