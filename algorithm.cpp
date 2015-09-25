

#include "algorithm.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Depth First Search
//
////////////////////////////////////////////////////////////////////////////////////////////
struct Node{
	string visit;
	Node *next;
};

void AddNode(Node *&listpointer,string a){
	Node *temp;
	temp=new Node;
	temp->visit=a;
	temp->next=listpointer;
	listpointer=temp;
}

bool Search(Node*listpointer,string a){
	Node *current;
	current = listpointer;
	while(true){
		if(current==NULL){break;}
		if(current->visit==a){
			return true;
		}
		current=current->next;
	}
	return false;
}


Node *A,*B;

string depthFirstSearch(string const initialState, string const goalState, int &numberOfStateExpansions){
	string path;
	int i=0;
	string strState;
	stack<Puzzle *> Q;
	Puzzle *state;
	Puzzle *nextState;
	state = new Puzzle(initialState, goalState);
	strState=state->toString();
	AddNode(A,strState);
	while(true){
			i++;	//UDLR

		if(state->canMoveDown()){
			nextState = state->moveDown();
			if(Search(A,nextState->toString())==false){
			Q.push(nextState);
			AddNode(A,nextState->toString());
			}
		 }
		if(state->canMoveRight()){
			nextState = state->moveRight();
			if(Search(A,nextState->toString())==false){
			Q.push(nextState);
			AddNode(A,nextState->toString());
			}
		 }
		if(state->canMoveUp()){
			nextState = state->moveUp();
			if(Search(A,nextState->toString())==false){
			Q.push(nextState);
			AddNode(A,nextState->toString());
			}
		 }
		if(state->canMoveLeft()){
			nextState = state->moveLeft();
			if(Search(A,nextState->toString())==false){
			Q.push(nextState);
			AddNode(A,nextState->toString());
			}
		 }
		 state=Q.top();
	    Q.pop();
		 if(state->goalMatch()){
	    break;
	    }
   }
	path=state->getPath();
	return path;
}



////////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Progressive Deepening Search
//
////////////////////////////////////////////////////////////////////////////////////////////

string progressiveDeepeningSearch(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth){
	string path;
	int i=0;
	int c=0;
	int len;
	string strState;
	stack<Puzzle *> Q;
	Puzzle *state;
	Puzzle *nextState;
	state = new Puzzle(initialState, goalState);
	strState=state->toString();
	AddNode(A,strState);
	while(i<500000){
		   i++;	//RLDU   
			if(state->canMoveRight()){
				nextState = state->moveRight();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveLeft()){
				nextState = state->moveLeft();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveDown()){
				nextState = state->moveDown();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveUp()){
				nextState = state->moveUp();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				AddNode(A,nextState->toString());
				}
			 }

		if(Q.empty()){
			 cout<<"no solution"<<endl;
			 break;
		}
	 	 state=Q.top();
	    Q.pop();
		if(state->goalMatch()){
			 len=state->getPathLength();
			 cout<<"have solution and length is : "<<len<<endl;
			 break;
	   }
   }
	path=state->getPath();
	return path;
}

string BreadthFirstSearch(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth){
	string path;
	int i=0;
	int c=0;
	int len;
	string strState;
	queue<Puzzle *> Q;	//queue
	Puzzle *state;
	Puzzle *nextState;
	state = new Puzzle(initialState, goalState);
	strState=state->toString();
	AddNode(A,strState);
	while(i<500000){
		   i++;	//UDLR
			if(state->canMoveUp()){
				nextState = state->moveUp();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveDown()){
				nextState = state->moveDown();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveLeft()){
				nextState = state->moveLeft();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveRight()){
				nextState = state->moveRight();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				AddNode(A,nextState->toString());
				}
			 }
		if(Q.empty()){
			 cout<<"no solution"<<endl;
			 break;
		}
	 	 state=Q.front();
	    Q.pop();
		if(state->goalMatch()){
			 len=state->getPathLength();
			 cout<<"have solution and length is : "<<len<<endl;
			 break;
	   }
   }
	path=state->getPath();
	return path;
}


string UCS(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth){
	string path;
	int i=0;
	int c=0;
	int len;
	string strState;
	queue<Puzzle *> Q;	//queue
	queue<Puzzle *> Q2;
	Puzzle *state;
	Puzzle *nextState;
	state = new Puzzle(initialState, goalState);
	strState=state->toString();
	AddNode(A,strState);//Expanded List
	while(i<500000){
		   i++;	//UDLR
			if(state->canMoveUp()){
				nextState = state->moveUp();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveDown()){
				nextState = state->moveDown();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveLeft()){
				nextState = state->moveLeft();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveRight()){
				nextState = state->moveRight();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
		if(Q.empty()){
			 cout<<"no solution"<<endl;
			 break;
		}
		state=Q.front();
		while(!Q.empty()){
			if(Q.front()->getPathLength()<=state->getPathLength()){
				state=Q.front();
			}
		Q2.push(Q.front());
		Q.pop();
		}
		while(!Q2.empty()){
			if(Q2.front()!=state){
				Q.push(Q2.front());
				Q2.pop();
			}else{
				Q2.pop();
			}
		}
		AddNode(A,state->toString());
	 	 //state=Q.front();
	    //Q.pop();
		if(state->goalMatch()){
			 len=state->getPathLength();
			 cout<<"have solution and length is : "<<len<<endl;
			 break;
	   }
   }
	path=state->getPath();
	return path;
}

string A4(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth){
	//A* Search without the Expanded List, Heuristic = Number of Misplaced Tiles
	string path;
	int i=0;
	int c=0;
	int len;
	string strState;
	queue<Puzzle *> Q;	//queue
	queue<Puzzle *> Q2;
	Puzzle *state;
	Puzzle *nextState;
	state = new Puzzle(initialState, goalState);
	state->updateHCost(misplacedTiles);
	state->updateFCost();
	strState=state->toString();
	//AddNode(A,strState);//Expanded List
	while(i<500000){
		   i++;	//UDLR
			if(state->canMoveUp()){
				nextState = state->moveUp();
				nextState->updateHCost(misplacedTiles);
				nextState->updateFCost();
				if(nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveDown()){
				nextState = state->moveDown();
				nextState->updateHCost(misplacedTiles);
				nextState->updateFCost();
				if(nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveLeft()){
				nextState = state->moveLeft();
				nextState->updateHCost(misplacedTiles);
				nextState->updateFCost();
				if(nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveRight()){
				nextState = state->moveRight();
				nextState->updateHCost(misplacedTiles);
				nextState->updateFCost();
				if(nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
		if(Q.empty()){
			 cout<<"no solution"<<endl;
			 break;
		}
		state=Q.front();
		while(!Q.empty()){
			if(Q.front()->getFCost()<=state->getFCost()){
				state=Q.front();
			}
		Q2.push(Q.front());
		Q.pop();
		}
		while(!Q2.empty()){
			if(Q2.front()!=state){
				Q.push(Q2.front());
				Q2.pop();
			}else{
				Q2.pop();
			}
		}
		//AddNode(A,state->toString());
	 	 //state=Q.front();
	    //Q.pop();
		if(state->goalMatch()){
			 len=state->getPathLength();
			 cout<<"have solution and length is : "<<len<<endl;
			 break;
	   }
   }
	path=state->getPath();
	return path;
}

string A5(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth){
	//A* Search with the Strict Expanded List, Heuristic = Number of Misplaced Tiles
	string path;
	int i=0;
	int c=0;
	int len;
	string strState;
	queue<Puzzle *> Q;	//queue
	queue<Puzzle *> Q2;
	Puzzle *state;
	Puzzle *nextState;
	state = new Puzzle(initialState, goalState);
	state->updateHCost(misplacedTiles);
	state->updateFCost();
	strState=state->toString();
	AddNode(A,strState);//Expanded List
	while(i<500000){
		   i++;	//UDLR
			if(state->canMoveUp()){
				nextState = state->moveUp();
				nextState->updateHCost(misplacedTiles);
				nextState->updateFCost();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveDown()){
				nextState = state->moveDown();
				nextState->updateHCost(misplacedTiles);
				nextState->updateFCost();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveLeft()){
				nextState = state->moveLeft();
				nextState->updateHCost(misplacedTiles);
				nextState->updateFCost();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveRight()){
				nextState = state->moveRight();
				nextState->updateHCost(misplacedTiles);
				nextState->updateFCost();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
		if(Q.empty()){
			 cout<<"no solution"<<endl;
			 break;
		}
		state=Q.front();
		while(!Q.empty()){
			if(Q.front()->getFCost()<=state->getFCost()){
				state=Q.front();
			}
		Q2.push(Q.front());
		Q.pop();
		}
		while(!Q2.empty()){
			if(Q2.front()!=state){
				Q.push(Q2.front());
				Q2.pop();
			}else{
				Q2.pop();
			}
		}
		AddNode(A,state->toString());
	 	 //state=Q.front();
	    //Q.pop();
		if(state->goalMatch()){
			 len=state->getPathLength();
			 cout<<"have solution and length is : "<<len<<endl;
			 break;
	   }
   }
	path=state->getPath();
	return path;
}

string A6(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth){
	//A* Search without the Expanded List, Heuristic = Sum of Manhattan Distance
	string path;
	int i=0;
	int c=0;
	int len;
	string strState;
	queue<Puzzle *> Q;	//queue
	queue<Puzzle *> Q2;
	Puzzle *state;
	Puzzle *nextState;
	state = new Puzzle(initialState, goalState);
	state->updateHCost(manhattanDistance);
	state->updateFCost();
	strState=state->toString();
	//AddNode(A,strState);//Expanded List
	while(i<500000){
		   i++;	//UDLR
			if(state->canMoveUp()){
				nextState = state->moveUp();
				nextState->updateHCost(manhattanDistance);
				nextState->updateFCost();
				if(nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveDown()){
				nextState = state->moveDown();
				nextState->updateHCost(manhattanDistance);
				nextState->updateFCost();
				if(nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveLeft()){
				nextState = state->moveLeft();
				nextState->updateHCost(manhattanDistance);
				nextState->updateFCost();
				if(nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveRight()){
				nextState = state->moveRight();
				nextState->updateHCost(manhattanDistance);
				nextState->updateFCost();
				if(nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
		if(Q.empty()){
			 cout<<"no solution"<<endl;
			 break;
		}
		state=Q.front();
		while(!Q.empty()){
			if(Q.front()->getFCost()<=state->getFCost()){
				state=Q.front();
			}
		Q2.push(Q.front());
		Q.pop();
		}
		while(!Q2.empty()){
			if(Q2.front()!=state){
				Q.push(Q2.front());
				Q2.pop();
			}else{
				Q2.pop();
			}
		}
		//AddNode(A,state->toString());
	 	 //state=Q.front();
	    //Q.pop();
		if(state->goalMatch()){
			 len=state->getPathLength();
			 cout<<"have solution and length is : "<<len<<endl;
			 break;
	   }
   }
	path=state->getPath();
	return path;
}

string A7(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth){
	//A* Search with the Strict Expanded List, Heuristic = Sum of Manhattan Distance
	string path;
	int i=0;
	int c=0;
	int len;
	string strState;
	queue<Puzzle *> Q;	//queue
	queue<Puzzle *> Q2;
	Puzzle *state;
	Puzzle *nextState;
	state = new Puzzle(initialState, goalState);
	state->updateHCost(manhattanDistance);
	state->updateFCost();
	strState=state->toString();
	AddNode(A,strState);//Expanded List
	while(i<500000){
		   i++;	//UDLR
			if(state->canMoveUp()){
				nextState = state->moveUp();
				nextState->updateHCost(manhattanDistance);
				nextState->updateFCost();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveDown()){
				nextState = state->moveDown();
				nextState->updateHCost(manhattanDistance);
				nextState->updateFCost();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveLeft()){
				nextState = state->moveLeft();
				nextState->updateHCost(manhattanDistance);
				nextState->updateFCost();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
			if(state->canMoveRight()){
				nextState = state->moveRight();
				nextState->updateHCost(manhattanDistance);
				nextState->updateFCost();
				if(Search(A,nextState->toString())==false&&nextState->getDepth()<=maxDepth){
				Q.push(nextState);
				//AddNode(A,nextState->toString());
				}
			 }
		if(Q.empty()){
			 cout<<"no solution"<<endl;
			 break;
		}
		state=Q.front();
		while(!Q.empty()){
			if(Q.front()->getFCost()<=state->getFCost()){
				state=Q.front();
			}
		Q2.push(Q.front());
		Q.pop();
		}
		while(!Q2.empty()){
			if(Q2.front()!=state){
				Q.push(Q2.front());
				Q2.pop();
			}else{
				Q2.pop();
			}
		}
		AddNode(A,state->toString());
	 	 //state=Q.front();
	    //Q.pop();
		if(state->goalMatch()){
			 len=state->getPathLength();
			 cout<<"have solution and length is : "<<len<<endl;
			 break;
	   }
   }
	path=state->getPath();
	return path;
}