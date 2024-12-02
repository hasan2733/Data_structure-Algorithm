#include <bits/stdc++.h>
using namespace std;

class bank_account
{
  public:
    string name;
    int balance;
    
    void withdraw(int amount)
    {
      balance = balance - amount;
    }
    void print()
    {
      cout<<name <<" has "<<balance<<" dollars"<<endl;
    }
};

int main() 
{
   bank_account ac1,ac2;
   ac1.name="Abid";
   ac1.balance=1000;
   ac1.print();
   cout<<"ENTER THE DETAILS FOR ACCOUNT 2 "<<endl;
   cin>>ac2.name;
   cin>>ac2.balance;
   cout<<ac2.name <<" has "<<ac2.balance<<" dollars"<<endl;
   cout<<endl;
   ac2.withdraw(33);
   ac2.print();
   
   
}
