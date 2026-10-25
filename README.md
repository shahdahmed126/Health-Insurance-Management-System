# Health Insurance Management System

## Project Overview
A console-based application developed in C++ to manage patient information and health insurance plans.

## Features
- Add new patients and their insurance details.
- Display all active patients.
- Search for patients by name.
- Calculate total monthly insurance premiums.
- Delete patients (using a soft-delete flag).
- Update insurance plans and monthly premium amounts.
- Display statistics, including the number of active patients and average patient age.

## Technologies Used
- C++
- Arrays
- Functions
- Loops and conditional statements
- Console input/output

## How to Run
1. Download or clone this repository.
2. Open `main.cpp` in a C++ compiler or IDE.
3. Compile the program using a C++11-compatible compiler or newer.
4. Run the program and follow the menu options in the console.

Example compile command:

```bash
g++ main.cpp -o health_insurance
```

Then run it:

- Windows: `health_insurance.exe`
- Linux/macOS: `./health_insurance`

## Data Storage
Patient information is stored in arrays in memory. Data is not saved after the program exits.

## Notes
This is an educational project. It uses a fixed-size array with a maximum capacity of 100 patients.
