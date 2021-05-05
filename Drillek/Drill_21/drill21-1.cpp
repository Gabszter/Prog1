#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Item
{
	string name;
	int iid;
	double value;
};

istream& operator>>(istream& is,Item& v)
{
	string n;
	int i;
	double val;
	is >> n >> i >> val;
	Item v1 {n,i,val};
	v=v1;
	return is;
}

bool by_name(const Item a, const Item b)
{
	return a.name<b.name;
}

bool by_iid(const Item a, const Item b)
{
	return a.iid<b.iid;
}

bool by_value(const Item a, const Item b)
{
	return a.value<b.value;
}


template<typename T>
void print(const T& t,string something)
{		
	cout <<  something << ":" << endl;
	for(auto a : t)
		cout << a.name << ' ' << a.iid << ' ' << a.value << endl;;
		cout << endl;
}

struct erase_by_name {
	string n;
	erase_by_name(string nm) : n{nm} {}
	bool operator() (const Item it){return it.name==n;}
};

struct erase_by_iid {
	int i;
	erase_by_iid(int id) : i{id} {}
	bool operator() (const Item it){return it.iid==i;}
};

int main()
try{
	const string fname {"teszt.txt"};
	ifstream ifs{fname};
	if(!ifs) throw runtime_error("No file or can t read.");
	vector<Item> vi;
	for(Item i;ifs>>i;) vi.push_back(i);
	print(vi,"Basic");

	sort(vi.begin(),vi.end(),by_name);
	print(vi,"Sort by name");

	sort(vi.begin(),vi.end(),by_iid);
	print(vi,"Sort by iid");

	sort(vi.begin(),vi.end(),by_value);
	print(vi,"Sort by value");

	vi.insert(vi.begin(),{"horse shoe",99,12.34});
	vi.insert(vi.begin(),{"Canon S400",9988,499.95});

	print(vi,"After insert");

	vi.erase(find_if(vi.begin(),vi.end(),erase_by_name("horse shoe")));
	print(vi,"After erase(name)");
	vi.erase(find_if(vi.begin(),vi.end(),erase_by_iid(9988)));
	print(vi,"After erase(iid)");

	return 0;
}catch(exception& e){
	cout << "Error: " << e.what() << endl;
	return 1;
}catch(...){
	cout << "Unknown error" << endl;
	return 2;
}