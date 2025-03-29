#pragma once

namespace BookMyShow::Common {

   enum class PaymentMode {
      CREDIT_CARD,
      DEBIT_CARD,
      NET_BANKING,
      UPI,
      WALLET,
      CASH
   };
}
