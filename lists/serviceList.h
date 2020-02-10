//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)

struct serviceNode
{
	tString memNum;//to hold key to ensure proper data is fetched. 
	service * head;
	sNode * next;
	
}sNode;

class serviceList
{
	public:
		serviceList();
		~serviceList();

	private:
		s_node ** table;
} sList;
