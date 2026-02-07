/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:32:05 by szhong            #+#    #+#             */
/*   Updated: 2026/02/07 13:32:12 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	bool parseInput(int argc, char** argv);
	void sort();
	void displayBefore() const;
	void displayAfter() const;
	void displayTimes() const;
	size_t getSize() const;

private:
	std::vector<int> _vecOriginal;
	std::vector<int> _vec;
	std::deque<int> _deq;
	double _vecTime;
	double _deqTime;

	void fordJohnsonVector(std::vector<int>& arr);
	void fordJohnsonDeque(std::deque<int>& arr);

	std::vector<size_t> generateJacobsthalSequence(size_t n) const;
	std::vector<size_t> generateInsertionOrder(size_t pendSize) const;
};
#endif
