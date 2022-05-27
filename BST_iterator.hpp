#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP


#include "iterator.hpp"
#include "Utils.hpp"
#include "BST.hpp"


template <typename key, typename T>
class BST_iter : public ft::iterator<ft::bidirectional_iterator_tag, T>
{
    public:
        typedef key     								key_type;
        typedef T                                       mapped_type;
        typedef ft::pair<const key_type, mapped_type>   value_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef const value_type& 						const_reference;
	
	private:

		typedef typename BST<key_type, mapped_type>::iter	BST_node;
		BST_node _p;
	
	public:

		BST_iter(): _p(NULL){}
		
		~BST_iter(){}

		BST_node getPtr(){ return this->_p; }




};

#endif