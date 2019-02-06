## Programmable Calculator in C++ 

Implemented a programmable calculator by using the Gang of Four's design pattern for virtual functions. 
Course: Object Oriented Languages and Environment under Prof. Ugo Buy at the University of Illinois at Chicago.

## Project Description

Implemented a Programmable Calculator which lets the users specify sequences of arithmetic operations on 4 registers, denoted by w, x, y, and z. The Programmable Counter will read instruction sequences from a file located in the same directory where the cpp files are present. The Programmable Calculator is capable of the implementing the following commands:

1. i <file_name> – Input file (Reads the input file <file_name>. It first checks if the file exists and then reads the instruction sequences.)
2. d – Debug (The next instruction to be executed is tracked by a program counter. The debug command executes only the next available instruction. If the last instruction was already executed in the previous instruction call, it would execute the first instruction of the file.)
3. r – Run (Executes all the instructions of the file. The only criteria is that it can execute only 100 instruction sequences per call. For ex: If a file has 120 instructions of which 10 have already been executed, then this command would execute instructions 11-110. It would terminate once it reaches the end of the file.)
4. c - Continue (If the 'r' command has executed 100 instructions from a file, it can only continue further when this command is called.)
5. p - Print (This command prints the instruction sequence and the content of the registers.)
6. q - Quit application

## Instructions on how to use the application

1. Extract the contents of the folder so that you have all the code files. There are 6 code files viz. Command.h, main.cpp, ProgCalculatorAbstract.h, ProgCalculatorAbstract.cpp, ProgCalculatorImplement.h and ProgCalculatorImplement.cpp.
2. Create a input file for storing the instruction sequence. An example file is already provided as input.in. 
3. Build the code files.
4. Run the code files. You can use six different commands as depicted above - i <file_name>, d, r, c, p, q.


## An Example input file

x = 3.
y = 2.
w = 2.
z = x ** y.
w = w - 1.
x = x + 1.
w ? 4.
x = x - 1.
  