#ifndef BANK_SERVICE_H
#define BANK_SERVICE_H

// ============================================================================
//  FILE        : bank_service.h
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Defines the bank service module and banking operations.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  In the original PF project, all account records were stored in global arrays
//  and all operations were written in one file.
//
//  In this refactored version, banking operations are grouped into a dedicated
//  service module. The UI does not directly manage the account array.
//
//  PRINCIPLES APPLIED
//  • Separation of Concerns
//      Account storage and banking operations are separated from console UI.
//
//  • Single Responsibility Principle
//      This module focuses only on banking operations.
//
//  • Maintainability
//      Add, search, deposit, withdraw, and report logic are centralized.
// ============================================================================

#include "account.h"

#define MAX_BANK_ACCOUNTS 100

typedef struct
{
    Account accounts[MAX_BANK_ACCOUNTS];
    int totalAccounts;
} BankService;

void BankService_init(BankService* service);

int BankService_createAccount(BankService* service, int accountNumber, const char* holderName, double openingBalance);
int BankService_deposit(BankService* service, int accountNumber, double amount);
int BankService_withdraw(BankService* service, int accountNumber, double amount);

Account*       BankService_findAccount(BankService* service, int accountNumber);
const Account* BankService_findAccountConst(const BankService* service, int accountNumber);

void   BankService_printAllAccounts(const BankService* service);
double BankService_getTotalBankBalance(const BankService* service);

#endif
