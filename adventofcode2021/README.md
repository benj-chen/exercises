To input your own custom input, put it in a file a.txt, for example. Then, run the executable by saying "./[executable name] < a.txt".
If you have to put input into the command line, and acceptable input is int only, you can put the input in and type an unacceptable input (ie "a") to have the while loop stop reading the input. Not advisable.
Format: directories = [day number]
Each directory has "a.cpp" and "b.cpp", first part and second part of the puzzle respectively; and "input.txt", the input text file that I got.
To run, compile a cpp program to. Then, in the terminal, type `[executable] < [day]/input.txt`. For example, if I wanted to run day 1 part A, it would look like this:
```
g++ -std=c++17 1/a.cpp -o a.exe
./a.exe < 1/input.txt
```

Custom input should be put into the input.txt file, not into the standard input. Due to how my cpp programs accept input, it might accept inputs forever and never calculate anything.