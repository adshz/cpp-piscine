/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:44:59 by szhong            #+#    #+#             */
/*   Updated: 2026/02/07 13:45:01 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;

	if (!sorter.parseInput(argc, argv)) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	sorter.displayBefore();
	sorter.sort();
	sorter.displayAfter();
	sorter.displayTimes();

	return 0;
}
