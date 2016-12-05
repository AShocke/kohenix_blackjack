#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <iostream>
#include <vector>

/*
 * Manages the game
 * Note that this is version of blackjack 
 * is simplified for the ai
 */
class Blackjack {
private:
    const int BLACKJACK = 21;
    const int MAX_CARDS = 52;
    char deck_[52] = {
	2 , 2, 2 , 2,
	3, 3, 3, 3,
	4, 4, 4, 4,
	5, 5, 5, 5,
	6, 6, 6, 6,
	7, 7, 7, 7,
	8, 8, 8, 8,
	9, 9, 9, 9,
	10, 10, 10, 10,
	'J','J','J','J',
	'Q','Q','Q','Q',
	'K','K','K','K',
	'A','A','A','A'
    };
    int deck_index_ = 0;
    std::vector<char> player_hand_;
    std::vector<char> dealer_hand_;
    void shuffle_deck();
    bool dealer_turn;
public:
    Blackjack();
    void give_card();
    int count_hand(std::vector<char> h);
    std::vector<char> get_player_hand() {
	return player_hand_;
    }
    void change_turn();
    bool did_dealer_win();
    bool did_bust(std::vector<char> h);
    //bool natural_blackjack();
};
#endif
