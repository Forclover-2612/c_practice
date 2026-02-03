#include<iostream>
using namespace std;

class Account{
    public:
    void deposit(double money)
    {
        balance+=money;
    }
    private:
    double balance;
};

int main()
{
    Account myAcc;
    myAcc.deposit(100);
    // myAcc.balance=10000;
    return 0;
}