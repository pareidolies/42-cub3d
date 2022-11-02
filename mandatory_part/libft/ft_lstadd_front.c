/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:08:45 by smostefa          #+#    #+#             */
/*   Updated: 2021/12/08 19:30:06 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

/*
#include <stdio.h>

int	main()
{
	char test[] = "test-test-test1";
	t_list *struc = ft_lstnew(test);
	t_list **testt;
	testt = &struc;
	char test2[] = "test-test-test2";
	t_list *struc2 = ft_lstnew(test2);
	ft_lstadd_front(testt, struc2);
	char test3[] = "test-test-test3";
	t_list *struc3 = ft_lstnew(test3);
	ft_lstadd_front(testt, struc3);
	char test4[] = "test-test-test4";
	t_list *struc4 = ft_lstnew(test4);
	ft_lstadd_front(testt, struc4);
	char test5[] = "test-test-test5";
	t_list *struc5 = ft_lstnew(test5);
	t_list *hhhh = *testt;

printf("%s	  4\n", hhhh->content);
printf("%s	  3\n", hhhh->next->content);
printf("%s	  2\n", hhhh->next->next->content);
printf("%s	  1\n", hhhh->next->next->next->content);
printf("%d		  4\n",ft_lstsize(hhhh));
printf("%s	  1\n",ft_lstlast(hhhh)->content);
ft_lstadd_back(testt,struc5);
printf("\n%s	  4\n", hhhh->content);
printf("%s	  3\n", hhhh->next->content);
printf("%s	  2\n", hhhh->next->next->content);
printf("%s	  1\n", hhhh->next->next->next->content);
printf("%s	  5\n", hhhh->next->next->next->next->content);
printf("%d		  5\n",ft_lstsize(hhhh));
//ft_lstiter(hhhh,fonctiontest);
//printf("\n%s	 -4\n", hhhh->content);
//printf("%s	 -3\n", hhhh->next->content);
//printf("%s	 -2\n", hhhh->next->next->content);
//printf("%s	 -1\n", hhhh->next->next->next->content);
//printf("%s	 -5\n", hhhh->next->next->next->next->content);
}
*/
