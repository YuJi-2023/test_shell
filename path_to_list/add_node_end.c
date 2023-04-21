#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * add_node_end - a function that adds a new node at the end
 * of a list_t list
 * @head: input parameter of a pointer to the beginning of a linked list
 * @str: input string that too be added at the end
 * Return: pointer to the list or NULL if it faild
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp = malloc(sizeof(list_t));
	list_t *ptr;

	if (temp == NULL)
	{
		return (NULL);
	}
	temp->str = strdup(str);
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	return (*head);
}
