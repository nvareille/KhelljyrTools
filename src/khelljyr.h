#ifndef KHELLJYR_H_
# define KHELLJYR_H_

#include <stdlib.h>

typedef struct		s_Khelljyr
{
  int			a;
}			Khelljyr;

typedef struct		s_Command
{
  char			*name;
  unsigned short	nbr_args;
  void			(*fct)(Khelljyr *, char **);
}			Command;

void			format_exec_command(size_t, void (*)(void *, char *, size_t), void *);

void			create_project(Khelljyr *, char **);
void			install_js(Khelljyr *, char **);
void			project_update(Khelljyr *, char **);

void			set_khelljyr_repo(void *, char *str, size_t);

#endif
