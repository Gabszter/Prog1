#include "Simple_window.h"
#include "Graph.h"

int main()
{
	int max_width=600;
	int max_height=400;

	Simple_window win{Point{100,100}, max_width, max_height, "Graphical classes"};

	//Shape s {Point{100,100}, Point{200,200}}; 

	//Line l (Point{100,100}, Point{200,200});

	//win.attach(l);

	Rectangle r {Point{100,100}, Point{400,200}};
	r.set_fill_color(Color::yellow);
	
	win.attach(r);

	win.wait_for_button();
}