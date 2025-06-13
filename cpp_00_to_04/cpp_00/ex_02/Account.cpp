#include <Account.hpp>
#include <iostream>
#include <stdio.h>
#include <string>
# include <ctime>
#include <cstdlib>
#include <stdbool.h>

int  Account::_nbAccounts = 0;
int  Account::_totalNbDeposits = 0;
int  Account::_totalAmount = 0;
int  Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getTotalAmount( void )
{
	return	_totalAmount;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;	
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:"<< Account::getNbAccounts()  << ";total:"
	 << Account::getTotalAmount() << ";deposit: "
	 << Account::getNbDeposits() << ";withdrawals: " << getNbWithdrawals() << std::endl;
}
	Account::Account( int initial_deposit )
	{
		_accountIndex = _nbAccounts;
		_amount = initial_deposit;
		Account::_displayTimestamp();
		std::cout << "index:"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";created" << std::endl;
		_totalAmount += initial_deposit;

	}
	Account::~Account()
	{
		_displayTimestamp();
		std::cout << "index:"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";close" << std::endl;
		return;
	}


	void	Account::makeDeposit( int deposit )
	{
		_displayTimestamp();
		std::cout<<"index"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";deposits:"<<_nbDeposits<< std::endl;
		_totalNbDeposits++;
		_totalAmount+=deposit;
		_amount+=deposit;
	}

	bool	Account::makeWithdrawal( int withdrawal )
	{

		_displayTimestamp();
		if(_amount < withdrawal)
		{
			std::cout<<"index"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";deposits:"<<_nbDeposits<< ";withdrawals:"<< "refused"<< std::endl;
			return 0;
		}
		_totalNbWithdrawals ++;
		std::cout<<"index"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";deposits:"<<_nbDeposits<< ";withdrawals:"<< _nbWithdrawals<< std::endl;
		
		_nbWithdrawals++;
		_amount-=withdrawal;
		_totalAmount-=withdrawal;
		return 1;
	}
	int		Account::checkAmount( void ) const 
	{
		std::cout<<"checkAmount"<<std::endl;
			return (getTotalAmount());
	}

	void	Account::_displayTimestamp( void )
	{
		std::cout << "[19920104_091532]";
	}
	void	Account::displayStatus( void ) const
	{
		_displayTimestamp();
	std::cout<<"index"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";deposits:"<<_nbDeposits
		<< ";withdrawals:"<< _nbWithdrawals<< std::endl;
	}