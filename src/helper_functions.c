#include "../calculator.h"

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
		if(*op == 'x')
			total = (*num1) * (*num2);
		if(*op == '/')
		{
			if(*num2 == 0)
			{
				*stat = 'D';
                return 0;
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
    int is_negative = 0;

    if (nbr == 0)
    {
        (*str)[endpoint] = '0';
        return;
    }

    if (nbr < 0)
    {
        is_negative = 1;
        nbr = -nbr;
    }

    while (nbr > 0)
    {
        (*str)[endpoint] = (nbr % 10) + '0';
        nbr /= 10;
        endpoint--;
    }

    if (is_negative)
    {
        (*str)[endpoint] = '-';
    }
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