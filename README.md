BankVault - Bank Management System
Refactored C Project for Software Construction and Development

This project was refactored from an old Programming Fundamentals semester project.
The old version was a single C file with global arrays, direct scanf/printf handling,
and all banking operations written together.

The refactored version keeps the project in C, but improves its construction quality
using SCD principles.

Folder Structure:

BankVault_SCD_Refactor_C
|
|-- include
|   |-- account.h
|   |-- bank_service.h
|   |-- input_reader.h
|   |-- console_ui.h
|
|-- src
|   |-- account.c
|   |-- bank_service.c
|   |-- input_reader.c
|   |-- console_ui.c
|   |-- main.c
|
|-- .vscode
|   |-- tasks.json
|
|-- README.txt

Main Refactoring Improvements:

1. The old single-file program is separated into multiple files.
2. Account data is managed through account.h/account.c.
3. Banking operations are handled in bank_service.h/bank_service.c.
4. Input validation is centralized in input_reader.h/input_reader.c.
5. Menu and console interaction are handled in console_ui.h/console_ui.c.
6. main.c is kept small and only starts the application.
7. Duplicate account numbers are prevented.
8. Negative deposits and withdrawals are rejected.
9. Balance checking, deposit, withdrawal, and account creation are cleaner.

SCD Concepts Demonstrated:

- Modularization
- Separation of Concerns
- Single Responsibility Principle
- Maintainability
- Reusability
- Defensive input validation
- Cleaner program structure

How to Compile:

gcc -std=c11 -Wall -Wextra src/main.c src/account.c src/bank_service.c src/input_reader.c src/console_ui.c -Iinclude -o BankVault.exe

How to Run in CMD:

BankVault.exe

How to Run in PowerShell:

.\BankVault.exe

Presentation Summary:

I selected an old Bank Management System made in C during Programming Fundamentals.
The old program was functional, but all logic was placed in one file. For SCD, I
refactored it into multiple modules. This improved readability, maintainability,
reusability, and separation of responsibilities.
