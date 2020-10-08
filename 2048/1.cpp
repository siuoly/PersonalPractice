#include<iostream>
using namespace std;

class Grid{

	private:
		int number;
	
	public:
		Grid(int n=2 ):number(n){}
		Grid& operator+(Grid );

		// test print
		friend ostream& operator<<( ostream& , Grid );
};

Grid& Grid::operator+(Grid other){
	number+=other.number;
	return *this;
}

ostream& operator<<( ostream& os , Grid g)
{	
	os << "number: " <<  g.number ;
	return os;
}

int main(){
	cout << a;
}
