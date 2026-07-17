#include "bank_service.h"
#include "console_ui.h"

// ============================================================================
//  FILE        : main.c
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Application entry point.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  In the original PF project, main() contained the complete menu loop and
//  directly called all banking functions.
//
//  In this refactored version, main() is intentionally small. It creates the
//  bank service and starts the console UI.
//
//  PRINCIPLES APPLIED
//  • Separation of Concerns
//      main.c starts the program, console_ui.c handles user flow, and
//      bank_service.c handles banking operations.
//
//  • Maintainability
//      A small main function is easier to understand and safer to modify.
// ============================================================================

int main(void)
{
    BankService bankService;

    BankService_init(&bankService);
    ConsoleUI_run(&bankService);

    return 0;
}
