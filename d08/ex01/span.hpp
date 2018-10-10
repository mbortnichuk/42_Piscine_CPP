/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:11:07 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/17 11:11:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span {
private:
	unsigned int n;
	std::vector<int> vec;
public:
	Span();
	~Span();
	Span(unsigned int a);
	Span(Span const & ref);
	Span& operator=(Span const & ref);

	unsigned int getN()const;
	const std::vector<int> &getVec()const;

	void setN(unsigned int n);
	void setVec(const std::vector<int> & vec);

	void addNumber(int);

	int shortestSpan();
	int longestSpan();

	int difference(int const a, int const b);
};

#endif
