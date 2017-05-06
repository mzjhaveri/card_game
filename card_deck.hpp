//  card_deck.hpp
//  card_game
//  Header file for Card class
//  Created by Mufaddal Jhaveri on 3/3/17.
//  Copyright © 2017 self.edu. All rights reserved.
//

#ifndef card_deck_hpp
#define card_deck_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include "card.hpp"

#define NUM_CARD_VALUE 13
#define NUM_CARD_SUIT 4
#define NUM_CARDS (NUM_CARD_VALUE * NUM_CARD_SUIT)

//Class CardDeck which manages interface to a deck of Cards

class CardDeck
{
public:
    
    CardDeck();
    ~CardDeck(){}
    
    CardDeck& operator = (CardDeck &cd1);
    
    //  Function to check if card deck has a sequence same as sequence in previous card deck
    //  Sequence begins from the same location in previous and current card deck
    //  input: curr_cd -> current card deck
    //         prev_cd -> previous card_deck
    //         seq_count -> number of cards to be checked for sequence
    //  output: true or false
    friend bool check_card_sequence_present(CardDeck &curr_cd, CardDeck &prev_cd, int seq_count);
    
    // Function to randomly shuffle deck of cards
    // input: none
    // output : none
    void deck_shuffle();
    
    // Function to print deck of cards
    // input: none
    // output : none
    void print_deck();
    
private:
    std::vector <Card> m_current_card_deck;
};

#endif /* card_deck_hpp */
