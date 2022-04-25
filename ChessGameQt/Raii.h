/*
* \file   Raii.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once

template<typename T>
class Raii
{
public:
	Raii(T* obj) {obj_ = obj;}
	~Raii() { delete obj_; }
private:
	T* obj_;
};

