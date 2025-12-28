#include "calculator.h"

void m_split(char *formula, int *numbers, char *ops)
{

}
void clearer(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == ' ' || str[i] == 'a')
        {
            i++;
            continue;
        }
        m_putchar(str[i]);
        i++;
    }
    m_putchar('\n');
    return ;
}

int main(int ac, char **av)
{
    if(ac != 2)
    {
        putstr("pls add a formula my dude \n");
        return 0;
    }

    clearer(av[1]);
}