#include <stdio.h>
#include <string.h>
#include "khelljyr.h"

static const Command	commands[] =
  {
    {"create-project", 1, create_project},
    {"install", 1, install},
    {"install-js", 0, install_js},
    {"update-project", 0, project_update},
  };

static const Command		*command_cmp(char *str)
{
  unsigned int		count = 0;
  
  while (count < (sizeof(commands) / sizeof(*commands)))
    {
      if (!strcmp(commands[count].name, str))
	return (&commands[count]);
      ++count;
    }
  return (NULL);
}

static int		do_commands(int argc, char **argv)
{
  int			count = 1;
  const Command		*c;

  if (argc <= 1)
    return (dprintf(2, "Bad parameters number\n"));
  while (count < argc)
    {
      if ((c = command_cmp(argv[count])) && (argc > count + c->nbr_args))
	{
	  c->fct(NULL, argv + count);
	  count += c->nbr_args;
	}
      else
	return (dprintf(2, "Bad command: %s\n", argv[count]));
      ++count;
    }
  return (0);
}

int			main(int argc, char **argv)
{
  return (do_commands(argc, argv));
}
