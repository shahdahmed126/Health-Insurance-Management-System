#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

const int MAX_PATIENTS = 100;

string patientNames[MAX_PATIENTS];
int patientAges[MAX_PATIENTS];
string patientPlans[MAX_PATIENTS];
double patientPremiums[MAX_PATIENTS];
bool patientActive[MAX_PATIENTS];
int totalPatients = 0;

void addPatient() {
    if (totalPatients >= MAX_PATIENTS) {
        cout << "Patient limit reached. Cannot add more patients.\n";
        return;
    }

    cout << "\n=== Add New Patient ===\n";
    cout << "Enter patient name: ";
    getline(cin >> ws, patientNames[totalPatients]);

    cout << "Enter patient age: ";
    if (!(cin >> patientAges[totalPatients]) ||
        patientAges[totalPatients] < 0) {
        cout << "Invalid age. Please enter a non-negative number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter insurance plan (Basic/Premium/Gold): ";
    cin >> patientPlans[totalPatients];

    cout << "Enter monthly premium: ";
    if (!(cin >> patientPremiums[totalPatients]) ||
        patientPremiums[totalPatients] < 0) {
        cout << "Invalid premium. Please enter a non-negative amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    patientActive[totalPatients] = true;
    totalPatients++;
    cout << "Patient added successfully!\n";
}

void displayPatients() {
    cout << "\n=== All Active Patients ===\n";
    bool found = false;

    for (int i = 0; i < totalPatients; i++) {
        if (patientActive[i]) {
            found = true;
            cout << "\nPatient #" << i + 1 << '\n';
            cout << "Name: " << patientNames[i] << '\n';
            cout << "Age: " << patientAges[i] << '\n';
            cout << "Plan: " << patientPlans[i] << '\n';
            cout << "Monthly premium: $" << fixed << setprecision(2)
                 << patientPremiums[i] << '\n';
        }
    }

    if (!found) {
        cout << "No active patients found.\n";
    }
}

void searchPatient() {
    string searchName;
    cout << "Enter patient name to search: ";
    getline(cin >> ws, searchName);

    for (int i = 0; i < totalPatients; i++) {
        if (patientNames[i] == searchName && patientActive[i]) {
            cout << "\nPatient found!\n";
            cout << "Name: " << patientNames[i] << '\n';
            cout << "Age: " << patientAges[i] << '\n';
            cout << "Plan: " << patientPlans[i] << '\n';
            cout << "Monthly premium: $" << fixed << setprecision(2)
                 << patientPremiums[i] << '\n';
            return;
        }
    }

    cout << "Patient not found!\n";
}

void calculateTotalPremiums() {
    double total = 0.0;

    for (int i = 0; i < totalPatients; i++) {
        if (patientActive[i]) {
            total += patientPremiums[i];
        }
    }

    cout << "Total monthly premiums: $" << fixed << setprecision(2)
         << total << '\n';
}

void deletePatient() {
    string deleteName;
    cout << "Enter patient name to delete: ";
    getline(cin >> ws, deleteName);

    for (int i = 0; i < totalPatients; i++) {
        if (patientNames[i] == deleteName && patientActive[i]) {
            patientActive[i] = false;
            cout << "Patient deleted successfully!\n";
            return;
        }
    }

    cout << "Patient not found!\n";
}

void updatePatient() {
    string updateName;
    cout << "Enter patient name to update: ";
    getline(cin >> ws, updateName);

    for (int i = 0; i < totalPatients; i++) {
        if (patientNames[i] == updateName && patientActive[i]) {
            cout << "Enter new insurance plan (Basic/Premium/Gold): ";
            cin >> patientPlans[i];

            cout << "Enter new monthly premium: ";
            if (!(cin >> patientPremiums[i]) || patientPremiums[i] < 0) {
                cout << "Invalid premium. Update cancelled.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }

            cout << "Patient information updated!\n";
            return;
        }
    }

    cout << "Patient not found!\n";
}

void displayStatistics() {
    int activePatients = 0;
    int totalAge = 0;

    for (int i = 0; i < totalPatients; i++) {
        if (patientActive[i]) {
            activePatients++;
            totalAge += patientAges[i];
        }
    }

    cout << "\n=== Insurance Statistics ===\n";
    cout << "Total active patients: " << activePatients << '\n';

    if (activePatients > 0) {
        cout << "Average patient age: "
             << static_cast<double>(totalAge) / activePatients << '\n';
    } else {
        cout << "Average patient age: N/A\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n=== Health Insurance Management System ===\n";
        cout << "1. Add Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Calculate Total Premiums\n";
        cout << "5. Delete Patient\n";
        cout << "6. Update Patient Information\n";
        cout << "7. Display Statistics\n";
        cout << "8. Exit\n";
        cout << "Enter your choice (1-8): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 8.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
            case 4: calculateTotalPremiums(); break;
            case 5: deletePatient(); break;
            case 6: updatePatient(); break;
            case 7: displayStatistics(); break;
            case 8: cout << "Thank you for using the system!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
