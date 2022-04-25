/*
* \file   TooManyKingsException.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#include <stdexcept>

class TooManyKingsException : public std::logic_error
{
public:
	using logic_error::logic_error;
};

