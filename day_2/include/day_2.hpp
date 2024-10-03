#include <iostream>
#include <string>
#include <vector>

namespace puzzle {

namespace part_1 {

constexpr int red_max = 12;
constexpr int green_max = 13;
constexpr int blue_max = 14;

uint32_t
calculate_score_of_possible_games(std::vector<std::string> &file_contents);
std::pair<int, std::string> extract_dice_roll(const std::string &dice_roll);
bool round_valid(std::unordered_map<std::string, int> &mp);
std::string extract_color(const std::string &dice_roll);
int extract_number(const std::string &dice_roll);
} // namespace part_1

} // namespace puzzle
