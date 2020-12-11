#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *remainder = "2345678\n23456";
	char *line = "sdfghjhgfd";
	int i;
	int j;

	j = 0;
	i = 0;
	while (remainder[i] != '\n')
	{
		line[j] = remainder[i];
		j++;
		i++;
	}
	printf("%s\n", line);
}