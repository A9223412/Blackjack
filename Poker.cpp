#include"Poker.h"
Poker::Poker()
{

    poker[0] = 0;
    for (int i = 1; i <= 13; i++)   
    {                       
        poker[i] = i;          
        poker[i + 13] = i;      
        poker[i + 26] = i;   
        poker[i + 39] = i; 
    }

    pokerValue[0] = 0;
    for (int i = 1; i <= 52; i++)
    {
        if (poker[i] <= 10)  pokerValue[i] = poker[i];
        else              pokerValue[i] = 10;
    }


    pokerName[0] = "";
    for (int i = 0; i < 4; i++)
    {
        pokerName[1 + 13 * i] = "A";
        pokerName[2 + 13 * i] = "2";
        pokerName[3 + 13 * i] = "3";
        pokerName[4 + 13 * i] = "4";
        pokerName[5 + 13 * i] = "5";
        pokerName[6 + 13 * i] = "6";
        pokerName[7 + 13 * i] = "7";
        pokerName[8 + 13 * i] = "8";
        pokerName[9 + 13 * i] = "9";
        pokerName[10 + 13 * i] = "10";
        pokerName[11 + 13 * i] = "J";
        pokerName[12 + 13 * i] = "Q";
        pokerName[13 + 13 * i] = "K";
    }

    money = 200;
    bet = 0;

    for (int i = 0; i < 5;i++)
    {
        pokerF[i] = 0;
        pokerL[i] = 0;
    }


    pokerNumF = 0;
    pokerNumL = 0;

    srand((int)time(0));
    for (int i = 0; i < 1000; i++)
    {
        randNum[i] = rand() * 51 / 32767 + 1;
    }

}
void Poker::initPoker()
{
    cout << "新一局遊戲開始，開始洗牌>>>>>" << endl;

    pokerF[0] = randNum[j++];
    pokerF[1] = randNum[j++];
    pokerL[0] = randNum[j++];
    pokerL[1] = randNum[j++];

    pokerNumF = 2;
    pokerNumL = 2;

    cout << "洗牌完成,你的牌為:" << getPokerF() << endl;
}

string Poker::getPokerF()
{
    int i;
    string result = "";

    for (i = 0; i < pokerNumF; i++)
        result = result + pokerName[pokerF[i]] + " ";

    return result;
}

string Poker::getPokerL()
{
    int i;
    string result = "";

    for (i = 0; i < pokerNumL; i++)
        result = result + pokerName[pokerL[i]] + " ";

    return result;
}

int Poker::getSumF()
{
    int result = 0;

    for (int i = 0; i < pokerNumF; i++)
        result = result + pokerValue[pokerF[i]];

    return result;
}

int Poker::getSumL()
{

    int result = 0;

    for (int i = 0; i < pokerNumL; i++)
        result = result + pokerValue[pokerL[i]];

    return result;
}

void Poker::farmerAsk()
{
    if (pokerNumF >= 5)
    {
        cout << "你的牌數已夠5張，不能再要牌了" << endl;
        landlordProcess();
    }
    else
    {
        pokerF[pokerNumF++] = randNum[j++];
        cout << "你的牌為:" << getPokerF() << endl;
        if (getSumF() > 21)
        {
            cout << "你爆了,你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經輸光了，哈哈" << endl;
                cout << "遊戲結束" << endl;
                exit(0);
            }
            inputBet();
            initPoker();
        }
        else if (getSumF() == 21)
        {
            landlordProcess();
        }
    }
}

void Poker::landlordAsk()
{
    if (pokerNumL >= 5)
    {
        if (getSumF() > getSumL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initPoker();
        }
        else if (getSumF() == getSumL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "平手" << endl;
            inputBet();
            initPoker();
        }
        else if (getSumF() < getSumL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經輸光了" << endl;
                cout << "遊戲結束" << endl;
                exit(0);
            }
            inputBet();
            initPoker();
        }
    }
    else
    {
        pokerL[pokerNumL++] = randNum[j++];
        if (getSumL() > 21)
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "莊家爆了,你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initPoker();
        }
        else    landlordProcess();
    }
}
void Poker::inputBet()
{
    cout << "你現在有" << money << "元,請輸入賭注:";
    do
    {
        cin >> bet;
        if (bet > money)
            cout << "你沒那麼多錢，重新輸入吧:";
    } while (bet > money);

}

void Poker::newGame()
{
    inputBet();
    initPoker();
    cout << "你得到的牌為:" << getPokerF() << endl;
}

void Poker::landlordProcess()
{
    if (getSumL() >= 17)
    {
        if (getSumL() > getSumF())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "莊家獲勝，你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經輸光了" << endl;
                cout << "遊戲結束" << endl;
                exit(0);
            }
            inputBet();
            initPoker();
        }
        else if (getSumF() == getSumL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "本次遊戲平手" << endl;
            inputBet();
            initPoker();
        }
        else
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initPoker();
        }
    }
    else
    {
        landlordAsk();
    }
}
