/*

	Description: Create a staking example based off of instructions in /staking.py
		Complete the script to select a proposer for each block in this epoch based on the current stakers.
		In a consensus protocol each block needs 1 or more proposers.  In this case its just 1 proposer per block.
		The result should be a list of pub_keys for each block in this epoch.
		Feel free to use any language so long as the code is simple, readable and maintainable.
		Try to follow the comments outlined here in your solution unless you find a more efficient way to solve it.
		The only real constraint is that the variables & data created above should have the same structure.
		The solution should be available on your GitHub. Please email the repo address to tigran@c4coin.org
	Date Created: 05/31/2018
	Author: Sam Cesario
*/


#include <stdio.h>
#include <stdlib.h>
#include "staking.h"
#include <string.h>
#include <time.h>
int main(int argc, char *argv[]){
	if(argv[1] == NULL){
		// Set Preset Rand for testing
		int testVal = 101010;
		int *i = &testVal;
		buildStake(testVal);
	}
	else{
		int i = atoi(argv[1]);
		buildStake(i);
	}
	return 0;
}

void buildStake(int randStr){
	// An epoch is a sequence of blocks to be proposed by a non-changing (static) list of stakers.
	// A staker should be assigned a block fairly based on the amount of coins they have staked.
	// Assume there exists 30 blocks per epoch and we want to select a staker to be a proposer for each block.
	// Each staker has a public key address and an associated balance.
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


	/* Step 1 - 
		Sort the list of account balances by the pub key
		We do this so coin 0 to (coin 0 + acc1.balance) are owned by acc1 and so on...
		Basically all the coins are indexed in a sequence from the beginning to the total stake. 
	*/
	qsort(stakers_in_epoch,(STAKERS_AMT),sizeof(stakerAccount),compare);
	int coins_staked = 0;
	for(int j; j<STAKERS_AMT; j++){
		
		//printf("Index: %i Num: %c \n",j,stakers_in_epoch[j].pub_key[3]);
		// Step 2
		coins_staked += stakers_in_epoch[j].balance;

	}
	// Compute total number of coins that are being staked for this epoch (ie total stake per epoch)
	printf("Total Coins: %i \n",coins_staked);

	/* Step 3 - 
		Randomly select a coin index from all the of coins being staked. 
		Do this for each block in the epoch so we can assign a proposer.
	*/
	//printf("%i",*randStr);
	srand(randStr + time(NULL));
	int coins[BLOCKS_PER_EPOCH];
	for(int k; k<BLOCKS_PER_EPOCH; k++){
		int res_coin = rand() % 95;
		coins[k] = res_coin;
	}
	printf("Coins: ");
	for(int l; l<BLOCKS_PER_EPOCH; l++){
		printf("%i ", coins[l]);

	}
	printf("\n");
	/* Step 4 - 
		For each selected coin per block determine the coin owner.
		These coin owners will be the list of proposers for this block number.
	*/
		//proposers = ?
	for(int m; m <BLOCKS_PER_EPOCH; m++){

	}

}
// Standard compare function for qsort
int compare(const void *vp, const void *vq){
	const struct stakers *p = vp;
	const struct stakers *q = vq;

	int difference = (int)(p->pub_key[3] - '0') - (int)(q->pub_key[3] - '0');
	//printf("Diff: %i , q:%i \n",difference,(int)(q->pub_key[3] - '0'));
	return (difference <= 0 ) ? ((difference < 0) ? -1 : 0) : +1;
	
}

/*

# Example output
# > print(coins)
# > print(proposers)
# [52, 43, 86, 45, 79, 23, 69, 82, 66, 20, 78, 59, 87, 29, 55, 94, 31, 87, 21, 61, 8, 17, 67, 47, 23, 64, 61, 90, 83, 46]
# ['acc4', 'acc3', 'acc5', 'acc3', 'acc5', 'acc1', 'acc4', 'acc5', 'acc4', 'acc1', 'acc5', 'acc4', 'acc6', 'acc1', 'acc4', 'acc7', 'acc2', 'acc6', 'acc1', 'acc4', 'acc0', 'acc1', 'acc4', 'acc3', 'acc1', 'acc4', 'acc4', 'acc7', 'acc5', 'acc3']
*/