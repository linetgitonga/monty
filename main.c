#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#define  _GNU_SOURCE
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Author :Linet Gitonga
* Return: 0 on success
*/
ssize_t getline_custom(char **lineptr, size_t *n, FILE *stream) {
    ssize_t read_line;

    if (*lineptr == NULL || *n == 0) {
        *n = 128; 
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }

    read_line = (ssize_t)fgets(*lineptr, *n, stream);

    if (read_line != -1) {
        size_t len = strlen(*lineptr);
        if ((*lineptr)[len - 1] == '\n') {
            (*lineptr)[len - 1] = '\0';
        } else {
            *lineptr = realloc(*lineptr, len + 1);
            if (*lineptr == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
    }

    return read_line;
}
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline_custom(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
