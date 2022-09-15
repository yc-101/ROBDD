#include <iostream>
#include <fstream>
#include <vector>
using std::string, std::cin, std::cout, std::vector;

struct node{
	int index;
	string ilb_name;
	node *else_edge, *then_edge;
};

struct tree{
	node *root;
}


int main(){
    string plaName, dotName;
    cin >> plaName >> dotName;
	ifstream pla;
	ofstream dot;
	pla.open(plaName);
	dot.open(dotName);
//--------------------------
	int num_i, num_o;
	vector<string> ilb;
	string ob;
	while(!fin.eof())
	{
		string op;
		pla >> op;
		if(op == ".i")
		{
			pla >> num_i;
		}
		else if(op == ".o")
		{
			pla >> num_o;
		}
		else if(op == ".ilb")
		{
			ilb.resize(num_i);
			for(int i = 0; i < num_i; i++)
			{
				pla >> op;
				ilb.push_back(op);
			}
		}
		else if(op == ".ob")
		{
			pla >> ob;
		}
		else if(op == ".p")
		{
			int num;
			pla >> num;
			for(int i = 0; i < num; i++)
			{
				pla >> op; // "01-" 1
				
			}
		}


}
