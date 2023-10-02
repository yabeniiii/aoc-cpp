#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  if (argc <= 1 || argc > 2) {
    std::cerr << "Invalid number of arguments" << std::endl;
    return 1;
  }

  std::ifstream inputFile(argv[1]);

  if (!inputFile.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return 1;
  }

  std::vector<int> totals;
  std::string line;
  int current = 0;
  while (std::getline(inputFile, line)) {
    if (line.empty()) {
      totals.push_back(current);
      current = 0;
    } else {
      int number = std::stoi(line);
      current += number;
    }
  }
  totals.push_back(current);
  current = 0;

  inputFile.close();

  std::sort(totals.begin(), totals.end());

  std::cout << totals.back() << std::endl;
}
