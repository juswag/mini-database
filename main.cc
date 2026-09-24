#include "kv/database.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "No command\n";
    return 0;
  }

  string command = argv[1];

  mini_database::Database data;

  if (command == "get" && argc == 3) {
    string key = argv[2];
    int res = data.get(key);

    if (res == 1) {
      std::cout << "Failed to GET" << '\n';
      return 1;
    }

  } else if (command == "set" && argc == 4) {
    string key = argv[2];
    string new_value = argv[3];

    int res = data.set(key, new_value);

    if (res == 1) {
      std::cout << "Failed to SET" << '\n';
      return 1;
    }

  } else if (command == "add" && argc == 4) {

    string new_key = argv[2];
    string new_value = argv[3];

    int res = data.add(new_key, new_value);

    if (res == 1) {
      std::cout << "Failed to ADD" << '\n';
      return 1;
    }

  } else if (command == "remove" && argc == 3) {

    string key = argv[2];

    int res = data.remove(key);

    if (res == 1) {
      std::cout << "Failed to REMOVE" << '\n';
      return 1;
    }

  } else if (command == "list" && argc == 2) {

    int res = data.list();
    if (res == 1) {
      std::cout << "Failed to LIST" << '\n';
      return 1;
    }

  } else {
    std::cout << "Wrong command OR missing parameters" << '\n';
    return 1;
  }

  std::cout << "OK\n";
  return 0;
}
