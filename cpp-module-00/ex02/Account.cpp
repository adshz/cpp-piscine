#include "Account.hpp"

#include <ctime>
#include <iostream>

/*
    Step 1: ./GBU > new.log

    Step 2: < new.log cut -d " " -f2 > my_no_timestamps.log

    Step 3: <19920104_091532.log cut -d " " -f2 > given_no_timestamps.log

    Step 4: diff -s given_no_timestamp.log my_no_timestamps.log
*/

/******************************************************************************/
/*						STATIC MEMBER INITIALIZATION
 */
/******************************************************************************/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
    _accountIndex = _nbAccounts;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    Account::_nbAccounts++;
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    Account::_nbAccounts++;
    Account::_totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";"
              << "created" << std::endl;
    return;
}

Account::~Account(void) {
    Account::_nbAccounts--;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";"
              << "closed" << std::endl;
    return;
}

/**********************************************/
/*								GETTERS
 */
/**********************************************/
int Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int Account::getTotalAmount(void) { return (Account::_totalAmount); }

int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

/******************************************************************************/
/*							PRIVATE FUNCTIONS
 */
/******************************************************************************/

void Account::_displayTimestamp(void) {
    std::time_t rawTime;
    struct tm *timeInfo;

    std::time(&rawTime);
    timeInfo = std::localtime(&rawTime);

    std::cout << "[" << timeInfo->tm_year + 1900;
    if (timeInfo->tm_mon < 10) std::cout << "0";
    std::cout << timeInfo->tm_mon;
    if (timeInfo->tm_mday < 10) std::cout << "0";
    std::cout << timeInfo->tm_mday << "_";
    if (timeInfo->tm_hour < 10) std::cout << "0";
    std::cout << timeInfo->tm_hour;
    if (timeInfo->tm_min < 10) std::cout << "0";
    std::cout << timeInfo->tm_min;
    if (timeInfo->tm_sec < 10) std::cout << "0";
    std::cout << timeInfo->tm_sec << "] ";
    return;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS
 */
/******************************************************************************/
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";"
              << "deposit:";
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout << deposit << ";" << "amount:" << this->_amount << ";"
              << "nb_deposits:" << this->_nbDeposits << std::endl;
    return;
}

int Account::checkAmount(void) const { return (this->_amount); }

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";" << "withdrawal:";
    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
        return (false);
    } else {
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        std::cout << withdrawal << ";" << "amount:" << this->_amount << ";"
                  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    }
    return (true);
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
    return;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
    return;
}