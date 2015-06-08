#ifndef SMAP
#define SMAP
#include<iostream>
#include"string"
#include <vector>
using namespace std;
template<typename Comparable>
class SequenceMap
{

public:
	Comparable DNA;
	vector<Comparable> enzyme;
	SequenceMap()
	{

	}
	SequenceMap(string a, string b)
	{
		DNA = a;
		enzyme.push_back(b);
	}
	bool operator < (const SequenceMap & a)const
	{
		return (DNA.compare(a.DNA)<0);
	}

	friend std::ostream& operator<< (std::ostream& stream, const SequenceMap& a) { 
		stream << a.DNA << std::endl; 
		return stream;
	}

	void merge( SequenceMap other)
	{
		enzyme.insert(enzyme.end(), other.enzyme.begin(), other.enzyme.end());
	}


};

#endif