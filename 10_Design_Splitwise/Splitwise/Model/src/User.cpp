#include "User.h"

namespace Splitwise::Model {
   User::User(int id, string name, string phone, string password)
      : userId(id), name(name), phoneNumber(phone), encryptedPassword(password)
   {
   }
}