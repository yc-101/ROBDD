#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
using std::string, std::cin, std::cout, std::vector;

struct Node {
  	string ilb_name;
  	int else_edge, then_edge;
	bool isRedundant = 0;
};

void check(string op, int now_op, int now_node, int exp, vector<Node*> nodes)
{
	cout<<"\nnow_node = "<<now_node;
	
	if(op[now_op] == '0')	//else_edge
	{
		if(now_node >= exp)	//if there is 4 ilb, then exp = 2 ^ (exp - 1) = 2 ^ (4-1) = 8, then we decide its edge to be bool 1.
		{
			nodes[now_node]->else_edge = pow(2, exp + 1);
			cout<<"\nnow_node's else edge is "<<nodes[now_node]->else_edge ;
			return;
		}
		check(op, now_op + 1, nodes[now_node]->else_edge, exp, nodes);
	}
	else if(op[now_op] == '1')	//then_edge
	{
		if(now_node >= exp)
		{
			nodes[now_node]->then_edge = pow(2, exp + 1);
			cout<<"\nnow_node's then edge is "<<nodes[now_node]->then_edge ;
			return;
		}
		check(op, now_op + 1, nodes[now_node]->then_edge, exp, nodes);
	}
	else if(op[now_op] == '-')	//dont care
	{
		if(now_node >= exp)
		{
			nodes[now_node]->else_edge = pow(2, exp + 1);
			nodes[now_node]->then_edge = pow(2, exp + 1);
			cout<<"\nediting both......";
			return;
		}
		check(op, now_op + 1, nodes[now_node]->else_edge, exp, nodes);
		check(op, now_op + 1, nodes[now_node]->then_edge, exp, nodes);
	}
	else
	{
		cout << "\n\t[error] op [" <<now_op<<"] = "<< op[now_op];
	}
}

int main() 
{
	string plaName("a.pla"), dotName("robdd.dot");
	//cin >> plaName >> dotName;
	
	std::ifstream pla;
	std::ofstream dot;
	pla.open(plaName);
	dot.open(dotName);
	//--------------------------
	//Node* nodes;
	vector<Node*> nodes;
	int num_i, num_o;
	vector<string> ilb;
	string ob;
	while (!pla.eof()) 
	{
		string op;
		pla >> op;
		if (op == ".i") 
		{
			pla >> num_i;
		} 
		else if (op == ".o") 
		{
			pla >> num_o;
		} 
		else if (op == ".ilb") 
		{
			cout<<"\n-----------ilb-----------\n";
			ilb.resize(num_i);
			nodes.resize(pow(2, num_i) + 1);
			cout<<pow(2, num_i) + 1;
			int j = 1;
			nodes.push_back();
			for (int i = 0; i < num_i; i++) 
			{
				pla >> op;
				ilb.push_back(op);
				for( ; j < pow(2, i); j++)
				{
					nodes[j]->else_edge = j * 2;
					nodes[j]->then_edge = j * 2 + 1;
					nodes[j]->isRedundant = 0;
					cout<<j<<" : "<<nodes[j]->else_edge<<" "<<nodes[j]->then_edge;
				}
			}
			for( ; j < pow(2, num_i); j++)
			{
				nodes[j]->else_edge = 0;
				nodes[j]->then_edge = 0;
				nodes[j]->isRedundant = 0;
			}
		}
		else if (op == ".ob") 
		{
			pla >> ob;
		}
		else if (op == ".p") 
		{
			int num;
			pla >> num;	//how many lines of p (e.g. 001- 1)
			for (int i = 0; i < num; i++) 
			{
				pla >> op; // "01-" 1
				cout<<"\nop = "<<op;
				check(op, 0, 1, pow(2, num_i - 1), nodes);
			}
		}

		cout<<"ALL NODES' I/O:\n";
		for(int i=0; i <= pow(2, num_i); i++)
		{
			cout<<"["<<i<<"] "<<  
				nodes[i]->else_edge<<"\t"<<
				nodes[i]->then_edge<<"\n";
		}
	}
}