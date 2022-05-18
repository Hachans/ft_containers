#ifndef BST_HPP
# define BST_HPP

#include "iterator.hpp"

namespace ft{

template < typename T > class BST{

	public:

		typedef std::size_t							size_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::ptrdiff_t						difference_type;
		typedef std::random_access_iterator_tag		iterator_catregory;
		
	private:

		value_type data;
		BST *left;
		BST *right;

	public:

		BST(): data(0), left(NULL), right(NULL){}
		BST( size_type val ): data(val), left(NULL), right(NULL){}
		
		BST* insert( BST* root, size_type val ){
			if(!root)
				return new BST(val);
			if(val > root->data)
				root->right = insert(root->right, val);
			else
				root->left = insert(root->left, val);
			return root;
			
		}
		~BST(){}
};

} //end namepsace

#endif