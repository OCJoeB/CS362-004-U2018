Submission files for the random quiz

testme.c
makefile

To run file, type "make testme" to compile and run the executable - it should then print the error message within the allotted 5 minute timeframe - generally it will be much faster.

"make clean" will remove the executable, the .gdca file, and the gcno file.

No work with gcov is done as part of the makefile - it can be done later if desired. The program achieves coverage of 
all but the return 0 from main since the string match results in an error code and program exit.  
