// BalanceAndInterest.cpp
// Andre Freitas
// This code is used to check the interest that will be earned over a chosen period of time both with additional monthly deposits and without





#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//Calls the h file
#include "BalanceAndInterest.h"

//sets the invest variable
void InterestAndBalance::SetInvest(double initial) {
    invest = initial;
}
//Gets the invest variable
double InterestAndBalance::GetInvest() {
    return invest;
}
//sets the deposit variable
void InterestAndBalance::SetDeposit(double dep) {
    deposit = dep;
}
//gets the deposit variable
double InterestAndBalance::GetDeposit() {
    return deposit;
}
//sets the interest variable
void InterestAndBalance::SetInterest(double intr) {
    interest = intr;
}
//gets the interest variable
double InterestAndBalance::GetInterest() {
    return interest;
}
//sets the years variable
void InterestAndBalance::SetYears(double time) {
    years = time;
}
//gets the years variable
double InterestAndBalance::GetYears() {
    return years;
}
//function that prints out lines used in the table
void Lines() {
    int i;
    for (i = 0; i < 66; i++) {
        cout << "-";
        
    }
    cout << endl;
}

//Calculates the interest without the monthly deposit and returns it
double InterestAndBalance::CalculateBalanceWithoutMonthlyDeposit(double newInv) {
    newInv;
    double monthlyInterest = (newInv) * ((interest / 100) / 12);

    return monthlyInterest;
}
//calculates the interest with a monthly deposit and returns it
double InterestAndBalance::CalculateBalanceWithMonthlyDeposit(double depositInv) {
    depositInv;
    double monthlyInterest = (depositInv) * ((interest / 100) / 12);

    return monthlyInterest;
}
//Calculates and prints out the years, new balance, and interest earned per year without additional deposits
void InterestAndBalance::ResultsWithoutDeposit() {
    int i;
    int j;
    double intAdded;
    double newInterest = 0;
    double newBalance = invest;
    string spaces = "                 ";
    string spaces2 = "                 ";
    string lastBalance = "a";
    //for loop that prints out the variables after calculating them
    for (i = 1; i <= years; i++) {
        newInterest = 0;
        //internal for loop that calculates the monthly interest and adds it together
        for (j = 0; j < 12; j++) {
       
            intAdded = CalculateBalanceWithoutMonthlyDeposit(newBalance);
            newBalance += intAdded;
            newInterest += intAdded;

            
        }
        //turns the balance into a string to compare string sizes so text stays aligned

        std::string newB = to_string(newBalance);
        if (newB.length() > lastBalance.length()) {
            spaces.erase(0, 1);
        }
        //prints out the line
        cout << "   " << i << spaces << "$" << fixed << setprecision(2) << newBalance << spaces2 << "$" << fixed << setprecision(2) << newInterest << endl;
        lastBalance = newB;


    }

}

//Calculates and prints out the years, new balance, and interest earned per year
void InterestAndBalance::ResultsWithDeposit() {
    int i;
    int j;
    double money;
    double newInterest = 0;
    double intAdded = 0;
    double newBalance = invest;

    string spaces = "                 ";
    string spaces2 = "                 ";
    string lastBalance = "a";
    //for loop that prints out the variables after calculating them
    for (i = 1; i <= years; i++) {
        newInterest = 0;
        //internal for loop that calculates the monthly interest and adds it together
        for (j = 0; j < 12; j++) {
            money = newBalance + deposit;
            intAdded = CalculateBalanceWithMonthlyDeposit(money);
            newInterest += intAdded;
            newBalance = money + intAdded;
            
        }
        //turns the balance into a string to compare string sizes so text stays aligned
        std::string newB = to_string(newBalance);
        if (newB.length() > lastBalance.length()) {
            spaces.erase(0, 1);
        }
        //prints out the line
        cout <<"   " << i << spaces << "$" << fixed << setprecision(2) << newBalance << spaces2 << "$" << fixed << setprecision(2) << newInterest << endl;
        lastBalance = newB;
        
    }

}
//Prints out the top portion of the table that shows what column aligns with what number and that the table is for interest without additional deposits
void NoInterest() {
    cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
    Lines();
    Lines();
    cout << "   Year         Year End Balance      Year End Earned Interest    " << endl;
    Lines();
}
//Prints out the top portion of the table that shows what column aligns with what number and that the table is for additional monthly deposit interest
void WithInterest() {
    cout << "     Balance and Interest With Additional Monthly Deposits        " << endl;
    Lines();
    Lines();
    cout << "   Year         Year End Balance      Year End Earned Interest    " << endl;
    Lines();
}
//First part of the request for user input
void Intro() {
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;

}
//Main method that calls the functions from above
int main() {
    InterestAndBalance investmentAccount;
    double initial;
    double dep;
    double intr;
    double time;
    char proceed;

    Intro();
    //sets the variables that will be used throughout the method
    cout << "Initial Investment Amount:";
    cin >> initial;
    investmentAccount.SetInvest(initial);
    cout << endl;
    cout << "Monthly Deposit:";
    cin >> dep;
    investmentAccount.SetDeposit(dep);
    cout << endl;
    cout << "Annual Interest:";
    cin >> intr;
    investmentAccount.SetInterest(intr);
    cout << endl;
    cout << "Number of Years:";
    cin >> time;
    investmentAccount.SetYears(time);
    cout << endl;
    cout << "Press any key to continue...";
    cin >> proceed;
    cout << endl;

    NoInterest();
    investmentAccount.ResultsWithoutDeposit();
    cout << endl;
    WithInterest();
    investmentAccount.ResultsWithDeposit();
    
}