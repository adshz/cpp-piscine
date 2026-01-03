/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:28:03 by szhong            #+#    #+#             */
/*   Updated: 2025/11/08 21:40:38 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeRequiredToSign;
		int const			_gradeRequiredToExecute;

	public:
		AForm(void);
		AForm(const AForm& src);
		AForm(std::string const & name, int const gradeToSign, int const gradeToExecute);
		AForm& operator=(const AForm& src);
		~AForm(void);

		bool execute(const Bureaucrat& executor);
		virtual beExecutedl() = 0;
		std::string const & getName() const;
		bool				isSigned(void) const;
		int					getGradeRequiredToSign(void) const;
		int					getGradeRequiredToExecute(void) const;
		void				beSigned(Bureaucrat const & Bureaucrat);
		
		class GradeTooHighException: public std::exception {
			public:
				virtual const char * what(void) const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char * what(void) const throw();
		};
		class AlreadySignedException: public std::exception {
			public:
				virtual const char * what(void) const throw();
		};
};

std::ostream & operator<<(std::ostream & os, Form const & obj);

#endif

