/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:21:51 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/11 17:20:43 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

struct list
{
	int ch;
	struct list *next_rec;
};

typedef struct list LIST;
typedef LIST *LISTPTR;

LISTPTR	add_to_list(int, LISTPTR);
void	show_list(LISTPTR);
void	free_memory_list(LISTPTR);

int	main(void)
{
	LISTPTR first;
	int i;
	int ch;
	char trash[256];

	i = 0;
	first = NULL;
	while (i++ < 5)
	{
		ch = 0;
		printf("\nEnter character %d, ", i);

		do
		{
			printf("\nMust be a to z: ");
			ch = getc(stdin);
			gets(trash);
		}while ((ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z'));

		first = add_to_list(ch, first);
	}

	show_list(first);
	free_memory_list(first);
	return (0);
}

LISTPTR	add_to_list(int ch, LISTPTR first)
{
	LISTPTR new_rec = NULL;
	LISTPTR tmp_rec = NULL;
	LISTPTR prev_rec = NULL;

	new_rec = (LISTPTR)ft_memalloc(sizeof(LIST));
	if (!new_rec)
		return (NULL);

	new_rec->ch = ch;
	new_rec->next_rec = NULL;

	if (first == NULL)
	{
		first = new_rec;
		new_rec->next_rec = NULL;
	}
	else
	{
		if (new_rec->ch < first->ch)
		{
			new_rec->next_rec = first;
			first = new_rec;
		}
		else
		{
			tmp_rec = first->next_rec;
			prev_rec = first;

			if (tmp_rec == NULL)
				prev_rec->next_rec = new_rec;
			else
			{
				while ((tmp_rec->next_rec != NULL))
				{
					if (new_rec->ch < tmp_rec ->ch)
					{
						new_rec->next_rec = tmp_rec;
					if (new_rec->next_rec != prev_rec->next_rec)
					{
						printf("ERROR");
						getc(stdin);
						exit(0);
					}
					prev_rec->next_rec = new_rec;
					break;
					}
				else
				{
					tmp_rec = tmp_rec->next_rec;
					prev_rec = prev_rec->next_rec;
				}
			}
			if (tmp_rec->next_rec == NULL)
			{
				if (new_rec->ch < tmp_rec->ch)
				{
					new_rec->next_rec = tmp_rec;
					prev_rec->next_rec = new_rec;
				}
				else
				{
					tmp_rec->next_rec = new_rec;
					new_rec->next_rec = NULL;
				}
			}
		}
	}
	}
	return (first);
}

void	show_list(LISTPTR first)
{
	LISTPTR cur_ptr;
	int	counter;

	counter = 1;
	printf("\n\nRec addr Position Data Next Rec addr\n");
	printf("======== ======== ==== =============\n");
	cur_ptr = first;
	while (cur_ptr != NULL)
	{
		printf(" %X ", cur_ptr );
		printf(" %2i       %c", counter++, cur_ptr->ch);
		printf("   %X \n",cur_ptr->next_rec);
		cur_ptr = cur_ptr->next_rec;
	}
}

void	free_memory_list(LISTPTR first)
{
	LISTPTR cur_ptr, next_rec;
	cur_ptr = first;

	while (cur_ptr != NULL)
	{
		next_rec = cur_ptr->next_rec;
		free(cur_ptr);
		cur_ptr = next_rec;
	}
}
