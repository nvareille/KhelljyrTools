#include <string.h>
#include <jansson.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#include "khelljyr.h"

static void	cpy_resource(void *data, char *str, size_t size)
{
  char		*name = data;

  snprintf(str, size, "cp %s resources/", name);
}

static char	*get_file(char *str)
{
  char		*save = str;

  while (*str)
    {
      if (*str == '/')
	save = str + 1;
      ++str;
    }
  return (save);
}

void		add_resource(Khelljyr *k, char **argv)
{
  int		fd = open("Khelljyr.conf", O_RDONLY);
  json_t	*root;
  json_t	*res;
  json_t	*data;
  json_error_t	e;

  if (fd != -1)
    {
      format_exec_command(512, cpy_resource, argv[1]);
      root = json_load_file("appinfo.json", JSON_DECODE_ANY, &e);
      if (root)
	{
	  res = json_object_get(root, "resources");
	  res = json_object_get(res, "media");
	  data = json_pack("{s:s, s:s, s:s}", "type", argv[3], "name", argv[2], "file", get_file(argv[1]));
	  json_array_append(res, data);
	  json_dump_file(root, "appinfo.json", JSON_INDENT(2));
	}
    }
  else
    help(k, argv);
}
