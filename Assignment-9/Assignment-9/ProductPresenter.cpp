#include "stdafx.h"
#include "ProductPresenter.h"

#include <iostream>

ProductPresenter::~ProductPresenter()
{
	std::cout << "The product presenter destruictior called"<<std::endl;
}