#include "day_1.hpp"
#include <algorithm>

char part_1::get_left_most_number_char(std::string &line) {
  for (const char &val : line) {
    if (std::isdigit(val)) {
      return val;
    }
  }
  return '0';
};

char part_1::get_right_most_number_char(std::string &line) {
  for (int i = line.size() - 1; i >= 0; i--) {
    if (std::isdigit(line[i])) {
      return line[i];
    }
  }
  return '0';
};

uint32_t part_1::convert_char_nums_to_number(char &val_1, char &val_2) {
  uint32_t first_digit = val_1 - '0';
  uint32_t second_digit = val_2 - '0';
  return (first_digit * 10) + second_digit;
}

uint32_t
part_1::calculate_calibration_values(std::vector<std::string> &file_contents) {
  int sum = 0;
  for (std::string line : file_contents) {
    char first_number = get_left_most_number_char(line);
    char second_number = get_right_most_number_char(line);
    uint32_t value = convert_char_nums_to_number(first_number, second_number);
    sum += value;
  }
  return sum;
}
