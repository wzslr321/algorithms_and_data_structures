#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

void get_board(std::vector<std::vector<std::vector<int>>> &boards);
void scan(const std::vector<std::vector<std::vector<int>>> &boards,
          const std::vector<int> &marked, std::vector<int> &winners);
void print_boards(const std::vector<std::vector<std::vector<int>>> &boards);
int sum(const std::vector<std::vector<int>> &board,
        const std::vector<int> &marked);

int main() {
  std::string numbers_str;
  std::getline(std::cin, numbers_str);
  std::vector<int> numbers;
  std::stringstream ss(numbers_str);
  for (int i = 0; ss >> i;) {
    numbers.push_back(static_cast<int>(i));
    if (ss.peek() == ',') ss.ignore();
  }

  std::vector<std::vector<std::vector<int>>> boards;
  get_board(boards);
  print_boards(boards);
  std::vector<int> marked;
  int winner_board = -1;
  int last_drawn = -1;
  std::vector<int> winners;
  for (int i = 0; i < numbers.size(); ++i) {
    marked.push_back(numbers[i]);
    scan(boards, marked, winners);
    if (winners.size() >= boards.size()) {
      winner_board = winners[winners.size() - 1];
      last_drawn = marked[i];
      break;
    }
  }

  int unmarked_sum = sum(boards[winner_board], marked);

  int answer = unmarked_sum * last_drawn;

  std::cout << "\nSum: " << unmarked_sum << '\n';
  std::cout << "Winner board: " << winner_board << '\n';
  std::cout << "Last drawn: " << last_drawn << '\n';
  std::cout << "Answer: " << answer << '\n';

  return 0;
}

int sum(const std::vector<std::vector<int>> &board,
        const std::vector<int> &marked) {
  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      bool isCool = true;
      for (size_t y = 0; y < marked.size(); ++y) {
        if (board[i][j] == marked[y]) {
          isCool = false;
          break;
        }
      }
      if (isCool) sum += board[i][j];
    }
  }
  return sum;
}

void scan(const std::vector<std::vector<std::vector<int>>> &boards,
          const std::vector<int> &marked, std::vector<int> &winners) {
  for (int b = 0; b < boards.size(); ++b) {
    auto is_winner = std::find(winners.begin(), winners.end(), b);
    if (is_winner != std::end(winners)) continue;
    for (int i = 0; i < 5; ++i) {
      int match_row = 0;
      for (int j = 0; j < 5; ++j) {
        for (int z = 0; z < marked.size(); ++z) {
          if (boards[b][i][j] == marked[z]) ++match_row;
        }
      }
      if (match_row == 5) {
        // I don't like this part too, i hope my laziness will allow me to
        // refactor it later
        auto is_winner = std::find(winners.begin(), winners.end(), b);
        if (is_winner == std::end(winners)) winners.push_back(b);
      }
    }
    for (int i = 0; i < 5; ++i) {
      int match_column = 0;
      for (int j = 0; j < 5; ++j) {
        for (int z = 0; z < marked.size(); ++z) {
          if (boards[b][j][i] == marked[z]) ++match_column;
        }
      }
      if (match_column == 5) {
        auto is_winner = std::find(winners.begin(), winners.end(), b);
        if (is_winner == std::end(winners)) winners.push_back(b);
      }
    }
  }
}

void get_board(std::vector<std::vector<std::vector<int>>> &boards) {
  std::vector<std::vector<int>> board;
  for (int i = 0; i < 5; ++i) {
    std::vector<int> row(5);
    for (int j = 0; j < 5; ++j) {
      int num;
      std::cin >> num;
      if (num == 997) return;
      row[j] = num;
    }
    board.push_back(row);
  }
  boards.push_back(board);
  get_board(boards);
}

void print_boards(const std::vector<std::vector<std::vector<int>>> &boards) {
  for (size_t i = 0; i < boards.size(); ++i) {
    for (auto j = 0; j < 5; ++j) {
      for (auto y = 0; y < 5; ++y) {
        std::cout << boards[i][j][y] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }
}
