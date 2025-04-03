#include "UserExpense.h"

namespace Splitwise::Model {
   UserExpense::UserExpense(int userId, int expenseId, double amount, UserExpenseType type)
      : userId(userId), expenseId(expenseId), amount(amount), userExpenseType(type) {
   }
}