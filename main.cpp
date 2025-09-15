#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Maze {
public:
    Maze(std::string fileName) {

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file" << std::endl;
    }

    std::string line;
    while (std::getline(inputFile, line)) {     //reading in file and adding to 2D vector
        std::vector<int> row;
        for (char c : line) {
            if (c == '0') {
                row.push_back(0);
            }
            if (c == '1') {
                row.push_back(1);
            }
        }
        maze.push_back(row);     //adding row vectors to big maze vector
    }

    rows = maze.size();
    cols = maze[0].size();

    for (int j = 0; j < cols; ++j) {
        if (maze[0][j] == 0) {     //locating entrance cell on top row
            start_y = 0;
            start_x = j;
        }
        if (maze[rows - 1][j] == 0) {     //locating exit cell on bottom row
            exit_y = rows - 1;
            exit_x = j;
        }
    }
    for (int i = 0; i < rows; ++i) {
        if (maze[i][0] == 0) {     //locating entrance cell on left column
            start_y = i;
            start_x = 0;
        }
        if (maze[i][cols - 1] == 0) {     //locating exit cell on right column
            exit_y = i;
            exit_x = cols - 1;
        }
    }
    }
    bool solved() {     //checks if successfully explored or not
        return explore(start_y, start_x);
    }
    void printMaze() {     //print function
        for (int i = 0; i < maze.size(); ++i) {
            for (int j = 0; j < maze[i].size(); ++j) {
                std::cout << maze[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void printPrettyMaze() {     //doesn't work
        for (int i = 0; i < maze.size(); ++i) {
            for (int j = 0; j < maze[i].size(); ++j) {
                if (maze[i][j] == 0) {     //marks unexplored spaces
                    std::cout << " ";
                }
                else if (maze[i][j] == 1) {     //marks walls
                    std::cout << 1;
                }
                else if (maze[i][j] == 4) {     //marks final path
                    std::cout << "*";
                }
                else if (maze[i][j] == 5) {     //marks explored path
                    std::cout << ".";
                }
            }
            std::cout << std::endl;
        }
    }
    //used to test if entrance and exit are found
    int getStartY() const {return start_y;}
    int getStartX() const {return start_x;}
    int getExitY() const {return exit_y;}
    int getExitX() const {return exit_x;}

private:

    std::vector<std::vector<int>> maze;
    int rows;
    int cols;
    int start_y;
    int start_x;
    int exit_y;
    int exit_x;

    bool explore (int curr_y, int curr_x) {
        //base case
        if (curr_y == exit_y && curr_x == exit_x) {     //base case
            maze[curr_y][curr_x] = 5;     //marks as explored for the final path
            return true;
        }
        maze[curr_y][curr_x] = 4;
        //checking up
        if (curr_y - 1 >= 0 && maze[curr_y - 1][curr_x] == 0) {
            if (explore(curr_y - 1, curr_x)) {
                return true;
            }
        }
        //checking left
        if (curr_x - 1 >= 0 && maze[curr_y][curr_x - 1] == 0) {
            if (explore(curr_y, curr_x - 1)) {
                return true;
            }
        }
        //checking right
        if (curr_x + 1 < maze[0].size() && maze[curr_y][curr_x + 1] == 0) {
            if (explore(curr_y, curr_x + 1)) {
                return true;
            }
        }
        //checking down
        if (curr_y + 1 < maze.size() && maze[curr_y + 1][curr_x] == 0) {
            if (explore(curr_y + 1, curr_x)) {
                return true;
            }
        }
        //backtracking to get final path
        // NEEDS WORK
        maze[curr_y][curr_x] = 5;
        return false;
    }
};

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <fileName>" << std::endl;
        return 1;
    }
    //calling function
    Maze maze(argv[1]);     //takes input file from command line
    maze.printMaze();
    std::cout << "The entrance cell is at: [" << maze.getStartY() << "][" << maze.getStartX() << "]" << std::endl;
    std::cout << "The exit cell is at: [" << maze.getExitY() << "][" << maze.getExitX() << "]" << std::endl;
    //std::cout << "The current cell is: " << maze[curr_y][curr_x] << std::endl;
    if (maze.solved()) {
        std::cout << "The maze was solved successfully!" << std::endl;
    }
    else {
        std::cout << "No solution is possible." << std::endl;
    }
    maze.printPrettyMaze();
    return 0;
}

