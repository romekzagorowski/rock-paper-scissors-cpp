#include <array>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <print>
#include <random>
#include <string>
#include <string_view>

int main() {
    constexpr std::array<std::string_view, 3> choices{"rock", "paper", "scissors"};
    const std::map<std::string_view, std::string_view> choice_aliases{
        {"r", "rock"}, {"p", "paper"}, {"s", "scissors"}};
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<std::size_t> pick_choice(0, choices.size() - 1);
    int player_score = 0;
    int computer_score = 0;

    std::println("Welcome to Rock Paper Scissors!");
    std::println("Enter rock (r), paper (p), or scissors (s). Type q to quit.");

    while (true) {
        std::print("Your choice: ");
        std::fflush(stdout);
        std::string input;
        if (!(std::cin >> input)) {
            break;
        }

        for (char& character : input) {
            character = static_cast<char>(
                std::tolower(static_cast<unsigned char>(character)));
        }

        if (input == "q" || input == "quit") {
            break;
        }

        if (const auto alias = choice_aliases.find(input);
            alias != choice_aliases.end()) {
            input = alias->second;
        }

        std::size_t player_choice = choices.size();
        for (std::size_t index = 0; index < choices.size(); ++index) {
            if (input == choices[index]) {
                player_choice = index;
                break;
            }
        }

        if (player_choice == choices.size()) {
            std::println("Invalid choice. Please enter rock (r), paper (p), scissors (s), or quit (q).");
            continue;
        }

        const std::size_t computer_choice = pick_choice(generator);
        std::println("You chose {}. The computer chose {}.",
                     choices[player_choice], choices[computer_choice]);

        if (player_choice == computer_choice) {
            std::println("It's a tie!");
        } else if ((player_choice + 1) % choices.size() == computer_choice) {
            ++computer_score;
            std::println("The computer wins this round.");
        } else {
            ++player_score;
            std::println("You win this round!");
        }

        std::println("Score - You: {}, Computer: {}", player_score, computer_score);
    }

    std::println("Final score - You: {}, Computer: {}", player_score, computer_score);
    std::println("Thanks for playing!");
}
