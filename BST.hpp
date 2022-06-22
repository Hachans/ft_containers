#ifndef BST_HPP
# define BST_HPP

#include "iterator.hpp"
#include "Utils.hpp"


#include <cstdio>
namespace ft{

template< typename Key, typename T, typename Compare = std::less<Key>
, typename Allocator = std::allocator<ft::pair<const Key, T> > > class BST{

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
			value_type data;
		};

	private:

		node 			*_bst;
		size_type		_size;
		allocator_type	_alloc;
		std::allocator<node> _node_alloc;

	public:
		key_compare	_comp;

		BST(): _bst(NULL), _size(0){}

		BST& operator=(const BST& other){
			_bst = other._bst;
			_size = other._size;
			_alloc = other._alloc;
			_node_alloc = other._node_alloc;
			return *this;
		}

		bool empty() const{ return this->_size == 0; }

		size_type size() const{ return this->_size; }

		node *_new_node(const value_type &value, node* left = NULL, node* right = NULL, node* parent = NULL){
			
			node *new_node = _node_alloc.allocate(1);

			_alloc.construct(&(new_node->data), value);
			new_node->left = left;
			new_node->right = right;
			new_node->parent = parent;
			_size++;
			return(new_node);
		}

		size_type max_size() const{
			return(this->_alloc.max_size());
		}

		node* getRoot() const{
			return this->_bst;
		}

		bool _isLeaf(node *bst) const{
			return bst->left == NULL && bst->right == NULL;
		}

		bool _isEmpty(node *bst) const{
			return bst == NULL;
		}

		void _clear(node* nd = NULL){
			if (_bst == NULL)
				return ;
			if (nd == NULL)
				nd = _bst;
			if (nd->right)
				_clear(nd->right);
			if (nd->left)
				_clear(nd->left);
			if(_isLeaf(nd)){
				if(nd->parent && nd->parent->right == nd)
					nd->parent->right = NULL;
				else if(nd->parent && nd->parent->left == nd)
					nd->parent->left = NULL;
				_node_alloc.deallocate(nd, 1);
			}
			if(nd == _bst)
				_bst = NULL;
			_size--;
		}

		node* _findNode(const key_type& key) const{

			node* res = _bst;

			for (; res != NULL && extract_key(res->data) != key;)
			{
				if (_comp(key, extract_key(res->data)))
					res = res->left;
				else
					res = res->right;
			}
			return res;
		}

		node* _insert(const value_type& value){
			node* found;
			node* tmp;
		
			if(!_bst){
				_bst = _new_node(value);
				return _bst;
			}
			found = _findNode(value.first);
			if(found)
				return found;
			tmp = NULL;
			found = _bst;
			while(found != NULL){
				tmp = found;
				if(value.first < found->data.first)
					found = found->left;
				else
					found = found->right;
			}
			found = _new_node(value, NULL, NULL, tmp);
			if(value.first < tmp->data.first)
				tmp->left = found;
			else
				tmp->right = found;
			return found;
		}
		
		void _printMap(node* root)
		{
			if (root != NULL) {
				_printMap(root->left);
				std::cout << root->data.first << ":" << root->data.second << " ";
				_printMap(root->right);
			}
		}

		void _minNmax()
		{
			if(!_bst)
				return ;
			node* min_node = minNode(_bst);
			node* max_node = maxNode(_bst);
			std::cout << "Min node: (" << min_node->data.first << ", " << min_node->data.second << ")\n";
			std::cout << "Max node: (" << max_node->data.first << ", " << max_node->data.second << ")\n";
		}

		node* minNode(node* bst) const{
			node* current = bst;
		
			while (current && current->left != NULL)
				current = current->left;
			return current;
		}

		node* 	maxNode(node* bst) const{
			node* current = bst;
		
			while (current && current->right != NULL)
				current = current->right;
			return current;
		}

		void changeData(node* &curr, const value_type& val){
			_alloc.construct(&(curr->data), val);
		}

		void _deleteNode(node* bst){

			node* tmp = NULL;
			if(!bst)
				return ;
			if(_isLeaf(bst))
				_clear(bst);
			else if(!_isLeaf(bst))
			{
				if(bst->left)
					tmp = maxNode(bst->left);
				else if(bst->right)
					tmp = minNode(bst->right); 
				changeData(bst, tmp->data);
				_deleteNode(tmp);
			}
		}

		size_type _erase(const key_type &key){
			 
			 node*	found = _findNode(key);

			if(!_bst || !found)
				return 0;
			_deleteNode(found);
			return 1;
		}

		node*	begin(void) const{
			node*	tmp = this->_bst;

			while (tmp && tmp->left)
				tmp = tmp->left;
			return (tmp);
		}

		node*	end(void) const{
			node*	tmp = this->_bst;

			while (tmp && tmp->right)
				tmp = tmp->right;
			tmp = tmp->right;
			return (tmp);
		}
		
		node*	rbegin(void) const{
			node*	tmp = this->_bst;

			while (tmp && tmp->right)
				tmp = tmp->right;
			return (tmp);
		}

		node*	rend(void) const{
			node*	tmp = this->_bst;

			while (tmp && tmp->left)
				tmp = tmp->left;
			tmp = tmp->left;
			return (tmp);
		}


		~BST(){}
};

template <class value>
value extract_key(value v) {return v;}

template <class first, class second>
first extract_key(ft::pair<first, second> pair){ return pair.first;}

} //end namepsace

#endif