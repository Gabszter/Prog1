#include <iostream>
#include <vector>
#include "../std_lib_facilities.h"
using namespace std;

template <typename T>
struct S{
public:
	explicit S(T v=0) : val{v} {} 
	
	S& operator=(const T&);

	T& get();
	const T& get() const;
	void set(const T& v);
private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}
template<typename T>
const T& S<T>::get() const
{
	return val;
}
template<typename T>
ostream& operator<<(ostream& os,vector<T>& v)
{
	for(int i=0;i<v.size();++i)
	{
		os << v[i] << " ";
	}
	return os;
}

template<typename T>
istream& operator>>(istream& is,vector<T>& v)
{
	char ch=0;
	int val;
	is >> ch;
	if(ch!='{'){
		return is;
	}
	while(is>>val){

		v.push_back(val);
		is >> ch;
		if(ch!=',') break;
	}
	return is;
		
}



template<typename T> 
istream& operator>>(istream& is,S<T>& v)
{
	T v1;
	cin >> v1;
	v=v1;
	return is;
}

template<typename T>
void S<T>::set(const T& v)
{
	val=v;
}

template<typename T>
S<T>& S<T>::operator=(const T& new_v)
{
	val=new_v;
	return *this;
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

int main()
try{
	S<int> s_int(5);
	S<char> s_char('x');
	S<double> s_double(3.58);
	S<string> s_string("Hello");
	S<vector<int>> s_vector {vector<int>{1,2,3,4,5}};
   
	cout << "S_int: " << s_int.get() << endl;	
	cout << "S_char: " << s_char.get() << endl;	
	cout << "S_double: " << s_double.get() << endl;	
	cout << "S_string: " << s_string.get() << endl;	
	cout << "S_vector: " << s_vector.get() << endl;	
	cout << endl;

	cout << "Set:" << endl;
	s_int.set(358);
	s_char.set('y');
	s_double.set(3.26);
	s_string.set("Hi");
	cout << "S_int: " << s_int.get() << endl;	
	cout << "S_char: " << s_char.get() << endl;	
	cout << "S_double: " << s_double.get() << endl;	
	cout << "S_string: " << s_string.get() << endl;		
	cout << endl;

	cout << "= operator" << endl;
	s_int=900;
	s_char='N';
	s_double=9.53;
	s_string="Yes";
	cout << "S_int: " << s_int.get() << endl;	
	cout << "S_char: " << s_char.get() << endl;	
	cout << "S_double: " << s_double.get() << endl;	
	cout << "S_string: " << s_string.get() << endl;		
	cout << endl;

	cout << "read_val" << endl;
	cout << "S_int :";
	read_val(s_int);
	cout << "S_char :";
	read_val(s_char);
	cout << "S_double :";
	read_val(s_double);
	cout << "S_string :";
	read_val(s_string);
	cout << endl;
	cout << "S_int: " << s_int.get() << endl;	
	cout << "S_char: " << s_char.get() << endl;	
	cout << "S_double: " << s_double.get() << endl;	
	cout << "S_string: " << s_string.get() << endl;	 	
	cout << endl;

	cout << "Vector:" << "{ val, val, val }" << endl;
	vector<int> vector1;
	read_val(vector1);
	S<vector<int>> s2_vector{vector1};
	cout << s2_vector.get() << endl;
	
	return 0;
}catch(exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
}catch(...){
	cout << "Unknown error" ;
	return 2;
}
