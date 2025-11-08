/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:38:20 by szhong            #+#    #+#             */
/*   Updated: 2025/11/07 12:49:49 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include <iostream>

# define DF "\e[0m"
# define RED "\e[31m"

void	createTestBureaucrat(std::string name, int grade)
{
	std::cout << std::endl << "....Creating an object bureaucrat named \""
		<< name << "\" with an input grade " << grade << ":" << std::endl;
	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat << " CREATION SUCCESS! " << std::endl;
		return ;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << RED "Exception: " << e.what() << DF << std::endl;
	}
	catch (Bureaucrat:: GradeTooLowException & e)
	{
		std::cerr << RED "Exception: " << e.what() << DF << std::endl;
	}
}

int	main(void)
{
	std::cout << std::endl << "==== TEST DEFAULT CONSTRUCTOR ====" << std::endl;
	{
		Bureaucrat bureaucrat;
		std::cout << "Default bureaucrat is: " << bureaucrat << std::endl;
	}

	std::cout << "==== TEST CONSTRUCTOR WITH PARAMETER ==== " << std::endl;
	createTestBureaucrat("David", 20);
	createTestBureaucrat("Joy", 1);
	createTestBureaucrat("Chairman", 150);
	createTestBureaucrat("Fred", 151);
	createTestBureaucrat("Michelle", -10);
	createTestBureaucrat("Jacqueline", 0);
	{
		std::cout << std::endl << "---- TEST BUREAUCRAT ASSIGNMENT OPERATOR" << std::endl; 
		Bureaucrat bureaucrat1("DAVID", Bureaucrat::lowestGrade);
		Bureaucrat bureaucrat2("david", 42);

		std::cout << "Two bureaucrats created:\n"
			"\t" << bureaucrat1 << "\n"
			"\t" << bureaucrat2 << std::endl;
		
		bureaucrat1 = bureaucrat2;
		std::cout << "First bureaucrat = second bureaucrat:\n"
			"\t" << bureaucrat1 << "\n"
			"\t" << bureaucrat2 << std::endl;
	}
	{
		std::cout << "==== TEST BUREAUCRAT GRADE INCREMENT/DECREMENT ====" << std::endl;
		Bureaucrat	bureaucrat("David", 2);
		std::cout << "an object 'bureaucrat' is created" << std::endl;
		try
		{
			std::cout << "=========================" << std::endl;
			std::cout << "Decrement grade by 1: " << std::endl;
			bureaucrat.decrementGrade();
			std::cout << "UPDATE " << bureaucrat << std::endl;
			std::cout << "=========================" << std::endl;
			std::cout << "Incrementing grade by 1: " << std::endl;
			bureaucrat.incrementGrade();
			std::cout << "UPDATE " << bureaucrat << std::endl;
			std::cout << "=========================" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << RED "Eception: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cout << RED "Exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << "==== TEST BUREAUCRAT GRADE INCREMENT/DECREMENT WITH PARAMETER ====" << std::endl;
		Bureaucrat	bureaucrat("David", 30);
		std::cout << "an object 'bureaucrat' is created" << std::endl;
		try
		{
			int	degradeNumber = 50;
			int	increment = 100;
			std::cout << "=========================" << std::endl;
			std::cout << "Decrement grade by: " << degradeNumber << std::endl;
			bureaucrat.decrementGrade(degradeNumber);
			std::cout << "UPDATE " << bureaucrat << std::endl;
			std::cout << "=========================" << std::endl;
			std::cout << "Incrementing grade by " << increment << std::endl;
			bureaucrat.incrementGrade(increment);
			std::cout << "UPDATE " << bureaucrat << std::endl;
			std::cout << "=========================" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << RED "Eception: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cout << RED "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
