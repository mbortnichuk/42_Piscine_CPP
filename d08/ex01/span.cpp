/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:11:00 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/17 11:11:02 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

unsigned int Span::getN()const {
	return n;
}

const std::vector<int> &Span::getVec()const {
	return vec;
}

void Span::setVec(const std::vector<int> &vec) {
	Span::vec = vec;
}

void Span::setN(unsigned int n) {
	Span::n = n;
}

Span::Span() : n(0) {
}

Span::Span(unsigned int a) : n(a) {
}

Span::Span(Span const & ref) {
	*this = ref;
}

Span &Span::operator=(Span const & ref) {
	n = ref.getN();
	this->vec = ref.vec;
	return *this;
}

Span::~Span() {
}

void Span::addNumber(int a) {
	if (vec.size() < n)
		vec.push_back(a);
	else
		throw std::exception();
}

int Span::shortestSpan() {
	if (n < 2)
		throw std::exception();
	std::vector<int> temp;
	temp = vec;
	std::sort(temp.begin(), temp.end());

	int result = temp[1] - temp[0];
	for (unsigned int i = 1; i < temp.size(); i++) {
		if (Span::difference(temp[i - 1], temp[i] < result))
			 result = Span::difference(temp[i - 1], temp[i]);
	}
	return result;
}

int Span::longestSpan() {
	if (n < 2)
		throw std::exception();
	std::vector<int> temp;
	temp = vec;
	std::sort(temp.begin(), temp.end());
	return temp[temp.size() - 1] - temp[0];
}

int Span::difference(int const a, int const b) {
	int result;

	result = b - a;
	return (result < 0 ? -result : result);
}
