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

std::unordered_map<std::string, int> word_to_number{
    {"zero", 0}, {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"1", 1},    {"2", 2},   {"3", 3},     {"4", 4},     {"5", 5},
    {"6", 6},    {"7", 7},   {"8", 8},     {"9", 9}};

uint32_t part_2::calculate_calibration_values(
    std::vector<std::string> const &file_contents) {

  uint32_t sum = 0;
  for (std::string const &line : file_contents) {
    // store each digit in number or letter form in vector
    std::vector<uint8_t> numbers{};
    for (int window_start = 0; window_start < line.size(); window_start++) {
      int window_end = window_start;
      while (window_end <= line.size()) {
        if (word_to_number[line.substr(window_start,
                                       window_end - window_start)]) {
          numbers.push_back(word_to_number[line.substr(
              window_start, window_end - window_start)]);
          break;
        }
        window_end++;
      }
    }
    uint32_t first_digit = numbers.front();
    uint32_t last_digit = numbers.back();
    sum += (first_digit * 10) + last_digit;
  }

  return sum;
}
