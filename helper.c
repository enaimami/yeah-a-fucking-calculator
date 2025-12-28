#include "calculator.h"
void m_putchar(char c)
{
    write(1, &c,1);
}
void putstr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        m_putchar(str[i]);
        i++;
    }
    return ;
}
int m_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i+1;
}
char *m_strcpy(char *str)
{
    int i;
    char *newstr;
    
    newstr = malloc(m_strlen(str) + 1);
    i = 0;
    while (str[i] != '\0')
    {
        newstr[i] = str[i];
        i++;
    }
    newstr[i] = '\0';
    return newstr;
}