#ifndef MAP_HPP
# define MAP_HPP

#include "Utils.hpp"
#include "vector.hpp"
#include "iterator.hpp"
#include "BST.hpp"


namespace ft{

template< class Key, class T, class Compare = std::less<Key>
, class Allocator = std::allocator<ft::pair<const Key, T> > > class map{
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
		typedef BST<value_type, key_compare>				iterator;
		typedef BST<value_type, key_compare>				const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:

		key_compare		_comp;
		pointer			_map;
		size_type		_limit;
		size_type		_size;
		allocator_type	_alloc;

	public:



		explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ):
			_comp(comp), _map(0), _limit(0), _size(0), _alloc(alloc){}

		// template< class InputIt >
		// map( InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
		// 	_comp(comp), _map(0), _limit(0), _size(0), _alloc(alloc){
		// 	_map = _alloc.construct(0);
		// 	insert()

		// }

		map( const map& other ): _limit(other.limit), _size(other._size), _alloc(other._alloc){
			_map = _alloc.allocate(_limit);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_map[i], other._map[i]);
		}

		map& operator=( const map& other ){
			this->_size = other._size;
			this->_limit = other.limit;
			this->_alloc = other._alloc;
			_map = _alloc.allocate(_limit);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_map[i], other._map[i]);
		}

		allocator_type get_allocator() const{
			return this->_alloc;
		}

		value_type& at( const Key& key );
		const value_type& at( const Key& key ) const;
		// value_type& operator[]( const Key& key ){
		// 	if !key
		// 		insert key
			
		// }
		// iterator begin();
		// const_iterator begin() const;

		// iterator end();
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();
		// const_reverse_iterator rend() const;


		bool empty() const {
			return this->_size == 0;
		}

		size_type size() const{
			return this->_size;
		}

		size_type max_size() const{
			return (std::numeric_limits<difference_type>::max());
		}

		// void clear(){
		// 	for (; _size != 0; _size--)
		// 		erase();
		// }

		// std::pair<iterator, bool> insert( const value_type& value );
		// iterator insert( iterator hint, const value_type& value );
		// template< class InputIt > void insert( InputIt first, InputIt last );
		// void erase( iterator pos );
		// void erase( iterator first, iterator last );
		// size_type erase( const Key& key );
		// void swap( map& other );
		// size_type count( const Key& key ) const;
		// iterator find( const Key& key );
		// const_iterator find( const Key& key ) const;
		// std::pair<iterator,iterator> equal_range( const Key& key );
		// std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
		// iterator lower_bound( const Key& key );
		// const_iterator lower_bound( const Key& key ) const;
		// iterator upper_bound( const Key& key );
		// const_iterator upper_bound( const Key& key ) const;
		// key_compare key_comp() const;
		// map::value_compare value_comp() const;
};

template< class Key, class T, class Compare, class Alloc >
bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

} //namespace end

#endif