
#ifndef CREDITCARD_H_
#define CREDITCARD_H_

#include <string>					// provides string
#include <iostream>					// provides ostream

class CreditCard {
public:
  CreditCard(const std::string& no,	// constructor
  	const std::string& nm, int lim, double bal=0);
  									// accessor functions
  std::string   getNumber() const	{ return number; }
  std::string   getName() const		{ return name; }
  double   	getBalance() const	{ return balance; }
  int      	getLimit() const	{ return limit; }
  double    getInterest() const { return interestRate;}
  // add these new modifier functions in the public section : Exercise R-1.15

  void setBalance(double newBalance);      // 잔액 변경
  void setLimit(int newLimit);             // 한도 변경
  void setInterestRate(double newRate);    // 이자율 변경

    // 기존 기능
  bool chargeIt(double price);  // 결제
  void makePayment(double payment); // 대금 납부

  bool chargeIt(double price); 		// make a charge
  void makePayment(double payment);	// make a payment
private:                           	// private member data
  std::string   number;				// credit card number
  std::string   name;				// card owner's name
  int       	limit;				// credit limit
  double    	balance;			// credit card balance
  double        interestRate;
};
  									// print card information
std::ostream& operator<<(std::ostream& out, const CreditCard& c);

#endif /* CREDITCARD_H_ */
