#include "Group.h"

namespace Splitwise::Model {
   Group::Group(int id, string name, shared_ptr<User> adminUser)
      : groupId(id), groupName(name), admin(adminUser) {
   }
   void Group::addMember(shared_ptr<User> user) {
      members.push_back(user);
   }
   void Group::addExpense(shared_ptr<Expense> expense) {
      expenses.push_back(expense);
   }
}  
