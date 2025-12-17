#ifndef CALC_H
#define CALC_H

#include <stdlib.h>
#include <stdio.h>

int	m_strlen(char *str);
int	m_array_strlen(int size,int first, char **str_arr);
int calculate_two(int *num1, int *num2, char *op, char *stat);
void write_number_to_string(char **str, int endpoint, int nbr);
char	*concatenate_arguments(int ac,char **av);

#define m_isoperator(c) ((c) == '+' || (c) == '-' || (c) == 'x' || (c) == '/')
#define m_isspace(c) ( ( (c) == ' ') || ( (c) >= 9 && (c) <= 13))
#define m_isalpha(c) ( ( (c) >= 'a' && (c) <= 'z') || ( (c) >= 'A' && (c) <= 'Z'))
#define m_isnbr(c) ( (c) >= '0' && (c) <= '9')

#endif
