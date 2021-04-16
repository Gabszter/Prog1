#include "../std_lib_facilities.h"

struct Person {
	Person() {}
	Person(string f,string l, int a);

	string first_name() const {return first;}
	string last_name() const {return last;}
	string name() const {return first+last;}
	int a() const {return age;}
private:
	string first;
	string last;
	int age;
};

Person::Person(string f,string l, int a): first{f},last{l},age{a}
{
	if(age <0 || age>150) error("Invalid age");

	string full_name=f+l;

	for (char c : full_name){
		switch(c){
			case ';' :  case ':' : case '"' : case '[' :
			case ']' : case '*' : case '&' : case '^':
			case '%' : case '$' : case '#' : case '@' : 
			case '!' :
			error("bad char in name");
			break;
			default:
			break;
		}
	}
}
ostream& operator<< (ostream& os,Person& p)
{
	return os << p.first_name() << ' ' << p.last_name() << ' ' << p.a();
}

istream& operator>>(istream& is,Person& p)
{
	string f1;
	string l1;
	int a;

	is >> f1 >> l1 >> a;
	p=Person(f1,l1,a);
	return is;
}
int main()
try{

	Person p("Goofy"," ",63);
	cout << p << endl;

	Person p2;
	cout << "Give me name and age:";
	cin >>p2;
	cout << p2 << endl;
	cout << endl;
	vector<Person> p3;
	cout << "Enter 3 names and ages" << endl;
	for(int i=0;i<3;++i)
	{
		Person vp;
		cin >> vp;
		p3.push_back(vp);
	}
	cout << endl;

	for(int i=0;i<3;i++) cout << p3[i] << endl;


}catch(exception& e){
	cout << "Exception: " << e.what() << endl;
	return 1;
}
catch(...){
	cout << "Unknown error!" << endl;
	return 2;
}