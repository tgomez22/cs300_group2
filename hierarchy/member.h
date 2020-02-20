//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)

#include "person.h"

//This class is derived from class person. 
//It contains relevant info to members of ChocAn.
//A true or false if the member is suspended. 
//If the member is suspended, then the amount due is set.
//
class member: public person
{
	public:
		member();
		member(const member & toAdd);
		~member();
		void display()const;
		bool append();

	private:
		bool suspended;
		float amtDue;
};
