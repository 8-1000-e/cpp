/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:07:52 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/07 14:59:19 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _size(n) {}

Span::Span(): _size(0) {}

Span::~Span() {}

Span::Span(const Span &copy)
{
    _size = copy._size;
    v.clear();
    for (unsigned int s = 0; s < _size; s++)
        v.push_back(copy.v[s]);
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _size = other._size;
        v.clear();
        for (unsigned int s = 0; s < _size; s++)
            v.push_back(other.v[s]);
    }
    return *this;
}

void    Span::addNumber(int nb)
{
    if (v.size() == _size)
        throw SpanFullException();
    else
        v.push_back(nb);
}

void	Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->v.size() + std::distance(begin, end) > this->_size)
		throw Span::SpanFullException();
	this->v.insert(this->v.end(), begin, end);
}

int Span::shortestSpan()
{
    if (v.size() < 2)
        throw SpanEmptyException();

    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::abs(sorted[1] - sorted[0]);
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int diff = std::abs(sorted[i + 1] - sorted[i]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (v.size() < 2)
        throw SpanEmptyException();

    int min = *std::min_element(v.begin(), v.end());
    int max = *std::max_element(v.begin(), v.end());

    return max - min;
}

const char *Span::SpanEmptyException::what() const throw()
{
    return "Size is lower than 2, no Span possible !";
}

const char *Span::SpanFullException::what() const throw()
{
    return "All span slot are full!";
}
