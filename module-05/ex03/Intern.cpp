/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:00:00 by szhong            #+#    #+#             */
/*   Updated: 2026/01/03 12:00:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::createShrubberyCreation(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomyRequest(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidentialPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

/*
** BAD EXAMPLE - if/else chain (NOT accepted in evaluation):
  BAD - if/else chain:
  - Repetitive, hard to maintain
  - Adding a new form = adding another else if block
  - Violates DRY principle
**
** AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
** {
**     if (formName == "shrubbery creation")
**     {
**         std::cout << "Intern creates Shrubbery Creation" << std::endl;
**         return (new ShrubberyCreationForm(target));
**     }
**     else if (formName == "robotomy request")
**     {
**         std::cout << "Intern creates Robotomy Request" << std::endl;
**         return (new RobotomyRequestForm(target));
**     }
**     else if (formName == "presidential pardon")
**     {
**         std::cout << "Intern creates Presidential Pardon" << std::endl;
**         return (new PresidentialPardonForm(target));
**     }
**     else
**     {
**         std::cout << "Error: Form \"" << formName << "\" does not exist" << std::endl;
**         return (NULL);
**     }
** }
*/

// GOOD EXAMPLE - parallel arrays with function pointers:
/*  GOOD - parallel arrays + function pointers:
  - Data-driven approach
  - Adding a new form = add one entry to each array
  - Single loop handles all cases
  - Scales cleanly


 * */
AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm	*(Intern::*creators[3])(const std::string &) = {
		&Intern::createShrubberyCreation,
		&Intern::createRobotomyRequest,
		&Intern::createPresidentialPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			AForm	*form = (this->*creators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Error: Form \"" << formName << "\" does not exist" << std::endl;
	return (NULL);
}
