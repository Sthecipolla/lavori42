void	*cmd_add_error(char	*str,int i, t_cmd_line **cmd)
{
	int				j;
	t_cmd_line		*arg;

	arg = *cmd;
	if(arg == NULL)
		return ("");
	while(arg->next != NULL)
		arg = arg->next;
	while(ft_isspace(str[i]) == TRUE && i > 0)
		i --;
	j = i;
	if(str[i] != '\0')
		i ++;
	while(ft_isspace(str[j]) == FALSE && j > 0)
		j --;
	j ++;
	if(ft_isspace(str[j]) == TRUE)
		return ("");
	return (ft_substr(str, j, i - j));
}
