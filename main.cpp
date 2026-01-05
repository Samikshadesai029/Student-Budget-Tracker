#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void addExpense() {
    string item;
    double cost;
    ofstream outFile("budget.txt", ios::app);

    cout << "\nEnter item name: ";
    cin.ignore();
    getline(cin, item);
    cout << "Enter cost: ";
    cin >> cost;

    outFile << item << " " << cost << endl;
    outFile.close();
    cout << "Success! Saved to database.\n";
}

void viewTotal() {
    string item;
    double cost;
    double total = 0;
    ifstream inFile("budget.txt");

    cout << "\n--- Expense History ---" << endl;
    while (inFile >> item >> cost) {
        cout << "- " << item << ": $" << fixed << setprecision(2) << cost << endl;
        total += cost;
    }
    inFile.close();
    cout << "-----------------------" << endl;
    cout << "TOTAL SPENT: $" << total << endl;
}

int main() {
    int choice;

    do {
        cout << "\n== Engineering Budget Menu ==";
        cout << "\n1. Add Expense";
        cout << "\n2. View History & Total";
        cout << "\n3. Exit";
        cout << "\nSelect an option: ";
        cin >> choice;

        if (choice == 1) addExpense();
        else if (choice == 2) viewTotal();

    } while (choice != 3);

    cout << "Program exited. Great work today!" << endl;
    return 0;
}
