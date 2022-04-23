#pragma once
#include <stdexcept>

class TooManyKingsException : public std::logic_error
{
public:
	using logic_error::logic_error;
};

