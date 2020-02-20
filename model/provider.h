#ifndef __PROVIDER_H
#define __PROVIDER_H

//Tristan Gomez

#include "person.h"

class provider: public person
{
	public:
		provider();
		provider(const provider & toAdd);
		~provider();
};

#endif
