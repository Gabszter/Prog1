#include <iostream>
#include <list>
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
	list<Item> li;
	for(Item i;ifs>>i;) li.push_back(i);
	print(li,"Basic");

	li.sort(by_name);
	print(li,"Sort by name");

	li.sort(by_iid);
	print(li,"Sort by iid");

	li.sort(by_value);
	print(li,"Sort by value");

	li.insert(li.begin(),{"horse shoe",99,12.34});
	li.insert(li.begin(),{"Canon S400",9988,499.95});

	print(li,"After insert");

	li.erase(find_if(li.begin(),li.end(),erase_by_name("horse shoe")));
	print(li,"After erase(name)");
	li.erase(find_if(li.begin(),li.end(),erase_by_iid(9988)));
	print(li,"After erase(iid)");

	return 0;
}catch(exception& e){
	cout << "Error: " << e.what() << endl;
	return 1;
}catch(...){
	cout << "Unknown error" << endl;
	return 2;
}