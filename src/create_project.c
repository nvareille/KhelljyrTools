#include <stdio.h>
#include <stdlib.h>
#include "khelljyr.h"

void		set_khelljyr_repo(void *data, char *str, size_t size)
{
  (void)data;
  snprintf(str, size, "echo " VERSION " > Khelljyr.conf");
}

static void	create_khelljyr_repo(void *data, char *str, size_t size)
{
  char		*name = data;

  snprintf(str, size, "pebble new-project %s", name);
}

static void	go_khelljyr_repo(void *data, char *str, size_t size)
{
  char		*name = data;

  snprintf(str, size, "cd %s;echo " VERSION " > Khelljyr.conf;mkdir resources;cd src/;git clone https://github.com/nvareille/Khelljyr", name);
}

static void	create_khelljyr_main(void *data, char *str, size_t size)
{
  char		*name = data;

  snprintf(str, size, "cd %s/src;rm %s.c;echo %s > main.c", name, name, MAIN_FILE);
}

void		create_project(Khelljyr *k, char **argv)
{
  (void)k;

  format_exec_command(512, create_khelljyr_repo, argv[1]);
  format_exec_command(512, go_khelljyr_repo, argv[1]);
  format_exec_command(512, create_khelljyr_main, argv[1]);
}
