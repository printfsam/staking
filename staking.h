// staking.h
#include <stdbool.h>
#define STAKERS_AMT 8
#define BLOCKS_PER_EPOCH 30
#define PUBKEY_INDEX 4


void buildStake(int randStr, bool test);
int compare(const void *vp,const void *vq);
void printProposers(char proposers[][PUBKEY_INDEX]);
void printCoins(int coins[BLOCKS_PER_EPOCH]);
int testResults(char proposers[BLOCKS_PER_EPOCH][PUBKEY_INDEX]);

typedef struct stakers{
		char pub_key[3];
		int balance;
		int node_num;
		int lowerBounds;
		int upperBounds;
	} stakerAccount;