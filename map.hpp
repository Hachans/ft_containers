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
		typedef ft::BST_iter<Key, T>						iterator;
		typedef const ft::BST_iter<Key, T>					const_iterator;
		typedef ft::reverse_BST_iter<Key, T>				reverse_iterator;
		typedef const ft::reverse_BST_iter<Key, T>			const_reverse_iterator;

	private:

		BST<key_type, mapped_type>	_bst;
		key_compare		_comp;
		allocator_type	_alloc;

	public:


		explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ):
			_bst(), _comp(comp), _alloc(alloc){}

		template< class InputIt >
		map( InputIt first, InputIt last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()):
			_bst(), _comp(comp), _alloc(alloc){
			for(;first != last; first++)
				this->_bst._insert(*first);
		}

		map( const map& other ): _bst(other._bst), _comp(other._comp), _alloc(other._alloc){}

		map& operator=( const map& other ){
			this->_alloc = other._alloc;
			this->_comp = other._comp;

			iterator tmp = other.begin();
			for(;tmp != other.end(); tmp++){
				this->_bst._insert(*tmp);
			}
			return *this;
		}

		class value_compare
		{
			friend class map;

			protected:
				key_compare	comp;
				value_compare(Compare c) : comp(c) {}

			public:
				typedef bool 		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;

				bool operator()(const value_type & x, const value_type & y) const{
					return comp(x.first, y.first);
				}
		};

		allocator_type get_allocator() const{
			return this->_alloc;
		}

		mapped_type& at( const key_type& key ){

			iterator tmp = find(key);

			if(tmp == end())
				throw std::out_of_range("map::at");
			else
				return tmp->second;
		}

		const mapped_type& at( const key_type& key ) const{
			iterator tmp = find(key);

			if(tmp == end())
				throw std::out_of_range("map::at");
			else
				return tmp->second;
		}

		mapped_type& operator[]( const key_type& key ){
			return ((*((this->insert(ft::make_pair(key,mapped_type()))).first)).second);
		}
			
		iterator begin(){
			return (iterator(_bst.begin(), _bst.begin(), _bst.rbegin()));
		}

		const_iterator begin() const {
			return (const_iterator(_bst.begin(), _bst.begin(), _bst.rbegin()));
		}

		iterator end(){
			return (iterator(NULL, _bst.begin(), _bst.rbegin()));
		}

		const_iterator end() const{
			return (const_iterator(NULL, _bst.begin(), _bst.rbegin()));
		}

		reverse_iterator rbegin(){
			return (reverse_iterator(_bst.rbegin(), _bst.begin(), _bst.rbegin()));
		}

		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator(_bst.rbegin(), _bst.begin(), _bst.rbegin()));
		}

		reverse_iterator rend(){
			return (reverse_iterator(NULL, _bst.begin(), _bst.rbegin()));
		}
		const_reverse_iterator rend() const{
			return (const_reverse_iterator(NULL, _bst.begin(), _bst.rbegin()));
		}

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

		ft::pair<iterator, bool> insert(const value_type& value){

			iterator it(_bst._insert(value));
			if(it != iterator())
				return(ft::make_pair(it, true));
			else
				return(ft::make_pair(it, false));
		}

		void printMap(){
			this->_bst._printMap(_bst.getRoot());
			std::cout << std::endl;
		}

		void minNmax(){
			this->_bst._minNmax();
		}

		iterator insert( iterator hint, const value_type& value ){
			if(hint != iterator())
				return(this->_bst._insert(value));
			return (iterator());
		}

		template< class InputIt > void insert( InputIt first, InputIt last ){
			for(; first != last; first++)
				_bst._insert(*first);
		}

		void erase( iterator pos ){
			_bst._erase((*pos).first);
		}

		void erase( iterator first, iterator last ){
			for(; first != last; first++)
				_bst._erase((*first).first);
		}

		size_type erase( const key_type& key ){
			return _bst._erase(key);
		}

		void swap( map& other ){
			map<key_type, mapped_type, key_compare, allocator_type> tmp(other);
			// std::cout << tmp.size() << std::endl;
			// std::cout << this->size() << std::endl << std::endl;

			*this = other;
			other = tmp;

			// std::cout << tmp.size() << std::endl;
			// std::cout << this->size() << std::endl;
			
		}

		size_type count( const key_type& key ) const{
			if(!_bst._findNode(key))
				return 0;
			return 1;
		}

		iterator find( const key_type& key ){
			return (iterator(this->_bst._findNode(key)));
		}

		const_iterator find( const key_type& key ) const{
			const_iterator res = _bst._findNode(key);
			if(res != NULL)
				return res;
			else 
				return(const_iterator(end()));
		}

		ft::pair<iterator,iterator> equal_range( const key_type& key ){
			return(ft::make_pair(lower_bound(key), upper_bound(key)));
		}

		ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const{
			return(ft::make_pair(lower_bound(key), upper_bound(key)));
		}

		iterator lower_bound( const key_type& key ){
			iterator it  = begin();

			while (it != end() && _comp(it->first, key))
				++it;
			return it;
		}

		const_iterator lower_bound( const key_type& key ) const{
			const_iterator it  = begin();

			while (it != end() && _comp(it->first, key))
				++it;
			return it;
		}

		iterator upper_bound( const key_type& key ){
			iterator it  = begin();

			while (it != end() && !_comp(key, it->first))
				++it;
			return it;
		}
		const_iterator upper_bound( const key_type& key ) const{
			const_iterator it  = begin();

			while (it != end() && !_comp(key, it->first))
				++it;
			return it;
		}

		key_compare key_comp() const{
			return this->_comp;
		}

		value_compare value_comp() const{
			return (value_compare(_comp));
		}

};

template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ){
		lhs.swap(rhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
	return !(lhs == rhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); 
}

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
	return !(rhs < lhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
	return !(lhs < rhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
	return lhs > rhs;
}

} //namespace end

#endif