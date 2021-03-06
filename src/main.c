#include <stdio.h>
#include <string.h>
#include "khelljyr.h"

static const char		*help_lines[] =
  {
    "\nKhelljyr "VERSION,
    "Here are the commands supported:\n",
    "add-resource [resource] [name] [type]:\tAdd a resource to the current Khelljyr project",
    "clean:\t\t\t\t\tClean the project relocatable files",
    "convert:\t\t\t\tUpdates the current version of Khelljyr in the current project",
    "create [name]:\t\t\t\tCreate a new Khelljyr project",
    "download:\t\t\t\tInstall the Khelljyr framework in the current project",
    "examples [folder]:\t\t\tGet the Khelljyr examples",
    "help:\t\t\t\t\tDisplays this message",
    "install:\t\t\t\tInstall the current application on Pebble",
    "install-js:\t\t\t\tInstall the JavaScript framework in the current project",
    "logs:\t\t\t\t\tLogs the debug messages\n",
    "No parameters will compile the current project\n"
  };

void				help(Khelljyr *k, char **argv)
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
    {"add-resource", 3, add_resource},
    {"clean", 0, clean},
    {"convert", 0, project_update},
    {"create", 1, create_project},
    {"download", 0, install},
    {"examples", 1, examples},
    {"help", 0, help},
    {"install", 0, install_bin},
    {"install-js", 0, install_js},
    {"logs", 0, logs},
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

static int		do_commands(int argc, char **argv, char **env)
{
  int			count = 1;
  const Command		*c;
  Khelljyr		k;

  k.env = env;
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
	      c->fct(&k, argv + count);
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

int			main(int argc, char **argv, char **env)
{
  return (do_commands(argc, argv, env));
}
