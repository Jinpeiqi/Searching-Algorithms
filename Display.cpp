//Jinpeiqi 12207549
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

#include "graphics.h"
//#include "puzzle.h" //may be utilised but not required for the assignment
#include "algorithm.h"

using namespace std;

#define OUTPUT_LENGTH 2 /* Length of output string. */

const int HEIGHT = 400; /**< Height of board for rendering in pixels. */
const int WIDTH  = 400; /**< Width of board for rendering in pixels. */

/**
 * Update the board and draw it to the screen. This function displays the
 * board updates in a flicker-free way.
 *
 * @param board 3 x 3 array containing the current board state,
 *              0 indicates an empty space.
 */


//////////////////////////////////////////////////////
// Function prototypes

 
void displayBoard(string const elements); 
void AnimateSolution(string const initialState, string const initialState, string path);
void PrintTimer(clock_t tmrStart, clock_t tmrEnd);

////////////////////////////////////////////////////// 
 
void update(int **board) {
    /* Setting up the graphics. */
    static bool setup = false;

    if(!setup) {
        int graphDriver = 0;
        int graphMode = 0;
        initgraph(&graphDriver, &graphMode, "", WIDTH, HEIGHT);
        setup = true;
    }

    /* Variables for the function. */
    int xIncrement = (WIDTH - 40) / 3;        /* Grid's raster width. */
    int yIncrement = ((HEIGHT - 6) - 40) / 3; /* Grid's raster height. */
    int x = 0;            /* Temporary x positions. */
    int y = 0;            /* Temporary y positions. */
    char outputString[OUTPUT_LENGTH]; /* Holder for output strings in the GUI. */
    static bool visual;   /* Indicator which visual page to draw to
                           * to prevent flickers. */

    /* Initalising the variables. */
    strncpy(outputString, "", OUTPUT_LENGTH);
    /* Even though this is not necessary here the protected version of "strcpy"
       is used in this case. It should ALWAYS be used to prevent boundary
       overwrites! */

    /* Initialising the GUI. */
    setactivepage(visual);
    setbkcolor(BLACK);
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    /* Display different coloured squares for different numbers. */
    y = 10;
    for(int i = 0; i < 3; i++) {
        x = 10;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 0) {
                setcolor(board[i][j]);
                bar(x, y, x + xIncrement, y + yIncrement);
            }
            x += 10;
            x += xIncrement;
        }
        y += 10;
        y += yIncrement;
    }

    /* Display the actual numbers. */
    y = 8 * HEIGHT / 40;
    for(int i = 0; i < 3; i++) {
        x = WIDTH / 6;
        for(int j = 0; j < 3; j++) {
            setcolor(WHITE);
            setbkcolor(board[i][j]);
            if(board[i][j] != 0) {
                snprintf(outputString, OUTPUT_LENGTH, "%d", board[i][j]);
                /* Even though this is also not necessary here the protected
                   version of "sprintf" is used in this case. It should ALWAYS
                   be used to prevent boundary overwrites! */
                outtextxy(x, y, outputString);
                moveto(0, 0);
            }
            x += 2 * (WIDTH / 6);
        }
        y += 13 * HEIGHT / 40;
    }

    /* Set the page to display. */
    setvisualpage(visual);
    visual = !visual;

    delay(1000);
}


void displayBoard(string const elements) {
    /* Setting up the graphics. */
    
    int board[3][3];
    
    /* - works!
    
    int **board;
    
    board = new int*[3];
    
    board[0] = new int[3];
    board[1] = new int[3];
    board[2] = new int[3];
    */
    
    
    int n=0;
    
    for(int i=0; i < 3;i++){
	    for(int j=0; j < 3;j++){
		    
		    board[i][j] = elements.at(n) - '0';
  		    //board[i][j] = atoi(elements.at(n)); //error!
		    
		    //cout << "Elements = "  << elements.at(n) << endl; //works too!
		    //cout << "Elements = " << "board[" << i << "][" << j << "] = " << board[i][j] << endl; //works!
		    
		    n++;
		    
		 }   
	 }
    
    
    static bool setup = false;

    if(!setup) {
        int graphDriver = 0;
        int graphMode = 0;
        initgraph(&graphDriver, &graphMode, "", WIDTH, HEIGHT);
        setup = true;
        
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()/2,"press any key to start.");
        cout << endl << endl << "press any key to start." << endl << endl;
        getch();
        
    }

    /* Variables for the function. */
    int xIncrement = (WIDTH - 40) / 3;        /* Grid's raster width. */
    int yIncrement = ((HEIGHT - 6) - 40) / 3; /* Grid's raster height. */
    int x = 0;            /* Temporary x positions. */
    int y = 0;            /* Temporary y positions. */
    char outputString[OUTPUT_LENGTH]; /* Holder for output strings in the GUI. */
    static bool visual;   /* Indicator which visual page to draw to
                           * to prevent flickers. */

    /* Initalising the variables. */
    strncpy(outputString, "", OUTPUT_LENGTH);
    /* Even though this is not necessary here the protected version of "strcpy"
       is used in this case. It should ALWAYS be used to prevent boundary
       overwrites! */

    /* Initialising the GUI. */
    setactivepage(visual);
    setbkcolor(BLACK);
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    /* Display different coloured squares for different numbers. */
    y = 10;
    for(int i = 0; i < 3; i++) {
        x = 10;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 0) {
                setcolor(board[i][j]);
                bar(x, y, x + xIncrement, y + yIncrement);
            }
            x += 10;
            x += xIncrement;
        }
        y += 10;
        y += yIncrement;
    }

    /* Display the actual numbers. */
    y = 8 * HEIGHT / 40;
    for(int i = 0; i < 3; i++) {
        x = WIDTH / 6;
        for(int j = 0; j < 3; j++) {
            setcolor(WHITE);
            setbkcolor(board[i][j]);
            if(board[i][j] != 0) {
                snprintf(outputString, OUTPUT_LENGTH, "%d", board[i][j]);
                /* Even though this is also not necessary here the protected
                   version of "sprintf" is used in this case. It should ALWAYS
                   be used to prevent boundary overwrites! */
//                outtextxy(x, y, (char *)elements[i+j*3]);   
                outtextxy(x, y, outputString);
                moveto(0, 0);
            }
            x += 2 * (WIDTH / 6);
        }
        y += 13 * HEIGHT / 40;
    }

    /* Set the page to display. */
    setvisualpage(visual);
    visual = !visual;

    delay(1000);
}



void AnimateSolution(string const initialState, string const goalState, string path){

	int step=1;
	
	cout << endl << "--------------------------------------------------------------------" << endl;

	if (path==""){
		 cout << endl << "Nothing to animate." << endl;
	} else {
	    cout << endl << "Animating solution..." << endl;
	    cout << "Solution path = " << path << endl;
	}
	
	Puzzle *p = new Puzzle(initialState, goalState);
	string strState;
		
	strState = p->toString();
   displayBoard(strState);
	
	cout << "--------------------------------------------------------------------" << endl;
	      
	for(int i=0; i < path.length(); i++){
		
		cout << endl << "Step #" << step << ")  ";
		switch(path[i]){
			
			case 'U': p = p->moveUp(); cout << "[UP]" << endl;
			          break;
			case 'D': p = p->moveDown(); cout << "[DOWN]" << endl;
			          break;
			case 'L': p = p->moveLeft(); cout << "[LEFT]" << endl;
			          break;
         case 'R': p = p->moveRight(); cout << "[RIGHT]" << endl;
			          break;
 		}
 		strState = p->toString();
      displayBoard(strState);
      
      step++;
	}
	
	delete p;	
	cout << endl << "Animation done." << endl;
	cout << "--------------------------------------------------------------------" << endl;
	
	//getch();
}


int main(void) {


   string initialState, goalState, path;
	int depth;
	int numOfStateExpansions=0;
	int maxdepth=30;
	 
	initialState =  "481302675";// "168342750"; //"042158367" 481302675; 876543210 123804765
	goalState = "012345678"; 
   depth=500; 
	clock_t tmr1, tmr2, tmr;

   char answer = 'N';
   
   do{
	   cout << endl << endl << endl << "Search Algorithms" << endl;
	   cout << "--------------------------" << endl;
	   cout << "(1) Progressive Deepening Search (with Visited List)" << endl << "(2) BFS (with Visited List)" << endl << "(3) Uniform Cost Search with the Strict Expanded List" << endl << "(4) A Star (without the Expanded List, Heuristic = Number of Misplaced Tiles)" << endl << "(5) A Star (without the Expanded List, Heuristic = Sum of Manhattan Distance)" << endl << "(6) A Star (with the Strict Expanded List, Heuristic = Number of Misplaced Tiles)" << endl << "(7) A Star (with the Strict Expanded List, Heuristic = Sum of Manhattan Distance)"  << endl << "(I) Initial State" << endl << "(G) Goal State" << endl << "(Q) Quit" << endl<< "(M) Maxdepth" << endl;  
      cout << "Current Initial state = " << initialState << endl;
      cout << "Current Goal state = " << goalState << endl << endl;
		cout << "Current maxdepth = " << maxdepth << endl << endl;
	   cout << "Type selection: " << endl;
	   cin >> answer;
	   
	   if(answer == 'Q') break;
	   
	   int n;
		string test;
	   
	   switch(answer){
		   case 'I':  cout << "Initial state = " << initialState << endl;
               	  cout << "Goal state = " << goalState << endl;
               	  
               	  cout << "Enter new initial state: " << endl;
               	  cin >> initialState;
		              break; 
		   case 'G':  cout << "Initial state = " << initialState << endl;
               	  cout << "Goal state = " << goalState << endl;
               	  
               	  cout << "Enter new goal state: " << endl;
               	  cin >> goalState;
		              break; 
			case 'M':  cout << "Maxdpeth = " << maxdepth << endl;
               	  cout << "Enter new maxdpeth: " << endl;
               	  cin >> maxdepth;
		              break; 
           		   
			case '1':  cout << "Progressive Deepening Search (using the Visited List)" << endl;
							tmr1 = clock();
						   path = progressiveDeepeningSearch(initialState, goalState, n,maxdepth);	
							tmr2 = clock();
                     PrintTimer(tmr1, tmr2);
						   break;
                    
			case '2':  
                 	  cout << "Breadth-First Search" << endl << endl;
                     tmr1 = clock();						  
			            path = BreadthFirstSearch(initialState,goalState,n, maxdepth);
							tmr2 = clock();
                     PrintTimer(tmr1, tmr2);
							break;
			case '3':  
                 	  cout << "Uniform Cost Search using the Expanded List" << endl << endl;
						  tmr1 = clock();		
						  path = UCS(initialState, goalState, n,maxdepth);
						  tmr2 = clock();
						  PrintTimer(tmr1, tmr2);
		              break;
			case '4':  
                 	  cout << "A* Search without the Expanded List, Heuristic = Number of Misplaced Tiles" << endl << endl;
						  tmr1 = clock();		
			           path = A4(initialState, goalState, n,maxdepth); 
						  tmr2 = clock();
						  PrintTimer(tmr1, tmr2);			
		              break;
			case '5':  
                 	  cout << "A* Search without the Expanded List, Heuristic = Sum of Manhattan Distance" << endl << endl;
						  tmr1 = clock();		
						  path = A6(initialState, goalState, n,maxdepth);  
						  tmr2 = clock();
                    PrintTimer(tmr1, tmr2);
						  break;
			case '6':  
                 	  cout << "A* Search with the Strict Expanded List, Heuristic = Number of Misplaced Tiles" << endl << endl;
						  tmr1 = clock();					
			           path = A5(initialState, goalState, n,maxdepth); 
						  tmr2 = clock();
                    PrintTimer(tmr1, tmr2);
		              break;
         case '7':  
                 	  cout << "A* Search with the Strict Expanded List, Heuristic = Sum of Manhattan Distance" << endl << endl;
						  tmr1 = clock();					
			           path = A7(initialState, goalState, n,maxdepth);  
						  tmr2 = clock();
                    PrintTimer(tmr1, tmr2);
		              break;											
			
			
		}
		
	   if(path != "") {
		    AnimateSolution(initialState, goalState, path);
		}
		answer = 'N';
		path.clear();
	   
	} while(1);
   cout << "Done." << endl;
	   
    /* Show that we have exited without an error. */
    return 0;
}

void PrintTimer(clock_t tmrStart, clock_t tmrEnd){
    clock_t total = tmrEnd - tmrStart;
    if (total < 1000){ cout << "The total time consuming is: " << total << "ms" << endl; }
    else { total = total / CLOCKS_PER_SEC; cout << "The total time consuing is: " << total << "s" << endl;}
}

