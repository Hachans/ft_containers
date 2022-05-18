#ifndef MAP_HPP
# define MAP_HPP

#include "Utils.hpp"
#include "vector.hpp"
#include "iterator.hpp"
#include "BST.hpp"


namespace ft{

template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > class map{
	public:

		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const Key, T>						value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef BST<value_type>								iterator;
		typedef BST<value_type>								const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:

		pointer			_map;
		size_type		_limit;
		size_type		_size;
		allocator_type	_alloc;

	public:



		// explicit map( const Compare& comp, const Allocator& alloc = Allocator() ): _map(0), _limit(0), _size(0), _alloc(alloc){}

		// template< class InputIt >
		// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ){}

		map( const map& other ): _limit(other.limit), _size(other._size), _alloc(other._alloc){
			_map = _alloc.allocate(_limit);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_map[i], other._map[i]);
		}

		map& operator=( const map& other ){
			this->_size = other._size;
			this->_limit = other.limit;
			this->_alloc = other._alloc;
		}

		allocator_type get_allocator() const{ return this->_alloc; }
		bool empty() const { return this->_size == 0; }
		size_type size() const{ return this->_size; }
		size_type max_size() const{ return (std::numeric_limits<difference_type>::max()); }

};

} //namespace end

#endif