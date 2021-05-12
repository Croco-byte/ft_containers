/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:31:25 by user42            #+#    #+#             */
/*   Updated: 2021/05/11 19:20:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

/*
** PRIVATE HELPER FUNCTIONS
*/
template < class K, class T, class C, class A >
void				ft::map<K,T,C,A>::recursive_postorder_deletion(Node * root)
{
	if (root == 0)
	return ;

	recursive_postorder_deletion(root->left);
	recursive_postorder_deletion(root->right);
	delete root;
}


template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *		ft::map<K,T,C,A>::leftmost(Node * node)
{
	if (!node)
		return (0);
	while (node->left)
		node = node->left;
	return (node);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *		ft::map<K,T,C,A>::next(Node * node)
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
void		ft::map<K,T,C,A>::iterative_inorder_print(void) const
{
	Node * iterator = leftmost(this->_root);
	while (iterator)
	{
		std::cout << iterator->data.first << " ";
		iterator = next(iterator);
	}
	std::cout << std::endl;
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *		ft::map<K,T,C,A>::rightmost(Node * node)
{
	if (!node)
		return (0);
	while (node->right)
		node = node->right;
	return (node);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::Node *		ft::map<K,T,C,A>::prev(Node * node)
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
typename ft::map<K,T,C,A>::Node *		ft::map<K,T,C,A>::range_to_BST(InputIterator first, InputIterator last, int start, int end)
{
	if (start > end)
		return (0);

	iterator tmp = first;
	int mid = (start + end) / 2;
	for (int i = 0; i < mid; i++)
		tmp++;
	
	Node * root = new Node(*tmp);

	root->left = range_to_BST(first, last, start, mid - 1);
	root->right = range_to_BST(first, last, mid + 1, end);
	return (root);
}



/*
** CONSTRUCTORS / DESTRUCTORS
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
}

template < class K, class T, class C, class A >
ft::map<K,T,C,A>::~map()
{ recursive_postorder_deletion(this->_root); }


/*
** ITERATOR FUNCTIONS
*/
template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::iterator			ft::map<K,T,C,A>::begin(void)
{
	iterator it(leftmost(this->_root));
	return (it);
}

template < class K, class T, class C, class A >
typename ft::map<K,T,C,A>::iterator			ft::map<K,T,C,A>::end(void)
{
	iterator it(0);
	return (it);
}

































/* DEBUG / EXPERIMENTATION FUNCTIONS */
template < class K, class T, class C, class A >
ft::map<K,T,C,A>::map(key_type const & key, mapped_type const & value)
{
	this->_root = new Node(key, value);

	this->_root->left = new Node(key - 5, value);
	this->_root->left->parent = this->_root;

	this->_root->left->left = new Node(key - 7, value);
	this->_root->left->left->parent = this->_root->left;

	this->_root->left->right = new Node(key - 3, value);
	this->_root->left->right->parent = this->_root->left;

	this->_root->left->left->left = new Node(key - 9, value);
	this->_root->left->left->left->parent = this->_root->left->left;

	this->_root->right = new Node(key + 5, value);
	this->_root->right->parent = this->_root;

	this->_root->right->right = new Node(key + 10, value);
	this->_root->right->right->parent = this->_root->right;

	this->_size = 7;
}

template < class K, class T, class C, class A >
void		ft::map<K,T,C,A>::inorder(Node * root)
{
	if (root == 0)
		return ;

	inorder(root->left);
	std::cout << root->data.first << " ";
	inorder(root->right);
}

template < class K, class T, class C, class A >
void		ft::map<K,T,C,A>::postorder(Node * root)
{
	if (root == 0)
		return ;

	postorder(root->left);
	postorder(root->right);
	std::cout << root->data.first << " ";
}

template < class K, class T, class C, class A >
void		ft::map<K,T,C,A>::preorder(Node * root)
{
	if (root == 0)
		return ;

	std::cout << root->data.first << " ";
	preorder(root->left);
	preorder(root->right);

}

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
void		ft::map<K,T,C,A>::printInorder(void) const
{ inorder(this->_root); }

template < class K, class T, class C, class A >
void		ft::map<K,T,C,A>::printPostorder(void) const
{ postorder(this->_root); }

template < class K, class T, class C, class A >
void		ft::map<K,T,C,A>::printPreorder(void) const
{ preorder(this->_root);}

template < class K, class T, class C, class A >
void		ft::map<K,T,C,A>::rev_iterative_inorder_print(void) const
{
	Node * iterator = rightmost(this->_root);
	while (iterator)
	{
		std::cout << iterator->data.first << " ";
		iterator = prev(iterator);
	}
	std::cout << std::endl;
}
