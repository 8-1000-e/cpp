// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

int main(void) {
    // Définition de types pour simplifier la lecture
    typedef std::vector<Account::t> accounts_t;
    typedef std::vector<int> ints_t;
    typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

    // 🔹 Initialisation des comptes avec des montants de départ
    int const amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
    size_t const amounts_size = sizeof(amounts) / sizeof(int);
    accounts_t accounts(amounts, amounts + amounts_size);
    
    accounts_t::iterator acc_begin = accounts.begin();
    accounts_t::iterator acc_end = accounts.end();

    // 🔹 Montants des dépôts
    int const deposits_data[] = {5, 765, 564, 2, 87, 23, 9, 20};
    size_t const deposits_size = sizeof(deposits_data) / sizeof(int);
    ints_t deposits(deposits_data, deposits_data + deposits_size);
    
    ints_t::iterator dep_begin = deposits.begin();
    ints_t::iterator dep_end = deposits.end();

    // 🔹 Montants des retraits
    int const withdrawals_data[] = {321, 34, 657, 4, 76, 275, 657, 7654};
    size_t const withdrawals_size = sizeof(withdrawals_data) / sizeof(int);
    ints_t withdrawals(withdrawals_data, withdrawals_data + withdrawals_size);
    
    ints_t::iterator wit_begin = withdrawals.begin();
    ints_t::iterator wit_end = withdrawals.end();

    // 🔹 Affichage des informations initiales des comptes
    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

    // 🔹 Traitement des dépôts
    for (acc_int_t it(acc_begin, dep_begin); 
         it.first != acc_end && it.second != dep_end;
         ++(it.first), ++(it.second)) 
    {
        (*(it.first)).makeDeposit(*(it.second));
    }

    // 🔹 Affichage après dépôts
    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

    // 🔹 Traitement des retraits
    for (acc_int_t it(acc_begin, wit_begin); 
         it.first != acc_end && it.second != wit_end;
         ++(it.first), ++(it.second)) 
    {
        (*(it.first)).makeWithdrawal(*(it.second));
    }

    // 🔹 Affichage après retraits
    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

    return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
