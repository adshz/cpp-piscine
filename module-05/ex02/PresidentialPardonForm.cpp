/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:00:00 by szhong            #+#    #+#             */
/*   Updated: 2025/12/31 12:00:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Required grades: sign 25, exec 5
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon", 25, 5)
	, _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
	: AForm(src)
	, _target(src._target)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: AForm("Presidential Pardon", 25, 5)
	, _target(target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

std::string const& PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::executeAction(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
