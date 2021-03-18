// g++ ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a.out

#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

using namespace Graph_lib;

int main()
try{
	//1. f
	const Point tl {100,100};
	Simple_window win(tl, 800,1000,"13 Drill");
	win.wait_for_button();

	//2.f
	int y_size=800;
	int x_size=800;
	int x_grid=100;
	int y_grid=100;

	Lines grid;

	for (int i = x_grid; i < x_size; i+=x_grid)
	{
		grid.add(Point{i,0},Point{i,y_size});
	}

	for (int i = y_grid; i < y_size; i+=y_grid)
	{
			grid.add(Point{0,i},Point{x_size,i});
	}

	win.attach(grid);
	win.set_label("Drill_13-2");
	win.wait_for_button();

	//3. f
	Vector_ref<Rectangle> rect;

	for (int i = 0; i < 8; ++i)
	{
		rect.push_back(new Rectangle{Point{i*100,i*100},100,100});
		rect[i].set_fill_color(Color::red);
		win.attach(rect[i]);
	}
	win.set_label("Drill_13-3");
	win.wait_for_button();


	//4.f
	Image gamer1(Point(300,100),"Gamer.jpg");
	Image gamer2(Point(100,300),"Gamer.jpg");
	Image gamer3(Point(500,300),"Gamer.jpg");
	Image gamer4(Point(300,500),"Gamer.jpg");
	win.attach(gamer1);
	win.attach(gamer2);
	win.attach(gamer3);
	win.attach(gamer4);
	win.set_label("Drill_13-4");
	win.wait_for_button();

	//5.f

	Image smile(Point(0,0),"smile.gif");
	win.attach(smile);
	win.set_label("Drill_13-5");
	win.wait_for_button();

	for(int i=0;i<7;++i)
	{
		smile.move(100,0);
		win.wait_for_button();
	}
	for(int i=0;i<7;++i)
	{
		smile.move(0,100);
		win.wait_for_button();
	}
	for(int i=0;i<7;++i)
	{
		smile.move(-100,0);
		win.wait_for_button();
	}
	for(int i=0;i<7;++i)
	{
		smile.move(0,-100);
		win.wait_for_button();
	}

}catch(exception& e){
	cout << "exception: " << e.what() << "\n";
	return 1;
}catch(...) {
	cout << "Unknown error\n";
	return 2;
}