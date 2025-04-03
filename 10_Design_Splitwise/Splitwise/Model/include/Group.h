#include <string>
#include <memory>
#include <vector>
#include "User.h"
#include "Expense.h"

namespace Splitwise::Model {
   using namespace std;
   class Group {
      int groupId;
      string groupName;
      shared_ptr<User> admin;
      vector<shared_ptr<User>> members;
      vector<shared_ptr<Expense>> expenses;
   public:
      Group(int id, string name, shared_ptr<User> adminUser);
      void addMember(shared_ptr<User> user);
      void addExpense(shared_ptr<Expense> expense);
   };
}