#ifndef CALC_H
#define CALC_H

#include <stdlib.h>

int	m_strlen(char *str);
int	space_count(char *str);
char	*skip_spaces(char *formula);

#define m_isoperator(c) ((c) == '+' || (c) == '-' || (c) == '*' || (c) == '/' || (c) == '(' || (c) == ')')
#define m_isspace(c) ( ( (c) == ' ') || ( (c) >= 9 && (c) <= 13))
#define m_isalpha(c) ( ( (c) >= 'a' && (c) <= 'z') || ( (c) >= 'A' && (c) <= 'Z'))
#define m_isnbr(c) ( (c) >= '0' && (c) <= '9')

#endif
