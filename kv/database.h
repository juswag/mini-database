#include <iostream>

namespace mini_database{

class Database{
  public: 
    void set(const std::string key, const std::string value);
    int get(const std::string key);
    void remove(const std::string key);
    void list();
};

}

