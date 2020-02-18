//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)

struct serviceNode
{
	entity memNum;//to hold key to ensure proper data is fetched. 
	service * head;
	sNode * next;
	
}sNode;

class serviceList
{
	public:
		serviceList();
		~serviceList();
		int memberFunctions();//use this function as a wrapper for member only functions. Put those functions into the private section. 

	private:
		int getKey(const int toUse); //hashing function to get arr index
		bool addService(const service & toAdd);
		int getIndex(const int toUse);
		sNode ** table;
} sList;
