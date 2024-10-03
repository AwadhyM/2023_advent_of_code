#include <iostream>
#include <string>
#include <vector>

namespace puzzle {
std::string extract_color(const std::string &dice_roll);
int extract_number(const std::string &dice_roll);
std::pair<int, std::string> extract_dice_roll(const std::string &dice_roll);

namespace part_1 {

constexpr int red_max = 12;
constexpr int green_max = 13;
constexpr int blue_max = 14;

uint32_t
calculate_score_of_possible_games(std::vector<std::string> &file_contents);
bool round_valid(std::unordered_map<std::string, int> &mp);
} // namespace part_1

namespace part_2 {
uint32_t
calculate_total_power_of_sets_of_cubes(std::vector<std::string> &file_contents);
}

} // namespace puzzle
