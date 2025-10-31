/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:29:32 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/31 11:29:32 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *t_ptr)
{
	return (reinterpret_cast<uintptr_t>(t_ptr));
}

Data	*Serializer::deserialize(uintptr_t t_raw)
{
	return (reinterpret_cast<Data *>(t_raw));
}

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &)
{
}

Serializer &Serializer::operator=(Serializer const &)
{
	return (*this);
}

Serializer::~Serializer()
{
}
