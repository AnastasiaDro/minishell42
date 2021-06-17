//
// Created by Cesar Erebus on 6/17/21.
//

#ifndef ENV_EXPORT_UNSET_H
# define ENV_EXPORT_UNSET_H

int ft_env(char **envp);
void insert_var(t_list **envp_list, char *var);
int init_envp_list(t_list **envp_list, char **envp);
#endif
