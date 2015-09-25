
#include "puzzle.h"

using namespace std;


void Puzzle::setDepth(int d){
	depth = d;
}

int Puzzle::getDepth(){
	return depth;
}


int Puzzle::calcmisplacedTiles(){
	int x,y,sum;
	sum=0;
	for(y=0; y < 3;y++){
	    for(x=0; x < 3;x++){
			  if(board[y][x] !=0 ){
				if(board[y][x]!=goalBoard[y][x]){
					sum=sum+1;
					}
			  }      
		 }
   }
   return sum;
}

int Puzzle::calcManhattanDistance(int n){
	int x,y;
	int x1,y1,x2,y2;
	bool found=false;
	
	for(y=0; y < 3;y++){
	    for(x=0; x < 3;x++){
			        
			  if(board[y][x] == n){
				  x1=x;
				  y1=y;
				  found = true;
				  break;
			  }      
		 }
		 if(found) break;   
   }
   
   if(!found) return -1; //to signal error
   
   
   found = false;
   //find x-y components of tile with number n
   for(y=0; y < 3;y++){
	    for(x=0; x < 3;x++){
			        
			  if(goalBoard[y][x] == n){
				  x2=x;
				  y2=y;
				  found = true;
				  break;
			  }      
		 }   
		 if(found) break;
   }
	
   if(!found) return -1; //to signal error
   return (abs(x1-x2) + abs(y1-y2));
}

void Puzzle::updateHCost(heuristicFunction hFunction){
	hCost = h(hFunction);
}

void Puzzle::updateFCost(){
	fCost = hCost + pathLength;
}

int Puzzle::getFCost(){
	return fCost;
}

int Puzzle::h(heuristicFunction hFunction){
	
	int sum;
	
	switch(hFunction){
		case misplacedTiles:
		         sum=calcmisplacedTiles();
		        break;
		         
		case manhattanDistance:
		        
		        
		        sum=0;
		        for(int i=0; i < 9;i++){
                  sum = sum + calcManhattanDistance(i);
			     }
		        
		        break;         
		           
	}
	
	return sum;
	
}


//constructor
Puzzle::Puzzle(const Puzzle &p) : path(p.path){
	
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    board[i][j] = p.board[i][j];
		    goalBoard[i][j] = p.goalBoard[i][j];
		}
	}	
	
	x0 = p.x0;
	y0 = p.y0;
	//path = p.path;
	pathLength = p.pathLength;
	hCost = p.hCost;
	fCost = p.fCost;
	
	
}

//constructor
Puzzle::Puzzle(string const elements, string const goal){
	
	int n;
	
	n = 0;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    board[i][j] = elements[n] - '0';
		    if(board[i][j] == 0){
			    x0 = j;
			    y0 = i;
			 }
		    n++;
		} 
	}
		
	///////////////////////
	n = 0;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    goalBoard[i][j] = goal[n] - '0';
		    n++;
		} 
	}
		
	///////////////////////
	
	path = "";
	pathLength=0;
	hCost = 0;
	fCost = 0;
	depth = 0;
	
}




//converts board state into its string representation
string Puzzle::toString(){
  int n;
  
  string stringPath;
   
  
  n=0;
  for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    //stringPath[n] = board[i][j] + '0'; //error
		    stringPath.insert(stringPath.end(), board[i][j] + '0');
		    n++;
		} 
  }
  
//  cout << "toString = " << stringPath << endl;
  
  return stringPath;
}

//checks if the current state matches the goal state
bool Puzzle::goalMatch(){
	
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		  //useful for debugging purposes only
		  //cout << endl << board[i][j]  << " compared to " << goalBoard[i][j];
		  if( board[i][j] != goalBoard[i][j]){
		     //cout << endl;
		     return false;
		  }
		}
	}
	cout << endl;
	return true;
}


bool Puzzle::canMoveLeft(){
	
/*
	if(x0 > 0){
		return true;
	} else {
		return false;
	}
*/
   
   return (x0 > 0);
	
}

const string Puzzle::getPath(){
	return path;
}

bool Puzzle::canMoveRight(){

   return (x0 < 2);
	
}


bool Puzzle::canMoveUp(){

   return (y0 > 0);
	
}

bool Puzzle::canMoveDown(){

   return (y0 < 2);
	
}


Puzzle *Puzzle::moveLeft(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(x0 > 0){
		
		p->board[y0][x0] = p->board[y0][x0-1];
		p->board[y0][x0-1] = 0;
		
		p->x0--;
		
		p->path = path + "L";
		p->pathLength = pathLength + 1;  
		p->depth = depth + 1; //incorrect
		
	}
	p->strBoard = p->toString();
	return p;
	
}


Puzzle *Puzzle::moveRight(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(x0 < 2){
		
		p->board[y0][x0] = p->board[y0][x0+1];
		p->board[y0][x0+1] = 0;
		
		p->x0++;
		
		p->path = path + "R";
		p->pathLength = pathLength + 1;  
		p->depth = depth + 1;
		
	}
	
	p->strBoard = p->toString();
	
	return p;
	
}


Puzzle *Puzzle::moveUp(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(y0 > 0){
		
		p->board[y0][x0] = p->board[y0-1][x0];
		p->board[y0-1][x0] = 0;
		
		p->y0--;
		
		p->path = path + "U";
		p->pathLength = pathLength + 1;  
		p->depth = depth + 1;
		
	}
	p->strBoard = p->toString();
	return p;
	
}

Puzzle *Puzzle::moveDown(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(y0 < 2){
		
		p->board[y0][x0] = p->board[y0+1][x0];
		p->board[y0+1][x0] = 0;
		
		p->y0++;
		
		p->path = path + "D";
		p->pathLength = pathLength + 1;  
		p->depth = depth + 1;
		
	}
	p->strBoard = p->toString();	
	return p;
	
}

void Puzzle::printBoard(){
	cout << "board: "<< endl;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		  cout << endl << "board[" << i << "][" << j << "] = " << board[i][j];
		}
	}
	cout << endl;
	
}

int Puzzle::getPathLength(){
	return pathLength;
}
