//  card.hpp
//  Header file for Card class
//  card_game
//
//  Created by Mufaddal Jhaveri on 3/3/17.
//  Copyright © 2017 self.edu. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

#include <stdio.h>
#include <ostream>

typedef enum CardSuit
{
    SUIT_NONE = -1,
    HEART,
    SPADE,
    DIAMOND,
    FLOWER
}e_CardSuit;

typedef enum CardValue
{
    VALUE_NONE = -1,
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,

}e_CardValue;

//Class Card which manages interface to a Card

class Card
{
public:
    
    Card(e_CardSuit card_suit, e_CardValue card_value) : m_card_suit(card_suit), m_card_value(card_value)
    {
    }
    
    Card(): m_card_suit(SUIT_NONE), m_card_value(VALUE_NONE)
    {
        
    }
    
    Card(const Card &c1)
    {
        m_card_suit = c1.m_card_suit;
        m_card_value = c1.m_card_value;
    }
    ~Card(){}
    
    Card& operator = (Card &c1);
    
    friend std::ostream& operator<< (std::ostream &os, const Card &c1);
    friend void swap(Card &c1,Card &c2);

    // Function to get card value
    // input : none
    // output : card value
    e_CardValue get_card_value() const;
    
    // Function to get card suit
    // input : none
    // output : card suit
    e_CardSuit get_card_suit() const;
private:
    
    e_CardSuit m_card_suit;
    e_CardValue m_card_value;

};

#endif /* card_hpp */
