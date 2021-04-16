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
	const int min=-10;
	const int max=10;
	const int points=400;
	const int x_scal=20;
	const int y_scal=20;
	Point origo{300,300};
	
	Simple_window win(Point{100,100},600,600, "Function graphs");
	win.wait_for_button();
	
	Axis x{Axis::x,Point{100,300},400,20, "1==20 pixels"};
	Axis y{Axis::y,Point{300,500},400,20, "1==20 pixels"};
	
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);
	win.wait_for_button();

	Function f1 {one, min,max,origo,points,x_scal,y_scal};
	win.attach(f1);
	win.set_label("One");
	win.wait_for_button();

	Function f2 {slope, min,max,origo,points,x_scal,y_scal};
	win.attach(f2);
	win.set_label("Slope");
	win.wait_for_button();

	Function f3 {cos, min,max,origo,points,x_scal,y_scal };
	f3.set_color(Color::blue);
	win.set_label("Square");
	win.attach(f3);
	win.wait_for_button();

	Function f4 {sloping_cos, min,max,origo,points,x_scal,y_scal};
	win.attach(f4);
	win.set_label("Sloping_cos");
	win.wait_for_button();

}catch(exception& e){
	cout << "exception: " << e.what() << "\n";
	return 1;
}catch(...) {
	cout << "Unknown error\n";
	return 2;
}