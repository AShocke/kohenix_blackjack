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
void Blackjack::change_turn() {
    dealer_turn = (dealer_turn)? false : true;
}
void Blackjack::give_card() {
    player_hand_.push_back(deck_[deck_index_++]);
}

bool Blackjack::did_dealer_win() {
    return (count_hand(dealer_hand_) > count_hand(player_hand_));
}

bool Blackjack::did_bust(std::vector<char> h) {
    return (count_hand(h) > 21);
}

int Blackjack::count_hand(std::vector<char> h) {
    int sum = 0;
    int alt_sum = 0; // only one ace can be worth 11
    for (std::vector<char>::size_type x = 0; x != h.size(); x++){
	if (h[x] == 'A') {
	    if ((sum + 11) <= BLACKJACK) {
		alt_sum += 11;
	    }
	    else {
		sum += 1;
	    }
	}
	if ((h[x] == 'J') || (h[x] == 'Q') || (h[x] == 'K')) {
	    sum += 10;
	    alt_sum += 10;
	}
	else {
	    sum += h[x];
	    alt_sum += h[x];
	}
    }
    return ((alt_sum > sum) && (alt_sum >= BLACKJACK))? alt_sum : sum;
}

	
    

