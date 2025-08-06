/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:36:46 by edubois-          #+#    #+#             */
/*   Updated: 2025/08/05 15:36:49 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cstdlib>
# include <cctype>
# include <cerrno>
# include <climits>
# include <cfloat>
# include <cmath>
# include <iomanip>

class ScalarConverter {

    private:
        ScalarConverter(void);

    public:
        virtual ~ScalarConverter(void) = 0;
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter &operator=(const ScalarConverter &src);

        static void convert(std::string convert);
};

#endif