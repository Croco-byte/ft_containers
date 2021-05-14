/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:31:25 by user42            #+#    #+#             */
/*   Updated: 2021/05/14 16:06:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

/*
** ----- PRIVATE HELPER FUNCTIONS -----
*/
template < class K, class T, class C, class A >
void		ft::map<K,T,C,A>::parents_preorder(Node * root)
{
	if (root == 0)
		return ;

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	parents_preorder(root->left);
	parents_preorder(root->right);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *				ft::map<K,T,C,A>::iterator_node(iterator position)
{
	Node * first = leftmost(this->_root)->parent;

	if (this->empty())
		return (0);
	iterator offset_it(first);
	int offset(0);
	while (offset_it++ != position)
		offset++;
	
	Node * pos_node = first;
	for (int i = 0; i < offset; i++)
		pos_node =  next(pos_node);
	return (pos_node);
}

template < class K, class T, class C, class A >
void											ft::map<K,T,C,A>::setPastTheEnd(Node * last)
{
	Node * past_end = new Node;
	last->right = past_end;
	past_end->parent = last;
}

template < class K, class T, class C, class A >
void											ft::map<K,T,C,A>::setBeforeBeginning(Node * first)
{
	Node * before_beg = new Node;
	first->left = before_beg;
	before_beg->parent = first;
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *				ft::map<K,T,C,A>::keyInTree(key_type const & k) const
{
	Node * iter = leftmost(this->_root)->parent;
	Node * past_end = rightmost(this->_root);
	while (iter != past_end)
	{
		if (iter->data.first == k)
			return (iter);
		iter = next(iter);
	}
	return (0);
}

template < class K, class T, class C, class A >
void											ft::map<K,T,C,A>::recursive_postorder_deletion(Node * root)
{
	if (root == 0)
	return ;

	recursive_postorder_deletion(root->left);
	recursive_postorder_deletion(root->right);
	delete root;
}

template < class K, class T, class C, class A >
void											ft::map<K,T,C,A>::recursive_copy(Node * root, Node * copyRoot)
{
	if (root == 0)
		return ;
	
	if (root->left)
	{
		Node * newLeftNode = new Node(root->left->data);
		copyRoot->left = newLeftNode;
		newLeftNode->parent = copyRoot;
		recursive_copy(root->left, copyRoot->left);
	}

	if (root->right)
	{
		Node * newRightNode = new Node(root->right->data);
		copyRoot->right = newRightNode;
		newRightNode->parent = copyRoot;
		recursive_copy(root->right, copyRoot->right);
	}
}


template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *				ft::map<K,T,C,A>::leftmost(Node * node)
{
	if (!node)
		return (0);
	while (node->left)
		node = node->left;
	return (node);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *				ft::map<K,T,C,A>::next(Node * node)
{
	if (!node)
		return (0);
	if (node->right != 0)					// Si l'on a des éléments supérieurs au node actuel, alors l'élément suivant sera le plus petit de ces éléments supérieurs (celui le plus à gauche)
		return (leftmost(node->right));
	Node * parent = node->parent;
	if (!parent)
		return (0);
	if (node == parent->left)				// Si l'on se situe dans le left subtree, alors on est inférieur au parent, et à tous les nodes situés au dessus / à droite du parent. Notre élément suivant est donc le parent
		return (parent);
	while (parent && node != parent->left)	// On se situe dans le right subtree. On remonte jusqu'à un noeud qui est un branche de gauche, et on retourne son parent.
	{										// En effet, on est dans le right subtree et on est pas une branche de gauche. Tous les éléments du subtree actuel
		node = parent;						// (y compris le root du subtree actuel) seront inférieurs à notre node. Pour trouver l'élément directement supérieur,
		parent = node->parent;				// il faut donc remonter à la racine du subtree actuel (un noeud qui est la branche de gauche d'un autre noeud),
	}										// et renvoyer le parent de cette racine de subtree.
	return (parent);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *				ft::map<K,T,C,A>::rightmost(Node * node)
{
	if (!node)
		return (0);
	while (node->right)
		node = node->right;
	return (node);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *				ft::map<K,T,C,A>::prev(Node * node)
{
	if (!node)
		return (0);
	if (node->left != 0)
		return (rightmost(node->left));
	Node * parent = node->parent;
	if (!parent)
		return (0);
	if (node == parent->right)
		return (parent);
	while (parent && node != parent->right)
	{
		node = parent;
		parent = node->parent;
	}
	return (parent);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *				ft::map<K,T,C,A>::range_to_BST(InputIterator first, InputIterator last, int start, int end)
{
	if (start > end)
		return (0);

	iterator tmp = first;
	int mid = (start + end) / 2;
	for (int i = 0; i < mid; i++)
		tmp++;
	
	Node * root = new Node(*tmp);

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	root->left = range_to_BST(first, last, start, mid - 1);
	root->right = range_to_BST(first, last, mid + 1, end);
	return (root);
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::insert_from_empty(ft::Pair<iterator,bool> & result, value_type const & val)
{
	Node * new_node = new Node(val);
	this->_root = new_node;
	this->setBeforeBeginning(this->_root);
	this->setPastTheEnd(this->_root);

	result.first = this->_root;
	result.second = true;
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::insert_smallest(Node * prec, value_type const & val)
{
	Node * new_node = new Node(val);

	new_node->parent = prec;
	new_node->left = prec->left;
	prec->left->parent = new_node;
	prec->left = new_node;
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::insert_biggest(Node * prec, value_type const & val)
{
	Node * new_node = new Node(val);

	new_node->parent = prec;
	new_node->right = prec->right;
	prec->right->parent = new_node;
	prec->right = new_node;
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *								ft::map<K,T,C,A>::recursive_insert(Node * node, value_type const & val)
{
	if (!node)
		return new Node(val);
	
	if (val.first > node->data.first)
	{
		node->right = recursive_insert(node->right, val);
		if (node->right)
			node->right->parent = node;
	}
	else
	{
		node->left = recursive_insert(node->left, val);
		if (node->left)
			node->left->parent = node;
	}
	return (node);
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::delete_node(Node * pos)
{
	if (pos->left == 0 && pos->right == 0)
	{
		if (pos->parent && pos == pos->parent->left)
		{
			pos->parent->left = 0;
			delete pos;
		}
		else if (pos->parent && pos == pos->parent->right)
		{
			pos->parent->right = 0;
			delete pos;
		}
	}
	else if (pos->left == 0)
	{
		if (pos->parent && pos == pos->parent->left)
		{
			pos->right->parent = pos->parent;
			pos->parent->left = pos->right;
			delete pos;
		}
		else if (pos->parent && pos == pos->parent->right)
		{
			pos->right->parent = pos->parent;
			pos->parent->right = pos->right;
			delete pos;
		}
	}
	else if (pos->right == 0)
	{
		if (pos->parent && pos == pos->parent->left)
		{
			pos->left->parent = pos->parent;
			pos->parent->left = pos->left;
			delete pos;
		}
		else if (pos->parent && pos == pos->parent->right)
		{
			pos->left->parent = pos->parent;
			pos->parent->right = pos->left;
			delete pos;
		}
	}
	else
	{
		Node * successor = next(pos);
		pos->data.first = successor->data.first;
		pos->data.second = successor->data.second;
		delete_node(successor);
	}
}



/*
** ----- CONSTRUCTORS / DESTRUCTORS -----
*/
template < class K, class T, class C, class A >
ft::map<K,T,C,A>::map(): _root(0), _size(0)
{}

template < class K, class T, class C, class A >
ft::map<K,T,C,A>::map(InputIterator first, InputIterator last)
{
	int range(0);
	for (iterator it = first; it != last; it++)
		range++;
	this->_size = range;

	this->_root = range_to_BST(first, last, 0, range - 1);
	parents_preorder(this->_root);
	this->setBeforeBeginning(leftmost(this->_root));
	this->setPastTheEnd(rightmost(this->_root));
}

template < class K, class T, class C, class A >
ft::map<K,T,C,A>::map(map const & src)
{
	this->_size = src._size;
	if (src.empty())
	{
		this->_root = 0;
		return ;
	}
	
	this->_root = new Node(src._root->data);
	recursive_copy(src._root, this->_root);
}

template < class K, class T, class C, class A >
ft::map<K,T,C,A>::~map()
{ if (!this->empty()) recursive_postorder_deletion(this->_root); }



/*
** ----- OPERATOR OVERLOADS -----
*/
template < class K, class T, class C, class A >
ft::map<K,T,C,A> &						ft::map<K,T,C,A>::operator=(map const & rhs)
{
	recursive_postorder_deletion(this->_root);
	this->_size = rhs._size;
	if (rhs.empty())
	{
		this->_root = 0;
		return (*this);
	}
	
	this->_root = new Node(rhs._root->data);
	recursive_copy(rhs._root, this->_root);
	return (*this);
}



/*
** ----- ITERATOR FUNCTIONS -----
*/
template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::iterator							ft::map<K,T,C,A>::begin(void)
{
	iterator it(leftmost(this->_root)->parent);
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::const_iterator					ft::map<K,T,C,A>::begin(void) const
{
	const_iterator it(leftmost(this->_root)->parent);
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::iterator							ft::map<K,T,C,A>::end(void)
{
	iterator it(rightmost(this->_root));
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::const_iterator					ft::map<K,T,C,A>::end(void) const
{
	const_iterator it(rightmost(this->_root));
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::reverse_iterator					ft::map<K,T,C,A>::rbegin(void)
{
	reverse_iterator it(this->end());
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::const_reverse_iterator			ft::map<K,T,C,A>::rbegin(void) const
{
	const_reverse_iterator it(this->end());
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::reverse_iterator					ft::map<K,T,C,A>::rend(void)
{
	reverse_iterator it(this->begin());
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::const_reverse_iterator			ft::map<K,T,C,A>::rend(void) const
{
	const_reverse_iterator it(this->begin());
	return (it);
}



/*
** ----- CAPACITY FUNCTIONS -----
*/
template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::size_type						ft::map<K,T,C,A>::size(void) const
{ return (this->_size); }

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::size_type		ft::map<K,T,C,A>::max_size(void) const
{ return (std::numeric_limits<size_type>::max() / (sizeof(Node) + sizeof(pointer))); }

template < class K, class T, class C, class A >
bool														ft::map<K,T,C,A>::empty(void) const
{ return (this->_size <= 0); }



/*
** ----- ELEMENT ACCESS -----
*/
template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::mapped_type &					ft::map<K,T,C,A>::operator[](key_type const & k)
{
	value_type pair = ft::Pair<K,T>::make_pair(k,mapped_type());
	ft::Pair<iterator,bool> result = this->insert(pair);
	return ((*(result.first)).second);
}



/*
** ----- MODIFYERS -----
*/
template < class K, class T, class C, class A >
ft::Pair<typename ft::map<K,T,C,A>::iterator,bool>				ft::map<K,T,C,A>::insert(value_type const & val)
{
	ft::Pair<iterator,bool> result;

	if (this->empty())
	{
		this->_size++;
		insert_from_empty(result, val);
		return (result);
	}

	Node * pos = this->keyInTree(val.first);
 	if (pos)
	{
		result.first = pos;
		result.second = false;
	}
	else
	{
		this->_size++;
		Node * biggest = rightmost(this->_root)->parent;
		Node * smallest = leftmost(this->_root)->parent;
		if (val.first < smallest->data.first)
			insert_smallest(smallest, val);
		else if (val.first > biggest->data.first)
			insert_biggest(biggest, val);
		else
			recursive_insert(this->_root, val);
		result.first = this->keyInTree(val.first);
		result.second = true;
	}
	return(result);
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::insert(InputIterator first, InputIterator last)
{
	iterator tmp = first;
	for (; tmp != last; tmp++)
		this->insert(*tmp);
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::erase(iterator position)
{
	if (this->empty())
		return ;
	Node * pos_node = iterator_node(position);
	delete_node(pos_node);
	this->_size--;
	if (this->_size == 0)
	{
		delete leftmost(this->_root);
		delete rightmost(this->_root);
	}
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::size_type							ft::map<K,T,C,A>::erase(key_type const & k)
{
	Node * pos_node = keyInTree(k);
	if (!pos_node)
		return (0);
	this->erase(pos_node);
	return (1);
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::erase(iterator first, iterator last)
{
	size_type offset(0);
	iterator it = first;

	for (iterator tmp = first; tmp != last; tmp++)
		offset++;
	for (size_type i = 0; i < offset; i++)
	{
		iterator temp = it;
		temp++;
		this->erase(it);
		it = temp;
	}
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::swap(map & x)
{
	Node *		tmpRoot = this->_root;
	size_type	tmpSize = this->_size;

	this->_root = x._root;
	this->_size = x._size;

	x._root = tmpRoot;
	x._size = tmpSize;
}

template < class K, class T, class C, class A >
void															ft::map<K,T,C,A>::clear(void)
{
	if (!this->empty())
		recursive_postorder_deletion(this->_root);
	this->_size = 0;
}



/*
** ----- OBSERVERS -----
*/
template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::key_compare							ft::map<K,T,C,A>::key_comp(void) const
{
	C internal_comp;
	return (internal_comp);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::value_compare						ft::map<K,T,C,A>::value_comp(void) const
{
	C internal_comp;
	value_compare v_comp(internal_comp);
	return (v_comp);
}



/*
** ----- OPERATIONS -----
*/
template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::iterator								ft::map<K,T,C,A>::find(key_type const & k)
{
	Node * pos = keyInTree(k);
	if (pos)
		return (pos);
	else
		return (this->end());
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::const_iterator						ft::map<K,T,C,A>::find(key_type const & k) const
{
	Node * pos = keyInTree(k);
	if (pos)
		return (pos);
	else
		return (this->end());
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::size_type							ft::map<K,T,C,A>::count(key_type const & k) const
{
	if (keyInTree(k))
		return (1);
	return (0);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::iterator								ft::map<K,T,C,A>::lower_bound(key_type const & k)
{
	C internal_comp;
	iterator it = this->begin();
	for (; it != this->end(); it++)
	{
		if (!internal_comp(it->first, k))
			return (it);
	}
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::const_iterator						ft::map<K,T,C,A>::lower_bound(key_type const & k) const
{
	C internal_comp;
	const_iterator it = this->begin();
	for (; it != this->end(); it++)
	{
		if (!internal_comp(it->first, k))
			return (it);
	}
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::iterator								ft::map<K,T,C,A>::upper_bound(key_type const & k)
{
	C internal_comp;
	iterator it = this->begin();
	for (; it != this->end(); it++)
	{
		if (!internal_comp(it->first, k))
			return (++it);
	}
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::const_iterator						ft::map<K,T,C,A>::upper_bound(key_type const & k) const
{
	C internal_comp;
	const_iterator it = this->begin();
	for (; it != this->end(); it++)
	{
		if (!internal_comp(it->first, k))
			return (++it);
	}
	return (it);
}

template < class K, class T, class C, class A >
ft::Pair<typename ft::map<K,T,C,A>::iterator, typename ft::map<K,T,C,A>::iterator>		ft::map<K,T,C,A>::equal_range(key_type const & k)
{
	iterator itKey = this->find(k);
	if (itKey == this->end())
	{
		iterator result = lower_bound(k);
		ft::Pair<iterator,iterator> pair(result, result);
		return (pair);
	}
	else
	{
		iterator from = lower_bound(k);
		iterator to = upper_bound(k);
		ft::Pair<iterator,iterator> pair(from, to);
		return (pair);
	}
}

template < class K, class T, class C, class A >
ft::Pair<typename ft::map<K,T,C,A>::const_iterator, typename ft::map<K,T,C,A>::const_iterator>		ft::map<K,T,C,A>::equal_range(key_type const & k) const
{
	iterator itKey = this->find(k);
	if (itKey == this->end())
	{
		const_iterator result = lower_bound(k);
		ft::Pair<const_iterator,const_iterator> pair(result, result);
		return (pair);
	}
	else
	{
		const_iterator from = lower_bound(k);
		const_iterator to = upper_bound(k);
		ft::Pair<const_iterator,const_iterator> pair(from, to);
		return (pair);
	}
}
