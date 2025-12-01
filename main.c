int	strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}
int	space_count(char *formula)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (formula[i] != '\0')
	{
		if(formula[i] == ' ' || (formula[i] >= 9 && formula[i] <= 13))
			count++;
		i++;
	}
	return (count);
}
char	*m_strdup(char *str)
{
	int	i;
	char	*temp;

	temp = malloc(strlen(str) + 1);
	if(temp == NULL)
		return NULL;
	i = 0;
	while(str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
char	*skip_spaces(char *formula)
{
	int	i;
	int	j;
	int	formula_space_count;
	char	*temp;

	i = 0;
	j = 0;
	formula_space_count = space_count(formula);
	if(formula_space_count == 0)
		return(m_strdup(formula));
	temp = malloc(strlen(formula) - formula_space_count + 1);
	if(temp == NULL)
		return NULL;
	while(formula[i] != '\0')
	{
		if(formula[i] == ' ' || (formula[i] >= 9 && formula[i] <= 13))
		{
			i++;
			continue;
		}
		temp[j] = formula[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}
int	main(int ac,char  **argv)
{
	int	i;

	i = 0;
	while(i < ac)
	{
		
	}
}
