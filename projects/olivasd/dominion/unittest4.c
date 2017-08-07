/*
 * Daniel Olivas
 * CS362
 * unittest4.c
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

    int count = 0;
    int currentPlayer = 0;
    int seed = 1000;
    int numPlayers = 2;

    struct gameState testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(numPlayers, k, seed, &testG);

    printf("----------------- Testing: %s ----------------\n", TESTCARD);

    testG.supplyCount[estate] = 3;
    printf("\ncheck 1: estate = 3\n");
    count = fullDeckCount(currentPlayer, estate, &testG);

    if(count == 3)
        printf("test successful\n");
    else testFail();

    testG.supplyCount[gold] = 3;
    printf("\ncheck 2: gold = 3\n");
    count = fullDeckCount(currentPlayer, gold, &testG);

    if(count == 3)
        printf("test successful\n");
    else testFail();

    testG.supplyCount[curse] = 3;
    printf("\ncheck 3: curse = 3\n");
    count = fullDeckCount(currentPlayer, curse, &testG);

    if(count == 3)
        printf("test successful\n");
    else testFail();

    testG.supplyCount[duchy] = 3;
    printf("\ncheck 4: duchy = 3\n");
    count = fullDeckCount(currentPlayer, duchy, &testG);

    if(count == 3)
        printf("test successful\n");
    else testFail();

    testG.supplyCount[province] = 3;
    printf("\ncheck 5: province = 3\n");
    count = fullDeckCount(currentPlayer, province, &testG);

    if(count == 3)
        printf("test successful\n");
    else testFail();

    printf("\n >>>>> Testing complete: %s <<<<<\n\n", TESTCARD);

    return 0;
}