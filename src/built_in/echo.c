#include "minishell.h"

static int is_it_a_valide_minus_n_flag(char *str)
{
  int i;

  i = 0;
  if(!str)
    return 0;
  if(str[i] != '-')
    return 0;
  i++;
  while(str[i])
  {
    if(str[i] != 'n')
      return 0;
    i++;
  }
  return 1;
}

void echo(char **args)
{
    int first_argument_flag;

    args++;
    first_argument_flag = 0;
  if(is_it_a_valide_minus_n_flag(*args))
  {
    first_argument_flag = 1;
    args ++;
  }
    while(*args)
    {
      if(!is_it_a_valide_minus_n_flag(*args) || first_argument_flag == 0)
      {
        printf("%s", *args);
        if(*(args + 1) != NULL)
          printf(" ");
      }
      args++;
    }
    if(!first_argument_flag)
         printf("\n");
}

