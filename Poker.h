#ifndef POKER_H
#define POKER_H

#include<iostream>
#include<string>
#include<time.h>
using namespace std;
                 

class Poker
{
private:
    int randNum[1000];
    int j = 2;
    int poker[53];     
    int pokerValue[53]; 
    string pokerName[53]; 

    int money;   
    int bet;    

    int pokerF[5];  
    int pokerL[5];   
    int pokerNumF;  
    int pokerNumL; 
public:
    Poker();           
    void initPoker(); 
    string getPokerF();  
    string getPokerL(); 
    int getSumF();      
    int getSumL();       
    void farmerAsk();        
    void landlordAsk();  
    void inputBet();        
    void newGame();          
    void landlordProcess();  

};
#endif
