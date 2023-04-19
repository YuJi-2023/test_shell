#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * split_string - a function that splits a string and returns an array of each word in it
 *
 * Return: pointer to the string array
 */
void split_string(char *str, char **word_array)
{
	char *word;
	int i = 0;

	word = strtok(str, " ");
	while (word != NULL)
	{
		word_array[i] = word;
		i = i + 1;
		word = strtok(NULL, " ");
	}
}

int main()
{
	char string_to_split[] = "The way to get started is to quit talking and begin doing";
	char *word_array[1024];
	int i;

	split_string(string_to_split, word_array);
	i = 0;
	while (word_array[i] != NULL)
	{
		printf("the word is : %s\n", word_array[i]);
		i = i + 1;
	}
	return (0);
}
