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
	formula[0] = '@';
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

char *clean_parentheses(char *formula)
{
	int i;
	int start;
	int end;
	int temp;
	int len;
	char *temparr;
	while(strchr(formula, ')') != NULL)
	{
		i = 0;
		
		while(formula[i] != '\0')
		{
			if(formula[i] == ')')
			{
				end = i;
				temp = i;
				while(formula[temp] != '(')
				{
					temp--;
				}
				start = temp;
				temparr = malloc(end - start);
				len = end - start - 1;
				temparr = strncpy(temparr, formula + start + 1, len);
				temparr[len] = '\0';
				//TODO : sıralı işlem yapacak bir fonksiyon yaz
				//formula'nın start'ıncı elemanından itibaren temparr'ı basacak ve döngü sayısı temparr'ın uzunluğundan kısa ise geri kalanına boşluk basacak bir fonksiyon yaz.
				//formulayı gelen sonuca eşitle ve döngüye devam et
			}
			i++;
		}
	}
	return (formula);
}

double calculate_two(double *num1, double *num2, char op,char **status)
{
	double total;

	total = 0;
	if(op != '?')
	{
		if(op == '+')
			total = *num1 + *num2;
		if(op == '-')
			total = *num1 - *num2;
		if(op == '*')
			total = *num1 * *num2;
		if(op == '/')
		{
			if(*num2 == 0)
			{
				*status = "undefined";
			}
			else
				total = *num1 / *num2;
		}
		*num1 = 0;
		*num2 = 0;
		op = '?';
		return total;
	}
	**status = "unvalid operator";
	return total;
}

char is_there_any_fucking_minus_or_plus(char *w)
{
	
}

double get_left_number(char **formula, int startindex)
{
	int i;

	i = startindex;
	while(m_isnbr(formula[i]))
	{
		write(1, formula[i],1);
		i--;
	}
}

double get_double_number(char *formula, int current_position)
{
	double result;
	int is_negative;
	int endindex;
	int startindex;
	int i;
	endindex = 0;
	is_negative = 1;
	result = 0;
	i = 0;
	while(!m_isoperator(formula[i]) && formula[i] != '\0')
	{
		i++;
	}
	endindex = i;
	while(formula[i] != '@')
	{
		i--;
	}
	startindex = i;
	if(formula[startindex + 1] == '-')
	{
		is_negative = -1;
	}
}

double solve(char *formula)
{
	int i;
	int k;
	int startindex;
	double num1;
	char op;
	double num2;

	i = 0;
	k = 0;
	num1 = 0;
	num2 = 0;
	startindex = 0;
	op = '?';
	while(formula[i] != '\0')
	{
		startindex = i;
		if(m_isoperator(formula[i]) && (formula[i] == 'x' || formula[i] == '/'))
		{
			k = i - 1;
			while(m_isnbr(formula[k]))
				k--;
			startindex = k;
			k++;
			while(k < i)
			{
				num1 = (10 * num1) + formula[k] - '0';
				formula[k] = ' ';
				k++;
			}
			if(formula[startindex] == '-')
				num1 = num1 * -1;
			op = formula[i];
			formula[i] = ' ';
			i++;
			while(m_isnbr(formula[i]))
			{
				num2 = (10 * num2) + formula[i] - '0';
				formula[i] = ' ';
				i++;
			}
			
		}
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
void    m_split(char *formula, int **numbers, char **operators)
{
    int i;
    int j;
    int k;
    int sign;
    i = 0;
    k = 0;
    j = 0;
    sign = 1;
    *numbers = malloc(m_strlen(formula) + 1);
    *operators = malloc(m_strlen(formula) + 1);
    if(formula[0] == '-')
        sign = -1;
    while(formula[i] != '\0')
    {
        if(m_isnbr(formula[i]))
        {
            (*numbers)[j] = formula[i] - '0';
            i++;
            while(m_isnbr(formula[i]))
            {
                (*numbers)[j] = ((*numbers)[j] * 10) + (formula[i] - '0');
                i++;
            }
            j++;
            continue;
        }
        if(m_isoperator(formula[i]))
        {
            (*operators)[k] = formula[i];
            k++;
            i++;
            continue;
        }
    }

}

int	main(int ac,char  **av)
{
	if(ac >= 2)
	{
		int *merhaba;
		char *naber;
		char *formultype_shi;
		formultype_shi = concatenate_arguments(ac,av);
		formultype_shi = m_skip_extras(formultype_shi);
		m_split(formultype_shi,&merhaba,&naber);
		printf("sayılar : %d", merhaba[0]);
		printf(",%d", merhaba[1]);
		printf(",%d \n", merhaba[2]);
		printf("işlemler : %s", naber);
		//TODO : değişken atama yap.
	}
	else
	{
		printf("go touch some grass");
	}
	
}
