//
//  BankAccount.cpp
//  project 7
//
//  Created by Josh Sarath on 10/29/13.
//  Copyright (c) 2013 Josh Sarath. All rights reserved.
//

#include "BankAccount.h"
using namespace std;

void BankAccount::setCustomer(string firstName, string lastName)
/*
 this function establishes a customer first and last name based on the input parameters which are strings
 */
{
    custFirstName = firstName;
    custLastName = lastName;
}
void BankAccount::setAccountNumber(long number, char type)
/*
 this function sets the account number and type which can be used as a reference for the Account
 */
{
    accountNumber = number;
    accountType = type;
}
void BankAccount::setBalance(double money)
/*
 this function sets the initial balance of the account
 */
{
    balance = money;
}






string BankAccount::getCustomer()
/*
 this function returns the name of a the customer for the given BankAccount instance
 */
{
    string custName;
    custName = custFirstName + " " + custLastName;
    return custName;
}






long BankAccount::getAccountNumber()
{
    return accountNumber; //returns account number
}





double BankAccount::getBalance()
{
    return balance; // returns current balance
}




double BankAccount::withdraw(double amount)
{
    if (balance >= amount) //checks if sufficient funds
    {
        balance = balance - amount; //withdraws money from account
        cout<<"The new balance is $"<<balance <<".\n";
    }
    else
        cout<< "This account has insufficient funds.\n"; //message indicating withdrawal could not be completed
    return balance; // returns balacne
}




double BankAccount::deposit(double amount)
{
    if (amount >=0)//checks that not depositing a negative number
    {
        balance = balance + amount;//adds deposit to balance
        cout<<"The new balance is $"<<balance <<".\n";
    }
    else
        cout << "You may not deposit a negative number. \n"; //error message on transaction unable to be completed
    return balance;//returns balance
}






double BankAccount::transfer(BankAccount& fromAccount, double amount)
{
    if (balance>=amount) //tests if account has enough funds to transfer the money
    {
        fromAccount.withdraw(amount);//withdraws money from first account
        balance = balance + amount; //deposits money into current account
        cout<<"The new balance is $"<<balance <<".\n";
    }
    else
        cout<< "There are insufficient funds to complete this transfer. \n"; //error for not enough funds
    return balance; //returns balance
}

istream & operator >> (istream & is, BankAccount & ba)
{   //free function for extracting BankAccount objects
	//from input streams like this cin >> a;
	
	string lName, fName;
	long aNum;
	char aType;
	double aBalance;
	
	is >> lName >> fName >> aNum >> aType >> aBalance;
	is.ignore(72, '\n'); // flush anything else on the same line
    ba.setCustomer(lName, fName);
    ba.setAccountNumber(aNum, aType);
    ba.setBalance(aBalance);
	return is;
	//use member functions…
}

