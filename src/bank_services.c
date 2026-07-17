#include "bank_service.h"

#include <stdio.h>

// ============================================================================
//  FILE        : bank_service.c
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Implements account storage and banking operations.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  This file contains the core business logic. UI input/output is mostly kept
//  outside this module, so banking rules can be changed without rewriting menu
//  code.
//
//  PRINCIPLES APPLIED
//  • Modularization
//      Banking operations are moved from one large file into a focused module.
//
//  • Maintainability
//      Search, create, deposit, withdraw, and report logic are organized here.
//
//  • Defensive Checks
//      Duplicate accounts, full storage, and invalid amounts are handled safely.
// ============================================================================

void BankService_init(BankService* service)
{
    if (service == NULL)
    {
        return;
    }

    service->totalAccounts = 0;
}

Account* BankService_findAccount(BankService* service, int accountNumber)
{
    if (service == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < service->totalAccounts; i++)
    {
        if (service->accounts[i].accountNumber == accountNumber)
        {
            return &service->accounts[i];
        }
    }

    return NULL;
}

const Account* BankService_findAccountConst(const BankService* service, int accountNumber)
{
    if (service == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < service->totalAccounts; i++)
    {
        if (service->accounts[i].accountNumber == accountNumber)
        {
            return &service->accounts[i];
        }
    }

    return NULL;
}

int BankService_createAccount(BankService* service, int accountNumber, const char* holderName, double openingBalance)
{
    if (service == NULL || holderName == NULL || openingBalance < 0)
    {
        return 0;
    }

    if (service->totalAccounts >= MAX_BANK_ACCOUNTS)
    {
        return 0;
    }

    if (BankService_findAccount(service, accountNumber) != NULL)
    {
        return 0;
    }

    Account_init(&service->accounts[service->totalAccounts], accountNumber, holderName, openingBalance);
    service->totalAccounts++;

    return 1;
}

int BankService_deposit(BankService* service, int accountNumber, double amount)
{
    Account* account = BankService_findAccount(service, accountNumber);

    if (account == NULL)
    {
        return 0;
    }

    return Account_deposit(account, amount);
}

int BankService_withdraw(BankService* service, int accountNumber, double amount)
{
    Account* account = BankService_findAccount(service, accountNumber);

    if (account == NULL)
    {
        return 0;
    }

    return Account_withdraw(account, amount);
}

void BankService_printAllAccounts(const BankService* service)
{
    if (service == NULL || service->totalAccounts == 0)
    {
        printf("  No accounts available.\n");
        return;
    }

    for (int i = 0; i < service->totalAccounts; i++)
    {
        printf("\n  Account #%d\n", i + 1);
        printf("  ------------------------------\n");
        Account_print(&service->accounts[i]);
    }
}

double BankService_getTotalBankBalance(const BankService* service)
{
    if (service == NULL)
    {
        return 0.0;
    }

    double total = 0.0;

    for (int i = 0; i < service->totalAccounts; i++)
    {
        total += service->accounts[i].balance;
    }

    return total;
}
