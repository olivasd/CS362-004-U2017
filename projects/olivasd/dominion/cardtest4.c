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

#define TESTCARD "Village"

void testFail(){
    printf("\ntest failure\n");
}

int main() {

    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;
    int newActions = 0;

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

   // callVillage(&testG, currentPlayer, handPos);
    cardEffect(village, 0, 0, 0, &testG, handPos, 0);

    newCards = 1;

    printf("hand count = %d, expected = %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - newCards + shuffledCards);

    if(testG.handCount[currentPlayer] != G.handCount[currentPlayer] + newCards - discarded)
        testFail();
    if(testG.deckCount[currentPlayer] != G.deckCount[currentPlayer] - newCards + shuffledCards)
        testFail();

    newActions = 2;

    printf("number of actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions);

    if(testG.numActions != G.numActions + newActions)
        testFail();

    printf("\n >>>>> Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}