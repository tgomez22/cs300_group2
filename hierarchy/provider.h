//Tristan Gomez

#include "person.h"

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
