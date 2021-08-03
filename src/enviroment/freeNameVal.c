void freeNameVal(char **names)
{
	int i;

	i = 0;
	while(names[i])
	{
		free(names[i]);
		names[i] = NULL;
		i++;
	}

}