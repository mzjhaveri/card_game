//
//  main.cpp
//  card_game
//
//  Created by Mufaddal Jhaveri on 3/3/17.
//  Copyright © 2017 self.edu. All rights reserved.
//

#include <iostream>
#include "card_deck.hpp"

using namespace std;



int main(int argc, const char * argv[])
{
    bool keep_shuffling;
    int shuffle_count;
    //Create a card deck
    
    try
    {
        CardDeck curr_cd;
        
        //Create a temp card deck to keep history of previous shuffle
        CardDeck prev_cd;
        
        //Print Current Card Deck
        curr_cd.print_deck();
        
        //Shuffle the Card Deck
        curr_cd.deck_shuffle();
        
        //Print Current Card Deck
        curr_cd.print_deck();
        
        //Find sequence pair of Cards in current Card deck
        // which are in same in previous Card deck prior to shuffle
        keep_shuffling = true;
        while(keep_shuffling)
        {
            prev_cd = curr_cd;
            
            //Shuffle the Card Deck
            curr_cd.deck_shuffle();
            
            //Print Current Card Deck
            curr_cd.print_deck();
            
            //Check for Sequence
            keep_shuffling = check_card_sequence_present(curr_cd, prev_cd, 2);
            
            shuffle_count ++;
            cout << "Shuffle Iteration:" << shuffle_count << endl;
            
        }
        
    }
    catch(...)
    {
        std::cerr<<"Exception Encountered!" <<std::endl;
    }
    return 0;
    
}
