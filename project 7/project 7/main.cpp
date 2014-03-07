//
//  main.cpp
//  project 7
//
//  Created by Josh Sarath on 10/29/13.
//  Copyright (c) 2013 Josh Sarath. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "BankAccount.h"
using namespace std;

int main()
{
    // this section reads the file baccount2.txt and inputs the data into the array accounts
    ifstream file;
    BankAccount accounts[35];
    
    file.open("baccount2.txt");
    for(int i=0; i<35; i++)
    {
        file >> accounts[i];
    }
    
    
    //this section computes average and maximum account balance
    float a,b, max, average;
    long largestAccount;
    int counter;
    int customer;
    string name;
    
    customer = 35; //initialized to 35, will be reduced if names repeated
    counter =0; //counts number of accounts over $500
    b = 0;//running total of balance sum
    max = 0;//max account balance
    for(int i=0; i<35;i++)  //loops through accounts
    {
        a = accounts[i].getBalance();//gets balance of each item
        b= b+a;//creates a sum total
        
        if(a>max)//if statement to iteratively find maximum
        {
            max = a; //defines max if statement is true
            largestAccount = accounts[i].getAccountNumber(); //records account number of max balance
        }
        if (a>500) //tests if balance is over 500
            counter = counter +1; //counts number of accounts over $500
        
        /*
         this section of the code will test to see if names have already been used
         first it assigns a name in the initial loop above
         next it has a new for loop that will go from i+1 until 35
            this will test each name beyond the i in the overarching for loop
            for example in the 3rd iteration of the above loop, the new loop will test names 4 through 35 to see if names are repeated
         using an if statement, if a name is found later in the file, the variable customer (initialized to 35) will decrease by one, because this name was repeated
         if the name is not repeated the variable customer will not change
         
         this code will only work if we assume that there is no name repeated a third time
        */
        name = accounts[i].getCustomer();//name to iteratively test
        for (int j=i+1; j<35 ; j++) //new for loop that will test only names above accounts[i]
        {
            if (name == accounts[j].getCustomer())//tests whether name is a repeat
            {
                customer = customer - 1;//if repeat, reduce customer count
            }
            
        }
        
        
    }
    average=b/35;//total over number to get average
    cout<<"The average account balance is $"<<average<<".\n"; //reports account average
    cout<<"The largest account has $"<<max<<".\n"; //reports maximum balance
    cout<<"The account number of the account with the largest balance is "<<largestAccount<<".\n"; //reports account number with largest balance
    cout<<"The number of accounts with more than $500 is "<<counter<<"\n";
    cout<<"The number of distinct customers is "<<customer<<".\n";
}


