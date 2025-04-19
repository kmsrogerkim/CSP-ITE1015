#include <iostream>
#include "accounts.h"
using namespace std;

bool check_valid_indices(int id, AccountManager* account_manager)
{
    return (id >= 0 && id <= (*account_manager).getMaxID());
}

int main()
{
    AccountManager account_manager;

    while (1)
    {
        char inpt;

        cout << "Job?" << endl;
        cin >> inpt;

        if (inpt == 'N')
        {
            if (account_manager.createAccount())
            {
                cout << "Success!" << endl;
                account_manager.printAccount(account_manager.getMaxID());
                continue;
            }
            cout << "Failure!" << endl;
            continue;
        }
        else if (inpt == 'D')
        {
            int prim_id, ammount;
            cin >> prim_id >> ammount;

            if (!check_valid_indices(prim_id, &account_manager))
            {
                cout << "Failure!" << endl;
                continue;
            }

            if(!account_manager.deposit(prim_id, ammount)){
                cout << "Failure!" << endl;
                continue;
            }
            cout << "Success!" << endl;
            account_manager.printAccount(prim_id);
        }
        else if (inpt == 'W')
        {
            int prim_id, ammount;
            cin >> prim_id >> ammount;

            if (!check_valid_indices(prim_id, &account_manager))
            {
                cout << "Failure!" << endl;
                continue;
            }

            if(!account_manager.withdraw(prim_id, ammount)){
                cout << "Failure!" << endl;
                continue;
            }
            cout << "Success!" << endl;
            account_manager.printAccount(prim_id);
        }
        else if (inpt == 'T')
        {
            int prim_id, to_id, ammount;
            cin >> prim_id >> to_id >> ammount;

            if (!(check_valid_indices(prim_id, &account_manager) && check_valid_indices(to_id, &account_manager)))
            {
                cout << "Failure!" << endl;
                continue;
            }

            int small, big;
            if (prim_id > to_id)
            {
                small = to_id;
                big = prim_id;
            }
            else if (prim_id < to_id)
            {
                small = prim_id;
                big = to_id;
            }
            else
            {
                cout << "Failure!" << endl;
                continue;
            }

            if(!account_manager.transfer(prim_id, to_id, ammount)){
                cout << "Failure!" << endl;
            }
            else
            {
                cout << "Success!" << endl;
            }

            account_manager.printAccount(small);
            account_manager.printAccount(big);
            continue;
        }
        else if (inpt == 'Q')
        {
            return 0;
        }
    }
    return 0;
}
