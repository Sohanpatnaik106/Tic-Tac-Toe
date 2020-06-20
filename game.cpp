#include "bits/stdc++.h"
using namespace std;

bool game_over = false;
vector<int> X;
vector<int> O;
vector<int> checker_position;
int player_turn = 1;
string player1_name, player2_name;

void display_game_board() {
    system("clear");
    for(int i = 0; i < 3; i++) {
        if(i == 0) {
            for(int j = 0; j < 3; j++) 
                cout << " ___";
            cout << endl << endl;
        }
        if(checker_position.size() == 0) {
            for(int j = 0; j < 3; j++) {
                cout << "|   ";
            }
        }
        else {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < checker_position.size(); k++) {
                    if(find(X.begin(), X.end(), checker_position[k]) != X.end()) {
                        if(checker_position[k]/3 == i && checker_position[k]%3 == j) {
                            cout << "| X ";
                            j++;
                        }
                    }
                    if(find(O.begin(), O.end(), checker_position[k])!= O.end()) {
                        if(checker_position[k]/3 == i && checker_position[k]%3 == j) {
                            cout << "| O ";
                            j++;
                        }
                    }
                }
                if(j != 3) {
                    cout << "|   ";
                }
            }
        }
        cout << "|" << endl;
        for(int j = 0; j < 3; j++) {
            cout << " ___";
        }
        cout << endl << endl;
    }
}

void turn() {
    int position;
    if(player_turn % 2 != 0) {
        label1:
        cout << player1_name << ", enter the position of X : ";
        cin >> position;
        if(find(checker_position.begin(), checker_position.end(), position-1) != checker_position.end()) {
            cout << "The position is already occupied." << endl;
            goto label1;
        }
        X.push_back(position-1);
        checker_position.push_back(position-1);
        sort(checker_position.begin(), checker_position.end());
    }
    else {
        label2:
        cout << player2_name << ", enter the position of O : ";
        cin >> position;
        if(find(checker_position.begin(), checker_position.end(), position-1) != checker_position.end()) {
            cout << "The position is already occupied." << endl;
            goto label2;
        }
        O.push_back(position-1);
        checker_position.push_back(position-1);
        sort(checker_position.begin(), checker_position.end());
    }
    player_turn++;
}

void check_winner() {
    if(player_turn == 6 || player_turn == 8 || player_turn == 10) {
        vector<int> :: iterator it1, it2, it3;
        it1 = find(X.begin(), X.end(), 0);
        it2 = find(X.begin(), X.end(), 1);
        it3 = find(X.begin(), X.end(), 2);
        if(it1 != X.end() && it2 != X.end() && it3 != X.end()) {
            cout << player1_name << " won." << endl;
            game_over = true;
            return;
        }
        it1 = find(X.begin(), X.end(), 3);
        it2 = find(X.begin(), X.end(), 4);
        it3 = find(X.begin(), X.end(), 5);
        if(it1 != X.end() && it2 != X.end() && it3 != X.end()) {
            cout << player1_name << " won." << endl;
            game_over = true;
            return;
        }
        it1 = find(X.begin(), X.end(), 6);
        it2 = find(X.begin(), X.end(), 7);
        it3 = find(X.begin(), X.end(), 8);
        if(it1 != X.end() && it2 != X.end() && it3 != X.end()) {
            cout << player1_name << " won." << endl;
            game_over = true;
            return;
        }
        it1 = find(X.begin(), X.end(), 0);
        it2 = find(X.begin(), X.end(), 3);
        it3 = find(X.begin(), X.end(), 6);
        if(it1 != X.end() && it2 != X.end() && it3 != X.end()) {
            cout << player1_name << " won." << endl;
            game_over = true;
            return;
        }
        it1 = find(X.begin(), X.end(), 1);
        it2 = find(X.begin(), X.end(), 4);
        it3 = find(X.begin(), X.end(), 7);
        if(it1 != X.end() && it2 != X.end() && it3 != X.end()) {
            cout << player1_name << " won." << endl;
            game_over = true;
            return;
        }
        it1 = find(X.begin(), X.end(), 2);
        it2 = find(X.begin(), X.end(), 5);
        it3 = find(X.begin(), X.end(), 8);
        if(it1 != X.end() && it2 != X.end() && it3 != X.end()) {
            cout << player1_name << " won." << endl;
            game_over = true;
            return;
        }
        it1 = find(X.begin(), X.end(), 0);
        it2 = find(X.begin(), X.end(), 4);
        it3 = find(X.begin(), X.end(), 8);
        if(it1 != X.end() && it2 != X.end() && it3 != X.end()) {
            cout << player1_name << " won." << endl;
            game_over = true;
            return;
        }
        it1 = find(X.begin(), X.end(), 2);
        it2 = find(X.begin(), X.end(), 4);
        it3 = find(X.begin(), X.end(), 6);
        if(it1 != X.end() && it2 != X.end() && it3 != X.end()) {
            cout << player1_name << " won." << endl;
            game_over = true;
            return;
        }
    }
    else if(player_turn == 7 || player_turn == 9) {
        vector<int> :: iterator it1, it2, it3;
        it1 = find(O.begin(), O.end(), 0);
        it2 = find(O.begin(), O.end(), 1);
        it3 = find(O.begin(), O.end(), 2);
        if(it1 != O.end() && it2 != O.end() && it3 != O.end()) {
            cout << player2_name << " won." << endl;
            game_over = true;
            return;
        }

        it1 = find(O.begin(), O.end(), 3);
        it2 = find(O.begin(), O.end(), 4);
        it3 = find(O.begin(), O.end(), 5);
        if(it1 != O.end() && it2 != O.end() && it3 != O.end()) {
            cout << player2_name << " won." << endl;
            game_over = true;
            return;
        }
        
        it1 = find(O.begin(), O.end(), 6);
        it2 = find(O.begin(), O.end(), 7);
        it3 = find(O.begin(), O.end(), 8);
        if(it1 != O.end() && it2 != O.end() && it3 != O.end()) {
            cout << player2_name << " won." << endl;
            game_over = true;
            return;
        }
        
        it1 = find(O.begin(), O.end(), 0);
        it2 = find(O.begin(), O.end(), 3);
        it3 = find(O.begin(), O.end(), 6);
        if(it1 != O.end() && it2 != O.end() && it3 != O.end()) {
            cout << player2_name << " won." << endl;
            game_over = true;
            return;
        }
        
        it1 = find(O.begin(), O.end(), 1);
        it2 = find(O.begin(), O.end(), 4);
        it3 = find(O.begin(), O.end(), 7);
        if(it1 != O.end() && it2 != O.end() && it3 != O.end()) {
            cout << player2_name << " won." << endl;
            game_over = true;
            return;
        }
       
        it1 = find(O.begin(), O.end(), 2);
        it2 = find(O.begin(), O.end(), 5);
        it3 = find(O.begin(), O.end(), 8);
        if(it1 != O.end() && it2 != O.end() && it3 != O.end()) {
            cout << player2_name << " won." << endl;
            game_over = true;
            return;
        }
        
        it1 = find(O.begin(), O.end(), 0);
        it2 = find(O.begin(), O.end(), 4);
        it3 = find(O.begin(), O.end(), 8);
        if(it1 != O.end() && it2 != O.end() && it3 != O.end()) {
            cout << player2_name << " won." << endl;
            game_over = true;
            return;
        }
        
        it1 = find(O.begin(), O.end(), 2);
        it2 = find(O.begin(), O.end(), 4);
        it3 = find(O.begin(), O.end(), 6);
        if(it1 != O.end() && it2 != O.end() && it3 != O.end()) {
            cout << player2_name << " won." << endl;
            game_over = true;
            return;
        }
    }
    if(player_turn == 10 && game_over == false) {
        game_over = true;
        cout << "The match is drawn." << endl;
        return;
    }
}

int main() {
    system("clear");
    cout << "Welcome to Tic-Tac-Toe game" << endl;
    cout << "Press Enter to begin" << endl;
    cout << "Enter the name of the player who takes X : ";
    cin >> player1_name;
    cout << "Enter the name of the player who takes O : ";
    cin >> player2_name;
    getchar();
    
    display_game_board();
    while(!game_over) {
        turn();
        display_game_board();
        check_winner();
    }
    return 0;
}