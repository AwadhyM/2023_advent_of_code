#include "day_2.hpp"
#include <numeric>
#include <regex>
#include <sstream>
#include <utility>

using namespace puzzle;

std::string puzzle::extract_color(const std::string &dice_roll) {

  std::regex color_pattern(R"([a-zA-Z]+)");
  std::smatch m;

  std::regex_search(dice_roll, m, color_pattern);
  std::string color = m[0].str();

  if (color[0] == 'b') {
    return "blue";
  } else if (color[0] == 'r') {
    return "red";
  } else {
    return "green";
  }

  return color;
}

int puzzle::extract_number(const std::string &dice_roll) {
  std::regex num_pattern(R"(\d+)");
  std::smatch m;
  std::regex_search(dice_roll, m, num_pattern);
  std::string num = m[0].str();
  int number = std::stoi(num);
  return number;
}

std::pair<int, std::string>
puzzle::extract_dice_roll(const std::string &dice_roll) {

  int number = extract_number(dice_roll);
  std::string color = extract_color(dice_roll);

  std::pair<int, std::string> dice_roll_data = std::make_pair(number, color);
  return dice_roll_data;
}

bool part_1::round_valid(std::unordered_map<std::string, int> &mp) {
  return (mp["blue"] <= blue_max && mp["red"] <= red_max &&
          mp["green"] <= green_max);
}

uint32_t part_1::calculate_score_of_possible_games(
    std::vector<std::string> &file_contents) {
  uint16_t sum = 0;
  for (int i = 0; std::string & game : file_contents) {
    i++;
    std::string game_details = game.substr(game.find(":") + 1);
    std::stringstream ss(game_details);

    bool valid_game = true;
    while (std::getline(ss, game_details, ';') && valid_game) {
      std::regex pattern(R"((\d+)\s+([a-zA-Z]+))");
      std::sregex_iterator begin(game_details.begin(), game_details.end(),
                                 pattern);
      std::unordered_map<std::string, int> mp;
      for (std::sregex_iterator i = begin; i != std::sregex_iterator(); i++) {
        std::smatch m = *i;
        std::pair<int, std::string> dice_roll = extract_dice_roll(m.str());
        mp[dice_roll.second] += dice_roll.first;
        if (!round_valid(mp)) {
          valid_game = false;
          break;
        }
      }
    }
    if (valid_game) {
      sum += i;
    }
  }
  return sum;
}

uint32_t part_2::calculate_total_power_of_sets_of_cubes(
    std::vector<std::string> &file_contents) {
  uint32_t sum = 0;
  for (int i = 0; std::string & game : file_contents) {
    std::string game_details = game.substr(game.find(":") + 1);
    std::stringstream ss(game_details);

    std::regex pattern(R"((\d+)\s+([a-zA-Z]+))");
    std::sregex_iterator begin(game_details.begin(), game_details.end(),
                               pattern);

    std::unordered_map<std::string, int> mp;
    while (std::getline(ss, game_details, ';')) {
      for (std::sregex_iterator i = begin; i != std::sregex_iterator(); i++) {
        std::smatch m = *i;
        std::pair<int, std::string> dice_roll = extract_dice_roll(m.str());
        if (mp[dice_roll.second] < dice_roll.first) {
          mp[dice_roll.second] = dice_roll.first;
        }
      }
    }
    int product = 1;
    for (auto const &[key, val] : mp) {
      product *= val;
    }
    sum += product;
  }
  return sum;
}
