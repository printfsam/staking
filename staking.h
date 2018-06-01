// staking.h

#define STAKERS_AMT 8



void buildStake(int* randStr);
struct stakerAccount {
		char* pub_key;
		int balance;
	};