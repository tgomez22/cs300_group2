//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)

struct generalNode
{
	person * data;
	g_node * next;

}gNode;

class generalList
{
	public:
		generalList();
		~generalList();

	private:
		g_node ** table;
} gList;
