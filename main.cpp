#include <iostream>
#include <string>
#include <random>

using std::cout, std::endl, std::cin;

int random_number();
int set_difficulty();
bool out_of_games(int);


int main() {
    bool continue_game = true;
    // Start the game
    int computer_choice = random_number();
    int life_count = set_difficulty();

    while(continue_game){

        // Player guessing
        int player_guess{};
        cout << "Choose a number from 1 to 100" << endl;
        cout << "Enter your guess: ";
        cin >> player_guess;

        // Check Guess
        if(player_guess != computer_choice){
            life_count--;
            if(player_guess < computer_choice){
                cout << "Guess is too low." << endl;
            }
            else{
                cout << "Guess is too high." << endl;
            }

            // Check life count
            if(life_count == 0){
                continue_game = out_of_games(computer_choice);
                if(continue_game){
                    computer_choice = random_number();
                    life_count = set_difficulty();
                }
            }
        }
        else{
            // Player got the win
            char more_games {'y'};
            cout << "You got it!\nThe number was " << player_guess << "!!!" << endl;
            cout << "Do you want to play another game?\ny for yes and n for no: ";
            cin >> more_games;
            if(more_games == 'n' or more_games == 'N'){
                continue_game = false;
            }
            if(continue_game){
                computer_choice = random_number();
                life_count = set_difficulty();
            }
        }


    }


    return 0;
}

int random_number(){
    // Random seeding
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int choice = dist(mt);
    return choice;
}

int set_difficulty(){
    // Get difficulty level
    char player_choice{'p'};
    cout << "Enter difficulty. p for practice, e for easy, and h for hard." << endl;
    cout << "Practice mode gives you unlimited lives.\nEasy mode gives you 10 lives.\nHard mode gives you 5 lives." <<endl;
    cin >> player_choice;

    // Set difficulty level
    if(player_choice == 'p' or player_choice == 'P'){
        // Practice mode
        return 1000;
    }

    if(player_choice == 'e' or player_choice == 'E'){
        // Easy mode
        return 10;
    }

    // Hard mode
    return 5;
}

bool out_of_games(int computer_choice){
    char more_games{'y'};
    cout << "Sorry, you are out of lives. The number was " << computer_choice << "." << endl;
    cout << "Continue? Enter y for yes and n for no." << endl;
    cin >> more_games;
    if(more_games == 'n' or more_games == 'N'){
        return false;
    }

    return true;
}