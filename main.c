#include "calculator.h"

void m_split(char *formula, int *numbers, char *ops)
{

}
char *skiper(char *str, char mode)
{
    long int i;
    char *temp;

    i = 0;
    temp = malloc(m_strlen(str) + 1);
    if(mode = 's')
    {
        while(str[i] != '\0')
        {
            if(str[i] == ' ')
            {
                i++;
                continue;
            }
            temp[i] = str[i];
            i++;
        }
    }

    return temp;
}

char  *clearer(char *str)
{
    int i;
    int k;
    char *formula;

    i = 0;
    k = 0;
    formula = malloc(m_strlen(str) + 1);
    while(str[k] != '\0')
    {
        if(!((str[k] >= '0' && str[k] <= '9') || str[k] == '-' || str[k] == '+' || str[k] == '*' || str[k] == '/'))
        {
            k++;
            continue;
        }
        formula[i] = str[k];
        i++;
        k++;
    }
    formula[i] = '\0';
    return formula;
}

int main(int ac, char **av)
{
    char *formula;
    if(ac != 2)
    {
        if(ac == 1)
        {
            print("you didnt entered a formula");
            return 0;
        }
        print("you entered a lot of things\n");
        return 0;
    }

    formula = clearer(av[1]);
    print(formula);
    free(formula);
}