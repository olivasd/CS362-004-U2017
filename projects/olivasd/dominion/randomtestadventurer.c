/*
 * Daniel Olivas
 * CS362
 * randomtestadventurer.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

    int i, j;
    int good = 0, bad = 0;
    struct gameState *G;
    for (i = 0; i < 2000; i++) {
        int numPlayers = (rand() % 4) + 1;
        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                     sea_hag, tribute, smithy, council_room};
        int seed = rand() % 1000;
        G = malloc(sizeof(struct gameState));

        initializeGame(numPlayers, k, seed, G);

        int currentPlayer = 0;
        int treasureCards = 0;
        G->deckCount[currentPlayer] = rand() % MAX_DECK;
        G->handCount[currentPlayer] = rand() % MAX_HAND;
        G->discardCount[currentPlayer] = rand() % MAX_DECK;

        for (j = 0; j < G->handCount[currentPlayer]; j++) {
            if (G->hand[currentPlayer][j] == gold || G->hand[currentPlayer][j] == silver || G->hand[currentPlayer][j] == copper)
                treasureCards++;
        }

        cardEffect(adventurer, 0, 0, 0, G, 0, 0);

        for (j = 0; j < G->handCount[currentPlayer]; j++) {
            if (G->hand[currentPlayer][j] == gold || G->hand[currentPlayer][j] == silver || G->hand[currentPlayer][j] == copper)
                treasureCards--;
        }

        if (treasureCards == -2)
            good++;
        else bad++;

        free(G);
    }

    printf("good %d, bad %d\n", good, bad );

    return 0;
}