#include "minishell.h"

void plist(t_list *lst);

void splitt_by_White_space(t_shell_control_block *sh)
{
  
  t_list *node;

  char **ptr;
  ptr = customized_split(sh->line);
  while(*ptr)
  {
    node = ft_lstnew(*ptr);
    ft_lstadd_back(&(sh->cmd_line), node);
    ptr++;
  }
    plist(sh->cmd_line);
  exit(1);
}
void parse_line(t_shell_control_block *shell)
{
  splitt_by_White_space(shell);
  shell->splitted = split_with_operators(shell->splitted);
  expand(shell);
  shell->splitted = handle_dollar_with_quotes(shell->splitted);
  shell->splitted = split_after_expantion(shell->splitted);
  shell->tokenized = make_token(shell);
}

void execute_line(t_shell_control_block *shell)
{
  if (shell->tokenized)
  {
    create_all_heredocs(shell);
    get_cmd_and_its_args(shell);
    if(!is_there_a_pipe(shell) && execute_built_in(shell))
      ;
    else
      execute_command_line(shell);
  }
}

int main(int ac, char **av, char **env)
{ 
  t_shell_control_block shell;

  ft_init_shell_block(&shell, ac, av);
  shell.env_cpy = copy_env(env);
  shell.env_of_export = copy_env(env);
 while (1) {
    handle_signals(0);
    if(!ft_readline(&shell))
      continue;
    parse_line(&shell);
    execute_line(&shell);
    free_memory(get_garbage_pointer(1));
    free(shell.line);
  }
  return (0);
}

void plist(t_list *lst)
{
  t_list *ptr;
  ptr  = lst;
  while (ptr)
  {
    printf("->%s\n", (char *)ptr->content);
   ptr = ptr->next;
  }
}