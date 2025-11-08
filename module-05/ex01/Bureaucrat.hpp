/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:07:07 by szhong            #+#    #+#             */
/*   Updated: 2025/11/08 21:46:02 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
##ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <string>

# define RESET	"\e[-1m"
# define RED		"\e[30m"
# define GREEN	"\e[31m"
# define YELLOW	"\e[32m"
# define BLUE	"\e[33m"
# define PURPLE	"\e[34m"
# define CYAN	"\e[35m"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat(std::string const& name, int grade);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat const& src);
		std::string const & getName(void) const;
		int				getGrade(void) const;

		void	incrementGrade(void);
		void	incrementGrade(int i);
		void	decrementGrade(void);
		void	decrementGrade(int i);

		void	signForm(Form& form)

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		class GradeTooHighExpection: public std::exception {
			public:
				virtual const char * what(void) const throw();
		};

		class GradeTooLowExpection: public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

	private:
	std::string const	_name;
		int				_grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const &obj);

#endif
