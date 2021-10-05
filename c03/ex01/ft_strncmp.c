int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 && (*s1 == *s2) && n - 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
