#include <iostream>
#include <ctime>
#include <vector>
#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

using namespace std;

int main()
{
    // Start Blockchain
    Blockchain awesomeCoin;
    
    // Data for the first block
    time_t data1Time;
    TransactionData data1(1.5, "Rahul", "Yusra", time(&data1Time));
    awesomeCoin.addBlock(data1);
    
    time_t data2Time;
    TransactionData data2(0.2233, "Divya", "Arpit", time(&data2Time));
    awesomeCoin.addBlock(data2);
    
    // Prints the awesomeCoin blockchain
    awesomeCoin.printChain();
    
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    
    // Someone's getting sneaky
    Block *hackBlock = awesomeCoin.getLatestBlock();
    hackBlock->data.amount = 10000; // 
    hackBlock->data.receiverKey = "Jon";
 
    awesomeCoin.printChain();

    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    
    return 0;
}
