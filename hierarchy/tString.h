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
		bool addOverwrite(char * toAdd);
		bool addOverwrite(const tString & toAdd);
		bool addNotOverwrite(char * toAdd);
		bool addNotOverwrite(const tString & toAdd);
		void display()const;
		int getArrayValue()const;

		void copyToArg(tString & destination)const;
		void copyFromArg(const tString & source);
		
	private:
		char * array;
};
