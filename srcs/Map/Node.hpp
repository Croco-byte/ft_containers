/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:55:59 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 16:40:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_NODE_HPP
# define MAP_NODE_HPP

#include "Pair.hpp"

namespace ft
{

template < typename T1, typename T2 >
class	Node
{
	public:
		/* PUBLIC MEMBER TYPES */
		typedef	ft::Pair<T1,T2>			Pair;

		/* CONSTRUCTORS / DESTRUCTORS */
		Node()									: data(), left(0), right(0), parent(0)									{}
		Node(Pair const & pair)					: data(pair), left(0), right(0), parent(0)								{}
		Node(T1 const & key, T2 const & value)	: data(key, value), left(0), right(0), parent(0)						{}
		Node(Node const & src)					: data(src.data), left(src.left), right(src.right), parent(src.parent)	{}
		~Node()																									{}

		/* SOME HELPER FUNCTIONS */
		static Node *							create_node(T1 const & first, T2 const & second)						{ Pair pair(first, second); Node * new_node = new Node(pair); return (new_node); }

		/* PUBLIC MEMBER VARIABLES */
		Pair	data;
		Node *	left;
		Node *	right;
		Node *	parent;
};

}


#endif
