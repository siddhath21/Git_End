#include <iostream>

using namespace std;

class bank {
    char name[100], add[100], y;
    int balance;

public:
    void open_account();
    void deposite_money();
    void withdraw_money();
    void display_account();
};

void bank::open_account() {
    cout << "enter your Full name: ";
    cin.ignore();
    cin.getline(name, 100);
    cout << "Enter your Address: ";
    cin.getline(add, 100);
    cout << "What type of account you want to open saving(s) or current (c): ";
    cin >> y;
    cout << "Enter amount to be deposited: ";
    cin >> balance;
    cout << "Your account is created\n";
}

void bank::deposite_money() {
    int a;
    cout << "Enter Money to deposit: ";
    cin >> a;
    balance += a;
    cout << "Total amount after deposit: " << balance << endl;
}

void bank::display_account() {
    cout << "Your full name: " << name << endl;
    cout << "Your address: " << add << endl;
    cout << "Type of account you opened: " << y << endl;
    cout << "Current Balance: " << balance << endl;
}

void bank::withdraw_money() {
    int b;
    cout << "Enter money to be Withdraw: ";
    cin >> b;
    if (b > balance) {
        cout << "Insufficient Amount. Enter 1 to withdraw again or 2 to exit: ";
        int a;
        cin >> a;
        switch (a) {
            case 1: {
                withdraw_money();
                break; // Don't forget to add break statement.
            }
            case 2: {
                return; // Exit from the function instead of continuing with withdrawal.
            }
            default: {
                cout << "Invalid option. Exiting withdrawal.\n";
                return;
            }
        }
    } else {
        cout << "Withdrawal Successful\n";
        balance -= b;
    }
}

int main() {
    char ch,x;
    bank obj;
    do {
        cout << "1) Open account\n";
        cout << "2) Deposit money\n";
        cout << "3) Withdraw money\n";
        cout << "4) Display account\n";
        cout << "5) Exit\n";
        cout << "Select the option from above: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                obj.open_account();
                break;
            }
            case 2: {
                obj.deposite_money();
                break;
            }
            case 3: {
                obj.withdraw_money();
                break;
            }
            case 4: {
                obj.display_account();
                break;
            }
            case 5: {
                cout << "Exiting the program.\n";
                break;
            }
            default: {
                cout << "Invalid option. Try again.\n";
            }
        }

        cout << "Do you want to select the next option then press :: Y: ";
        cout << "Do you want to exit then press :: N: ";
        cin>>x;

        if(x=='n'||x=='N') exit(0);
    } while (x == 'y' || x == 'Y');
    cout<<" Thanks for using our services "<<endl;
    return 0;
}