//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)

struct personNode
{
	person * data;
	g_node * next;

}pNode;

class personList
{
	public:
		personList();
		~personList();
		int authenticate(); //either pass in memID as arg, or prompt user to enter memID within function to return proper code. 
		int providerFunctions(); //If provider, then call this function. Use it as a wrapper for functions only providers can use. 
	       				 //put those functions into the private section. 
		int managerFunctions(); //If manager, then call this function. Use it as a wrapper for functions that managers can use.
					//put those functions into the private section. 	


	private:

		pNode ** table;
} pList;
