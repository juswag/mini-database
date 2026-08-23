#include <iostream>
#include <string>
#include "kv/database.h"

using namespace std;

int main(int argc, char* argv[]){

   if (argc < 2){
     std::cout << "No command\n";
     return 0;
   }

   string command = argv[1];

    mini_database::Database data;

   if (command == "set"){
   }

   std::cout << "OK\n";

   return 0;
}
