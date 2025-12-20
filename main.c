#include "calculator.h"
#include <stdio.h>

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

int get_numbers(char **formula, int *i)
{
	int num;

	num = 0;
	while((*formula)[(*i)] != '\0' && m_isnbr((*formula)[*i]))
	{
		num = (num * 10) + (*formula)[*i] - '0';
		printf("%c", (*formula)[*i]);
		(*formula)[*i] = ' ';
		(*i)++;
	}
	return num;
}

int get_sign(char **formula, int *i)
{
	int sign = 1;
	if((*formula)[(*i)] == '-' || (*formula)[(*i)] == '+')
	{
		if((*formula)[(*i)] == '-')
			sign = -1;
		(*formula)[(*i)] = ' ';
		(*i)++;
	}
	return sign;
}

char *solve(char *formula)
{
	int i;
	char stat;
	char op;
	int total;
	int num1;
	int num2;
	int sign;

	i = 0;
	num1 = 0;
	num2 = 0;
	total = 0;
	sign = 1;
	op = '?';
	stat = 'S';
	while(1 == 1)
	{
		sign = get_sign(&formula,&i);
		num1 = get_numbers(&formula, &i);
		num1 = num1 * sign;
		printf("\n");
		if(m_isoperator(formula[i]))
		{
			op = formula[i];
			printf("%c", formula[i]);
			formula[i] = ' ';
			i++;
		}
		printf("\n");
		sign = 1;
		sign = get_sign(&formula,&i);
		num2 = get_numbers(&formula, &i);
		num2 = num2 * sign;
		sign = 1;
		printf("\n");
		write_number_to_string(&formula,i,calculate_two(&num1,&num2,&op,&stat));
		formula = m_skip_extras(formula);
		if(stat != 'S')
		{
			if(op == '?')
			{
				break;
			}
			printf("Hesaplama %c hatası verdi.", stat);	
			exit(0);
		}
		i = 0;
		total = atoi(formula);
	}
	printf("İşlem sonucu : %d \n", total);
	return formula;
}

char *operator_clearer(char *formula)
{
	int i;
	int minus_count;

	minus_count = 0;
	i = 0;
	while(formula[i] != '\0')
	{
		if ((formula[i] == '-' || formula[i] == '+') &&
    (i == 0 || m_isoperator(formula[i - 1])))
{
    i++;
    continue;
}


		if(formula[i] != '-' && formula[i] != '+')
		{
			i++;
			continue;
		}
		minus_count = 0;
		while(formula[i] == '-' || formula[i] == '+')
		{
			if(formula[i] == '-')
				minus_count ++;
			formula[i] = ' ';
			i++;
		}
		if(i > 0 && m_iseven(minus_count))
		{
			formula[i-1] = '+';
		}
		else
		{
			formula[i-1] = '-';
		}
	}
	formula = m_skip_extras(formula);
	return formula;
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
		formultype_shi = m_skip_extras(formultype_shi);
		printf("%s\n", formultype_shi);
		formultype_shi = operator_clearer(formultype_shi);
		printf("%s\n",formultype_shi);
		formultype_shi = solve(formultype_shi);
		free(formultype_shi);
	}
	else
	{
		printf("go touch some grass \n");
	}
	
}
