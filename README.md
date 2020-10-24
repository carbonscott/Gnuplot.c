# A minimal Gnuplot wrapper written in C

The idea behind this wrapper is discussed
[here](https://carbonscott.github.io/wrap_command_line_application_in_python.html).
A minimal example is demonstrated in `main.c`.  

# Usage

```C
write_gp(__gp_filehandler__, __gp_command__);
```

The following code snippet plots $sin(x)$ and $cos(x)$ in Gnuplot.  

```C
/* Initialize Gnuplot... */
FILE * gp = init_gp();

/* Plot sin(x) and cos(x) in Gnuplot... */
write_gp(gp, "plot sin(x), \\");
write_gp(gp, "     cos(x)");

/* Displaying Gnuplot window until any key press is accepted... */
char anykey[2];
printf("Press any key to exit...");
fgets(anykey, 2, stdin);

/* Terminate Gnuplot... */
write_gp(gp, "exit");
close_gp(gp);
```
