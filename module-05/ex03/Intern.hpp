/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:00:00 by szhong            #+#    #+#             */
/*   Updated: 2026/01/03 12:00:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &other);
	~Intern(void);
	Intern &operator=(const Intern &other);

	AForm	*makeForm(const std::string &formName, const std::string &target);

private:
	AForm	*createShrubberyCreation(const std::string &target);
	AForm	*createRobotomyRequest(const std::string &target);
	AForm	*createPresidentialPardon(const std::string &target);
};

#endif
