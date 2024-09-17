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

std::array<std::string, 10> part_2::words = {"zero",  "one",  "two", "three",
                                             "four",  "five", "six", "seven",
                                             "eight", "nine"};
std::unordered_map<std::string, int> word_to_number{
    {"zero", 0}, {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

bool part_2::is_substring_of_word(const std::string &str) {
  for (const std::string &number_word : part_2::words) {
    if (number_word.find(str) != std::string::npos) {
      return true;
    }
  }
  return false;
}

bool part_2::is_number(const std::string &word) {
  for (const std::string &number_word : part_2::words) {
    if (word == number_word) {
      return true;
    }
  }
  return false;
}

uint32_t part_2::calculate_calibration_values(
    std::vector<std::string> const &file_contents) {

  uint32_t sum = 0;

  for (std::string const &line : file_contents) {
    // store each digit in number or letter form in vector
    std::vector<uint8_t> numbers;
    std::string temp = "";
    // For every char in string
    for (int i = 0; i < line.size(); i++) {
      // If we have landed on a digit such as 1
      if (std::isdigit(line[i])) {
        numbers.push_back(line[i] - '0');
        temp = "";
        continue;
      }

      temp += line[i];
      int j = i;
      if (is_substring_of_word(temp)) {
        while (is_substring_of_word(temp)) {
          if (is_number(temp)) {
            numbers.push_back(word_to_number[temp]);
            break;
            i = j;
          }
          j++;
          temp += line[j];
        }
      }
      temp = "";
    }
    uint32_t first_digit = numbers.front();
    uint32_t last_digit = numbers.back();
    sum += (first_digit * 10) + last_digit;
  }

  return sum;
}
