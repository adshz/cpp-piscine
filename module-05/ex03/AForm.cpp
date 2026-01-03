/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:00:00 by szhong            #+#    #+#             */
/*   Updated: 2025/12/31 12:00:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(void)
	: _name("Default Form")
	, _isSigned(false)
	, _gradeToSign(150)
	, _gradeToExecute(150)
{
}

AForm::AForm(const AForm& src)
	: _name(src._name)
	, _isSigned(src._isSigned)
	, _gradeToSign(src._gradeToSign)
	, _gradeToExecute(src._gradeToExecute)
{
}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute)
	: _name(name)
	, _isSigned(false)
	, _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(AForm const& src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

AForm::~AForm(void)
{
}

// Getters
std::string const& AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::isSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

// Actions
void AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	// Check 1: Is form signed?
	if (!this->_isSigned)
		throw AForm::NotSignedException();
	// Check 2: Is executor's grade high enough?
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	// All checks passed - call the concrete class's action
	this->executeAction();
}

// Exceptions
const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char* AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& os, AForm const& form)
{
	os << "Form \"" << form.getName() << "\" ["
	   << (form.isSigned() ? "signed" : "unsigned") << "] "
	   << "(sign: " << form.getGradeToSign()
	   << ", exec: " << form.getGradeToExecute() << ")";
	return (os);
}
