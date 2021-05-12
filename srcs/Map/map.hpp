/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroland <qroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:31:04 by user42            #+#    #+#             */
/*   Updated: 2021/05/12 16:37:48 by qroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP


#include "less.hpp"
#include "Node.hpp"
#include "../Iterators/allocator.hpp"
#include "../Iterators/iterator_tags.hpp"
#include "../Iterators/reverse_iterator.hpp"
#include <iostream>
#include <limits>


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
		#include "../Iterators/bidirectional/map/const_map_iterator.hpp"
		typedef ft::reverse_iterator< iterator >								reverse_iterator;
		typedef ft::reverse_iterator< const_iterator >							const_reverse_iterator;
		typedef typename ft::map< key_type,mapped_type >::iterator				InputIterator;


		/* CONSTRUCTORS / DESTRUCTORS */
		map();
		map(InputIterator first, InputIterator last);
		map(map const & src);
		~map();

		/* OPERATOR OVERLOADS */
		map &				operator=(map const & rhs);


		/* ITERATOR FUNCTIONS */
		iterator				begin(void);
		const_iterator			begin(void)										const;
		iterator				end(void);
		const_iterator			end(void)										const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void)									const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void)										const;

		/* CAPACITY FUNCTIONS */
		size_type				size(void)										const;
		size_type				max_size(void)									const;
		bool					empty(void)										const;

		/* ELEMENT ACCESS */
		mapped_type &			operator[](key_type const & k);

		/* MODIFYERS */
		ft::Pair<iterator,bool>	insert(value_type const & val);

		/* DEBUG / EXPERIMENTATION FUNCTIONS */
		map(key_type const & key, mapped_type const & value);
		static void				inorder(Node * root);					// Recursive
		static void				postorder(Node * root);					// Recursive
		static void				preorder(Node * root);					// Recursive
		static void				parents_preorder(Node * root);			// Recursive
		void					printInorder(void)								const;
		void					printPostorder(void)							const;
		void					printPreorder(void)								const;
		void					iterative_inorder_print(void)					const;
		void					rev_iterative_inorder_print(void)				const;



	private:
		/* PRIVATE MEMBER ATTRIBUTES */
		Node *		_root;
		size_type	_size;

		/* PRIVATE HELPER FUNCTIONS */
		void					setPastTheEnd(Node * last);
		void					setBeforeBeginning(Node * last);
		Node *					keyInTree(key_type const & k);
		static void				recursive_copy(Node * root, Node * copyRoot);											// Do a recursive copy from root node, to copyRoot tree.
		static void				recursive_postorder_deletion(Node * root);												// Traverse tree in postorder to delete it
		static Node *			leftmost(Node * node);																	// Find smallest element in tree
		static Node *			rightmost(Node * node);																	// Find biggest element in tree
		static Node *			next(Node * node);																		// From given Node, find closest following Node from Key. Can be used to iterate through tree (++).
		static Node *			prev(Node * node);																		// From given Node, find closest preceding Node from Key. Can be used to iterate through tree (--).
		static Node *			range_to_BST(InputIterator first, InputIterator last, int start, int end);				// Convert an iterator range to a BST.
		
		static Node *			recursive_insert(Node * node, value_type const & val);
		static void				insert_smallest(Node * prec, value_type const & val);
		static void				insert_biggest(Node * prec, value_type const & val);
		void					insert_from_empty(ft::Pair<iterator,bool> & result, value_type const & val);
};

}

#include "map.ipp"


#endif

/*
 -- MAP TODO :

 ---> Member functions
 	---> Constructors
	 	> Default					OK				
		> Range						OK		
		> Copy						OK		
	
	---> Operators
		> Operator=					OK

	---> Iterators
		> begin()					OK
		> end()						OK		
		> rbegin()					OK		
		> rend()					OK		
	
	---> Capacity
		> size						OK
		> max_size					OK
		> empty						OK
	
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

	---> Implémentation identique aux listes, l'élément past_the_end et before_beginning sont des éléments spécifiques. Si la map est vide, ils sont égaux à 0 et ne doivent pas être déréférencés.
	---> Tenter de retirer la fonction rétablissant les parents après bst_to_range.
*/
