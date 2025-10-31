/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:58:50 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 16:58:50 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	ScalarConverter	&operator=(ScalarConverter const &);
	~ScalarConverter();

public:
	enum Type
	{
		NONE,
		CHAR,
		INT,
		DOUBLE,
		FLOAT
	};
	static void	convert(std::string const &t_str);
};

#endif
