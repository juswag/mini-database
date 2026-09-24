#include <iostream>
#include <string>

using namespace std;

namespace mini_database {

class Database {
public:
  int set(const string key, const string value);
  int get(const string key);
  int add(const string key, const string value);
  int remove(const string key);
  int list();
};

} // namespace mini_database
