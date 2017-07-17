/*
 * Daniel Olivas
 * CS362
 * cardtest4.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Adventurer"

void testFail(){
    printf("\ntest failure\n");
}

int main() {

    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;
    int cardDrawn;
    int drawntreasure = 0;
    int z = 0;
    int temphand[MAX_HAND];


    int seed = 1000;
    int numPlayers = 2;
    int currentPlayer = 0;
    int handPos = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    memcpy(&testG, &G, sizeof(struct gameState));

    callAdventurer(&testG, currentPlayer, cardDrawn, drawntreasure, z, temphand);



    printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}