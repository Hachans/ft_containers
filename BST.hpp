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
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		struct node{
			struct node *left;
			struct node *right;
			struct node *parent;
			size_type data;
		};

	private:

		node 			*_bst;
		size_type		_size;
		allocator_type	_alloc;

		node *_new_node(value_type &key, node *nptr){
			
			node *new_node = _alloc.allocate(1);
			new_node->data = _alloc.allocate(1);
			_alloc.construct(new_node->data, nptr);
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->parent = nptr;
			_size++;
			return(new_node);
		}

		node *rotateRight(node *nptr){

		}


		size_type max(size_type a, size_type b){ return (a > b)? a : b; }


	public:

		BST(): _bst(NULL), _size(0){}
		bool empty() const{ return this->_size == 0; }
		size_type size() const{ return this->_size; }
		node *insert(value_type &key){
			if(!_bst){
				_new_node(val, _bst);
			}
		}
		~BST(){}

};

} //end namepsace

#endif