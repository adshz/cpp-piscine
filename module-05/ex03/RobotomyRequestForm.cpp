/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:00:00 by szhong            #+#    #+#             */
/*   Updated: 2025/12/31 12:00:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Required grades: sign 72, exec 45
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request", 72, 45)
	, _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
	: AForm(src)
	, _target(src._target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: AForm("Robotomy Request", 72, 45)
	, _target(target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

std::string const& RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::executeAction(void) const
{
	std::cout << "* DRILLING NOISES * Brrrrrrr..." << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
}
