#include <stdio.h>
#include <string.h>
#include "khelljyr.h"

static const Command	commands[] =
  {
    {"install-js", 0, install_js}
  };

static const Command		*command_cmp(char *str)
{
  unsigned int		count = 0;
  
  printf("%s\n", str);
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
      if (*argv[count] == '-')
	{
	  if ((c = command_cmp(argv[count] + 1)) && (argc >= count + c->nbr_args))
	    c->fct(NULL, argv + count);
	  else
	    return (dprintf(2, "Bad command: %s\n", argv[count]));
	}
      ++count;
    }
  return (0);
}

int			main(int argc, char **argv)
{
  return (do_commands(argc, argv));
}
