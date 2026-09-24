#include "database.h"
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;

namespace {

constexpr string database = "../data/database.txt";

}

/* Helper Functions */
ifstream openDatabase() {
  ifstream file(database);
  return file;
}

namespace mini_database {

int Database::get(const string key) {

  ifstream file = openDatabase();

  if (!file.is_open()) {
    std::cerr << "Error: Could not open the file." << std::endl;
    return 1;
  }

  string line;
  while (getline(file, line)) {

    const auto idx = line.find("=");

    if (idx == -1) {
      std::cout << "Error splitting line" << std::endl;
      return 1;
    }

    string cur_key = line.substr(0, idx);

    if (cur_key == key) {
      string value = line.substr(idx + 1);
      std::cout << value << std::endl;
      return 0;
    }
  }

  file.close();

  return 1;
};

int Database::set(const std::string key, const std::string value) {

  ifstream file = openDatabase();
  string line;

  ofstream replacement("../data/database.txt.tmp");

  while (getline(file, line)) {

    const auto idx = line.find("=");

    if (idx == -1) {
      std::cout << "Error splitting line" << std::endl;
      return 1;
    }

    string cur_key = line.substr(0, idx);
    string cur_value = line.substr(idx);

    if (cur_key == key) {
      replacement << cur_key + '=' + value << '\n';
    } else {
      replacement << cur_key + cur_value << '\n';
    }
  }

  replacement.close();
  file.close();

  filesystem::rename("../data/database.txt.tmp", database);

  return 0;
};

int Database::add(const string key, const string value) {

  ifstream read_file = openDatabase();

  if (!read_file.is_open()) {
    std::cerr << "Error opening the file" << std::endl;
    return 1;
  }

  string line;
  while (getline(read_file, line)) {

    const auto idx = line.find("=");

    if (idx == -1) {
      std::cout << "Error splitting line" << std::endl;
      return 1;
    }

    string cur_key = line.substr(0, idx);

    if (cur_key == key) {
      std::cout << "Error key already exists, try changing the value using SET"
                << std::endl;
      return 1;
    }
  }

  ofstream write_file(database, ios::app);

  if (!write_file) {
    return 1;
  }

  write_file << key + "=" + value << '\n';

  read_file.close();
  write_file.close();

  return 0;
};

int Database::remove(const string key) {

  ifstream read_file = openDatabase();
  ofstream replacement("../data/database.txt.tmp");

  if (!read_file.is_open()) {
    std::cerr << "Error opening the file" << std::endl;
    return 1;
  }

  string line;
  while (getline(read_file, line)) {

    const auto idx = line.find("=");

    if (idx == -1) {
      std::cout << "Error splitting line" << std::endl;
      return 1;
    }

    string cur_key = line.substr(0, idx);
    string cur_value = line.substr(idx);

    if (cur_key != key) {
      replacement << cur_key + cur_value << "\n";
    }
  }

  filesystem::rename("../data/database.txt.tmp", database);

  read_file.close();
  replacement.close();

  return 0;
};

int Database::list() {

  ifstream file(database);

  if (!file) {
    return 1;
  }

  std::cout << file.rdbuf();
  return 0;
}

} // namespace mini_database
