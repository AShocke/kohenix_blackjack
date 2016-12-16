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
    int seen_value_;
    void shuffle_deck();
    void refresh_deck();
    bool dealer_turn;
public:
    Blackjack();
    void give_card();
    void change_turn();
    bool did_dealer_win();
    bool did_bust(std::vector<char> h);
    void new_round();
    void give_player_card();
    void give_dealer_card();
    void check_deck();
    void set_seen_value();
    int get_seen_value() {
	return seen_value_;
    }
    bool did_player_win();
    bool did_player_bust();
    int count_player_hand();
    int count_dealer_hand();

   
};
#endif
