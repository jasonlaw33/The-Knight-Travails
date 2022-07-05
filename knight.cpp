/*
** The Knight's Travails
** 
** Created by Jason Law on 18/Nov/2014.
** 
** Problem Description: Find the shortest sequence of moves for a Knight between the starting and ending positions.
*/

#include <stdio.h>
#include <vector>
using namespace std;

class KnightMove
{
	public:
		int x, y; 
};

void findShortestMoveSequence (char* sp, char* ep) {	
	KnightMove start;
	start.x = sp[0];
	start.y = sp[1];
	
	KnightMove end;
	end.x = ep[0];
	end.y = ep[1];
	
	int currentIndex = 0, numOfNewMoves = 1, numOfResult = 0, numOfTimeMoved = 0;
	bool shortestPathNotFound = true;
	vector<KnightMove> moveArray (1, start); // dynamic array for storing all the position(s) of the knight
	
	while (shortestPathNotFound) {
		// check whether the ending position is reached
		int i;
		for (i = currentIndex;i < currentIndex + numOfNewMoves;i++) {
			// if it is reached, proceed to output
			if (moveArray[i].x == end.x && moveArray[i].y == end.y) {
				shortestPathNotFound = false;
				
				// determine the output array size based on the no. of times moved  
				KnightMove output [numOfTimeMoved];
				
				// extract the shortest moves sequence from moveArray to output array
				int j;
				int tempNumOfTimeMoved = numOfTimeMoved, tempArraySize = moveArray.size(), moveIndex = i;
				for (j = numOfTimeMoved - 1;j >= 0;j--) {
					// copy the ending position to output array
					if (j == numOfTimeMoved - 1) {
						output[j] = moveArray[i];
					}
					// copy the rest of the move position to output array
					else {
						// track the last move position
						tempNumOfTimeMoved--;
						int k, m = 1;
						for (k = 0;k < tempNumOfTimeMoved;k++) {
							m = m*8;
						}
						tempArraySize = tempArraySize - (m*8);
						int l, lastIndex = tempArraySize;
						for (l = lastIndex - m;l < lastIndex;l++) {
							lastIndex = lastIndex + 8;
							if (moveIndex < lastIndex) {
								output[j] = moveArray[l];
								moveIndex = l;
								break;
							}
						}
					}
				}
				// print the result and alternatives(if any)
				if (numOfResult == 0) {
					printf("Output shortest sequence of moves: ");	
				}
				else if (numOfResult >= 1) {
					printf("Alternative sequence(%d):           ", numOfResult);
				}
				for (j = 0;j < numOfTimeMoved;j++) {
					printf("%c%c ", output[j].x, output[j].y);
				}
				printf("\n");
				numOfResult++;
			}
		}	
		// break the loop if shortest path is found.
		if (shortestPathNotFound == false) {
			break;
		}										
		// if shortest path still isn't found, continue the moves
		int k;
		int direction;
		KnightMove move;
		for (k = 0;k < numOfNewMoves*8;k++) {			
			// there are total 8 possible move direction
			direction = k%8;		
			switch (direction) {
				case 0: 
					move.x = moveArray[currentIndex].x-1;
					move.y = moveArray[currentIndex].y+2;						
					break;
					
				case 1:
					move.x = moveArray[currentIndex].x-2;
					move.y = moveArray[currentIndex].y+1;					
					break;
					
				case 2:
					move.x = moveArray[currentIndex].x-2;
					move.y = moveArray[currentIndex].y-1;						
					break;
					
				case 3:
					move.x = moveArray[currentIndex].x-1;
					move.y = moveArray[currentIndex].y-2;						
					break;
					
				case 4:
					move.x = moveArray[currentIndex].x+1;
					move.y = moveArray[currentIndex].y+2;					
					break;
					
				case 5:
					move.x = moveArray[currentIndex].x+2;
					move.y = moveArray[currentIndex].y+1;					
					break;
					
				case 6:
					move.x = moveArray[currentIndex].x+2;
					move.y = moveArray[currentIndex].y-1;					
					break;
					
				case 7:
					move.x = moveArray[currentIndex].x+1;
					move.y = moveArray[currentIndex].y-2;
					currentIndex++;
					break;
			} // end of switch
			// set the move to 0 if it is not within the boundaries
			if (!((move.x >= 65 && move.x <= 72) && (move.y >= 49 && move.y <= 56))) {
				move.x = 0;
				move.y = 0;
			}
			moveArray.push_back(move); // store the moves to the moveArray
		} // end of for loop
		numOfNewMoves = numOfNewMoves*8;
		numOfTimeMoved++;
	} // end of while loop
}