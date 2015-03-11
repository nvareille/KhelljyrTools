#include <stdio.h>
#include "khelljyr.h"

static void	update_pebble_project(void *data, char *str, size_t size)
{
  (void)data;
  snprintf(str, size, "pebble convert-project");
}

void		project_update(Khelljyr *k, char **argv)
{
  (void)k;
  (void)argv;

  format_exec_command(512, update_pebble_project, NULL);
  format_exec_command(512, set_khelljyr_repo, NULL);
}
