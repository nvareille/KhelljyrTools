#include <stdlib.h>
#include <stdio.h>

void		format_exec_command(size_t size, void (*ptr)(void *, char *, size_t), void *data)
{
  int		value;
  char		buff[size];

  ptr(data, buff, size);
  value = system(buff);
  if (value)
    dprintf(2, "Failed to exec command \"%s\"\n", buff);
}
