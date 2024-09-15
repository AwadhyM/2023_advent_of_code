#include "day_1.hpp"

std::vector<uint8_t>
part_1::get_numbers_found_in_string(std::string const &line) {
  std::vector<uint8_t> numbers;

  for (const auto &c : line) {
    if (std::isdigit(c)) {
      numbers.push_back(c - '0');
    }
  }
  return numbers;
}

uint32_t part_1::calculate_calibration_values(
    std::vector<std::string> const &file_contents) {
  uint32_t sum = 0;
  for (std::string const &line : file_contents) {
    std::vector<uint8_t> numbers = get_numbers_found_in_string(line);
    uint8_t first_digit = numbers.front();
    uint8_t second_digit = numbers.back();
    uint8_t double_digit = (first_digit * 10) + second_digit;
    sum += double_digit;
  }
  return sum;
}
