#ifndef INPUT_READER_H
#define INPUT_READER_H

// ============================================================================
//  FILE        : input_reader.h
//  PROJECT     : BankVault - Bank Management System
//  CONTEXT     : Refactored from a previous Programming Fundamentals C project
//                for Software Construction and Development.
//  DESCRIPTION : Declares safe input reading and validation helpers.
//
//  SCD RELEVANCE
//  ─────────────────────────────────────────────────────────────────────────
//  In the original PF project, scanf was used directly inside every feature.
//  That made invalid input harder to handle and repeated input logic.
//
//  In this refactored version, input handling is centralized in one module.
//
//  PRINCIPLES APPLIED
//  • Single Responsibility Principle
//      This module focuses only on reading and validating user input.
//
//  • Reusability
//      The same functions are reused by multiple menu actions.
//
//  • Maintainability
//      Input rules can be updated from one place.
// ============================================================================

int  InputReader_readInt(const char* label, int* out);
int  InputReader_readDouble(const char* label, double* out);
void InputReader_readText(const char* label, char* buffer, int size);

int  InputReader_isPositiveAmount(double amount);
int  InputReader_isNonNegativeAmount(double amount);

#endif
