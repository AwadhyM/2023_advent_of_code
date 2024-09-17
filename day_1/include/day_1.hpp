#include <array>
#include <fstream>
#include <iostream>
#include <vector>

namespace part_1 {
uint32_t
calculate_calibration_values(std::vector<std::string> const &file_contents);
} // namespace part_1

namespace part_2 {

extern std::array<std::string, 10> words;

uint32_t
calculate_calibration_values(std::vector<std::string> const &file_contents);
bool is_substring_of_word(const std::string &str);
bool is_number(const std::string &word);
} // namespace part_2
