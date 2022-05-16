#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "VectorIter.hpp"
#include "Utils.hpp"
#include <vector>


namespace ft{

template < typename T, typename Alloc = std::allocator<T> > class vector{
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

		explicit vector( const allocator_type& alloc = allocator_type()) :
		_vec(0), _limit(0), _size(0), _alloc(alloc){}

		explicit vector( size_type count, const value_type& value = value_type(),
						const allocator_type& alloc = allocator_type()) :
			_limit(count), _size(0), _alloc(alloc){

			_vec = _alloc.allocate(count);
			for (size_type i = 0; i < count; i++){
				_alloc.construct(&_vec[i], value);
				this->_size = i + 1;
			}
		}

		template< class InputIt >
		vector( InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0):
		_limit(0), _size(0), _alloc(alloc){
			_vec = _alloc.allocate(0);
			insert(begin(), first, last);
		}

		~vector(){
			// this->_alloc.deallocate(this->_vec, this->capacity());
		}

		vector(const vector<T>& other) :
			_limit(other._limit),
			_size(other._size),
			_alloc(other._alloc){
			this->_vec = _alloc.allocate(this->_size);
			for (size_type i = 0; i < this->_size; i++)
				_alloc.construct(&this->_vec[i], other._vec[i]);
		}

		vector& operator=(const vector<T>& other){
			this->_size = other._size;
			this->_limit = other._limit;
			this->_alloc = other._alloc;
			this->_vec = _alloc.allocate(this->_size);
			for (size_type i = 0; i < this->_size; i++)
				_alloc.construct(&this->_vec[i], other._vec[i]);
			return *this;
		}

		void assign( size_type count, const T& value ){
			reserve(count);
			this->_size = count;
			for (size_type i = 0; i < this->_size; i++)
				_alloc.construct(&this->_vec[i], value);
		}

		template< typename InputIt > void assign( InputIt first, InputIt last,
		typename ft::enable_if<!ft::is_integral< InputIt >::value >::type* =0){
			size_type diff = last - first;
			size_type i = 0;
			reserve(diff);
			this->_size = diff;
			for (; first != last; first++){
				_alloc.construct(this->_vec + i, *first);
				i++;
			}
		}

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
			return (std::numeric_limits<difference_type>::max());
		}

		void reserve( size_type new_cap ){
			if (new_cap > _alloc.max_size())
				throw (std::length_error("vector::reserve"));
			if(new_cap > this->_limit){
				this->_limit = new_cap;
				vector<value_type> tmp(*this);
				for (size_type i = 0; i < this->_size; i++)
					tmp._alloc.construct(tmp._vec + i, this->_vec[i]);
				swap(tmp);
			}
		}

		size_t capacity( void ) const {
			return this->_limit;
		}

		void clear(){
			while(this->_size !=0)
				pop_back();
		}

		iterator insert( iterator pos, const T& value ){
			size_type it = pos - begin();
			insert(pos, 1, value);
			return(iterator(this->_vec + it));
		}

		void insert( iterator pos, size_type count, const T& value ){
			size_type it = pos - begin();

			if(count + this->size() > this->capacity())
				reserve(size() + count);

			
			for(size_type i = 0; i < count; i++)
				this->_alloc.construct(this->_vec + this->_size + i, value);

			for(int i = this->_size - 1; i >= 0 && i >= (int)it; i--)
				this->_vec[i + count] = this->_vec[i];
			
			for(size_type i = it; i < it + count; i++)
				this->_vec[i] = value;
			this->_size += count;
		}

		template< typename InputIt >
		void insert( iterator pos, InputIt first, InputIt last,
		typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0){
			size_type it = pos - begin();
			size_type count = last - first;

			if(count + this->size() > this->capacity())
				reserve(size() + count);

			for(size_type i = 0; i < count; i++)
				this->_alloc.construct(this->_vec + this->_size + i, *first);

			for(int i = this->_size - 1; i >= 0 && i >= (int)it; i--)
				this->_vec[i + count] = this->_vec[i];
			
			for(size_type i = it; i < it + count; i++)
				this->_vec[i] = *first;
			this->_size += count;
		}

		iterator erase( iterator pos ){
			size_type i = pos - begin();

			for (; i < this->_size - 1; i++)
				this->_vec[i] = this->_vec[i+1];
			this->_size--;
			this->_alloc.destroy(this->_vec + this->_size);

			return pos;
		}

		iterator erase( iterator first, iterator last ){
			size_type i = last - first;

			for(; i > 0; i--)
				erase(first);

			return first;
		}
		
		void push_back( const value_type& value){
			if (this->_size==0 && this->_limit==0)
				reserve(1);
			else if(this->_size == this->_limit)
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

		void swap( vector& other ){
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