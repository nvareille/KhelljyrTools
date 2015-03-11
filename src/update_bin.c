#include <stdio.h>
#include "khelljyr.h"

static void	update(void *data, char *str, size_t size)
{
  (void)data;

  snprintf(str, size, "cd /tmp/;git clone https://github.com/nvareille/KhelljyrTools && cd KhelljyrTools && make install");
}

void		update_bin(Khelljyr *k, char **argv)
{
  (void)k;
  (void)argv;

  format_exec_command(512, update, NULL);
}
