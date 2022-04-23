#include "Raii.h"

Raii::Raii(bool x) : isExistent(x)
{
	isExistent = true;
}
Raii::~Raii()
{
	isExistent = false;
}
