#include "minishell.h"

char ** copy_env(char **env)
{
  int i;
  char **my_env;
  my_env = ft_malloc((len_of_two_d_array(env) + 1) * sizeof(char *), 0);
  i = 0;
  while(env[i])
  {
    my_env[i] = ft_strdup((const char *)env[i], 0);
    i++;
  }
  my_env[i] = NULL;
  return my_env;
}
