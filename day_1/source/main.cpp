#include "day_1.hpp"

int main(int argc, char *argv[]) {
  // TODO - implement input argument checking
  std::ifstream input_file(argv[1]);

  std::vector<std::string> contents_of_file;
  std::string line;
  while (getline(input_file, line)) {
    contents_of_file.push_back(line);
  }

  uint32_t calibration_value =
      part_1::calculate_calibration_values(contents_of_file);
  std::cout << calibration_value << std::endl;
  return 0;
}
