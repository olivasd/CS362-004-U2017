/*
 * Daniel Olivas
 * CS362
 * unittest3.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "updateCoins"

void testFail(){
    printf("\ntest failure\n");
}

int main() {

    int currentPlayer = 0;
    int bonus = 0;
    int seed = 1000;
    int numPlayers = 2;

    struct gameState testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &testG);

    printf("----------------- Testing: %s ----------------\n", TESTCARD);

    testG.supplyCount[copper] = 3;
    testG.supplyCount[silver] = 3;
    testG.supplyCount[gold] = 3;

    updateCoins(currentPlayer, &testG, bonus);

    printf("check 1: copper = 3, silver = 3, gold = 3\ntotal = 18\n");
    if(testG.coins == 18)
        printf("\ntest successful\n");
    else testFail();

    testG.supplyCount[copper] = 0;
    testG.supplyCount[silver] = 0;
    testG.supplyCount[gold] = 0;

    updateCoins(currentPlayer, &testG, bonus);

    printf("check 2: copper = 0, silver = 0, gold = 0\ntotal = 0\n");
    if(testG.coins == 0)
        printf("\ntest successful\n");
    else testFail();

    bonus = 2;

    printf("check 3: add 2 bonus to 0\ntotal = 2\n");
    if(testG.coins == 2)
        printf("\ntest successful\n");
    else testFail();

    printf("\n >>>>> Testing complete: %s <<<<<\n\n", TESTCARD);

    return 0;
}