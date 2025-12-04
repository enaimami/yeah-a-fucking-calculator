#include "calculator.h"
#include <stdio.h>
int	m_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}
int	space_count(char *formula)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (formula[i] != '\0')
	{
		if(formula[i] == ' ' || (formula[i] >= 9 && formula[i] <= 13))
			count++;
		i++;
	}
	return (count);
}
char	*m_strdup(char *str)
{
	int	i;
	char	*temp;

	temp = malloc(m_strlen(str) + 1);
	if(temp == NULL)
		return NULL;
	i = 0;
	while(str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
char	*m_skip_extras(char *formula)
{
	int	i;
	int	j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc(m_strlen(formula) + 1);
	if(temp == NULL)
		return NULL;
	while(formula[i] != '\0')
	{
		if(!(m_isnbr(formula[i])) && !(m_isoperator(formula[i])) )
		{
			i++;
			continue;
		}
		temp[j] = formula[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	temp = realloc(temp, j + 1);
	return (temp);
}
char	solve(char *formula)
{
	int	i;

	i = 0;
	while(formula[i] != '\0')
	{
		
	}
}


int	main(int ac,char  **argv)
{
	printf("%s", skip_spaces(argv[1]));
	
}
