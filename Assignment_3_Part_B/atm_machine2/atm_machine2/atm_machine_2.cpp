#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

// Global variables to store user's menu selection, bank accounts, and balances
char menuInput;
unordered_map<string, string> accounts;  // Stores user id and password
unordered_map<string, double> balances;  // Stores user id and balance
string currentUser = "";

// Main function
int main() {
    cout << "Hi! Welcome to Mr. Zamar’s ATM Machine!" << endl;
    start();
    return 0;
}

// Function to display the introduction menu
void printIntroMenu() {
    cout << "\nPlease select an option from the menu below:" << endl;
    cout << "l  -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

// Function to display the main banking menu
void printMainMenu() {
    cout << "\nd  -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r  -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

// Function to handle the initial menu options
void start() {
    while (true) {
        printIntroMenu();
        cin >> menuInput;
        switch (menuInput) {
        case 'l':
            login();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            exit(0);
            break;
        default:
            cout << "Invalid option, please try again." << endl;
        }
    }
}

// Function to create a new account
void createAccount() {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    // Check if account already exists
    if (accounts.find(userId) == accounts.end()) {
        accounts[userId] = password;
        balances[userId] = 0.0;  // Initial balance is zero
        cout << "Thank You! Your account has been created!" << endl;
    }
    else {
        cout << "Account already exists with this user id!" << endl;
    }
}

// Function to handle login
void login() {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    // Verify login credentials
    if (accounts.find(userId) != accounts.end() && accounts[userId] == password) {
        cout << "Access Granted!" << endl;
        currentUser = userId;
        while (true) {
            printMainMenu();
            cin >> menuInput;
            if (menuInput == 'd') {
                double depositAmount;
                cout << "Amount of deposit: $";
                cin >> depositAmount;
                balances[currentUser] += depositAmount;
            }
            else if (menuInput == 'w') {
                double withdrawAmount;
                cout << "Amount of withdrawal: $";
                cin >> withdrawAmount;
                if (withdrawAmount > balances[currentUser]) {
                    cout << "Insufficient funds!" << endl;
                }
                else {
                    balances[currentUser] -= withdrawAmount;
                }
            }
            else if (menuInput == 'r') {
                cout << "Your balance is $" << balances[currentUser] << "." << endl;
            }
            else if (menuInput == 'q') {
                cout << "Thanks for stopping by!" << endl;
                break;
            }
            else {
                cout << "Invalid option, please try again." << endl;
            }
        }
    }
    else {
        cout << "******** LOGIN FAILED! ********" << endl;
    }
}

