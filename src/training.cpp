#include <iostream>
#include "blackjack.h"
#include "logic.h"

void run_game(long long int iterations) {
    Blackjack b;
    Logic l;
    int player_hand_value = 0;
    int dealer_shown_value = 0;
    int player_moves = 0;
    bool did_player_win = true;
    int game_record[20][3]; // records where the player hit and at which
                            // values;
    // The data is stored like this:
    // |player_val||dealer_val||hit_or_stay(1 or 0)
    l.print();
    for (long long int c = 0; c < iterations; c++) {
        // Give each player 2 cards
        for (int x = 0; x < 2; x++) {
            b.give_player_card();
            b.give_dealer_card();
        }
        player_hand_value = b.count_player_hand();
        dealer_shown_value = b.get_seen_value();
        // player_turn();
        while(l.hit_or_stay(player_hand_value, dealer_shown_value)) {
            game_record[player_moves][0] = player_hand_value;
            game_record[player_moves][1] = dealer_shown_value;
            game_record[player_moves][2] = 1;
            player_moves++;
            b.give_player_card();
            player_hand_value = b.count_player_hand();
            if(b.did_player_bust()) {
                did_player_win = false;
                break;
            }
        }
        // dealer_turn();
        if(did_player_win) { // if player has not lost yet

        }
        // who won?
        if(did_player_win) {
            did_player_win = b.did_player_win();
        }
        if (did_player_win) {
            std::cout << "WIN!\n";
        }
        else {
            std::cout << "LOSS!\n";
        }
        // update_odds
        for (int x = 0; x < player_moves; x++) {
            int p_hand_val = game_record[x][0];
            int d_shown_val = game_record[x][1];
            bool h_o_s = (game_record[x][2] = 1)? true : false;
            l.update_odds(p_hand_val, d_shown_val, h_o_s, did_player_win);
        }
        
        // new round
        b.new_round();
    }
    // save
    l.save(true);
}


