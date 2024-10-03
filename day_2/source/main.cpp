#include "day_2.hpp"
#include "utils.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::vector<std::string> file_contents =
      utils::retrieve_file_contents(std::string(argv[1]));
  uint32_t ans =
      puzzle::part_1::calculate_score_of_possible_games(file_contents);
  std::cout << ans << std::endl;
  return 0;
}
