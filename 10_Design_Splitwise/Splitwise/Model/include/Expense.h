#pragma once
#include <string>
#include <memory>
#include <vector>
#include <chrono>

#include "User.h"
#include "ExpenseType.h"
#include "UserExpense.h"

namespace Splitwise::Model {
   using namespace std;
   using namespace std::chrono;
   class Expense
   {
      int expenseId;
      string description;
      double totalAmount;
      time_point<system_clock> createdAt;
      shared_ptr<User> createdBy;
      ExpenseType expenseType;
      vector<shared_ptr<UserExpense>> userExpenses;
   public:
      Expense(int id, string desc, double amount, 
         shared_ptr<User> creator, ExpenseType type);
   };
}