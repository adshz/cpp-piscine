/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:06:43 by szhong            #+#    #+#             */
/*   Updated: 2026/01/02 15:46:27 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"
#include <iostream>

Form::Form(void)
	: _name("Default Form")
	, _isSigned(false)
	, _gradeRequiredToSign(Bureaucrat::lowestGrade)
	, _gradeRequiredToExecute(Bureaucrat::lowestGrade)
{
}

Form::Form(const Form& src)
	: _name(src._name)
	, _isSigned(src._isSigned)
	, _gradeRequiredToSign(src._gradeRequiredToSign)
	, _gradeRequiredToExecute(src._gradeRequiredToExecute)
{
	std::cout	<< CYAN "Form:: Copy Constructor Called" 
				<< RESET 
				<< std::endl;
	return ;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name)
	, _isSigned(false)
	, _gradeRequiredToSign(gradeToSign)
	, _gradeRequiredToExecute(gradeToExecute)
{
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw Form::GradeTooHighException();
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw Form::GradeTooLowException();
	return ;
}

Form&	Form::operator=(const Form& src) {
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

Form::~Form(void)
{
	std::cout	<< CYAN 
				<< "Form:: Deconstructor called"
				<< RESET
				<< std::endl;
}

std::string Form::getName(void) const {
	return (this->_name);
}

bool Form::isSigned(void) const {
	return (this->_isSigned);
}

int Form::getGradeRequiredToSign(void) const
{
	return (this->_gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute(void) const
{
	return (this->_gradeRequiredToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_isSigned)
		throw Form::AlreadySignedException();
	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
	return ;
}

// void	Form::execute(const Bureaucrat& executor) const {
// 	if (!this->_isSigned)
// 		throw Form::NotSignedExecption();
// 	if (executor.getGrade() > this->_gradeRequiredToExecute)
// 		throw Form::GradeTooLowException();
// 	this->executeAction();
// }

const char* Form::GradeTooHighException::what(void) const throw() {
	return ("Grade are too high");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}

const char* Form::AlreadySignedException::what(void) const throw() {
	return ("Form is already signed");
}

const char* Form::NotSignedException::what(void) const throw() {
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os	<< "Form \"" 
		<< form.getName() 
		<< "\" ["
		<< (form.isSigned() ? "signed" : "unsigned") 
		<< "] "
		<< "(sign: " 
		<< form.getGradeRequiredToSign()
		<< ", exec: " 
		<< form.getGradeRequiredToExecute() 
		<< ")";
	return (os);
}
