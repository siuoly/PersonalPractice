typedef
struct listNode{
	struct listNode* next;
	bool tag;   // F/T: data, down
	union{
		char data;
		listNode* down;
	};

	listNode( char in):tag{false},data{in}{};
	void addData( char );
	void addDown( listNode* );
}Node;


void listNode::addData(char in ){
	this->next = new listNode(in);	
	tag = false;
}


void listNode::addDown( listNode* node )
{
	tag = true;
	this->down = node; 
}
class TreeList{
	private:
		Node root;
	public:
		// TreeList(){};
		void print();

};
void TreeList::print(){
		
}
