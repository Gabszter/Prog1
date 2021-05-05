#include <numeric>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print(vector<T> v,string something)
{
	cout << something << endl;
	for(auto a : v) cout << a << " " <<endl;
}

int main()
try{

	const string fname {"teszt2.txt"};
	ifstream ifs{fname};
	if(!ifs) throw runtime_error("No file or can t read.");
	vector<double> vd;
	for(double i;ifs>>i;) vd.push_back(i);
	print(vd,"Basic(double):");

	vector<int> vi;
	for(auto a : vd) vi.push_back(a);
	print(vi,"Basic(int):");
	
	cout << "Pair:" << endl;
	for(int i=0;i<vd.size();++i) cout << vd[i] << "\t" << vi[i] << endl;

	double sum=accumulate(vd.begin(),vd.end(),0.0);
	
	cout << "Double vector sum: " << sum << endl;

	int sum1=accumulate(vi.begin(),vi.end(),0);

	cout << "Double vector - int vector: " << sum-sum1 << endl;

	reverse(vd.begin(),vd.end());
	print(vd,"Double vector reverse: ");

	double av=sum/vd.size();
	cout << "Double vector avg: " << av << endl;

	vector<double> vd2 (vd.size());

	copy_if(vd.begin(),vd.end(),vd2.begin(),[&] (const double a) {return a< av;});
	auto it=copy_if(vd.begin(),vd.end(),vd2.begin(),[&] (const double a) {return a< av;});
	vd2.resize(distance(vd2.begin(),it));
	print(vd2,"Vd2:");

	sort(vd.begin(),vd.end());
	print(vd,"vd sort:");



	return 0;
}catch(exception& e){
	cout << "Error: " << e.what() << endl;
	return 1;
}catch(...){
	cout << "Unknown error" << endl;
	return 2;
}