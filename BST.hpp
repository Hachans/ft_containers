#ifndef BST_HPP
# define BST_HPP

#include "iterator.hpp"

namespace ft{



template< class Key, class T, class Compare = std::less<Key>
, class Allocator = std::allocator<ft::pair<const Key, T> > > class BST{

	public:

		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

};

} //end namepsace

#endif