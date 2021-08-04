//
// Created by Cesar Erebus on 6/17/21.
//

#ifndef ENVEXPORTUNSET_H
# define ENVEXPORTUNSET_H

int ft_env(char **envp);
void insert_var(t_list **envp_list, char *var);
//int init_envp_list(char **envp, t_en_list **envp_list);
int init_envp_list(char **arr, t_en_list **list, t_en_list **env_list);
void ft_print_export( t_msh *msh);
void ft_print_env(t_msh *msh);

//для введения новой переенной
void ft_add_variable(t_msh *msh, char *name, char *value);

void ft_unset(t_msh *msh, char **names);
#endif
