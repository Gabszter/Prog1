// g++ ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp drill12.cpp `fltk-config --ldflags --use-images` -o a.out
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

using namespace Graph_lib;

int main()
try{
	Point tl{100,100};

	Simple_window win{tl, 600,400, "My window"};

	win.wait_for_button();

	//12.7.3
	Axis xa {Axis::x, Point{20,300}, 280,10, "x axis"};

	win.attach(xa);
	win.set_label("Axis-1");
	win.wait_for_button();

	Axis ya {Axis::y, Point{20,300},280,10, "y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("Axis-2");
	win.wait_for_button();

	//12.7.4
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	
	win.attach(sine);
	win.set_label("Function");
	win.wait_for_button();

	//12.7.5
	sine.set_color(Color::blue);

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Polygon");
	win.wait_for_button();

	//12.7.6
	Rectangle r{Point{200,200},100,50};
	win.attach(r);
	win.set_label("Rectangle");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	
	win.attach(poly_rect);
	win.set_label("Closed_polyline");
	win.wait_for_button();

	poly_rect.add(Point{50,75});
	win.set_label("Five_points");
	win.wait_for_button();

	//12.7.7
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Fill");
	win.wait_for_button();

	//12.7.8
	Text t{Point{150,150}, "Hello graphical world!"};
	win.attach(t);
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Text");
	win.wait_for_button();

	//12.7.9
	Image ii{Point{100,50},"badge.jpg"};
	win.attach(ii);
	win.set_label("Image");
	win.wait_for_button();

	ii.move(100,200);
	win.set_label("Image move");
	win.wait_for_button();

	//12.7.10
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m{Point{100,200}, 'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.set_label("And much more");
	win.wait_for_button();



}catch(exception& e) {
	cout << "Exception " << e.what() << "\n";
	return 1; 
}catch(...){
	cout << "error\n";
	return 2;
}