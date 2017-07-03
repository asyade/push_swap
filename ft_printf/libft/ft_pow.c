
int         ft_pow(int n, int p)
{
	int     i;
	int     new;

	new = n;
	i = 1;
	if (p == 0)
		return (0);
	while (i < p)
	{
		new *= n;
		i++;
	}
	return (new);
}
