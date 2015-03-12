#ifndef KHELLJYR_H_
# define KHELLJYR_H_

# include <stdlib.h>

# define VERSION "0.13"

# define MAIN_FILE "'#include \"Khelljyr/Khelljyr.h\"\n\nstatic void\texec()\n{\n}\n\nint\t\tmain()\n{\n\tapp_init(NULL, exec);\n}'"

typedef struct		s_Khelljyr
{
  char			**env;
}			Khelljyr;

typedef struct		s_Command
{
  char			*name;
  unsigned short	nbr_args;
  void			(*fct)(Khelljyr *, char **);
}			Command;

char			*get_env_var(Khelljyr *, char *);
void			format_exec_command(size_t, void (*)(void *, char *, size_t), void *);

void			clean(Khelljyr *, char **);
void			logs(Khelljyr *, char **);
void			install_bin(Khelljyr *, char **);
void			update_bin(Khelljyr *, char **);
void			compile(Khelljyr *, char **);
void			create_project(Khelljyr *, char **);
void			install(Khelljyr *, char **);
void			install_js(Khelljyr *, char **);
void			project_update(Khelljyr *, char **);

void			set_khelljyr_repo(void *, char *str, size_t);

#endif
