// g++ ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp drill15_1.cpp `fltk-config --ldflags --use-images` -o a.out

#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}

int main()
try{

	Point orig{xmax/2,ymax/2}
	
	Simple_window win(Point{100,100},600,600, "Function graphs");
	win.wait_for_button();
	
	Axis x{Axis::x,Point{100,300},400,20, "1==20 pixels"};
	Axis y{Axis::y,Point{300,500},400,20, "1==20 pixels"};
	
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);
	win.wait_for_button();

	Function f1 {one, -10,11,Point{300,300},400,20,20};
	win.attach(f1);
	win.wait_for_button();
	Function f2 {slope, -10,11,Point{300,300},400,20,20};
	win.attach(f2);
	win.wait_for_button();
	Function f3 {[](double x) {return x*x;}, -10,11,Point{300,300},400,20,20 };
	f3.set_color(Color::blue);
	win.attach(f3);
	win.wait_for_button();
	Function f4 {[](double x) {return cos(x)*slope(x);}, -10,11,Point{300,300},400,20,20 };
	win.attach(f4);
	win.wait_for_button();

}catch(exception& e){
	cout << "exception: " << e.what() << "\n";
	return 1;
}catch(...) {
	cout << "Unknown error\n";
	return 2;
}