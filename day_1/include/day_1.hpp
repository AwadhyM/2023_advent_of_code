#include <fstream>
#include <iostream>
#include <vector>

namespace part_1 {
uint32_t
calculate_calibration_values(std::vector<std::string> const &file_contents);
std::vector<uint8_t> get_numbers_found_in_string(std::string const &line);
} // namespace part_1
