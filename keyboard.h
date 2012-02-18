/*
 *  keyboard.h
 *  Typing
 *
 *  Created by Michael Dickens on 8/7/09.
 *
 * Includes the keyboard struct and the fitness function.
 */
 
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "tools.h"

/* Miscellaneous definitions */
#define IS_TRIGRAPH_THREE																		\
	if (sizeof(trigraph)/sizeof(char) != 3) {													\
		printf("The length of trigraph[] is %d, must be 3.", sizeof(trigraph)/sizeof(char));	\
		return -1;																				\
	}																							
	
#define IS_LOC_THREE																			\
	if (sizeof(locs)/sizeof(char) != 3) {														\
		printf("The length of locs[] is %d, must be 3.", sizeof(locs)/sizeof(char));			\
		return -1;																				\
	}																							


/* The shift value for simplePrintKeyboard(). */
#define SIMPLE_SHIFT 0 // 3

/* WARNING: Both k and index are evaluated multiple times.
 */
#define charAt(k, index) ((index) < ksize ? (k)->layout[index] : (k)->shiftedLayout[index])

int initKeyboard(Keyboard *k);
int setLayout(Keyboard *k, char *layout);
int copy(Keyboard *k, Keyboard *original);
int swap(Keyboard *k, int loc1, int loc2);
int swapPair(Keyboard *k, int loc1, int loc2);
int numberOfSameKeys(Keyboard *k, Keyboard *m);
int isEqual(Keyboard *k, Keyboard *m);
int printLayoutOnly(Keyboard *k);
int printLayoutRaw(char layout[]);
int printKeyboard(Keyboard *k);
int printPercentages(Keyboard *k);
int simplePrintKeyboard(Keyboard *k);
int qwertyPositions(Keyboard *k);
int readLayouts(Keyboard pool[], int length);

int isSwappable(char c);
int isLegalSwap(Keyboard *k, int i, int j);
int layoutFromFile(FILE *fp, Keyboard *k);
void shuffleIndices();
void shuffleLayout(Keyboard *kbd);
int loc(Keyboard *k, char c);
int locWithShifted(Keyboard *k, char c);


int calcFitnessDirect(Keyboard *k);
int scoreDigraphDirect(Keyboard *k, char digraph[], int multiplier);
int calcFitness(Keyboard *k);
int scoreDigraph(Keyboard *k, char digraph[], int multiplier, int allLocs[]);


void scoreTrigraph(Keyboard *k, char trigraph[], int multiplier, int allLocs[]);


char shortcutKeys[4];
char seedLayout[KSIZE_MAX]; // Holds every letter and is randomly shuffled. Used to seed the keyboards.
unsigned int seedVal;

int totalCalcFitness;

int64_t calcShortcuts(Keyboard *k);
int64_t calcQWERTY(Keyboard *k);
int64_t calcParentheses(Keyboard *k);
int64_t calcParensGeneric(Keyboard *k, char openChar, char closeChar);

int calcFingerWork(Keyboard *k);
int calcDistance(int loc0, int loc1);
int calcInRoll(int loc0, int loc1);
int calcOutRoll(int loc0, int loc1);
int calcSameHand(int loc0, int loc1);
int calcSameFinger(int loc0, int loc1);
int calcRowChange(int loc0, int loc1);
int calcHomeJump(int loc0, int loc1);
int calcRingJump(int loc0, int loc1);
int calcToCenter(int loc0, int loc1);
int calcToOutside(int loc0, int loc1);
