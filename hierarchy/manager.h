//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)

#include "person.h"
class manager: public person
{
	public:
		manager();
		manager(const manager & to_add);
		~manager();
		void display()const;
		bool append();

	private:

	//???
};
