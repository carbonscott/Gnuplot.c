# A minimal Gnuplot wrapper written in C

The idea behind this wrapper is discussed
[here](https://carbonscott.github.io/wrap_command_line_application_in_python.html).
A minimal example is demonstrated in `main.c`.  

# Usage

```C
write_gp(__gp_filehandler__, __gp_command__);
```
It can be simplified using macro `#define GP(CMD) write_gp(gp, CMD)`.

The following code snippet demonstrates a data-driven plotting.  

```C
#include <stdio.h>
#include <stdlib.h>
#include "gnuplot.h"

#define GP(CMD) write_gp(gp, CMD)

int
main (void)
{
  /* Initialize Gnuplot... */
  FILE * gp = init_gp();

  /* Seed the random number */
  srand(0);

  /* Generate 500 random numbers ranging from -100 to 100... */
  int len = 500;
  int randoms [len];
  for (int i = 0 ; i < len; ++i)
    {
      randoms[i] = rand() % 200 - 100;
    }

  /* Data-driven plotting... */
  GP("plot '-' using 1:2 with linespoints pointsize 2 linewidth 0.25 linecolor rgb 'blue',\\");
  GP("");

  for (int i = 0; i < len; ++i)
    {
      char cmd [100];
      sprintf(cmd, "%d    %d", i, randoms[i]);
      GP(cmd);
    }
  GP("e");


  /* Displaying Gnuplot window until any key press is accepted... */
  char anykey[2];
  printf("Press any key to exit...");
  fgets(anykey, 2, stdin);

  /* Terminate Gnuplot... */
  // write_gp(gp, "exit");
  GP("exit");
  close_gp(gp);

  return EXIT_SUCCESS;
}

```
