//Tristan Gomez
//
//2/7/2020
#ifndef TSTRING_H
#define TSTRING_H
class tString
{
	public:

        //initializes to null
		tString();

        //initalizes to arg values
		tString(char * toAdd);
		tString(const tString & toAdd);


		~tString();

        //FILE IO PEOPLE!!!!
        //returns char * to stored data. Should be very helpful w/
        //writing out.
        char * getString();

        //END FILE IO PEOPLE!!!

        //returns 0 if matching, else same as strcmp
		int compare(char * toCompare)const;
		int compare(const tString & toCompare)const;

        //initializes data to arg values. will overwrite stored data.
		bool add(char * toAdd);
		bool add(const tString & toAdd);	


		void display()const;

        //returns int of first index value. 
        //Use for authentication
        int getFirstIndex()const;

        //use for hashing, returns ascii sum of all stored data.
        int getArrayValue()const;
		
	private:
		char * array;
};
#endif
