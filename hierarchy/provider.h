//Tristan Gomez

#include "person.h"

//This class is derived from class person. It contains relevant information that a provider will have 
//associated with them, such as a weekly fee owned and the number of consults in a week. 
class provider: public person
{
	public:
		provider();
		provider(const provider & toAdd);
		~provider();
		void display()const;
		bool append();
	private:
		int consultNum;
		float weeklyFee;
};
