#include <stdio.h>
#include <fcntl.h>
#include "khelljyr.h"

static void	cpy_js(void *data, char *str, size_t size)
{
  (void)data;
  snprintf(str, size, "cp -r src/Khelljyr/js src/");
}

void		install_js(Khelljyr *k, char **argv)
{
  (void)k;
  (void)argv;
  
  int		fd = open("Khelljyr.conf", O_RDONLY);

  if (fd != -1)
    format_exec_command(512, cpy_js, NULL);
  else
    dprintf(2, "This is not a Khelljyr repository\n");
}
