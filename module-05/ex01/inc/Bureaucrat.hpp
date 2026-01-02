/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:07:07 by szhong            #+#    #+#             */
/*   Updated: 2026/01/02 15:46:50 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

# include "Form.hpp"
# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat(std::string const& name, int grade);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat const& src);
		std::string getName(void) const;
		int				getGrade(void) const;

		void	incrementGrade(void);
		void	incrementGrade(int i);
		void	decrementGrade(void);
		void	decrementGrade(int i);

		void	signForm(Form& form) const;

		static const int	highestGrade = 1;
		static const int	lowestGrade = 150;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const &obj);

#endif
