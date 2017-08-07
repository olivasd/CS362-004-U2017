/*
 * Daniel Olivas
 * CS362
 * unittest2.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "isGameOver"

void testFail(){
    printf("\ntest failure\n");
}

int main() {

    int seed = 1000;
    int numPlayers = 2;
    int gameOver;

    struct gameState testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &testG);

    printf("----------------- Testing: %s ----------------\n", TESTCARD);

    testG.supplyCount[province] = 0;
    printf("check 1: province cards = 0\n");
    gameOver = isGameOver(&testG);

    if(gameOver != 1)
        testFail();
    else printf("\ntest successful\n");

    testG.supplyCount[estate] = 0;
    testG.supplyCount[duchy] = 0;
    testG.supplyCount[copper] = 0;
    printf("check 2: 3 card piles = 0\n");

    gameOver = isGameOver(&testG);

    if(gameOver != 1)
        testFail();
    else printf("\ntest successful\n");

    printf("\n >>>>> Testing complete: %s <<<<<\n\n", TESTCARD);

    return 0;
}