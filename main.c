/*-----------------------------------------------------------------------------
  Copyright (c) 2020 Cong Wang

  MIT License

  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files (the
  "Software"), to deal in the Software without restriction, including
  without limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so, subject to
  the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
-----------------------------------------------------------------------------*/

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
