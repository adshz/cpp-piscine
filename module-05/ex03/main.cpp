/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:00:00 by szhong            #+#    #+#             */
/*   Updated: 2025/12/31 12:00:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	{
		Bureaucrat bob("Bob", 130);
		ShrubberyCreationForm shrub("home");

		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;

		bob.signForm(shrub);
		bob.executeForm(shrub);
	}

	std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robot("Bender");

		std::cout << alice << std::endl;
		std::cout << robot << std::endl;

		alice.signForm(robot);
		alice.executeForm(robot);
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << president << std::endl;
		std::cout << pardon << std::endl;

		president.signForm(pardon);
		president.executeForm(pardon);
	}

	std::cout << "\n=== Test 4: Execute unsigned form ===" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("garden");

		boss.executeForm(shrub);  // Should fail - not signed
	}

	std::cout << "\n=== Test 5: Grade too low to execute ===" << std::endl;
	{
		Bureaucrat lowGrade("LowGrade", 150);
		Bureaucrat manager("Manager", 50);
		RobotomyRequestForm robot("Target");

		manager.signForm(robot);
		lowGrade.executeForm(robot);
	}

	std::cout << "\n=== Test 6: Intern creates RobotomyRequestForm ===" << std::endl;
	{
		Intern		someRandomIntern;
		AForm		*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}

	std::cout << "\n=== Test 7: Intern creates all form types ===" << std::endl;
	{
		Intern		intern;
		Bureaucrat	boss("Boss", 1);
		AForm		*forms[3];

		forms[0] = intern.makeForm("shrubbery creation", "garden");
		forms[1] = intern.makeForm("robotomy request", "Marvin");
		forms[2] = intern.makeForm("presidential pardon", "Zaphod");

		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
			{
				boss.signForm(*forms[i]);
				boss.executeForm(*forms[i]);
				delete forms[i];
			}
		}
	}

	std::cout << "\n=== Test 8: Intern with invalid form name ===" << std::endl;
	{
		Intern	intern;
		AForm	*form;

		form = intern.makeForm("invalid form", "target");
		if (form == NULL)
			std::cout << "Form pointer is NULL as expected" << std::endl;
	}

	return (0);
}
