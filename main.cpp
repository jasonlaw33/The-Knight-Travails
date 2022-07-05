/*
** The Knight's Travails
** 
** Created by Jason Law on 18/Nov/2014.
** 
** Problem Description: Find the shortest sequence of moves for a Knight between the starting and ending positions.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "knight.hpp"
		
int main (int argc, char *argv[]) {	
	// if no parameter is entered, print the following.
	if (argc == 1) {
		printf("Usage: moveKnight <starting position> <ending position>\n");
		printf("Example:\n");
		printf("  moveKnight A8 B7\n");
		exit(0);
	}
	// Check and process the parameters.
	else {	
		int i;
		for (i = 1;i <= 2;i++) {
			// Convert to capital letter
			argv[i][0] = toupper(argv[i][0]);
			// check user input
			if (!(argc == 3 && strlen(argv[i]) == 2 && (argv[i][0] <= 72 && argv[i][0] >= 65) && (argv[i][1] <= 56 && argv[i][1] >= 49))) {
				// if input is wrong, remind the user about the usage.
				printf("Invalid input.\n\n");
				printf("Usage: moveKnight <starting position> <ending position>\n");
				printf("Example:\n");
				printf("  moveKnight A8 B7\n");
				exit(0);
			}
		}
		printf("\nInput: %s %s\n", argv[1], argv[2]);
		findShortestMoveSequence (argv[1], argv[2]);
	}
	return 0;
}