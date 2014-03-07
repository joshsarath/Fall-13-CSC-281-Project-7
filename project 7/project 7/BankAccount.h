//
//  BankAccount.h
//  project 7
//
//  Created by Josh Sarath on 10/29/13.
//  Copyright (c) 2013 Josh Sarath. All rights reserved.
//

#ifndef project_7_BankAccount_h
#define project_7_BankAccount_h


#include <iostream>
using namespace std;

class BankAccount
{
private:
    long accountNumber;
    string custLastName;
    string custFirstName;
    char accountType;
    double balance;
public:
    void setCustomer(string, string);
    void setAccountNumber(long, char);
    void setBalance(double);
    string getCustomer();
    long getAccountNumber();
    double getBalance();
    double withdraw(double);
    double deposit(double);
    double transfer(BankAccount&, double);
    
};
istream & operator >> (istream &, BankAccount &);

#endif
