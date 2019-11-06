# CS4900-QuadSolver
a command line tool to solve quadratic equations to be  run on a linux operating system by an engineer. Tool will need to be installed by a technician. Also the tool will need to have high accuracy for four significant digits.


## How to install
    type make install


## How to run
  After installation you can run the program with by typing in ./qsolve.
  Either type ./qsolve A B C where A B C are expected values for the quadratic equation
    or enter the program by typing ./qsolve and entering values for A B C when prompted.
    Entering the program will allow the user to solve more than 1 equation.

  You can pass a file to qsolve by typing ./qsolve < filename
    proper format of the file would be 3 values separated by space
      A B C
      A B C
      A B C
      ...

Logging can be enabled by typing in "log" after entering the program.

Typing in "q" will quit the qsolver program   


README files
  Each c file has a README files explaining what is expected behavior for that c file and all functions contained within. General logic for that function should be explained in the README file.
  example ./solveit/readme.md file
