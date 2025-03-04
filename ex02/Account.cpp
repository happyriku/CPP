# include "Account.hpp"
# include <iostream>
# include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void){
	std::time_t	now = std::time(NULL); //UNIX時間(1970年1月1日00:00)から現在までの経過秒数を取得
	std::tm*	localtime = std::localtime(&now); //UNIX時間を年・月・日・時・分・秒に変換した構造体を返す
	char		buf[18]; //文字列を格納するバッファ

	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%I%S]", localtime); //日時/時刻をstring型に変換する
	std::cout << buf << " ";
};

Account::Account(int initial_deposit){
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_totalAmount += initial_deposit;
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(){ return _nbAccounts; }

int Account::getTotalAmount(){ return _totalAmount; }

int Account::getNbDeposits(){ return _totalNbDeposits; }

int Account::getNbWithdrawals(){ return _totalNbWithdrawals; }

void Account::displayAccountsInfos(){

	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << ";";

}
