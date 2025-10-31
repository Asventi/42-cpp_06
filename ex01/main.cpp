/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:55:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 16:55:21 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Data.hpp"
#include "Serializer.hpp"
#include "doctest.h"

TEST_CASE("Serialization")
{
	Data	data;
	Data	data2;
	uintptr_t	ptr;

	data.name = "devan";
	data.num = 42;
	CHECK(&data == Serializer::deserialize(Serializer::serialize(&data)));
	ptr = Serializer::serialize(&data);
	data2 = * Serializer::deserialize(ptr);
	CHECK(data2.name == data.name);
	CHECK(data.num == data2.num);
	Serializer::serialize(NULL);
}
