# Maze
Project 1: Solving a Maze
Gabriela Carbajal Ortiz
007715715
https://github.com/carbajalor-creator/Maze.git


Collaboration & Sources
I used online resources and websites such as W3 Schools, GeekforGeeks and  AI to get my file in the correct directory and have it successfully read the text file. The rest of the functions like finding the entrance and exit, the explore function, and printing are my work.

Implementation Details
To read in the file I created a maze vector and for each row I used getline and pushback to add all the digits into multiple row vectors. Then I used 2 for loops one to search through the top and bottom row and left and right column to find the entrance and exit of the maze. My explore function takes 2 parameters, the coordinates for the starting position. My base case checks if the current coordinates are the same as the exit coordinates and if so the function returns true. Otherwise, the function will check if it can go up, left, right, and down if so it will recurr that way. 

Testing & Status
The function to find the entrance and exit works and the recursion works and is able to find whether there is an exit or not which I was able to find out by changing the input file and moving the zeros to different locations to see if the function was still able to find the entrance and exit. The recursion works because I printed the maze after the recursive calls and all the paths that could be reached were reached. What doesn't work is the backtracking which won't print out correctly.
