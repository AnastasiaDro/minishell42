//
// Created by Cesar Erebus on 6/17/21.
//

#ifndef ENV_EXPORT_UNSET_H
# define ENV_EXPORT_UNSET_H

int ft_env(char **envp);
void insert_var(t_list **envp_list, char *var);
//int init_envp_list(char **envp, t_en_list **envp_list);
int init_envp_list(char **arr, t_en_list **list, t_en_list **env_list);
void ft_print_export( t_msh *msh);
void ft_print_env(t_msh *msh);
void ft_add_envlist(t_msh *msh, char *str);
#endif
