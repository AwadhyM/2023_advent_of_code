#include "day_1.hpp"
#include "utils.hpp"

int main(int argc, char *argv[]) {
  // TODO - implement input argument checking
  std::string file_path(argv[1]);
  std::vector<std::string> contents_of_file =
      utils::retrieve_file_contents(file_path);
  uint32_t calibration_value =
      part_1::calculate_calibration_values(contents_of_file);
  std::cout << calibration_value << std::endl;

  uint32_t part_2_ans = part_2::calculate_calibration_values(contents_of_file);
  std::cout << part_2_ans << std::endl;
  return 0;
}
