#include <iostream>
#include <stdlib.h>
#include "blackjack.h"

Blackjack::Blackjack() {
    dealer_turn = false;
    shuffle_deck();
}
void Blackjack::shuffle_deck() {
    for (int i = MAX_CARDS-1; i >= 0; i--) {
	int r = (int)(rand() % MAX_CARDS);
	int temp = deck_[i];
	deck_[i] = deck_[r];
	deck_[r] = temp;
    }
}
void Blackjack::refresh_deck() {
    int new_deck[52] = {
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
    for (int x = 0; x < 52; x++) {
	deck_[x] = new_deck[x];
    }
    shuffle_deck();
}

void Blackjack::change_turn() {
    dealer_turn = (dealer_turn)? false : true;
}
void Blackjack::new_round() {
    player_hand_.clear();
    dealer_hand_.clear();
}
void Blackjack::give_player_card() {
    player_hand_.push_back(deck_[deck_index_++]);
    check_deck();
}

void Blackjack::check_deck() {
    if (deck_index_ >= 52) {	refresh_deck();
    }
}

void Blackjack::give_dealer_card() {
    dealer_hand_.push_back(deck_[deck_index_++]);
    if (dealer_hand_.size() == 1) {
    set_seen_value();
    }
    check_deck();
}

void Blackjack::set_seen_value() {
    if (dealer_hand_[0] == 'J' || dealer_hand_[0] == 'Q' || dealer_hand_[0] == 'K') {
        seen_value_ = 10;
    }
    else if (dealer_hand_[0] == 'A') {
        seen_value_ = 11;
    }
    else {
        seen_value_ = dealer_hand_[0];
    }
}
        

bool Blackjack::did_player_win() {
    return (count_player_hand() > count_dealer_hand());
}

bool Blackjack::did_player_bust() {
    return (count_player_hand() > 21); 
}
int Blackjack::count_player_hand() {
    int sum = 0;
    int alt_sum = 0; // only one ace can be worth 11
    for (std::vector<char>::size_type x = 0; x != player_hand_.size(); x++){
	if (player_hand_[x] == 'A') {
	    if ((sum + 11) <= BLACKJACK) {
		alt_sum += 11;
	    }
	    else {
		sum += 1;
	    }
	}
	if ((player_hand_[x] == 'J') || (player_hand_[x] == 'Q') || (player_hand_[x] == 'K')) {
	    sum += 10;
	    alt_sum += 10;
	}
	else {
	    sum += player_hand_[x];
	    alt_sum += player_hand_[x];
	}
    }
    return ((alt_sum > sum) && (alt_sum <= BLACKJACK))? alt_sum : sum;
}
int Blackjack::count_dealer_hand() {
    int sum = 0;
    int alt_sum = 0; // only one ace can be worth 11
    for (std::vector<char>::size_type x = 0; x != dealer_hand_.size(); x++){
	if (dealer_hand_[x] == 'A') {
	    if ((sum + 11) <= BLACKJACK) {
		alt_sum += 11;
	    }
	    else {
		sum += 1;
	    }
        }
	if ((dealer_hand_[x] == 'J') || (dealer_hand_[x] == 'Q') || (dealer_hand_[x] == 'K')) {
	    sum += 10;
	    alt_sum += 10;
	}
	else {
	    sum += dealer_hand_[x];
	    alt_sum += dealer_hand_[x];
	}
    }
    return ((alt_sum > sum) && (alt_sum <= BLACKJACK))? alt_sum : sum;
}
	
    

