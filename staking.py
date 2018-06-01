from collections import namedtuple
from random import randint


# An epoch is a sequence of blocks to be proposed by a non-changing (static) list of stakers.
# A staker should be assigned a block fairly based on the amount of coins they have staked.
# Assume there exists 30 blocks per epoch and we want to select a staker to be a proposer for each block.
blocks_per_epoch = 30

# Each staker has a public key address and an associated balance.
StakerAccount = namedtuple('StakerAccount', ['pub_key', 'balance'])
stakers_in_epoch = [
  StakerAccount(pub_key='acc2', balance=6),
  StakerAccount(pub_key='acc5', balance=10),
  StakerAccount(pub_key='acc1', balance=15),
  StakerAccount(pub_key='acc3', balance=14),
  StakerAccount(pub_key='acc0', balance=15),
  StakerAccount(pub_key='acc7', balance=5),
  StakerAccount(pub_key='acc6', balance=3),
  StakerAccount(pub_key='acc4', balance=27)
]

# Complete the script to select a proposer for each block in this epoch based on the current stakers.
# In a consensus protocol each block needs 1 or more proposers.  In this case its just 1 proposer per block.
# The result should be a list of pub_keys for each block in this epoch.
# Feel free to use any language so long as the code is simple, readable and maintainable.
# Try to follow the comments outlined here in your solution unless you find a more efficient way to solve it.
# The only real constraint is that the variables & data created above should have the same structure.
# The solution should be available on your GitHub. Please email the repo address to tigran@c4coin.org

# Step 1 - Sort the list of account balances by the pub key
# We do this so coin 0 to (coin 0 + acc1.balance) are owned by acc1 and so on...
# Basically all the coins are indexed in a sequence from the beginning to the total stake. 


# Step 2 - Compute total number of coins that are being staked for this epoch (ie total stake per epoch)
coins_staked = ?


# Step 3 - Randomly select a coin index from all the of coins being staked. 
# Do this for each block in the epoch so we can assign a proposer.
coins = ?


# Step 4 - For each selected coin per block determine the coin owner.
# These coin owners will be the list of proposers for this block number.
proposers = ?

# Example output
# > print(coins)
# > print(proposers)
# [52, 43, 86, 45, 79, 23, 69, 82, 66, 20, 78, 59, 87, 29, 55, 94, 31, 87, 21, 61, 8, 17, 67, 47, 23, 64, 61, 90, 83, 46]
# ['acc4', 'acc3', 'acc5', 'acc3', 'acc5', 'acc1', 'acc4', 'acc5', 'acc4', 'acc1', 'acc5', 'acc4', 'acc6', 'acc1', 'acc4', 'acc7', 'acc2', 'acc6', 'acc1', 'acc4', 'acc0', 'acc1', 'acc4', 'acc3', 'acc1', 'acc4', 'acc4', 'acc7', 'acc5', 'acc3']
