/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:05:01 by szhong            #+#    #+#             */
/*   Updated: 2026/01/02 16:05:58 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

# define DF "\e[0m"
# define RED "\e[31m"

int	main() {

	{
		std::cout << "----------Basic Bureaucrat-----------" << std::endl;
		Bureaucrat	UK;
		std::cout << UK << std::endl;
		Bureaucrat	US(UK);
		std::cout << "US object: " << US << std::endl;
		Bureaucrat	China("People's republic China", 75);
		std::cout << "China object: "<< China << std::endl;
		Bureaucrat	USSR("Soviet Union", 33);
		std::cout << "Soviet Union object: " << USSR << std::endl;
		std::cout << "====Copy assignment====" << std::endl;
		China = USSR;
		std::cout << "After China = USSR, China object becomes :" << China << std::endl;
	}
	{
		std::cout << "----------Basic Form-----------" << std::endl;
		Form	UKForm;
		std::cout << UKForm << std::endl;
		Form	USForm(UKForm);
		std::cout << USForm << std::endl;
		Form	ChinaForm("PRC-Form", 130, 130);
		std::cout << ChinaForm << std::endl;
		Form	USSRForm("USSR-Form", 55, 55);
		std::cout << "Soviet Union Form: " << USSRForm << std::endl;
		std::cout << "====Copy assignment====" << std::endl;
		ChinaForm = USSRForm;
		std::cout	<< "After ChinaForm = USSRForm, ChinaForm becomes :" 
					<< ChinaForm 
					<< std::endl;
	}
	{
		std::cout << "--------Error Handling: Bureaucrat--------" << std::endl;
		try {
			Bureaucrat	UK("UK", 151);
			std::cout<< "Bureaucrat Creation Success!" << std::endl;
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cerr << RED "Exception: " << e.what() << DF << std::endl;
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cerr << RED "Exception: " << e.what() << DF << std::endl;
		}
		try {
			Bureaucrat	US("US", -10);
			std::cout<< "Bureaucrat Creation Success!" << std::endl;
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cerr << RED "Bureaucrat Exception: " << e.what() << DF << std::endl;
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cerr << RED "Bureaucrat Exception: " << e.what() << DF << std::endl;
		}
		std::cout << "--------Error Handling: Form --------" << std::endl;
		try {
			Form	UKForm("UK Form", 155, 155);
			std::cout << "Form Creation Success!" << std::endl;
		} catch (Form::GradeTooHighException &e) {
			std::cerr << RED "Form Exception: " << e.what() << std::endl;
		} catch (Form::GradeTooLowException &e) {
			std::cerr << RED "Form Exception: " << e.what() << std::endl;
		}
		try {
			Form	USForm("UK Form", -10, -10);
			std::cout << "Form Creation Success!" << std::endl;
		} catch (Form::GradeTooHighException &e) {
			std::cerr << RED "Form Exception: " << e.what() << std::endl;
		} catch (Form::GradeTooLowException &e) {
			std::cerr << RED "Form Exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "--------Signing Forms--------" << std::endl;
		//Test successful signing
		Bureaucrat	highRank("Director", 10);
		Form		easyForm("Easy Form", 50, 50);
		std::cout << "Before signing: " << easyForm << std::endl;
		highRank.signForm(easyForm);
		std::cout << "After signing: " << easyForm << std::endl;

		// Won't run because the grade is too low
		Bureaucrat	lowRank("Intern", 149);
		Form		difficultForm("Difficult Form", 20, 20);
		lowRank.signForm(difficultForm); // Should not let you sign it
		std::cout << "After lowRank.signForm: " << difficultForm << std::endl;

		// Signing already signed form (see if AlreadySignedException is used)
		try {
			highRank.signForm(easyForm);
		} catch (Form::AlreadySignedException& e) {
			std::cerr << RED "Exception: " << e.what() << DF << std::endl;
		}
	}
	{
		std::cout << "-------Increment/Decrement Grade--------" << std::endl;

		Bureaucrat b("Test", 75);
		std::cout << "Initial: "<< b << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;

		// boundary - grade too high
		try {
			Bureaucrat top("Top Dog", 1);
			top.incrementGrade(); // should throw error
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << RED "Exception: " << e.what() << DF << std::endl;
		}
		
		// boundary - grade too low
		try {
			Bureaucrat bottom("Little Fish", 150);
			bottom.decrementGrade(); // should throw
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << RED "Exception: " << e.what() << DF << std::endl;
		}
	}
	return (0);
}
