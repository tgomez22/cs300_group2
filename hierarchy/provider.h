//Tristan Gomez

#include "person.h"

class provider: public person
{
	public:
		provider();
		provider(const provider & to_add);
		~provider();
		void display()const;
		bool append();
	private:
		int consultNum;
		float weeklyFee;
};
