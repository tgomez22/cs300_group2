//Tristan Gomez
//
//2/7/2020

class tString
{
	public:
		tString();
		tString(char * toAdd);
		tString(const tString & toAdd);
		~tString();
		int compare(char * toCompare)const;
		int compare(const tString & toCompare)const;
		bool add(char * toAdd);
		bool add(const tString & toAdd);
		
	private:
		char * array;
};
