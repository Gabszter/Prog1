#include <numeric>
#include <map>
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

template<typename T,typename T2>
void print(const map<T,T2>& m,string something)
{
	cout << something << endl;

	for (const auto& a : m) cout << a.first << ' ' << a.second << endl;

	cout << endl;
}

template<typename T,typename T2>
void fill_by_cin(map<T,T2>& m)
{
	string n;
	int v=0;
	cout << "Enter 10 item and value:" << endl;
	while(m.size()<10)
	{
		cin >> n >> v;
		m.insert(make_pair(n,v));
	}
	cout << endl;
}

void sum(map<string,int>& m)
{
	int sum=0;
	for(auto a : m) sum=sum+a.second;
	cout << sum << endl << endl;
}


void my_copy(map<string,int>& m, map<int,string>& m1)
{
	for(auto a : m) m1.insert(make_pair(a.second,a.first));
}

int main()
try{
	map<string,int> msi;

	msi["Camera"]=6;
	msi["Bike"]=4;
	msi["Tablet"]=9; 
	msi["Robot"]=4;
	msi["Guitar"]=5; 
	msi["Pen"]=1; 
	msi["Pc"]=3;
	msi["Laptop"]=2;
	msi["Mouse"]=8; 
	msi["Key"]=7; 

	print(msi,"Basic:");

	msi.erase(msi.begin(),msi.end());
	print(msi, "After erase:");

	fill_by_cin(msi);
	print(msi, "After fill:");

	cout << "Values sum:";
	sum(msi);

	map<int,string> mis;
	for(auto& a : msi)
	{
		mis[a.second]=a.first;

	}

	my_copy(msi,mis);
	print(mis,"mis:");

	return 0;
}catch(exception& e){
	cout << "Error: " << e.what() << endl;
	return 1;
}catch(...){
	cout << "Unknown error" << endl;
	return 2;
}