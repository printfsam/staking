// staking.h

#define STAKERS_AMT 8
#define BLOCKS_PER_EPOCH 30


void buildStake(int randStr);
int compare(const void *vp,const void *vq);


typedef struct stakers{
		char pub_key[3];
		int balance;
		int node_num;
	} stakerAccount;