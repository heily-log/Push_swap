/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:07:42 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 18:57:15 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pa, pb
//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.


static void	pa(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_b == NULL)
		return ;
	nd1 = stack->head_a;
	nd2 = stack->head_b;
	if (nd2->next != NULL)
	{
		stack->head_b = nd2->next;
		nd2->next->prev = NULL;
	}
	else
		stack->head_b = NULL;
	if (stack->head_a != NULL)
	{
		nd1->prev = nd2;
		nd2->next = nd1;
	}
	else
		nd2->next = NULL;
	stack->head_a = nd2;
}

static void	pb(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_a == NULL)
		return ;
	nd1 = stack->head_a;
	nd2 = stack->head_b;
	if (nd1->next != NULL)
	{
		stack->head_a = nd1->next;
		nd1->next->prev = NULL;
	}
	else
		stack->head_a = NULL;
	if (stack->head_b != NULL)
	{
		nd2->prev = nd1;
		nd1->next = nd2;
	}
	else
		nd1->next = NULL;
	stack->head_b = nd1;
}

void	push(t_stack *stack, char c)
{
	if (c == 'a')
	{
		pa(stack);
		ft_putstr_fd("pa\n", 1);
	}
	else
	{
		pb(stack);
		ft_putstr_fd("pb\n", 1);
	}
}