#ifndef BST_HPP
# define BST_HPP

#include "iterator.hpp"

namespace ft{



template< class Key, class T, class Compare = std::less<Key>
, class Allocator = std::allocator<ft::pair<const Key, T> > > class BST{

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

		typedef struct node{
			struct node *left;
			struct node *right;
			struct node *parent;
			size_type data;
		}node;

	private:

		node 			*_node;
		allocator_type	_alloc;

	public:

		BST(const allocator_type& alloc = allocator_type()): _alloc(alloc){
			_node->data = 0;
			_node->left = NULL;
			_node->right = NULL;
			_node->parent = NULL;
		}
		~BST(){}

};

} //end namepsace

#endif