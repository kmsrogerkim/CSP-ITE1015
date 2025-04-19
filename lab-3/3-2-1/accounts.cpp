#include "accounts.h"
#include <iostream>

void Account::setID(int id)
{
    _id = id;
}

void Account::setBalance(int amount)
{
    _balance = amount;
}

bool Account::deposit(int amount)
{
    if ((amount + _balance) > 1000000 || (amount + _balance) < 0)
    {
        return 0;
    }
    _balance = amount + _balance;

    return 1;
}

bool Account::withdraw(int amount)
{
    if ((_balance - amount) < 0)
    {
        return 0;
    }
    _balance = _balance - amount;

    return 1;
}

int Account::getID()
{
    return _id;
}

int Account::getBalance()
{
    return _balance;
}


// ACCOUNT MANAGER-------------------------------------------------------------

bool AccountManager::createAccount()
{
    if (num_accounts == 9)
    {
        return 0;
    }
    Account new_account;
    num_accounts += 1;

    new_account.setID(num_accounts);
    new_account.setBalance(0);

    accounts[num_accounts] = new_account;

    return 1;
}

bool AccountManager::deposit(int _id, int amount)
{
    return accounts[_id].deposit(amount);
}

bool AccountManager::withdraw(int _id, int amount)
{
    return accounts[_id].withdraw(amount);
}

bool AccountManager::transfer(int from, int to, int amount)
{
    Account* from_account = &accounts[from];
    Account* to_account = &accounts[to];

   return ((*from_account).withdraw(amount) && (*to_account).deposit(amount));
}

void AccountManager::printAccount(int _id)
{
    std::cout << "Balance of user" << _id << ":" << accounts[_id].getBalance() << std::endl;
}

int AccountManager::getMaxID()
{
    return num_accounts;
}

// void AccountManager::printAccounts()
// {
//     for (int i=0; i<=num_accounts; i++){
//         std::cout << i << " " << accounts[i].getBalance() << std::endl;
//     }
// }