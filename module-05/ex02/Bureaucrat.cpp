/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:00:00 by szhong            #+#    #+#             */
/*   Updated: 2025/12/31 12:00:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
	: _name("Default")
	, _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat constructor " << _name << " called" RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: _name(src._name)
	, _grade(src._grade)
{
	std::cout << CYAN "Bureaucrat copy constructor called." RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
	, _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat constructor with parameters called." RESET << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	if (grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src)
{
	std::cout << CYAN "Bureaucrat assignment operator overload called." RESET << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << CYAN "Bureaucrat desctructor called." RESET << std::endl;
	return ;
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout	<< RED this->_name 
					<< " couldn't sign " << form.getName()
					<< " because " 
					<< e.what() 
					<< RESET
					<< std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout	<< GREEN this->_name 
					<< " executed " 
					<< form.getName() 
					<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cout	<< RED this->_name 
					<< " couldn't execute " << form.getName()
					<< " because " 
					<< e.what() 
					<< std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat cannot get promoted anymore: too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat cannot get demoted anymore: too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os	<< "Bureaucrat \"" 
		<< obj.getName() 
		<< ", bureaucrat grade " 
		<< obj.getGrade();
	return (os);
}
