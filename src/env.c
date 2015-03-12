#include <string.h>
#include "khelljyr.h"

char		*get_env_var(Khelljyr *k, char *var)
{
  int		count = 0;
  size_t	size = strlen(var);


  while (k->env[count])
    {
      if (!strncmp(k->env[count], var, size))
	return (k->env[count] + size + 1);
      ++count;
    }
  return (NULL);
}
