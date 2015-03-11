#ifndef KHELLJYR_H_
# define KHELLJYR_H_

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

void			install_js(Khelljyr *, char **);

#endif
