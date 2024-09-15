#include <fstream>
#include <iostream>
#include <vector>

namespace part_1 {
uint32_t calculate_calibration_values(std::vector<std::string> &file_contents);
char get_left_most_number_char(std::string &line);
char get_right_most_number_char(std::string &line);
uint32_t convert_char_nums_to_number(char &val_1, char &val_2);
} // namespace part_1
