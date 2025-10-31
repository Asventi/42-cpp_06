/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:29:32 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/31 11:29:32 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &);
	Serializer	&operator=(Serializer const &);
	~Serializer();
public:
	static uintptr_t	serialize(Data *t_ptr);
	static Data			*deserialize(uintptr_t t_raw);
};

#endif
