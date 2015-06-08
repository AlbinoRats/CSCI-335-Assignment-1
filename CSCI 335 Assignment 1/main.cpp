#include"AvlTree.h"
#include"BinarySearchTree.h"
#include "LazyDeletion.h"
#include"SequenceMap.h"
#include<iostream>
#include<fstream>
#include <stdlib.h> 
#include<ostream>
#include <cstdlib>
using namespace std;
template<typename Comparable>
void parser(Comparable & tree)
{
	cout << "parsing... Please wait.\n";
	SequenceMap<string> node;
	ifstream rebase;
	rebase.open("rebase.txt");
	string line = "";
	string enzymeacr, sequence;
	string delim = "/";
	getline(rebase, line);
	getline(rebase, line);
	getline(rebase, line);
	getline(rebase, line);
	getline(rebase, line);
	getline(rebase, line);
	getline(rebase, line);
	getline(rebase, line);
	while (getline(rebase, line))
	{
		
		bool markb = false;
		rebase >> line;
		if (line == "")
		{
		}
		else
		{
			line.erase(line.length() - 1, line.length());
			while (line.length() != 0)
			{
				int mark = 0;
				int mark2 = 0;
				if (markb == false){
					enzymeacr = line.substr(mark, line.find(delim));
					mark2 = line.find(delim) + 1;
					line.erase(mark, mark2);
					markb = true;
					node.enzyme.push_back(enzymeacr);
				}


				sequence = line.substr(mark, line.find(delim));
				mark2 = line.find(delim) + delim.length();
				line.erase(mark, mark2);

				node.DNA = sequence;



				//cout << node.DNA<<endl;
			}
			//cout << node.DNA << endl;
			tree.insert(node);

		}
	}
	rebase.close();
	cout << "Done!\n";
}
template<typename Comparable>
void queryTree(Comparable tree,SequenceMap<string> map){
	
	parser(tree);
	//tree.printTree();
	if (tree.contains(map))
	{
		for (int i = 0; i < map.enzyme.size(); i++)
		{
			cout << map.enzyme[i] << endl;
		}
	}
	else{
		cout << "No corresponding enzyme\n";
	}
	cout <<"Total size: "<< map.enzyme.size()<<endl;
	
}
int main()
{
	BinarySearchTree<SequenceMap<string>> bst;
	AvlTree<SequenceMap<string>> avl;
	AvlTreeL<SequenceMap<string>>lazy;
	int choice;
	SequenceMap<string> map;
	cout << "Enter a recognition sequence\n";
	cin >> map.DNA;
	cout << "Enter:\n0: Binary Search Tree\n1:Avl Tree\n2:Lazy Deletion Avl Tree\n";
	cin >> choice;
	if (choice == 0)
	{
		queryTree(bst,map);
	}
	else if (choice == 1)
	{
		queryTree(avl,map);
	}
	else if (choice == 2)
	{
		queryTree(lazy,map);
	}
	else
	{
		"Please enter a valid number";
	}

	//parser(bst);
	//parser(avl);
	//parser(lazy);
	//system("pause");
}