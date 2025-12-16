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
int	m_array_strlen(int size,int first, char **str_arr)
{
	int	total;
	int	i;
	int j;

	total = 0;
	i = first;
	while(i < size)
	{
		j = 0;
		while(str_arr[i][j] != '\0')
		{
			total++;
			j++;
		}
		i++;
	}
	return (total);
}
char	*fucking_problematic_mallocs_i_hope_you_die_in_the_fucking_hell(char *formula)
{
	int	i;
	int	j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc(m_strlen(formula) + 2);
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
char	*m_skip_extras(char *formula)
{
	int	i;
	int	j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc(m_strlen(formula) + 2);
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
	free(formula);
	return (temp);
}

int calculate_two(int *num1, int *num2, char *op, char *stat)
{
	int total;

	total = 0;
	if(*op != '?')
	{
		if(*op == '+')
			total = *num1 + *num2;
		if(*op == '-')
			total = *num1 - *num2;
		if(*op == '*')
			total = *num1 * *num2;
		if(*op == '/')
		{
			if(*num2 == 0)
			{
				*stat = 'D';
			}
			else
				total = *num1 / *num2;
		}
		*num1 = 0;
		*num2 = 0;
		*op = '?';
		*stat = 'S';
		return total;
	}
	*stat = 'O';
	return total;
}

void write_number_to_string(char **str, int endpoint, int nbr)
{
    // Eğer sayı 0 ise manuel olarak yaz
    if (nbr == 0)
    {
        (*str)[endpoint] = '0';
        return;
    }
    
    while(nbr > 0)
    {
        (*str)[endpoint] = (nbr % 10) + '0';
        nbr = nbr / 10;
        endpoint--; 
    }
}

double solve(char *formula)
{
	int i;
	char stat;
	char op;
	int num1;
	int num2;

	i = 0;
	num1 = 0;
	num2 = 0;
	op = '?';
	stat = 'S';
	while(formula[i] != '\0')
	{
		while(formula[i] != '\0' && m_isnbr(formula[i]))
		{
			num1 = (num1 * 10) + formula[i] - '0';
			printf("%c", formula[i]);
			formula[i] = ' ';
			i++;
		}
		printf("\n");
		if(m_isoperator(formula[i]))
		{
			op = formula[i];
			printf("%c", formula[i]);
			formula[i] = ' ';
			i++;
		}
		printf("\n");
		while(formula[i] != '\0' && m_isnbr(formula[i]))
		{
			num2 = (num2 * 10) + formula[i] - '0';
			printf("%c",formula[i]);
			formula[i] = ' ';
			i++;
		}
		printf("\n");
		write_number_to_string(&formula,i-1,calculate_two(&num1,&num2,&op,&stat));
		formula = m_skip_extras(formula);
		if(stat != 'S')
		{
			printf("Hesaplama %c hatası verdi.", stat);	
			exit(0);
		}
		i = 0;
	}
	printf("%s", formula);
}

char	*concatenate_arguments(int ac,char **av)
{
	int	i;
	int	j;
	int	formula_len;
	char *formula;

	i = 1;
	formula_len = 0;
	formula = (char*)malloc(m_array_strlen(ac,1,av) + 2);
	formula[0] = '@';
	while (i < ac)
	{
		j = 0;
		while(av[i][j] != '\0')
		{
			formula[formula_len] = av[i][j];
			formula_len++;
			j++;
		}
		i++;
	}
	formula[formula_len] = '\0';
	return (formula);
}

int	main(int ac,char  **av)
{
	if(ac >= 2)
	{
		int *merhaba;
		char *naber;
		char *formultype_shi;
		formultype_shi = concatenate_arguments(ac,av);
		printf("%s \n", formultype_shi);
		formultype_shi = fucking_problematic_mallocs_i_hope_you_die_in_the_fucking_hell(formultype_shi);
		printf("%s\n", formultype_shi);
		solve(formultype_shi);
	}
	else
	{
		printf("go touch some grass");
	}
	
}
