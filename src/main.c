#include <stdio.h>
#include <string.h>
#include "khelljyr.h"

static const char		*help_lines[] =
  {
    "\nKhelljyr "VERSION,
    "Here are the commands supported:\n",
    "create [name]:\tCreate a new khelljyr project",
    "install-js:\tinstall the JavaScript framework in the current project",
    "update:\t\tUpdates the current version of Khelljyr in the current project",
    "help:\t\tDisplays this message",
    "No parameters will compile the current project\n"
  };

static void			help(Khelljyr *k, char **argv)
{
  (void)k;
  (void)argv;
  unsigned int			count = 0;

  while (count < (sizeof(help_lines) / sizeof(*help_lines)))
    {
      printf("%s\n", help_lines[count]);
      ++count;
    }
}

static const Command		commands[] =
  {
    {"create", 1, create_project},
    {"install-js", 0, install_js},
    {"update", 0, project_update},
    {"help", 0, help}
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

  if (argc == 1)
    {
      compile(NULL, NULL);
      return (0);
    }
  while (count < argc)
    {
      if ((c = command_cmp(argv[count])))
	{
	  if ((argc > count + c->nbr_args))
	    {
	      c->fct(NULL, argv + count);
	      count += c->nbr_args;
	    }
	  else
	    return (dprintf(2, "Missing args: %s\n", argv[count]));
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
