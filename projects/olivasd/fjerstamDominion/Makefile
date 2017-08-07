CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
    
cardtest1.out: cardtest1.c dominion.c rngs.c
	gcc -o cardtest1 -g dominion.c rngs.c cardtest1.c $(CFLAGS)
	cardtest1 >> cardtest1.out
	gcov -b -f dominion.c >> cardtest1.out	
	cat dominion.c.gcov >> cardtest1.out
    
cardtest2.out: cardtest2.c dominion.c rngs.c
	gcc -o cardtest2 -g dominion.c rngs.c cardtest2.c $(CFLAGS)
	cardtest2 >> cardtest2.out
	gcov -b -f dominion.c >> cardtest2.out	
	cat dominion.c.gcov >> cardtest2.out 
    
cardtest3.out: cardtest3.c dominion.c rngs.c
	gcc -o cardtest3 -g dominion.c rngs.c cardtest3.c $(CFLAGS)
	cardtest3 >> cardtest3.out
	gcov -b -f dominion.c >> cardtest3.out	
	cat dominion.c.gcov >> cardtest3.out
    
cardtest4.out: cardtest4.c dominion.c rngs.c
	gcc -o cardtest4 -g dominion.c rngs.c cardtest4.c $(CFLAGS)
	cardtest4 >> cardtest4.out
	gcov -b -f dominion.c >> cardtest4.out	
	cat dominion.c.gcov >> cardtest4.out

randomtestcard1.out: randomtestcard1.c dominion.c rngs.c
	gcc -o randomtestcard1 -g dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	gcov -b -f dominion.c >> randomtestcard1.out	
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard1.c dominion.c rngs.c
	gcc -o randomtestcard2 -g dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	gcov -b -f dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	gcc -o randomtestadventurer -g dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out	

all: playdom player testDrawCard testBuyCard badTestDrawCard cardtest1.out cardtest2.out cardtest3.out cardtest4.out randomtestadventurer.out randomtestcard1.out randomtestcard2.out 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard badTestDrawCard testDrawCard.exe cardtest1.out cardtest1 cardtest2.out cardtest2 cardtest3.out cardtest3 cardtest4.out cardtest4 randomtestadventurer.out randomtestadventurer randomtestcard1.out randomtestcard1 randomtestcard2.out randomtestcard2