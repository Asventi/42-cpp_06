/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:58:43 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 16:58:43 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>

static bool	isNan(std::string const &t_str)
{
	if (t_str == "nanf" || t_str == "nan")
		return (true);
    return (false);
}

static bool	isInf(std::string const &t_str)
{
	if (t_str == "+inf" || t_str == "+inff" || t_str == "inf" || t_str == "inff")
		return (true);
    return (false);
}

static bool	isNegInf(std::string const &t_str)
{
	if (t_str == "-inf" || t_str == "-inff")
		return (true);
    return (false);
}

static bool	isNanInf(std::string const &t_str)
{
	if (isNan(t_str) || isInf(t_str) || isNegInf(t_str))
		return (true);
    return (false);
}

static ScalarConverter::Type	getType(std::string const &t_str)
{
	size_t	n = t_str.find_first_not_of("0123456789-");
	size_t	dot_n;
	size_t	f_n;

	if (isNanInf(t_str))
		return (ScalarConverter::DOUBLE);
	if (t_str.rfind('-') != 0 && t_str.rfind('-') != std::string::npos)
		return (ScalarConverter::NONE);
	if (n != std::string::npos && t_str.length() > 1)
	{
			if (t_str.find_first_not_of("0123456789.f-") != std::string::npos)
				return (ScalarConverter::NONE);
			dot_n = t_str.find('.');
			if (dot_n == std::string::npos || t_str.find('.', dot_n + 1) != std::string::npos)
				return (ScalarConverter::NONE);
			f_n = t_str.find('f');
			if (f_n == std::string::npos)
				return (ScalarConverter::DOUBLE);
			if (dot_n > f_n || t_str.find('f', f_n + 1) != std::string::npos)
				return (ScalarConverter::NONE);
			f_n = t_str.rfind('f');
			if (t_str.find_first_of("0123456789", f_n) != std::string::npos)
				return (ScalarConverter::NONE);
			return (ScalarConverter::FLOAT);
	}
	if (t_str.length() == 1 && t_str.find_first_not_of("0123456789") != std::string::npos)
		return (ScalarConverter::CHAR);
	return (ScalarConverter::INT);
}

static void	printNone()
{
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

static void	fillChar(char c, int &i, float &f, double &d)
{
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

static void	printChar(std::string const &t_str, char c)
{
	if (isprint(c))
		std::cout << "char: " << c << "\n";
	else if (isNanInf(t_str))
		std::cout << "char: impossible\n";
	else
		std::cout << "char: Non displayable\n";
}

static void	printInt(std::string const &t_str, int i)
{
	if (!isNanInf(t_str))
		std::cout << "int: " << i << "\n";
	else
		std::cout << "int: impossible\n";
}

static void	printFloat(std::string const &t_str, float f)
{
	if (isNan(t_str))
		f = std::numeric_limits<float>::quiet_NaN();
	else if (isInf(t_str))
		f = std::numeric_limits<float>::infinity();
	else if (isNegInf(t_str))
		f = std::numeric_limits<float>::infinity() * -1;
	std::cout << "float: " << f << "f\n";
}

static void	printDouble(std::string const &t_str, double d)
{
	if (isNan(t_str))
		d = std::numeric_limits<double>::quiet_NaN();
	else if (isInf(t_str))
		d = std::numeric_limits<double>::infinity();
	else if (isNegInf(t_str))
		d = std::numeric_limits<double>::infinity() * -1;
	std::cout << "double: " << d << "\n";
}

static void	fillInt(char &c, int i, float &f, double &d)
{
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
}

static void	fillFloat(char &c, int &i, float f, double &d)
{
	i = static_cast<int>(f);
	c = static_cast<char>(f);
	d = static_cast<double>(f);
}

static void	fillDouble(char &c, int &i, float &f, double d)
{
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	c = static_cast<char>(d);
}

void	ScalarConverter::convert(std::string const &t_str)
{
	Type	type = getType(t_str);
	std::stringstream	strs(t_str);
	char	c;
	int		i;
	float	f;
	double	d;

	if (type == NONE)
		return (printNone());
	if (type == CHAR)
	{
		strs >> c;
		if (strs.fail())
			return (printNone());
		fillChar(c, i, f, d);
	}
	else if (type == INT)
	{
		strs >> i;
		if (strs.fail())
			return (printNone());
		fillInt(c, i, f, d);
	}
	else if (type == FLOAT)
	{
		strs >> f;
		if (strs.fail())
			return (printNone());
		fillFloat(c, i, f, d);
	}
	else
	{
		strs >> d;
		if (strs.fail())
			return (printNone());
		fillDouble(c, i, f, d);
	}
	printChar(t_str, c);
	printInt(t_str, i);
	printFloat(t_str, f);
	printDouble(t_str, d);
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &)
{
	return (*this);
}

ScalarConverter::ScalarConverter(ScalarConverter const &)
{
}

ScalarConverter::~ScalarConverter()
{
}

