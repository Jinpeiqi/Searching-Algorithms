#include <string>
#include <iostream>

using namespace std;


enum heuristicFunction{misplacedTiles, manhattanDistance};

class Puzzle{
	
	
private:

    string path;
    int pathLength;
    int hCost;
    int fCost;
    int depth;
   
        
    int goalBoard[3][3];
    
    int x0, y0; //coordinates of the blank or 0-tile
int board[3][3];

public:

    
    string strBoard;

    Puzzle(const Puzzle &p);
    Puzzle(string const elements, string const goal);
	 
    void printBoard();
    int calcManhattanDistance(int n);
    int calcmisplacedTiles();
    int h(heuristicFunction hFunction);
    void updateFCost(); 
    void updateHCost(heuristicFunction hFunction);
    
    bool goalMatch();
    string toString();
    
    bool canMoveLeft();
    bool canMoveRight();
    bool canMoveUp();
    bool canMoveDown();
    

    Puzzle * moveLeft();
    Puzzle * moveRight();
    Puzzle * moveUp();
    Puzzle * moveDown();

    const string getPath();
    
    void setDepth(int d);
    int getDepth();
    
    int getPathLength();
    int getFCost();
	
};
