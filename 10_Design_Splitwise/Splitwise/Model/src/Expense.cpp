#include "Expense.h"

namespace Splitwise::Model {
   Expense::Expense(int id, string desc, double amount, shared_ptr<User> creator, ExpenseType type)
      : expenseId(id), description(desc), totalAmount(amount), createdBy(creator), expenseType(type) {
   }
}