#include "console_ui.h"
#include "input_reader.h"
#include "account.h"

#include <stdio.h>

// ============================================================================
//  FILE        : console_ui.c
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Implements the console-based menu and user interaction.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  This file owns the menu flow. It asks the user for input, validates it,
//  and delegates banking operations to BankService.
//
//  PRINCIPLES APPLIED
//  • Separation of Concerns
//      The UI does not manually store accounts or calculate balances.
//
//  • Maintainability
//      Menu actions are divided into small helper functions.
//
//  • Reusability
//      InputReader helpers are reused instead of repeating scanf logic.
// ============================================================================

static void printDivider(void)
{
    printf("  --------------------------------------------------\n");
}

static void printHeader(const char* title)
{
    printf("\n");
    printDivider();
    printf("  %s\n", title);
    printDivider();
}

static int showMenu(void)
{
    int choice;

    printf("\n");
    printDivider();
    printf("  BANKVAULT - BANK MANAGEMENT SYSTEM\n");
    printf("  Refactored PF Project | SCD Principles Applied\n");
    printDivider();
    printf("  1. Create new account\n");
    printf("  2. Deposit money\n");
    printf("  3. Withdraw money\n");
    printf("  4. Check balance\n");
    printf("  5. Display all accounts\n");
    printf("  6. Total bank balance report\n");
    printf("  7. Exit\n");
    printDivider();

    if (!InputReader_readInt("  Enter choice: ", &choice))
    {
        return -1;
    }

    return choice;
}

static void createAccount(BankService* bankService)
{
    int accountNumber;
    char holderName[ACCOUNT_NAME_LENGTH];
    double openingBalance;

    printHeader("CREATE NEW ACCOUNT");

    if (!InputReader_readInt("  Account number       : ", &accountNumber))
    {
        printf("  [ERROR] Invalid account number.\n");
        return;
    }

    InputReader_readText("  Account holder name  : ", holderName, ACCOUNT_NAME_LENGTH);

    if (holderName[0] == '\0')
    {
        printf("  [ERROR] Name cannot be empty.\n");
        return;
    }

    if (!InputReader_readDouble("  Opening balance      : Rs. ", &openingBalance) ||
        !InputReader_isNonNegativeAmount(openingBalance))
    {
        printf("  [ERROR] Opening balance must be zero or greater.\n");
        return;
    }

    if (BankService_createAccount(bankService, accountNumber, holderName, openingBalance))
    {
        printf("  [SUCCESS] Account created successfully.\n");
        return;
    }

    printf("  [ERROR] Account could not be created. It may already exist or storage may be full.\n");
}

static void depositMoney(BankService* bankService)
{
    int accountNumber;
    double amount;

    printHeader("DEPOSIT MONEY");

    if (!InputReader_readInt("  Account number  : ", &accountNumber))
    {
        printf("  [ERROR] Invalid account number.\n");
        return;
    }

    if (!InputReader_readDouble("  Deposit amount  : Rs. ", &amount) ||
        !InputReader_isPositiveAmount(amount))
    {
        printf("  [ERROR] Deposit amount must be greater than zero.\n");
        return;
    }

    if (BankService_deposit(bankService, accountNumber, amount))
    {
        printf("  [SUCCESS] Amount deposited successfully.\n");
        return;
    }

    printf("  [ERROR] Account not found.\n");
}

static void withdrawMoney(BankService* bankService)
{
    int accountNumber;
    double amount;

    printHeader("WITHDRAW MONEY");

    if (!InputReader_readInt("  Account number   : ", &accountNumber))
    {
        printf("  [ERROR] Invalid account number.\n");
        return;
    }

    if (!InputReader_readDouble("  Withdraw amount  : Rs. ", &amount) ||
        !InputReader_isPositiveAmount(amount))
    {
        printf("  [ERROR] Withdraw amount must be greater than zero.\n");
        return;
    }

    if (BankService_withdraw(bankService, accountNumber, amount))
    {
        printf("  [SUCCESS] Amount withdrawn successfully.\n");
        return;
    }

    printf("  [ERROR] Account not found or insufficient balance.\n");
}

static void checkBalance(const BankService* bankService)
{
    int accountNumber;

    printHeader("CHECK BALANCE");

    if (!InputReader_readInt("  Account number  : ", &accountNumber))
    {
        printf("  [ERROR] Invalid account number.\n");
        return;
    }

    const Account* account = BankService_findAccountConst(bankService, accountNumber);

    if (account == NULL)
    {
        printf("  [ERROR] Account not found.\n");
        return;
    }

    Account_print(account);
}

static void displayAllAccounts(const BankService* bankService)
{
    printHeader("ALL BANK ACCOUNTS");
    BankService_printAllAccounts(bankService);
}

static void showTotalBankBalance(const BankService* bankService)
{
    printHeader("TOTAL BANK BALANCE REPORT");
    printf("  Total balance across all accounts: Rs. %.2f\n",
           BankService_getTotalBankBalance(bankService));
}

void ConsoleUI_run(BankService* bankService)
{
    int running = 1;

    while (running)
    {
        int choice = showMenu();

        switch (choice)
        {
            case 1:
                createAccount(bankService);
                break;
            case 2:
                depositMoney(bankService);
                break;
            case 3:
                withdrawMoney(bankService);
                break;
            case 4:
                checkBalance(bankService);
                break;
            case 5:
                displayAllAccounts(bankService);
                break;
            case 6:
                showTotalBankBalance(bankService);
                break;
            case 7:
                printf("\n  Exiting BankVault. Goodbye.\n");
                running = 0;
                break;
            default:
                printf("  [ERROR] Invalid choice. Please enter a number from 1 to 7.\n");
        }
    }
}
