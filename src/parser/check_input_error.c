
#include "minishell.h"

int	check_unclosed_quotes(char *str)
{
	int	i;
	int	single_quote;
	int	double_quote;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (str[i])
	{
		if (str[i] == single_q && double_quote == 0)
			single_quote = !single_quote;
		else if (str[i] == double_q && single_quote == 0)
			double_quote = !double_quote;
		i++;
	}
	return (single_quote || double_quote);
}

int	check_error(t_shell_control_block *shell)
{
  char *str;

  str = shell->line;
  if(!str || !*str)
    return 1;
	if (check_unclosed_quotes(str))
	{
		print_error("unclosed quote\n");
    shell->exit_status = 2;
    return 1;
	}
	return (0);
}
