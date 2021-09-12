#include <algorithm>
#include <array>
#include <iostream>
#include <random>

enum class CardRank {
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    jack,
    queen,
    king,
    ace,

    max_ranks
};

enum class CardSuit {
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits
};

struct Card {
    CardRank rank;
    CardSuit suit;
};

void printCard(const Card& card) {
    std::string suit_s{};
    std::string rank_s{};

    switch (card.rank) {
        case CardRank::rank_2:
            rank_s = "2";
            break;
        case CardRank::rank_3:
            rank_s = "3";
            break;
        case CardRank::rank_4:
            rank_s = "4";
            break;
        case CardRank::rank_5:
            rank_s = "5";
            break;
        case CardRank::rank_6:
            rank_s = "6";
            break;
        case CardRank::rank_7:
            rank_s = "7";
            break;
        case CardRank::rank_8:
            rank_s = "8";
            break;
        case CardRank::rank_9:
            rank_s = "9";
            break;
        case CardRank::rank_10:
            rank_s = "10";
            break;
        case CardRank::jack:
            rank_s = "J";
            break;
        case CardRank::queen:
            rank_s = "Q";
            break;
        case CardRank::king:
            rank_s = "K";
            break;
        case CardRank::ace:
            rank_s = "A";
            break;
        default:
            std::cout << "Error";
    }

    switch (card.suit) {
        case CardSuit::clubs:
            suit_s = "C";
            break;
        case CardSuit::diamonds:
            suit_s = "D";
            break;
        case CardSuit::hearts:
            suit_s = "H";
            break;
        case CardSuit::spades:
            suit_s = "S";
            break;
        default:
            std::cout << "Error";
    }

    std::cout << rank_s << suit_s << '\t';
}

std::array<Card, 52> createDeck() {
    std::array<Card, 52> deck{};
    std::array<Card, 52>::size_type in{};

    for (int i{}; i < static_cast<int>(CardSuit::max_suits); ++i) {
        for (int j{}; j < static_cast<int>(CardRank::max_ranks); ++j) {
            deck[in].suit = static_cast<CardSuit>(i);
            deck[in].rank = static_cast<CardRank>(j);
            ++in;
        }
    }
    return deck;
}

void printDeck(const std::array<Card, 52>& deck) {
    for (const Card& card : deck) {
        printCard(card);
    }
}

std::array<Card, 52> shuffleDeck(std::mt19937 gr, std::array<Card, 52>& deck) {
    std::shuffle(deck.begin(), deck.end(), gr);
    return deck;
}


int getCardValue(){
    // boring switch statement 2nd time. 
    // no need
}

int main() {
    std::array<Card, 52> deck{createDeck()};
    printDeck(deck);

    std::cout << '\n';

    std::random_device rd;
    std::mt19937 gr(rd());
    std::array<Card, 52> shuffledDeck{shuffleDeck(gr,deck)};
    printDeck(shuffledDeck);
    std::cout << '\n';

    return 0;
}

