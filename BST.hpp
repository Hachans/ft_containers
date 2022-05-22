#ifndef BST_HPP
# define BST_HPP

#include "iterator.hpp"

namespace ft{

template< class Key, class T, class Compare = std::less<Key>
, class Allocator = std::allocator<ft::pair<const Key, T> > > class BST{

	public:

		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		struct node{
			node *left;
			node *right;
			node *parent;
			pointer data;
		};

	private:

		node 			*_bst;
		size_type		_size;
		allocator_type	_alloc;
		std::allocator<node> _node_alloc;

		node *_new_node(const value_type &key, node *nptr){
			
			node *new_node = _node_alloc.allocate(1);
			new_node->data = _alloc.allocate(1);
			_alloc.construct(new_node->data, key);
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->parent = nptr;
			_size++;
			return(new_node);
		}

	public:

		void printMap(node *nptr){
			if(nptr != NULL){
				std::cout << nptr->data << " ";
				printMap(nptr->left);
				printMap(nptr->right);
			}
			std::cout << std::endl;
		}

		BST(): _bst(NULL), _size(0){}

		BST& operator=(const BST & other){
			this->_size = other._size;
			this->_alloc = other._alloc;
			this->_bst = other->_bst;
			return *this;
		}

		bool empty() const{ return this->_size == 0; }

		size_type size() const{ return this->_size; }

		node *_insert(const value_type &key){
			// printMap(nptr);
			if(!_bst)
				return(_new_node(key, _bst));
			if(key < _bst->data)
				_bst->left = _insert(_bst->left, key);
			if(key > _bst->data)
				_bst->right = _insert(_bst->right, key);
			else
				return _bst; // in case of equal value
		}
		~BST(){}

};

} //end namepsace

#endif