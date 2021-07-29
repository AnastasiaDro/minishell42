#include "minishell.h"

static void setPwd(t_msh *msh, char *dir)
{
	char *newDir;
	newDir = getcwd(NULL, 0);
	t_en_list *tmpExportList;
	t_en_list *tmpEnvList;
	tmpEnvList = msh->env_list;
	tmpExportList = msh->export_list;
	while (tmpExportList && tmpEnvList)
	{
		if (!ft_strncmp(tmpExportList->name, "OLDPWD", ft_strlen(tmpExportList->name))) // TODO: add 2 flags
			tmpExportList->value = dir;
		else if (!ft_strncmp(tmpExportList->name, "PWD", ft_strlen(tmpExportList->name)))
			tmpExportList->value = newDir;
		if (!ft_strncmp(tmpEnvList->name, "OLDPWD", ft_strlen(tmpEnvList->name)))
			tmpEnvList->value = dir;
		else if (!ft_strncmp(tmpEnvList->name, "PWD", ft_strlen(tmpEnvList->name)))
			tmpEnvList->value = newDir;
		tmpExportList = tmpExportList->next;
		tmpEnvList = tmpEnvList->next;
	}
}

void	ft_cd(t_msh *msh, const char *path)
{

	char *dir;
	dir = getcwd(NULL, 0);
	if (path == NULL)
		path = getExportVar(&msh->export_list, "HOME")->value;
	if (chdir(path) == 0)
	{
		setPwd(msh, dir);
	}
	else
		printf("msh: cd: %s: No such file or directory\n", path);
}
