// BalanceAndInterest.h
//

//defines the H file
#ifndef BALANCEANDINTEREST_H
#define BALANCEANDINTEREST_H

#include <string>
//Creates the class that will be used by the rest of the code
class InterestAndBalance {
public:
    //publicly accessed variables, methods, and functions inlcuding setters and getters
    void SetInvest(double invest);
    void SetDeposit(double deposit);
    void SetInterest(double interest);
    void SetYears(double years);
    double GetInvest();
    double GetDeposit();
    double GetInterest();
    double GetYears();
    double CalculateBalanceWithoutMonthlyDeposit(double newInv);
    double CalculateBalanceWithMonthlyDeposit(double depositInv);
    void ResultsWithDeposit();
    void ResultsWithoutDeposit();
private:
    //privately accessed setters and getters
    double invest;
    double deposit;
    double interest;
    double years;
};//Ends the H file
#endif