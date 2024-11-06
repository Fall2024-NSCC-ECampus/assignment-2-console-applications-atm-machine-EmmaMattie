#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function prototypes
void printIntroMenu();
void start();
void login();
void createAccount();

// Global variables to store user's menu selection and bank accounts
char menuInput;
unordered_map<string, string> accounts; // Stores user id and password

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
        // Part B will handle the next steps (e.g., deposit, withdraw, request balance)
    }
    else {
        cout << "******** LOGIN FAILED! ********" << endl;
    }
}