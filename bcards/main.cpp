/*
 0 goose
 1 loon
 2 mallard
 3 murganza
 4 goose top
 5 loon top
 6 mallard top
 7 murganza top
 clockwise
 */
#include <iostream>
using namespace std;

unsigned int bcards[9][4] =
{
    {6,3,1,5},
    {3,1,6,4},
    {6,5,7,0},
    {0,2,3,5},
    {0,4,7,1},
    {2,7,2,0},
    {4,3,6,1},
    {5,4,7,3},
    {4,3,5,6}
};

struct cardset
{
    unsigned int bcard[9]; // which of the 9 cards
    unsigned int bface[9]; // which of the 4 directions it can be turned
};

bool bcardopposite(unsigned int card1, unsigned int card2)
{
    bool retval = (card2 > card1) ?  (card2-card1 == 4) : (card1-card2 == 4);
    return retval;
}

bool testcards(struct cardset thecardset)
{
    bool bfail = false;
    if ( !bcardopposite(bcards[thecardset.bcard[0]][(1+thecardset.bface[0])%4] , bcards[thecardset.bcard[1]][(3+thecardset.bface[1])%4]) ) { bfail = true; return bfail; }
    if ( !bcardopposite(bcards[thecardset.bcard[3]][(1+thecardset.bface[3])%4] , bcards[thecardset.bcard[4]][(3+thecardset.bface[4])%4]) ) { bfail = true; return bfail; }
    if ( !bcardopposite(bcards[thecardset.bcard[6]][(1+thecardset.bface[6])%4] , bcards[thecardset.bcard[7]][(3+thecardset.bface[7])%4]) ) { bfail = true; return bfail; }
    
    if ( !bcardopposite(bcards[thecardset.bcard[1]][(1+thecardset.bface[1])%4] , bcards[thecardset.bcard[2]][(3+thecardset.bface[2])%4]) ) { bfail = true; return bfail; }
    if ( !bcardopposite(bcards[thecardset.bcard[4]][(1+thecardset.bface[4])%4] , bcards[thecardset.bcard[5]][(3+thecardset.bface[5])%4]) ) { bfail = true; return bfail; }
    if ( !bcardopposite(bcards[thecardset.bcard[7]][(1+thecardset.bface[7])%4] , bcards[thecardset.bcard[8]][(3+thecardset.bface[8])%4]) ) { bfail = true; return bfail; }
    
    
    if ( !bcardopposite(bcards[thecardset.bcard[0]][(2+thecardset.bface[0])%4] , bcards[thecardset.bcard[3]][(0+thecardset.bface[3])%4]) ) { bfail = true; return bfail; }
    if ( !bcardopposite(bcards[thecardset.bcard[1]][(2+thecardset.bface[1])%4] , bcards[thecardset.bcard[4]][(0+thecardset.bface[4])%4]) ) { bfail = true; return bfail; }
    if ( !bcardopposite(bcards[thecardset.bcard[2]][(2+thecardset.bface[2])%4] , bcards[thecardset.bcard[5]][(0+thecardset.bface[5])%4]) ) { bfail = true; return bfail; }
    
    if ( !bcardopposite(bcards[thecardset.bcard[3]][(2+thecardset.bface[3])%4] , bcards[thecardset.bcard[6]][(0+thecardset.bface[6])%4]) ) { bfail = true; return bfail; }
    if ( !bcardopposite(bcards[thecardset.bcard[4]][(2+thecardset.bface[4])%4] , bcards[thecardset.bcard[7]][(0+thecardset.bface[7])%4]) ) { bfail = true; return bfail; }
    if ( !bcardopposite(bcards[thecardset.bcard[5]][(2+thecardset.bface[5])%4] , bcards[thecardset.bcard[8]][(0+thecardset.bface[8])%4]) ) { bfail = true; return bfail; }
    return bfail;
}
int main ()
{
    struct cardset thiscardset;
    unsigned int cardinslot[9] = { 0 };
    bool cardspushed[9] = { 0 }; // Initial state all cards are pushed
    unsigned int depthpushed = 0;
    unsigned int positr[9];
    for (positr[0]=0; positr[0]<9; ++positr[0]) // 0
    {
        cardinslot[0]=positr[0];
        cardspushed[positr[0]] = true;
        for (positr[1]=0; positr[1]<9; ++positr[1]) // 1
        {
            cardinslot[1]=positr[1];
            if (cardspushed[positr[1]] == true) { continue; }
            cardspushed[positr[1]] = true;
            
            for (positr[2]=0; positr[2]<9; ++positr[2]) // 2
            {
                cardinslot[2]=positr[2];
                if (cardspushed[positr[2]] == true) { continue; }
                cardspushed[positr[2]] = true;
                
                for (positr[3]=0; positr[3]<9; ++positr[3]) // 3
                {
                    cardinslot[3]=positr[3];
                    if (cardspushed[positr[3]] == true) { continue; }
                    cardspushed[positr[3]] = true;
                    
                    for (positr[4]=0; positr[4]<9; ++positr[4]) // 4
                    {
                        cardinslot[4]=positr[4];
                        if (cardspushed[positr[4]] == true) { continue; }
                        cardspushed[positr[4]] = true;
                        
                        for (positr[5]=0; positr[5]<9; ++positr[5]) // 5
                        {
                            cardinslot[5]=positr[5];
                            if (cardspushed[positr[5]] == true) { continue; }
                            cardspushed[positr[5]] = true;
                            
                            for (positr[6]=0; positr[6]<9; ++positr[6]) // 6
                            {
                                cardinslot[6]=positr[6];
                                if (cardspushed[positr[6]] == true) { continue; }
                                cardspushed[positr[6]] = true;
                                
                                for (positr[7]=0; positr[7]<9; ++positr[7]) // 7
                                {
                                    cardinslot[7]=positr[7];
                                    if (cardspushed[positr[7]] == true) { continue; }
                                    cardspushed[positr[7]] = true;
                                    
                                    for (positr[8]=0; positr[8]<9; ++positr[8]) // 8
                                    {
                                        cardinslot[8]=positr[8];
                                        if (cardspushed[positr[8]] == true) { continue; }
                                        cardspushed[positr[8]] = true;
                                        
                                        
                                        
                                        
                                        
                                        
                                        thiscardset.bcard[0]=cardinslot[0];
                                        thiscardset.bcard[1]=cardinslot[1];
                                        thiscardset.bcard[2]=cardinslot[2];
                                        thiscardset.bcard[3]=cardinslot[3];
                                        thiscardset.bcard[4]=cardinslot[4];
                                        thiscardset.bcard[5]=cardinslot[5];
                                        thiscardset.bcard[6]=cardinslot[6];
                                        thiscardset.bcard[7]=cardinslot[7];
                                        thiscardset.bcard[8]=cardinslot[8];
                                        unsigned int faceitr[9];
                                        for (faceitr[0]=0; faceitr[0]<4; ++faceitr[0])
                                        {
                                            for (faceitr[1]=0; faceitr[1]<4; ++faceitr[1])
                                            {
                                                for (faceitr[2]=0; faceitr[2]<4; ++faceitr[2])
                                                {
                                                    for (faceitr[3]=0; faceitr[3]<4; ++faceitr[3])
                                                    {
                                                        for (faceitr[4]=0; faceitr[4]<4; ++faceitr[4])
                                                        {
                                                            for (faceitr[5]=0; faceitr[5]<4; ++faceitr[5])
                                                            {
                                                                for (faceitr[6]=0; faceitr[6]<4; ++faceitr[6])
                                                                {
                                                                    for (faceitr[7]=0; faceitr[7]<4; ++faceitr[7])
                                                                    {
                                                                        for (faceitr[8]=0; faceitr[8]<4; ++faceitr[8])
                                                                        {
                                                                            thiscardset.bface[0]=faceitr[0];
                                                                            thiscardset.bface[1]=faceitr[1];
                                                                            thiscardset.bface[2]=faceitr[2];
                                                                            thiscardset.bface[3]=faceitr[3];
                                                                            thiscardset.bface[4]=faceitr[4];
                                                                            thiscardset.bface[5]=faceitr[5];
                                                                            thiscardset.bface[6]=faceitr[6];
                                                                            thiscardset.bface[7]=faceitr[7];
                                                                            thiscardset.bface[8]=faceitr[8];
                                                                            bool bfail = testcards(thiscardset);
                                                                            if (!bfail) { cout << "Successful\n"; for (unsigned int itr = 0; itr < 9; ++itr) {cout << cardinslot[itr] << "," << faceitr[itr] <<"\n";} }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        
                                        
                                        cardspushed[positr[8]] = false;
                                    } // 8
                                    cardspushed[positr[7]] = false;
                                } // 7
                                cardspushed[positr[6]] = false;
                            } // 6
                            cardspushed[positr[5]] = false;
                        } // 5
                        cardspushed[positr[4]] = false;
                    } // 4
                    cardspushed[positr[3]] = false;
                } // 3
                cardspushed[positr[2]] = false;
            } // 2
            cardspushed[positr[1]] = false;
        } // 1
        cardspushed[positr[0]] = false;
    } // 0
    return 0;
}
