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

double solve(char *formula)
{
	int i;
	char stat;
	char op;
	char total;
	int num1;
	int num2;

	i = 0;
	num1 = 0;
	total = 0;
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
		solve(formultype_shi);
	}
	else
	{
		printf("go touch some grass \n");
	}
	
}
