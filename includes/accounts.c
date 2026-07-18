
#ifndef ACCOUNT_H
#define ACCOUNT_H

// ============================================================================
//  FILE        : account.h
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Defines the Account structure and account-level operations.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  In the original PF project, account data was accessed and modified directly
//  from different functions in the same file. This made the program harder to
//  control and maintain.
//
//  In this refactored version, account-related behavior is grouped in one
//  module. The banking service can use these functions instead of manually
//  changing account fields everywhere.
//
//  PRINCIPLES APPLIED
//  • Single Responsibility Principle
//      This module focuses only on account data and account-level operations.
//
//  • Encapsulation in C-style design
//      C does not have classes, so related data and functions are grouped
//      through a struct and dedicated functions.
//
//  • Maintainability
//      If account rules change later, updates can be made in this module.
// ============================================================================

#define ACCOUNT_NAME_LENGTH 100

typedef struct
{
    int accountNumber;
    char holderName[ACCOUNT_NAME_LENGTH];
    double balance;
} Account;

void Account_init(Account* account, int accountNumber, const char* holderName, double openingBalance);
int  Account_deposit(Account* account, double amount);
int  Account_withdraw(Account* account, double amount);
void Account_print(const Account* account);

#endif
