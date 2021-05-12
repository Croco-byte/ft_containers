/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:31:04 by user42            #+#    #+#             */
/*   Updated: 2021/05/11 19:21:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP


#include "less.hpp"
#include "Node.hpp"
#include "../Iterators/allocator.hpp"
#include "../Iterators/iterator_tags.hpp"
#include <iostream>


namespace ft
{

template < class Key, class T, class Compare = ft::less<Key>, class Alloc = ft::allocator<ft::Pair<Key, T> > >
class	map
{
	public:
		/* TYPEDEFs FOR CONTAINER CHARACTERISTICS */
		typedef	ft::Node<Key,T>													Node;
		typedef	Key																key_type;
		typedef T																mapped_type;
		typedef ft::Pair<key_type,mapped_type>									value_type;
		typedef Compare															key_compare;
		typedef Alloc															allocator_type;
		typedef typename allocator_type::reference								reference;
		typedef typename allocator_type::const_reference						const_reference;
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef typename allocator_type::difference_type						difference_type;
		typedef typename allocator_type::size_type								size_type;

		/* ITERATORS AND ITERATORS TYPEDEFs */
		#include "../Iterators/bidirectional/map/map_iterator.hpp"
		typedef typename ft::map< key_type,mapped_type >::iterator				InputIterator;


		/* CONSTRUCTORS / DESTRUCTORS */
		map();
		map(InputIterator first, InputIterator last);
		~map();

		/* ITERATOR FUNCTIONS */
		iterator			begin(void);
		iterator			end(void);




		/* DEBUG / EXPERIMENTATION FUNCTIONS */
		map(key_type const & key, mapped_type const & value);
		static void		inorder(Node * root);			// Recursive
		static void		postorder(Node * root);			// Recursive
		static void		preorder(Node * root);			// Recursive
		static void		parents_preorder(Node * root);			// Recursive
		void			printInorder(void)				const;
		void			printPostorder(void)			const;
		void			printPreorder(void)				const;
		void			iterative_inorder_print(void)	const;
		void			rev_iterative_inorder_print(void)	const;




	private:
	/* PRIVATE MEMBER ATTRIBUTES */
		Node *		_root;
		size_type	_size;

		/* PRIVATE HELPER FUNCTIONS */
		static void				recursive_postorder_deletion(Node * root);												// Traverse tree in postorder to delete it
		static Node *			leftmost(Node * node);																	// Find smallest element in tree
		static Node *			rightmost(Node * node);																	// Find biggest element in tree
		static Node *			next(Node * node);																		// From given Node, find closest following Node from Key. Can be used to iterate through tree (++).
		static Node *			prev(Node * node);																		// From given Node, find closest preceding Node from Key. Can be used to iterate through tree (--).
		static Node *			range_to_BST(InputIterator first, InputIterator last, int start, int end);

};

}

#include "map.ipp"


#endif

/*
 -- MAP TODO :

 ---> Member functions
 	---> Constructors
	 	> Default							
		> Range								
		> Copy								
	
	---> Operators
		> Operator=							

	---> Iterators
		> begin()							
		> end()								
		> rbegin()							
		> rend()							
	
	---> Capacity
		> size								
		> max_size							
		> empty								
	
	---> Element access
		> Operator[]						
	
	---> Modifyers
		> insert							
		> erase								
		> swap								
		> clear								

	---> Observers
		> key_comp
		> value_comp

	---> Operations
		> find
		> count
		> lower_bound
		> upper_bound
		> equal_range


=== REMARQUES ===

	---> Pour l'implémentation des maps, mon élément past_the_end sera simplement un pointeur NULL au lieu d'un vrai élément (comme j'ai pu le faire dans list).
		 Cela a l'avantage de la simplicité, et apparemment c'est bien comme ça que la STL procède dans l'implémentation de certains containers.

	---> Attention du coup, problème à régler : lorsqu'on fait map.end()--, ça ne recule pas pour le moment, puisqu'on pointe sur 0

*/
