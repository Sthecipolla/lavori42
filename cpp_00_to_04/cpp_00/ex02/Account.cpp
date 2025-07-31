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
	 << Account::getTotalAmount() << ";deposits:"
	 << Account::getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
	Account::Account( int initial_deposit )
	{
		_accountIndex = _nbAccounts;
		_amount = initial_deposit;
		Account::_displayTimestamp();
		std::cout << "index:"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";created" << std::endl;
		_totalAmount += initial_deposit;
		_nbAccounts++;

	}
	Account::~Account()
	{
		_displayTimestamp();
		std::cout << "index:"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";closed" << std::endl;
		return;
	}


	void	Account::makeDeposit( int deposit )
	{
		_displayTimestamp();
		_totalNbDeposits++;
		_totalAmount+=deposit;
		_nbDeposits++;
		std::cout<<"index:"<< _accountIndex << ";p_amount:"
	 	<< Account::_amount << ";deposit:"<<deposit << ";amount:"
	 	<< Account::_amount + deposit << ";nb_deposits:"<< _nbDeposits<< std::endl;
		_amount+=deposit;
	}

	bool	Account::makeWithdrawal( int withdrawal )
	{

		_displayTimestamp();
		if(_amount < withdrawal)
		{
			std::cout<<"index:"<< _accountIndex << ";p_amount:"
	 		<< Account::_amount << ";withdrawal:"<< "refused"<< std::endl;
			return 0;
			_nbWithdrawals++;
			_totalNbWithdrawals ++;
			return 1;
		}
		_totalNbWithdrawals ++;
		_nbWithdrawals++;
		std::cout<<"index:"<< _accountIndex << ";p_amount:"
	 	<< Account::_amount << ";withdrawal:"<<withdrawal
		<< ";amount:" << Account::_amount - withdrawal 
		<< ";nb_withdrawals:"<< _nbWithdrawals<< std::endl;
		
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
		std::cout << "[19920104_091532] ";
	}
	void	Account::displayStatus( void ) const
	{
		_displayTimestamp();
	std::cout<<"index:"<< _accountIndex << ";amount:"
	 	<< Account::_amount << ";deposits:"<<_nbDeposits
		<< ";withdrawals:"<< _nbWithdrawals<< std::endl;
	}