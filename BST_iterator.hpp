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
		BST_node _first;
		BST_node _last;
	
	public:

		BST_iter(): _p(NULL), _first(NULL), _last(NULL){}

		BST_iter(BST_node nd, BST_node f = NULL, BST_node l = NULL): _p(nd), _first(f), _last(l){}
		
		~BST_iter(){}

		BST_iter(const BST_iter& it) : _p(it._p), _first(it._first), _last(it._last) {}

		BST_node getPtr() const { return this->_p; }
		BST_node getf() const { return this->_first; }
		BST_node getl() const { return this->_last; }

		BST_iter& operator=(const BST_iter& other){
			_p = other._p;
			_first = other._first;
			_last = other._last;
			return *this;
		}

		BST_iter& operator++(){
			if(!_p)
				_p = _first;
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
				_p = _last;
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