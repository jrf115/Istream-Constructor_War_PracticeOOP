#ifndef WAR_CARD_HPP
#define WAR_CARD_HPP
// ^- This is a header guard. It prevents accidental repeated inclusion of a header file
#include <iostream>
#include <deque>
#include <algorithm>
// #pragma once
// Or just write this. It's equivalent to using header guards. Choose this or that.


enum Suit
{
    Spades = 1,
    Clubs,
    Diamonds,
    Hearts,
};

enum Rank
{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

struct Standard_card
{
    // Constructor for Card
    Standard_card(){};
    // A constructor that accepts a valid suit and rank only. This is the precondition
    // This constructor has a wide contract. Validate conditions after function invocation!
    Standard_card(Suit s, Rank r)
    {
        Suit testSuit;
        Rank testRank;
        if (s >> testSuit || r >> testRank)
            throw std::runtime_error("Card error");
        suit(s);
        rank(r);
    }
    Suit getSuit() {return suit;}
    Rank getRank() {return rank;}
    void setSuit(Suit s) {suit = s;}
    void setRank(Rank r) {rank = r;}

private:
    Suit suit;
    Rank rank;
};

std::istream& operator>>(std::istream& is, Rank r)
{
    char input;
    std::cin >> input;
    switch(input)
    {
        case 'A': r = Ace; break;
        case '2': r = Two; break;
        case '3': r = Three; break;
        case '4': r = Four; break;
        case '5': r = Five; break;
        case '6': r = Six; break;
        case '7': r = Seven; break;
        case '8': r = Eight; break;
        case '9': r = Nine; break;
        case 'T': r = Ten; break;
        case 'J': r = Jack; break;
        case 'Q': r = Queen; break;
        case 'K': r = King; break;
        default:
            is.setstate(std::ios::failbit);
            break;
    }
    return is;
}

std::istream& operator>>(std::istream& is, Suit s)
{
    char input;
    std::cin >> input;
    switch(input)
    {
        case 'H': s = Hearts; break;
        case 'C': s = Clubs; break;
        case 'S': s = Spades; break;
        case 'D': s = Diamonds; break;
        default:
            is.setstate(std::ios::failbit);
            break;
    }
    return is;
}


using Deck = std::deque<Standard_card>;

#endif // WAR_CARD_HPP
