
int		ft_strprefix(const char *str, const char *prefix)
{
	while (*prefix != '\0' && *str != '\0' && *str == *prefix)
	{
		prefix++;
		str++;
	}
	return (*prefix == '\0');
}
