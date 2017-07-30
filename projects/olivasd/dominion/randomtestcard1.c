/*
 * Daniel Olivas
 * CS362
 * randomtestcard1.c
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
    struct gameState *G;
    int hand, deck, good = 0, bad = 0;
    for (i = 0; i < 2000; i++) {
        int numPlayers = (rand() % 4) + 1;
        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                     sea_hag, tribute, smithy, council_room};
        int seed = rand() % 1000;
        //struct gameState G;
        G = malloc(sizeof(struct gameState));

        initializeGame(numPlayers, k, seed, G);

        int currentPlayer = 0;
        int discard = 1;
        int newCards = 3;

        G->deckCount[currentPlayer] = rand() % MAX_DECK;
        G->handCount[currentPlayer] = rand() % MAX_HAND;
        G->discardCount[currentPlayer] = rand() % MAX_DECK;

        hand = G->handCount[currentPlayer];
        deck = G->deckCount[currentPlayer];

        //callSmithy(&G, currentPlayer, handPos);
        cardEffect(smithy, 1, 1, 1, G, 0, 0);

        if ((G->handCount[currentPlayer] == hand + newCards - discard) && (G->deckCount[currentPlayer] == deck - newCards))
            good++;
        else bad++;

        free(G);

    }

    printf("good %d, bad %d\n", good, bad );

    return 0;

}