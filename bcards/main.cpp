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
    for (int itr1 = 0; itr1 < 36; ++itr1)
    {
        for (int itr2 = 0; itr2 < 36; ++itr2)
        {
            for (int itr3 = 0; itr3 < 36; ++itr3)
            {
                for (int itr4 = 0; itr4 < 36; ++itr4)
                {
                    for (int itr5 = 0; itr5 < 36; ++itr5)
                    {
                        for (int itr6 = 0; itr6 < 36; ++itr6)
                        {
                            for (int itr7 = 0; itr7 < 36; ++itr7)
                            {
                                for (int itr8 = 0; itr8 < 36; ++itr8)
                                {
                                    for (int itr9 = 0; itr9 < 36; ++itr9)
                                    {
                                        bool hasrepeat = false;
                                        bool whichhit[9] = {false,false,false,false,false,false,false,false,false};
                                        
                                        thiscardset.bcard[0]=itr1%9;
                                        thiscardset.bface[0]=itr1/9;
                                        thiscardset.bcard[1]=itr2%9;
                                        thiscardset.bface[1]=itr2/9;
                                        thiscardset.bcard[2]=itr3%9;
                                        thiscardset.bface[2]=itr3/9;
                                        thiscardset.bcard[3]=itr4%9;
                                        thiscardset.bface[3]=itr4/9;
                                        thiscardset.bcard[4]=itr5%9;
                                        thiscardset.bface[4]=itr5/9;
                                        thiscardset.bcard[5]=itr6%9;
                                        thiscardset.bface[5]=itr6/9;
                                        thiscardset.bcard[6]=itr7%9;
                                        thiscardset.bface[6]=itr7/9;
                                        thiscardset.bcard[7]=itr8%9;
                                        thiscardset.bface[7]=itr8/9;
                                        thiscardset.bcard[8]=itr9%9;
                                        thiscardset.bface[8]=itr9/9;
                                        
                                        for (unsigned int itr = 0; itr < 9; ++itr)
                                        {
                                            if (whichhit[ thiscardset.bcard[itr] ]==false)
                                            {
                                                whichhit[ thiscardset.bcard[itr] ]= true;
                                            }
                                            else
                                            {
                                                hasrepeat = true;
                                                continue;
                                            }
                                        }
                                        if (hasrepeat) { continue; }
                                        
                                        bool bfail = testcards(thiscardset);
                                        
                                        if (!bfail)
                                        {
                                            cout << "Successful\n";
                                            cout << itr1 << "\n";
                                            cout << itr2 << "\n";
                                            cout << itr3 << "\n";
                                            cout << itr4 << "\n";
                                            cout << itr5 << "\n";
                                            cout << itr6 << "\n";
                                            cout << itr7 << "\n";
                                            cout << itr8 << "\n";
                                            cout << itr9 << "\n";
                                            
                                        }
                                                                                      
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
