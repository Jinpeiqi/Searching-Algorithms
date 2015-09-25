#include <set>
#include <stack>
#include <deque>
#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

#include "puzzle.h"


const heuristicFunction HEURISTIC_FUNCTION=manhattanDistance;


//Function prototypes

bool fValueComparison(Puzzle *p1, Puzzle *p2);
string depthFirstSearch(string const initialState, string const goalState, int &numberOfStateExpansions);
string progressiveDeepeningSearch(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth);
string aStarSearch(string const initialState, string const goalState, int maxDepth);
string BreadthFirstSearch(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth);
string BreadthFirstSearch(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth);
string UCS(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth);
string A4(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth);
string A5(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth);
string A6(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth);
string A7(string const initialState, string const goalState, int &numberOfStateExpansions, int maxDepth);
