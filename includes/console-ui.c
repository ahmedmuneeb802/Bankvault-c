#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

// ============================================================================
//  FILE        : console_ui.h
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Declares the console UI workflow.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  In the original PF project, menu code and banking logic were written
//  together in main.c.
//
//  In this refactored version, the UI module handles menus and user interaction,
//  while BankService handles account operations.
//
//  PRINCIPLES APPLIED
//  • Separation of Concerns
//      UI workflow is separated from banking business logic.
//
//  • Single Responsibility Principle
//      This module focuses on console interaction only.
//
//  • Maintainability
//      Menu changes can be made here without touching account calculations.
// ============================================================================

#include "bank_service.h"

void ConsoleUI_run(BankService* bankService);

#endif
