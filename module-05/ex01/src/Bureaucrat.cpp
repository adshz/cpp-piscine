/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:40:47 by szhong            #+#    #+#             */
/*   Updated: 2026/01/02 15:51:03 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
	: _name("David Zhong")
	, _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat::default constructor called" RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: _name(src._name)
	, _grade(src._grade)
{
	std::cout << CYAN "Bureaucrat::copy constructor called." RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
	, _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat::constructor with parameters called." RESET << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << CYAN "Bureaucrat::desctructor called." RESET << std::endl;
	return ;
}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << CYAN "Bureaucrat:: copy assignment operator called." RESET << std::endl;
	if (this == &src)
		return (*this);
	this->_grade = src._grade;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->incrementGrade(1);
}

void	Bureaucrat::incrementGrade(int i)
{
	if (this->_grade - i < Bureaucrat::highestGrade)
		return (throw(Bureaucrat::GradeTooHighException()));
	else
	{
		this->_grade -= i;
		std::cout	<< GREEN 
					<< *this 
					<< " grade is incremented by "
					<< this->_grade 
					<< RESET 
					<< std::endl;
	}
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	this->decrementGrade(1);
}

void	Bureaucrat::decrementGrade(int i)
{
	if (this->_grade + i > Bureaucrat::lowestGrade)
		return (throw(Bureaucrat::GradeTooLowException()));
	else
	{
		this->_grade += i;
		std::cout	<< YELLOW 
					<< *this 
					<< "'s grade decremented by " 
					<< this->_grade
					<< RESET 
					<< std::endl;
	}
	return ;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout	<< GREEN 
					<< *this 
					<< " signed " 
					<< form 
					<< RESET 
					<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout	<< RED 
					<< *this 
					<< " couldn't sign " 
					<< form 
					<< " because: " 
					<< e.what()
					<< RESET
					<< std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat cannot get promoted anymore: too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat cannot get demoted anymore: too low");
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const &obj)
{
	os << "Bureaucrat \"" << obj.getName()
		<< "\" - grade: " << obj.getGrade();
	return (os);
}
