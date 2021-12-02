Official, timed competitions are placed in a directory titled the date that the competition started. If the problem was solved in time, passing all test cases, then
the .py file will just be the problem name. However, if I was not able to solve the problem in time, the py file will be the problem name + "_failed". If I ever
go back and redo a problem and it succeeds, that file will be called the problem name. Note that if there is a _failed problem that shares the same name with
another file in the same directory, the _failed was during the competition while not failed was the attempt after the competition finished. For example, in the
directory 2020dec18:

abc.py and daisy.py were solved during the competition.

rut_failed.py was the code I had during the competition, but it did not pass the test cases.

rut.py was the working code that I made after the competition that passes all of the test cases.

Unofficial problems are outside of any other directory. If I succeeded in all of the test cases, I will make a .explain file, where the problem details and my own
analysis of the problem will be. If something doesn't have a .explain file, then I haven't gotten around to making it, or it does not pass all test cases.

Before December 18, 2020, problem input is stored in a file called "problem.in" and output is written to a file called "problem.out", where "problem" is specified
by USACO's problem description.

On and after December 18, 2020, problem input is written to the program's standard input/stdin, and written to standard output/stdout. In python, that means that
input() and print() are used.
