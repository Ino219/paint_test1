#include "MyForm21.h"

System::Void painttest1::MyForm2::MyForm2_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	Graphics^ gr = Graphics::FromImage(bmp);

	//1
	/*Point p1 = Point(0, 0);
	Point p2 = Point(150, 0);
	Point p3 = Point(150, 50);
	Point p4 = Point(50, 50);
	Point p5 = Point(50, 150);
	Point p6 = Point(0,150);
	Point p7 = Point(0, 0);*/
	//2
	/*Point p1 = Point(0, 0);
	Point p2 = Point(150, 0);
	Point p3 = Point(150, 150);
	Point p4 = Point(100, 150);
	Point p5 = Point(100, 50);
	Point p6 = Point(0,50);
	Point p7 = Point(0, 0);*/
	//3
	/*Point p1 = Point(0, 0);
	Point p2 = Point(50, 0);
	Point p3 = Point(50, 100);
	Point p4 = Point(150, 100);
	Point p5 = Point(150, 150);
	Point p6 = Point(0,150);
	Point p7 = Point(0, 0);*/
	//4
	Point p1 = Point(100, 0);
	Point p2 = Point(150, 0);
	Point p3 = Point(150, 150);
	Point p4 = Point(0, 150);
	Point p5 = Point(0, 100);
	Point p6 = Point(100, 100);
	Point p7 = Point(100, 0);

	Rectangle rect = Rectangle(0, 0, 150, 150);

	array<Point>^ arr = gcnew array<Point>{p1, p2, p3, p4, p5, p6,p7};

	Point pp;
	double sX;
	double sY;
	double eX;
	double eY;

	for each (Point var in arr)
	{
		sX = rect.X;
		sY = rect.Y;
		eX = rect.X + rect.Width;
		eY = rect.X + rect.Height;
		if (var.X != sX && var.X != eX && var.Y != sY && var.Y != eY) {
			pp = var;
		}
	}

	int type=0;
	if (pp.X - sX < eX - pp.X&&pp.Y - sY < eY - pp.Y) {
		type = 1;
	}
	else if (pp.X - sX > eX - pp.X&&pp.Y - sY < eY - pp.Y) {
		type = 2;
	}
	else if (pp.X - sX < eX - pp.X&&pp.Y - sY > eY - pp.Y) {
		type = 3;
	}
	else if (pp.X - sX > eX - pp.X&&pp.Y - sY > eY - pp.Y) {
		type = 4;
	}

	Rectangle one;
	Rectangle two;

	if (type == 1) {
		one = Rectangle(sX, sY, pp.X, eY);
		two = Rectangle(pp.X, sY, eX - pp.X, pp.X - sY);
	}
	else if (type == 2) {
		one = Rectangle(sX, sY, pp.X, pp.Y - sY);
		two = Rectangle(pp.X, sY, eX - pp.X, eY - sY);
	}
	else if (type == 3) {
		one = Rectangle(sX, sY, pp.X, eY);
		two = Rectangle(pp.X, pp.Y, eX - pp.X, eY - pp.Y);
	}
	else if (type == 4) {
		one = Rectangle(pp.X, sY, eX - pp.X, eY - sY);
		two = Rectangle(sX, pp.Y, pp.X - sX, eY - pp.Y);
	}

	gr->DrawLines((gcnew Pen(Color::Black)), arr);
	gr->DrawRectangle((gcnew Pen(Color::Red, 3)), rect);
	gr->DrawRectangle((gcnew Pen(Color::Blue, 2)), one);
	gr->DrawRectangle((gcnew Pen(Color::Blue, 2)), two);


	pictureBox1->Image = bmp;

	return System::Void();
}
