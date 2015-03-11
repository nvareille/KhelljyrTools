#include <stdio.h>
#include <fcntl.h>
#include "khelljyr.h"

static void	cc(void *data, char *str, size_t size)
{
  (void)data;
  snprintf(str, size, "pebble build");
}

void		compile(Khelljyr *k, char **argv)
{
  (void)k;
  (void)argv;
  int		fd = open("Khelljyr.conf", O_RDONLY);

  if (fd != -1)
    format_exec_command(512, cc, NULL);
  else
    dprintf(2, "This is not a Khelljyr repository\n");
}
