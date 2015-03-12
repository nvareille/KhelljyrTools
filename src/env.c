#include <string.h>
#include "khelljyr.h"

char		*get_env_var(Khelljyr *k, char *var)
{
  int		count = 0;

  while (k->env[count])
    {
      if (!strcmp(k->env[count], var))
	return (k->env[count]);
      ++count;
    }
  return (NULL);
}
