#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "khelljyr.h"

static void	do_logs(void *data, char *str, size_t size)
{
  char		*var = get_env_var(data, "PEBBLE_PHONE");

  if (!var)
    {
      printf("The PEBBLE_PHONE variable is unset, using emulator\n");
      snprintf(str, size, "pebble logs --emulator aplite");
    }
  else
    snprintf(str, size, "pebble logs --phone %s", var);
}

void		logs(Khelljyr *k, char **argv)
{
  (void)k;
  (void)argv;
  int		fd = open("Khelljyr.conf", O_RDONLY);

  if (fd != -1)
    format_exec_command(512, do_logs, k);
  else
    dprintf(2, "This is not a Khelljyr repository\n");
}
