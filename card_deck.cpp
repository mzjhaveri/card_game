//  card_deck.cpp
//  card_game
//  Definitions of Card class member functions
//  Created by Mufaddal Jhaveri on 3/3/17.
//  Copyright © 2017 self.edu. All rights reserved.
//

#include "card_deck.hpp"

CardDeck::CardDeck()
{
    for(int i = 0; i < NUM_CARD_SUIT; ++i)
    {
        for(int j = 0; j < NUM_CARD_VALUE; ++j)
        {
            m_current_card_deck.push_back(Card((e_CardSuit)i,(e_CardValue)j));
        }
    }
}

// Function to randomly shuffle deck of cards
// input: none
// output : none
void CardDeck::deck_shuffle()
{
    std::cout << "********** Deck Shuffle ***********" << std::endl;
    std::random_shuffle(m_current_card_deck.begin(), m_current_card_deck.end());
}

// Function to print deck of cards
// input: none
// output : none
void CardDeck::print_deck()
{
    for(int i =0; i < m_current_card_deck.size(); ++i)
    {
        std::cout << m_current_card_deck[i] << std::endl;
    }
}


CardDeck& CardDeck::operator = (CardDeck &cd1)
{
    for(int i =0; i < cd1.m_current_card_deck.size(); ++i)
    {
        m_current_card_deck[i] = cd1.m_current_card_deck[i];
    }
    return *this;
}

//  Function to check if card deck has a sequence same as sequence in previous card deck
//  Sequence begins from the same location in previous and current card deck
//  input: curr_cd -> current card deck
//         prev_cd -> previous card_deck
//         seq_count -> number of cards to be checked for sequence
//  output: true or false

bool check_card_sequence_present(CardDeck &curr_cd, CardDeck &prev_cd, int seq_count)
{
    int i,zk;
    bool found = true;
    
    if(seq_count > prev_cd.m_current_card_deck.size())
        throw "Error:Seq count higher than card deck size";

    for(i = 0; i < prev_cd.m_current_card_deck.size(); i = i + seq_count)
    {
        found = true;
        for(k = 0; k <seq_count ; k++)
        {
            //Check if cards are same
            if(prev_cd.m_current_card_deck[i+k].get_card_suit() != curr_cd.m_current_card_deck[i+k].get_card_suit()
               && prev_cd.m_current_card_deck[i+k].get_card_value() != curr_cd.m_current_card_deck[i+k].get_card_value())
            {
                found = false;
                break;
            }
            
        }
        if(found)
            return true;

    }// for loop iterating over prev and current card deck
    
    return false;
    
}

