#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP


#include "iterator.hpp"
#include "Utils.hpp"
#include "BST.hpp"

namespace ft{

template <typename key, typename T>
class BST_iter : public ft::iterator<std::bidirectional_iterator_tag, T>
{
    public:
        typedef key     								key_type;
        typedef T                                       mapped_type;
        typedef ft::pair<const key_type, mapped_type>   value_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef const value_type& 						const_reference;
		typedef typename BST<key_type, mapped_type>::node*	BST_node;	
	private:
		BST_node _p;
	
	public:

		BST_iter(): _p(NULL){}

		BST_iter(BST_node nd): _p(nd){}
		
		~BST_iter(){}

		BST_iter(const BST_iter& it) : _p(it._p) {}

		BST_node getPtr() const { return this->_p; }

		BST_iter& operator=(const BST_iter& other){
			_p = other._p;
			return *this;
		}

		BST_iter& operator++(){
			if(!_p)
				return _p->end();
			if(_p->right != NULL){
				_p = _p->right;
				while(_p->left && _p->left != NULL)
					_p = _p->left;
			}
			else{
				BST_node tmp = _p->parent;
				while (tmp != NULL && _p == tmp->right) {
					_p = tmp;
					tmp = tmp->parent;
				}
				_p = tmp;
			}
			return *this;
		}

		BST_iter operator++(int){
			BST_iter tmp = *this;
			++(*this);
			return tmp;
		}

		BST_iter& operator--(){
			if(!_p)
				return *this;
			if(_p->left != NULL){
				_p = _p->left;
				while(_p->right && _p->right != NULL)
					_p = _p->right;
			}
			else{
				BST_node tmp = _p->parent;
				while (tmp != NULL && _p == tmp->left) {
					_p = tmp;
					tmp = tmp->parent;
				}
				_p = tmp;
			}
			return *this;
		}

		BST_iter operator--(int){
			BST_iter tmp = *this;
			--(*this);
			return tmp;
		}

		value_type* operator->(){
			return (&(_p->data));
		}

		value_type& operator*(){
			return (static_cast<BST_node>(_p)->data);
		}

		bool operator==(const BST_iter<key_type, mapped_type>& lhs) {
			return lhs.getPtr() == this->getPtr();
		}

		bool operator!=(const BST_iter<key_type, mapped_type>& lhs) {
			return !(lhs.getPtr() == this->getPtr());
		}
};
}

#endif