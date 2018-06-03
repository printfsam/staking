/**

	Description: Create a staking example based off of instructions in /staking.py
		Complete the script to select a proposer for each block in this epoch based on the current stakers.
		In a consensus protocol each block needs 1 or more proposers.  In this case its just 1 proposer per block.
		The result should be a list of pub_keys for each block in this epoch.
		Feel free to use any language so long as the code is simple, readable and maintainable.
		Try to follow the comments outlined here in your solution unless you find a more efficient way to solve it.
		The only real constraint is that the variables & data created above should have the same structure.
		The solution should be available on your GitHub. Please email the repo address to tigran@c4coin.org
	@date 05/31/2018
	@author Sam Cesario
*/

#include <stdio.h>
#include <stdlib.h>
#include "staking.h"
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){
	if((argv[1] == NULL) || (strcmp(argv[1],"-h") == 0)){
		printf("-t for running tests\n");
		printf("-h for running help\n");
		printf("-i (int) for adding randomness to picker\n");
	}
	else if(strcmp(argv[1],"-t") == 0){
		// dummy var for test Val
		int testVal = 101010;
		int *i = &testVal;
		buildStake(testVal,true);
		
	}
	else if(strcmp(argv[1],"-i") == 0){
		if(argv[2] == NULL){
			printf("Please Provide an integer val as second argument\n");
		}
		else{
			int i = atoi(argv[2]);
			buildStake(i,false);
		}
	}
	else{
		printf("-t for running tests\n");
		printf("-h for running help\n");
		printf("-i (int) for adding randomness to picker\n");
	}
	return 0;
}
/**
 * @brief Method to build and compute stake
 * @param randStr a Random String inputted from the user
 * @param test true if in test mode
 */
void buildStake(int randStr, bool test){
	
	struct stakers stakers_in_epoch[STAKERS_AMT];

	strcpy(stakers_in_epoch[0].pub_key,"acc2");
	stakers_in_epoch[0].balance = 6;

	strcpy(stakers_in_epoch[1].pub_key,"acc5");
	stakers_in_epoch[1].balance = 10;

	strcpy(stakers_in_epoch[2].pub_key,"acc1");
	stakers_in_epoch[2].balance = 15;

	strcpy(stakers_in_epoch[3].pub_key,"acc3");
	stakers_in_epoch[3].balance = 14;

	strcpy(stakers_in_epoch[4].pub_key,"acc0");
	stakers_in_epoch[4].balance = 15;

	strcpy(stakers_in_epoch[5].pub_key,"acc7");
	stakers_in_epoch[5].balance = 5;

	strcpy(stakers_in_epoch[6].pub_key,"acc6");
	stakers_in_epoch[6].balance = 3;

	strcpy(stakers_in_epoch[7].pub_key,"acc4");
	stakers_in_epoch[7].balance = 27;

	// Step 1
	qsort(stakers_in_epoch,(STAKERS_AMT),sizeof(stakerAccount),compare);

	// Step 2 
	int coins_staked = 0;
	int j;
	for(j=0; j<STAKERS_AMT; ++j){
		coins_staked += stakers_in_epoch[j].balance;
	}
	// Compute total number of coins that are being staked for this epoch (ie total stake per epoch)
	printf("Total Coins: %i \n",coins_staked);

	// Step 3
	int coins[BLOCKS_PER_EPOCH];
	if(test){
		int coinsIn[BLOCKS_PER_EPOCH] = {52, 43, 86, 45, 79, 23, 69, 82, 66, 20, 78, 59, 87, 29, 55, 94, 31, 87, 21, 61, 8, 17, 67, 47, 23, 64, 61, 90, 83, 46};
		memcpy(coins,coinsIn,sizeof(coins));
	}
	else{
		srand(randStr + time(NULL));
		int coinsIn[BLOCKS_PER_EPOCH];
		int k;
		for(k=0; k<BLOCKS_PER_EPOCH; ++k){
			int res_coin = rand() % coins_staked;
			coinsIn[k] = res_coin;  
		}
		memcpy(coins,coinsIn,sizeof(coins));
	}
	printCoins(coins);

	// Step 4
	int lowerBounds = 0;
	int upperBounds = 0;
	int n;
	for(n=0; n <STAKERS_AMT; ++n){
		// increment lower bounds from new balance
		lowerBounds = upperBounds;
		upperBounds += stakers_in_epoch[n].balance;	
		stakers_in_epoch[n].lowerBounds = lowerBounds;
		stakers_in_epoch[n].upperBounds = upperBounds;
	}
	int p;
	char proposers[BLOCKS_PER_EPOCH][PUBKEY_INDEX];
	for(p=0; p<BLOCKS_PER_EPOCH; ++p){
		int q = 0;
		for(q=0;q<STAKERS_AMT;++q){
			if((stakers_in_epoch[q].lowerBounds <= coins[p]) && (coins[p] < stakers_in_epoch[q].upperBounds)){
				strcpy(proposers[p],stakers_in_epoch[q].pub_key);
			}
		}
	}
	printProposers(proposers);
	if(test){
		if(testResults(proposers)){
			printf("All Tests Pass\n");
		}
		else{
			printf("Tests Failed\n");
		}
	}
}

/**
 * @brief Standard compare function for qsort
 * @param *vp pointer to element 1
 * @param *vq pointer to element 2
 */
int compare(const void *vp, const void *vq){
	const struct stakers *p = vp;
	const struct stakers *q = vq;

	int difference = (int)(p->pub_key[3] - '0') - (int)(q->pub_key[3] - '0');
	return (difference <= 0 ) ? ((difference < 0) ? -1 : 0) : +1;
	
}
/**
 * @brief Prints to Prospers
 * @param proposers a char[][] of proposers
 * 
 */
void printProposers(char proposers[][PUBKEY_INDEX]){
	int z;
	
	printf("Proposers: ");
	for(z=0; z<BLOCKS_PER_EPOCH; ++z){
		printf("%c%c%c%c ",proposers[z][0],proposers[z][1],proposers[z][2],proposers[z][3]);
	}
	printf("\n");
	
}
/**
 * @brief Prints coins 
 * @param proposers a char[][] of coins
 * 
 */
void printCoins(int coins[BLOCKS_PER_EPOCH]){
	printf("Coins: ");
		int l;
		for(l=0; l<BLOCKS_PER_EPOCH; ++l){
			printf("%i ", coins[l]);
		}
		printf("\n");
}
/**
 * @brief Run with -t, tests the outputs from staker.py
 * @param proposers a char[][] of proposers
 * 
 */
int testResults(char proposers[BLOCKS_PER_EPOCH][PUBKEY_INDEX]){
	int t;
	int retVal = 0;
	char proposersArr[BLOCKS_PER_EPOCH][PUBKEY_INDEX] = {"acc4", "acc3", "acc5", "acc3", "acc5", "acc1", "acc4", "acc5", "acc4", "acc1", "acc5", "acc4", "acc6", "acc1", "acc4", "acc7", "acc2", "acc6", "acc1", "acc4", "acc0", "acc1", "acc4", "acc3", "acc1", "acc4", "acc4", "acc7", "acc5", "acc3"};
	for(t=0;t<BLOCKS_PER_EPOCH;++t){
		if(memcmp(proposers[t],proposersArr[t],4) == 0){
			retVal = 1;
		}
		else{
			return 0;
		}
	}
	return retVal;
}
