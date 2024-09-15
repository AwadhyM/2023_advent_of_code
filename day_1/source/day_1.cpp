#include "day_1.hpp"
#include <ranges>

uint32_t part_1::calculate_calibration_values(
    std::vector<std::string> const &file_contents) {
  uint32_t sum = 0;
  for (std::string const &line : file_contents) {
    auto numbers{std::views::filter(line, [](char c) {
      if (std::isdigit(c))
        return c;
    })};
    uint8_t first_digit = numbers.front() - '0';
    uint8_t second_digit = numbers.back() - '0';
    uint8_t double_digit = (first_digit * 10) + second_digit;
    sum += double_digit;
  }
  return sum;
}
