#pragma once
#include <string>
using namespace std;

namespace Splitwise::Model {
   class User {
      int userId;
      string name;
      string phoneNumber;
      string encryptedPassword;
   public:
      User(int id, string name, string phone, string password);
   };
}
