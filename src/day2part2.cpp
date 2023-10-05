#include <fstream>
#include <iostream>
#include <string>

#define ROCK_SCORE 1
#define PAPER_SCORE 2
#define SCISSORS_SCORE 3

#define WIN_SCORE 6
#define DRAW_SCORE 3
#define LOSS_SCORE 0

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Incorrect number of arguments" << std::endl;
    return 1;
  }

  std::ifstream inputFile(argv[1]);

  if (!inputFile.is_open()) {
    std::cerr << "Couldn't open input file" << std::endl;
    return 1;
  }

  std::string line;
  unsigned int score = 0;
#pragma unroll
  while (std::getline(inputFile, line)) {
    if (line == "A X") {
      score += SCISSORS_SCORE + LOSS_SCORE;
    } else if (line == "B X") {
      score += ROCK_SCORE + LOSS_SCORE;
    } else if (line == "C X") {
      score += PAPER_SCORE + LOSS_SCORE;
    } else if (line == "A Y") {
      score += ROCK_SCORE + DRAW_SCORE;
    } else if (line == "B Y") {
      score += PAPER_SCORE + DRAW_SCORE;
    } else if (line == "C Y") {
      score += SCISSORS_SCORE + DRAW_SCORE;
    } else if (line == "A Z") {
      score += PAPER_SCORE + WIN_SCORE;
    } else if (line == "B Z") {
      score += SCISSORS_SCORE + WIN_SCORE;
    } else if (line == "C Z") {
      score += ROCK_SCORE + WIN_SCORE;
    } else {
      std::cerr << "invalid input" << std::endl;
      return 1;
    }
  }

  std::cout << "score: " << score << std::endl;

  return 0;
}
