#pragma once
#include <string>
#include "UserExpenseType.h"

namespace Splitwise::Model {
   class UserExpense {
      double amount;
      int userId;
      int expenseId;
      UserExpenseType userExpenseType;
   public:
      UserExpense(int userId, int expenseId, 
         double amount, UserExpenseType type);
   };
}