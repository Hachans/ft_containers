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
			value_type data;
			// pointer data;
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

		node *_new_node(const value_type &value, node* left = NULL, node* right = NULL){
			
			node *new_node = _node_alloc.allocate(1);

			// new_node->data = _alloc.allocate(1);
			_alloc.construct(&(new_node->data), value);
			new_node->left = left;
			new_node->right = right;
			return(new_node);
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
			if(_isLeaf(nd))
				delete nd;
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
			node* found = _insertPos(value);;
		
			if(found && extract_key(found->data) == extract_key(value))
				return NULL;
			node* new_node = _new_node(value);
			if(found == NULL)
				_bst = new_node;
			else if(_comp(extract_key(value), extract_key(found->data)))
				found->left = new_node;
			else
				found->right = new_node;
			_size++;
			return found;
		}

		node*	_insertPos(const value_type& value)
		{
			node* p = _bst;

			for (; p != NULL && extract_key(p->data) != extract_key(value);)
			{
				if (_comp(extract_key(value), extract_key(p->data)))
				{
					if (p->left == NULL)
						return p;
					p = p->left;
				}
				else
				{
					if (p->right == NULL)
						return p;
					p = p->right;
				}
			}
			return p;
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

		node* maxNode(node* bst) const{
			node* current = bst;
		
			while (current && current->right != NULL)
				current = current->right;
			return current;
		}

		void changeData(node* &curr, const value_type& val){
			_alloc.construct(&(curr->data), val);
		}

		void _deleteNode(node* &bst, const key_type& key){
			if(!bst)
				return ;
			if(bst->data.first == key)
			{
				if(bst->right && bst->left){
					node* tmp = minNode(bst->right);
					changeData(bst, tmp->data);
					_deleteNode(bst->right, tmp->data.first);
				}
				else{
					if(_isLeaf(bst))
						bst = NULL;
					else if(bst->left)
						bst = bst->left;
					else
						bst = bst->right;
				}
			}
			else if(key < bst->data.first)
				_deleteNode(bst->left, key);
			else
				_deleteNode(bst->right, key);
		}

		size_type _erase(const key_type &key){
			if(!_bst)
				return 0;
			_deleteNode(_bst, key);
			_size--;
			return 1;
		}

		node*	begin(void) const{
			node*	tmp = this->_bst;

			while (tmp && tmp->left)
				tmp = tmp->left;
			return (tmp);
		}
		
		node*	rbegin(void) const{
			node*	tmp = this->_bst;

			while (tmp && tmp->right)
				tmp = tmp->right;
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