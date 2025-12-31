/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:00:00 by szhong            #+#    #+#             */
/*   Updated: 2025/12/31 12:00:00 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		AForm(void);
		AForm(AForm const& src);
		AForm(std::string const& name, int gradeToSign, int gradeToExecute);
		AForm& operator=(AForm const& src);
		virtual ~AForm(void);

		// Getters
		std::string const&	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		// Actions
		void	beSigned(Bureaucrat const& bureaucrat);
		void	execute(Bureaucrat const& executor) const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

	protected:
		// Pure virtual - each concrete form implements its own action
		virtual void	executeAction(void) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif
