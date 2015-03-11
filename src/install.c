#include <stdio.h>
#include "khelljyr.h"

static void	clone_repo(void *data, char *str, size_t size)
{
  char		*path = data;

  snprintf(str, size, "cd %s && (git clone https://github.com/nvareille/Khelljyr || (cd Khelljyr && git pull))", path);
}

void		install(Khelljyr *k, char **argv)
{
  (void)k;
  format_exec_command(512, clone_repo, argv[1]);
}
