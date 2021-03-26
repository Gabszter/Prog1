#include "../std_lib_facilities.h"

struct B1{
	virtual void vf() {cout << "B1::vf()\n";}
	void f() {cout << "B1::f()\n";};
	virtual void pvf()=0;
};

struct D1:B1
{
	void vf() override {cout << "D1::vf()\n";}
	void f() {cout << "D1::f()\n";}
};

struct D2:D1{
	void pvf() override {cout << "D2::pvf()\n";}
};

struct B2 {
	virtual void pvf() =0; 
};

struct D21 : B2 {
	string s= "string";
	void pvf() override {cout << s << "\n";}
};

struct D22 : B2 {
	int n= 358cd;
	void pvf() {cout << n << "\n";};
};

void f (B2& b)
{
	b.pvf();
}

int main()
{
	
	//B1 b1;
	//b1.vf();
	//b1.f();

	//D1 d;
	//d1.vf();
	//d1.f();

	//B1& bref=D1;
	//bref.vf();
	//bref.f();
	
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	D21 d21;
	f(d21);

	D22 d22;
	f(d22);

	return 0;
}