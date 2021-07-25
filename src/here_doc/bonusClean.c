

#include "here_doc.h"

void fdPathListClean(int **fd, char **pathlist)
{
	closeFreeAllFds(fd);
	mFree(pathlist);
}
