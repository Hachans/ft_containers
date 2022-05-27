#ifndef MAP_HPP
# define MAP_HPP

#include "Utils.hpp"
#include "vector.hpp"
#include "iterator.hpp"
#include "BST.hpp"
#include "BST_iterator.hpp"

namespace ft{

template< typename Key, typename T, typename Compare = std::less<Key>,
	typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map{
	public:

		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef BST_iter<Key, T>				iterator;
		typedef BST_iter<Key, T>				const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:

		BST<key_type, mapped_type>	_bst;
		key_compare		_comp;
		allocator_type	_alloc;

	public:


		explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ):
			_bst(), _comp(comp), _alloc(alloc){}

		// template< class InputIt >
		// map( InputIt first, InputIt last, const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type()):
		// 	_comp(comp), _bst(), _alloc(alloc){
		// 	for(;first != last; first++)
		// 		this->_bst._insert(*first);
		// }

		map( const map& other ): _bst(other._bst), _comp(other._comp), _alloc(other._alloc){}

		// map& operator=( const map& other ){
		// 	this->_size = other._size;
		// 	this->_limit = other.limit;
		// 	this->_alloc = other._alloc;
		// 	_map = _alloc.allocate(_limit);
		// 	for (size_type i = 0; i < _size; i++)
		// 		_alloc.construct(&_map[i], other._map[i]);
		// }

		allocator_type get_allocator() const{
			return this->_alloc;
		}

		// value_type& at( const Key& key );
		// const value_type& at( const Key& key ) const;

		// value_type& operator[]( const key_type& key ){
		// 	return (*((this->insert(ft::make_pair(key, mapped_type()))).first)).second;
		// }
			
		iterator begin(){
			return (iterator(this->_bst.minNode(_bst.getRoot())));
		}

		const_iterator cbegin(){
			return (const_iterator(this->_bst.maxNode()));
		}

		iterator end() const{
			return (iterator(this->_bst.maxNode(_bst.getRoot())));
		}

		const_iterator cend() const{
			return (const_iterator(this->_bst.maxNode(_bst.getRoot())));
		}

		// reverse_iterator rbegin(){
		// 	return (reverse_iterator(iterator(this->_bst.maxNode(_bst.getRoot()))));
		// }
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();
		// const_reverse_iterator rend() const;


		bool empty() const {
			return this->_bst.size() == 0;
		}

		size_type size() const{
			return this->_bst.size();
		}

		size_type max_size() const{
			return (std::numeric_limits<difference_type>::max());
		}

		void clear(){
			_bst._clear(_bst.getRoot());
		}

		// ft::pair<iterator, bool> insert( const value_type& key );

		ft::pair<iterator, bool> insert(const value_type& value){

			if(this->_bst._insert(value) != NULL)
				return(ft::make_pair(iterator(), true));
			return(ft::make_pair(iterator(), false));
		}

		void printMap(){
			this->_bst._printMap(_bst.getRoot());
			std::cout << std::endl;
		}

		void minNmax(){
			this->_bst._minNmax();
		}

		// iterator insert( iterator hint, const value_type& value ){
		// 	if(hint != iterator())
		// 		return(this->_bst._insert(value));
		// 	return (iterator());
		// }

		template< class InputIt > void insert( InputIt first, InputIt last ){
			for(; first != last; first++)
				_bst._insert(*first);
		}

		void erase( iterator pos ){
			_bst._erase(pos);
		}

		void erase( iterator first, iterator last ){
			for(; first != last; ++first)
				_bst._erase(*first);
		}

		size_type erase( const key_type& key ){
			return _bst._erase(key);
		}

		void swap( map& other ){
			map<key_type, mapped_type, key_compare, allocator_type> tmp(other);

			other = *this;
			*this = tmp;
		}

		size_type count( const key_type& key ) const{
			if(!_bst._findNode(key))
				return 0;
			return 1;
		}

		// iterator find( const key_type& key ){
		// 	iterator res = _bst._findNode(key);
		// 	if(res)
		// 		return res;
		// 	else 
		// 		return(res = _bst.minNode());
		// }

		// const_iterator find( const key_type& key ) const{
		// 	const_iterator res = _bst._findNode(key);
		// 	if(res)
		// 		return res;
		// 	else 
		// 		return(res = _bst.minNode());
		// }

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
bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
	return lhs < rhs; 
}

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

} //namespace end

#endif