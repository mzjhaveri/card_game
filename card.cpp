//  card.cpp
//  card_game
//  Definitions of Card class member functions
//  Created by Mufaddal Jhaveri on 3/3/17.
//  Copyright © 2017 self.edu. All rights reserved.
//
#include <string>

#include "card.hpp"

// Function to get card value
// input : none
// output : card value
e_CardValue Card::get_card_value() const
{
    
    return m_card_value;
}

// Function to get card suit
// input : none
// output : card suit
e_CardSuit Card::get_card_suit() const
{
    return m_card_suit;
}

Card& Card::operator = (Card &c1)
{
    m_card_value = c1.get_card_value();
    m_card_suit = c1.get_card_suit();
    return *this;
}

std::ostream& operator<< (std::ostream &os, const Card &c1)
{
    std::string card_value;
    std::string card_suit;
    
    switch(c1.get_card_suit())
    {
        case SUIT_NONE: card_suit = "SUIT_NONE"; break;
        case HEART: card_suit = "HEART"; break;
        case SPADE: card_suit = "SPADE"; break;
        case DIAMOND: card_suit = "DIAMOND"; break;
        case FLOWER: card_suit = "FLOWER"; break;
        default: card_suit = "SUIT_NONE"; break;
    }
    
    switch (c1.get_card_value())
    {
        case VALUE_NONE: card_value = "VALUE_NONE"; break;
        case ACE: card_value = "ACE"; break;
        case TWO: card_value = "TWO"; break;
        case THREE: card_value = "THREE"; break;
        case FOUR: card_value = "FOUR"; break;
        case FIVE: card_value = "FIVE"; break;
        case SIX: card_value = "SIX"; break;
        case SEVEN: card_value = "SEVEN"; break;
        case EIGHT: card_value = "EIGHT"; break;
        case NINE: card_value = "NINE"; break;
        case TEN: card_value = "TEN"; break;
        case JACK: card_value = "JACK"; break;
        case QUEEN: card_value = "QUEEN"; break;
        case KING: card_value = "KING"; break;
        default: card_value = "VALUE_NONE"; break;
    }
    
    os << card_value << " of " << card_suit;
    return os;
}

 void swap(Card &c1,Card &c2)
{
    e_CardSuit temp_card_suit;
    e_CardValue temp_card_value;
    
    temp_card_suit = c1.m_card_suit;
    temp_card_value = c1.m_card_value;
    
    c1.m_card_suit = c2.m_card_suit;
    c1.m_card_value = c2.m_card_value;
    
    c2.m_card_suit = temp_card_suit;
    c2.m_card_value = temp_card_value;
    
}