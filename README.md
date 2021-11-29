# OS-Programming-Assignment-2
**This code was compiled with g++ in a Linux terminal.**
# Getting Started:
You can either clone this repo or directly copy+paste this code.\
All the proper include statements are included in the .cpp file.\
 \
To compile and run this code, you need two commands:\
**g++ banker.cpp -o banker**\
**./banker**

*In order for this program to work you MUST have an input text file named "input.txt", and have it formatted as such:*\
Only one piece of data per line.\
The first two lines are reserved for the number of programs (first line) and the number of resources (second line).\
Each subsequent line is reserved for the processess' allocations and their maximums.\
The final three lines are reserved for the available resources.
# Purpose:
This code is an example of The Banker's Algorithm, showing the safe sequence for any given number of programs and resources.
# Output:
This code will output the safe sequence of the programs given in the input file.
For this particular input file, the code outputs the following:
```
The following sequence is a safe sequence:
P1 then P3 then P4 then P0 then P2
```
# Resources
Here is a list of the websites I got information from:
```
https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/  <-- An example of the banker's algorithm heavily modified to dynamically read in from a file.
https://www.cplusplus.com/reference/string/stoi/
```
