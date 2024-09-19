#include "utils.hpp"
#include <fstream>

std::vector<std::string> retrieve_file_contents(std::string const &file_path) {
  std::ifstream input_file(file_path);
  std::string line;

  std::vector<std::string> file_contents;
  while (getline(input_file, line)) {
    file_contents.push_back(line);
  }

  return file_contents;
}
