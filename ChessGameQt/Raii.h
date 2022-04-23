#pragma once
class Raii
{
public:
	Raii(bool x);
	~Raii();
private:
	bool& isExistent;
};

