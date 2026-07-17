#include "account.h"

#include <stdio.h>
#include <string.h>

// ============================================================================
//  FILE        : account.c
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Implements account initialization, deposit, withdrawal, and
//                account display behavior.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  Account rules are separated from menu and storage logic. This keeps the
//  account module focused and reusable.
//
//  PRINCIPLES APPLIED
//  • Separation of Concerns
//      Account calculations are not mixed with menu handling.
//
//  • Defensive Programming
//      Invalid deposits and withdrawals are rejected before changing balance.
//
//  • Maintainability
//      Balance-related logic is centralized instead of repeated elsewhere.
// ============================================================================

void Account_init(Account* account, int accountNumber, const char* holderName, double openingBalance)
{
    if (account == NULL)
    {
        return;
    }

    account->accountNumber = accountNumber;
    strncpy(account->holderName, holderName, ACCOUNT_NAME_LENGTH - 1);
    account->holderName[ACCOUNT_NAME_LENGTH - 1] = '\0';
    account->balance = openingBalance;
}

int Account_deposit(Account* account, double amount)
{
    if (account == NULL || amount <= 0)
    {
        return 0;
    }

    account->balance += amount;
    return 1;
}

int Account_withdraw(Account* account, double amount)
{
    if (account == NULL || amount <= 0)
    {
        return 0;
    }

    if (account->balance < amount)
    {
        return 0;
    }

    account->balance -= amount;
    return 1;
}

void Account_print(const Account* account)
{
    if (account == NULL)
    {
        return;
    }

    printf("  Account Number : %d\n", account->accountNumber);
    printf("  Holder Name    : %s\n", account->holderName);
    printf("  Balance        : Rs. %.2f\n", account->balance);
}
