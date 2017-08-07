/*
 * Daniel Olivas
 * CS362
 * randomtestcard2.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    int i;
    int good = 0, bad = 0;
    struct gameState *G;

    for (i = 0; i < 2000; i++){
        int numPlayers = (rand() % MAX_PLAYERS) + 1;
        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                     sea_hag, tribute, smithy, council_room};
        int seed = rand() % 1000;
        G = malloc(sizeof(struct gameState));

        initializeGame(numPlayers, k, seed, G);

        int currentPlayer = 0;
        int discard = 1;
        int newCards = 1;
        int newActions = 2;

        G->deckCount[currentPlayer] = rand() % MAX_DECK;
        G->handCount[currentPlayer] = rand() % MAX_HAND;
        G->discardCount[currentPlayer] = rand() % MAX_DECK;

        int actions = G->numActions;
        int hand = G->handCount[currentPlayer];
        int deck = G->deckCount[currentPlayer];

        cardEffect(village, 0, 0, 0, G, 0, 0);

        if ((G->handCount[currentPlayer] == hand + newCards - discard)
            && (G->deckCount[currentPlayer] == deck - newCards)
            && (G->numActions == actions + newActions))
            good++;
        else bad++;

    }

    printf("good %d, bad %d\n", good, bad );

    return 0;
}