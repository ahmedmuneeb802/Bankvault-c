#include "input_reader.h"

#include <stdio.h>
#include <string.h>

// ============================================================================
//  FILE        : input_reader.c
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Implements safe input reading and validation helpers.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  This module replaces scattered scanf calls with reusable input helpers.
//  That makes the program safer and easier to maintain.
//
//  PRINCIPLES APPLIED
//  • Reusability
//      Common input reading logic is written once.
//
//  • Defensive Programming
//      Invalid input is cleared from the buffer instead of breaking the menu.
//
//  • Separation of Concerns
//      Input validation is not mixed directly with banking calculations.
// ============================================================================

static void clearInputBuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int InputReader_readInt(const char* label, int* out)
{
    if (label != NULL)
    {
        printf("%s", label);
    }

    if (scanf("%d", out) != 1)
    {
        clearInputBuffer();
        return 0;
    }

    clearInputBuffer();
    return 1;
}

int InputReader_readDouble(const char* label, double* out)
{
    if (label != NULL)
    {
        printf("%s", label);
    }

    if (scanf("%lf", out) != 1)
    {
        clearInputBuffer();
        return 0;
    }

    clearInputBuffer();
    return 1;
}

void InputReader_readText(const char* label, char* buffer, int size)
{
    if (label != NULL)
    {
        printf("%s", label);
    }

    if (buffer == NULL || size <= 0)
    {
        return;
    }

    if (fgets(buffer, size, stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

int InputReader_isPositiveAmount(double amount)
{
    return amount > 0;
}

int InputReader_isNonNegativeAmount(double amount)
{
    return amount >= 0;
}
