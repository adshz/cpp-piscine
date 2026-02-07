/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:31:49 by szhong            #+#    #+#             */
/*   Updated: 2026/02/07 13:31:53 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <climits>

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vecOriginal(other._vecOriginal), _vec(other._vec), _deq(other._deq),
	  _vecTime(other._vecTime), _deqTime(other._deqTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vecOriginal = other._vecOriginal;
		_vec = other._vec;
		_deq = other._deq;
		_vecTime = other._vecTime;
		_deqTime = other._deqTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];

		if (arg.empty())
			return false;

		for (size_t j = 0; j < arg.length(); j++) {
			if (!isdigit(arg[j]))
				return false;
		}

		char* endptr;
		long num = std::strtol(arg.c_str(), &endptr, 10);

		if (*endptr != '\0' || num < 0 || num > INT_MAX)
			return false;

		_vecOriginal.push_back(static_cast<int>(num));
	}

	return !_vecOriginal.empty();
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) const {
	std::vector<size_t> jacobsthal;
	if (n == 0) return jacobsthal;

	jacobsthal.push_back(0);
	if (n == 1) return jacobsthal;

	jacobsthal.push_back(1);
	while (jacobsthal.back() < n) {
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t pendSize) const {
	std::vector<size_t> order;
	if (pendSize == 0) return order;

	std::vector<size_t> jacobsthal = generateJacobsthalSequence(pendSize);
	std::vector<bool> inserted(pendSize, false);

	for (size_t i = 1; i < jacobsthal.size(); i++) {
		size_t curr = jacobsthal[i];
		size_t prev = jacobsthal[i - 1];

		if (curr > pendSize)
			curr = pendSize;

		for (size_t j = curr; j > prev; j--) {
			if (j > 0 && j <= pendSize && !inserted[j - 1]) {
				order.push_back(j - 1);
				inserted[j - 1] = true;
			}
		}
	}

	for (size_t i = 0; i < pendSize; i++) {
		if (!inserted[i])
			order.push_back(i);
	}

	return order;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr) {
	size_t n = arr.size();
	if (n <= 1)
		return;

	bool hasStraggler = (n % 2 == 1);
	int straggler = 0;
	if (hasStraggler) {
		straggler = arr.back();
		arr.pop_back();
		n--;
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < n; i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
	}
	fordJohnsonVector(mainChain);

	std::vector<int> pend;
	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == mainChain[i]) {
				pend.push_back(pairs[j].second);
				pairs[j].first = -1;
				break;
			}
		}
	}

	std::vector<int> sorted;
	if (!pend.empty()) {
		sorted.push_back(pend[0]);
	}
	for (size_t i = 0; i < mainChain.size(); i++) {
		sorted.push_back(mainChain[i]);
	}

	std::vector<size_t> insertOrder = generateInsertionOrder(pend.size());
	for (size_t i = 0; i < insertOrder.size(); i++) {
		size_t idx = insertOrder[i];
		if (idx == 0) continue;
		if (idx < pend.size()) {
			int val = pend[idx];
			std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
			sorted.insert(pos, val);
		}
	}

	if (hasStraggler) {
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
		sorted.insert(pos, straggler);
	}

	arr = sorted;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr) {
	size_t n = arr.size();
	if (n <= 1)
		return;

	bool hasStraggler = (n % 2 == 1);
	int straggler = 0;
	if (hasStraggler) {
		straggler = arr.back();
		arr.pop_back();
		n--;
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < n; i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
	}
	fordJohnsonDeque(mainChain);

	std::deque<int> pend;
	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == mainChain[i]) {
				pend.push_back(pairs[j].second);
				pairs[j].first = -1;
				break;
			}
		}
	}

	std::deque<int> sorted;
	if (!pend.empty()) {
		sorted.push_back(pend[0]);
	}
	for (size_t i = 0; i < mainChain.size(); i++) {
		sorted.push_back(mainChain[i]);
	}

	std::vector<size_t> insertOrder = generateInsertionOrder(pend.size());
	for (size_t i = 0; i < insertOrder.size(); i++) {
		size_t idx = insertOrder[i];
		if (idx == 0) continue;
		if (idx < pend.size()) {
			int val = pend[idx];
			std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
			sorted.insert(pos, val);
		}
	}

	if (hasStraggler) {
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
		sorted.insert(pos, straggler);
	}

	arr = sorted;
}

void PmergeMe::sort() {
	_vec = _vecOriginal;
	_deq = std::deque<int>(_vecOriginal.begin(), _vecOriginal.end());

	clock_t start = clock();
	fordJohnsonVector(_vec);
	clock_t end = clock();
	_vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	fordJohnsonDeque(_deq);
	end = clock();
	_deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayBefore() const {
	std::cout << "Before:";
	for (size_t i = 0; i < _vecOriginal.size(); i++) {
		std::cout << " " << _vecOriginal[i];
	}
	std::cout << std::endl;
}

void PmergeMe::displayAfter() const {
	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << " " << _vec[i];
	}
	std::cout << std::endl;
}

void PmergeMe::displayTimes() const {
	std::cout << "Time to process a range of " << _vecOriginal.size()
			  << " elements with std::vector : " << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _vecOriginal.size()
			  << " elements with std::deque  : " << _deqTime << " us" << std::endl;
}

size_t PmergeMe::getSize() const {
	return _vecOriginal.size();
}
