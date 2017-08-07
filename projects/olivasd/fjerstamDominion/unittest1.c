/*
 * Daniel Olivas
 * CS362
 * unittest1.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "endTurn"

void testFail(){
    printf("\ntest failure\n");
}

int main() {

    int currentPlayer = 0;
    int seed = 1000;
    int numPlayers = 2;
    int handCards = 5;

    struct gameState testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &testG);

    printf("----------------- Testing: %s ----------------\n", TESTCARD);

    endTurn(&testG);

    printf("Check 1: all cards in hand discarded");
    if(testG.handCount[currentPlayer] == 0 && testG.discardCount[currentPlayer] == handCards)
        printf("\ntest successful\n");
    else testFail();

    printf("check 2: next player turn");
    if(testG.whoseTurn == 1)
        printf("\ntest successful\n");
    else testFail();

    printf("check 3: next player draws 5 cards");
    if(testG.handCount[currentPlayer + 1] == 5)
        printf("\ntest successful\n");
    else testFail();


    printf("\n >>>>> Testing complete: %s <<<<<\n\n", TESTCARD);

    return 0;
}