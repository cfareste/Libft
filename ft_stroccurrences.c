int	ft_index(char *str, char c)
{
	int	index;

	index = 0;
	while (str && str[index] && str[index] != c)
		index++;
	if (str[index] != c)
		return (-1);
	return (index);
}

int	ft_stroccurrences(char *str, char c)
{
	int	occurrences;

	occurrences = 0;
	while (str && *str)
	{
		if (*str == c)
			occurrences++;
		str++;
	}
	return (occurrences);
}

int	ft_stroccurrences_set(char *str, char *set)
{
	int	occurrences;

	occurrences = 0;
	while (str && *str)
	{
		if (ft_stroccurrences(set, *str))
			occurrences++;
		str++;
	}
	return (occurrences);
}
