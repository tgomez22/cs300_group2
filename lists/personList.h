//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)
//INCLUDE CONST INT SIZE AND MULTBY
struct personNode
{
	entity person;
    int authority; //1 for member, 2 provider, 3 manager
	pNode * next;

}pNode;

class personList
{
	public:
		personList();
		~personList();
		int authenticate(const entity & toCheck); //either pass in memID as arg, or prompt user to enter memID within function to return proper code. 
        
		int managerFunctions(); //If manager, then call this function. Use it as a wrapper for functions that managers can use.
					//put those functions into the private section. 	
		int providerFunctions(); //If provider, then call this function. Use it as a wrapper for functions only providers can use. 
                                //put those functions into the private section. 

	private:
        bool add(const entity & toAdd);
        int getIndex(int keyValue);
		pNode ** table;
} pList;
