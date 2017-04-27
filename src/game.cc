#include <iostream>
#include <random>
#include <vector>
#include "game.h"
#include "logic.h"

int give_card() {
    std::random_device gen;
    std::mt19937 rng(gen());
    std::uniform_int_distribution<int> ran(1,11);
    int r =  ran(rng);
    std::cout << "cards given" << r << "\n";
    return r;
}

void update_all_odds(bool did_win, std::vector<int> state, int dealer_shown, Logic &l) {
    if (state.end() == state.begin()) {
	return;
    }
    // last move made is always a stay (assuming player did not bust)
    l.update_odds(state[state.size() - 1], dealer_shown, did_win, false);
    // all other moves must be hits, exlu
    std::cout << "state.size() " << state.size() << "\n";
    for (unsigned i = 0; i < state.size() - 1; i++) {
	std::cout << "state[" << i << "]: " << state[i] << "\n";
	l.update_odds(state[i]-1, dealer_shown-1, did_win, true);
    }
    l.save(true);
}
void run_game(long int iterations, bool new_data) {
    Logic l(new_data);
    //l.print();
    // START
    for (int i = 0; i < iterations; i++) {
	int player_hand = 0;
	int dealer_shown = 0;
	int dealer_hand = 0;
	bool did_player_bust = false;
	bool did_dealer_bust = false;
	std::vector<int> s; // Serves as move history storage for update odds
	dealer_shown = give_card();
	dealer_hand = dealer_shown;
	std::cout << "dealer_shown: " << dealer_shown << "\n";
	player_hand += give_card();
	// Player Turn
	while(l.hit_or_stay(player_hand, dealer_shown)) {
	    std::cout << "player_hand: " << player_hand << "\n";
	    s.push_back(player_hand);
	    int current = player_hand;
	    current += give_card();
	    if (current > BLACKJACK) {
		did_player_bust = true;
		std::cout << "IN HIT OR STAY BLOCK:" << player_hand << "\n";
		update_all_odds(false, s , dealer_shown, l);
		std::cout << "BUST!" << "\n";
		break;
	    }
	    player_hand = current;
	}
	// Checking For Bust
	if (did_player_bust) {
	    l.save(true);
	}
	else {
	    // Dealer Turn
	    std::cout << "DEALER TURN\n";
	    while(dealer_hand < 17) {
		int current = dealer_hand;
		current += give_card();
		if (current > BLACKJACK) {
		    did_dealer_bust = true;
		    update_all_odds(true, s, dealer_shown, l);
		    std::cout << "WIN! DEAL BUST!" << "\n";
		    break;
		}
		dealer_hand = current;
	    }
	    // Checking For Bust
	    if (did_dealer_bust) {
		l.save(true);
		std::cout << "WIN!" << "\n";
	    }
	    // Final Results
	    update_all_odds((player_hand >= dealer_hand), s, dealer_shown,l);
	    std::cout << ((player_hand >= dealer_hand)? "WIN!\n" : "LOSS\n");
	}
    }
}


