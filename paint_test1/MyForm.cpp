#include "MyForm.h"
#include "MyForm21.h"


using namespace painttest1;
using namespace System::Drawing;
using namespace System::Collections::Generic;

[STAThreadAttribute]

int main() {
	Application::Run(gcnew MyForm2());
	return 0;
}

System::Void painttest1::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	Graphics^ gr = Graphics::FromImage(bmp);

	Point p1 = Point(0, 0);
	Point p2 = Point(0, 5);
	Point p3 = Point(0, 10);
	Point p4 = Point(0, 15);
	Point p5 = Point(5, 15);
	Point p6 = Point(8, 15);
	Point p7 = Point(8, 13);
	Point p8 = Point(10, 13);
	Point p9 = Point(10, 10);
	Point p10 = Point(15, 10);
	Point p11 = Point(15, 8);
	Point p12 = Point(10, 8);
	Point p13 = Point(10, 5);
	Point p14 = Point(10, 0);
	Point p15 = Point(5, 0);
	Point p16 = Point(0, 0);

	Rectangle r1 = Rectangle(0, 0, 50, 50);
	Rectangle r2 = Rectangle(0, 50, 50, 50);
	Rectangle r3 = Rectangle(0, 100, 50, 50);
	Rectangle r4 = Rectangle(50, 0, 50, 50);
	Rectangle r5 = Rectangle(50, 50, 50, 50);
	Rectangle r6 = Rectangle(50, 100, 50, 50);
	Rectangle r7 = Rectangle(100, 50, 50, 50);

	Rectangle diff1 = Rectangle(80, 130, 20, 20);
	Rectangle diff2 = Rectangle(100, 80, 50, 20);

	infoList = gcnew List<rectangle_info^>;
	infoList2 = gcnew List<rectangle_info^>;

	//array<Rectangle>^ rectList = gcnew array<Rectangle>{r1,r2,r3,r4,r5,r6,r7,diff1,diff2};
	array<Rectangle>^ rectList = gcnew array<Rectangle>{r1, r2, r3, r4, r5, r6, r7};
	array<Rectangle>^ rectList2 = gcnew array<Rectangle>{diff1,diff2};

	array<Point>^ pointList = gcnew array<Point>{p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p11,p12,p13,p14,p15,p16};

	//rectangleの配列からinfoListを作成
	for each (Rectangle var in rectList)
	{
		rectangle_info^ temp = gcnew rectangle_info;

		temp->line1 = gcnew rectangle_line;
		temp->line2 = gcnew rectangle_line;
		temp->line3 = gcnew rectangle_line;
		temp->line4 = gcnew rectangle_line;

		temp->p1 = Point(var.X, var.Y);
		temp->p2 = Point(var.X + var.Width, var.Y);
		temp->p3 = Point(var.X + var.Width, var.Y + var.Height);
		temp->p4 = Point(var.X, var.Y + var.Height);

		temp->line1->startPoint = temp->p1;
		temp->line1->endPoint = temp->p2;
		temp->line2->startPoint = temp->p2;
		temp->line2->endPoint = temp->p3;
		temp->line3->startPoint = temp->p3;
		temp->line3->endPoint = temp->p4;
		temp->line4->startPoint = temp->p4;
		temp->line4->endPoint = temp->p1;

		if (var.Width < 50 || var.Height < 50) {
			temp->cut = true;
		}
		else {
			temp->cut = false;
		}

		temp->pList = gcnew array<Point>{temp->p1,temp->p2,temp->p3,temp->p4};
		temp->lineList = gcnew array<rectangle_line^>{temp->line1, temp->line2, temp->line3, temp->line4};


		infoList->Add(temp);
	}

	for each (Rectangle var in rectList2)
	{
		rectangle_info^ temp = gcnew rectangle_info;

		temp->line1 = gcnew rectangle_line;
		temp->line2 = gcnew rectangle_line;
		temp->line3 = gcnew rectangle_line;
		temp->line4 = gcnew rectangle_line;

		temp->p1 = Point(var.X, var.Y);
		temp->p2 = Point(var.X + var.Width, var.Y);
		temp->p3 = Point(var.X + var.Width, var.Y + var.Height);
		temp->p4 = Point(var.X, var.Y + var.Height);

		temp->line1->startPoint = temp->p1;
		temp->line1->endPoint = temp->p2;
		temp->line2->startPoint = temp->p2;
		temp->line2->endPoint = temp->p3;
		temp->line3->startPoint = temp->p3;
		temp->line3->endPoint = temp->p4;
		temp->line4->startPoint = temp->p4;
		temp->line4->endPoint = temp->p1;

		if (var.Width < 50 || var.Height < 50) {
			temp->cut = true;
		}
		else {
			temp->cut = false;
		}

		temp->pList = gcnew array<Point>{temp->p1, temp->p2, temp->p3, temp->p4};
		temp->lineList = gcnew array<rectangle_line^>{temp->line1, temp->line2, temp->line3, temp->line4};


		infoList2->Add(temp);
	}

	//最初のレクトアングルs処理
	//ポイントの合致数
	int match = 0;
	//総ポイントリスト
	List<Point>^ totallist = gcnew List<Point>;
	//rectangleの接点ポイントのリスト
	tlist = gcnew List<Point>;
	//総線分リスト
	lines = gcnew List<rectangle_line^>;
	//消す線分リスト
	sublines = gcnew List<rectangle_line^>;

	for each (Point^ var in infoList[0]->pList)
	{
		//重複していなければ、総ポイントリストに追加
		if (!distinctCheck(var, totallist)) {
			totallist->Add((Point)var);
		}
		for each (Point^ var2 in infoList[1]->pList)
		{
			if (!distinctCheck(var2, totallist)) {
				totallist->Add((Point)var2);
			}
			//ポイントが合致すれば、tlistに追加
			if (var->Equals(var2)) {
				tlist->Add((Point)var);
				match++;
			}
		}
	}

	//総線分リストを作成
	for each (rectangle_line^ var in infoList[0]->lineList)
	{
		lines->Add(var);
	}
	for each (rectangle_line^ var in infoList[1]->lineList)
	{
		lines->Add(var);
	}

	rectangle_line^ l1 = gcnew rectangle_line;
	rectangle_line^ l2 = gcnew rectangle_line;
	rectangle_line^ l3 = gcnew rectangle_line;
	rectangle_line^ l4 = gcnew rectangle_line;

	l1->startPoint = tlist[0];
	l1->endPoint = tlist[1];
	l2->startPoint = tlist[1];
	l2->endPoint = tlist[0];

	//消去する線分リストを作成
	sublines->Add(l1);
	sublines->Add(l2);
	distinctlines->Add(l1);
	distinctlines->Add(l2);

	//--------------------------------------------------------------

	for (int i = 2; i < 7; i++) {

		//接点が二つなら、以下の処理で問題ないが、三つとなると、別処理が必要

		match = 0;
		tlist = gcnew List<Point>;
		
		List<Point>^ temp = gcnew List<Point>;

		for each (Point^ var in totallist)
		{
			for each (Point^ var2 in infoList[i]->pList)
			{
				if (!distinctCheck(var2, totallist)) {
					if (!distinctCheck(var2, temp)) {
						temp->Add((Point)var2);
					}
				}
				if (var->Equals(var2)) {
					tlist->Add((Point)var);
					match++;
				}
			}
		}

		if (temp->Count != 0) {
			for each (Point var in temp)
			{
				totallist->Add(var);
			}
		}

		for each (rectangle_line^ var in infoList[i]->lineList)
		{
			lines->Add(var);
		}

		if (match == 2) {
			l1 = gcnew rectangle_line;
			l2 = gcnew rectangle_line;


			l1->startPoint = tlist[0];
			l1->endPoint = tlist[1];
			l2->startPoint = tlist[1];
			l2->endPoint = tlist[0];

			sublines->Add(l1);
			sublines->Add(l2);
			distinctlines->Add(l1);
			distinctlines->Add(l2);
		}
		else if (match == 3) {
			l1 = gcnew rectangle_line;
			l2 = gcnew rectangle_line;
			l3 = gcnew rectangle_line;
			l4 = gcnew rectangle_line;

			bool tate = false;
			bool yoko = false;

			//縦線の規定
			if (tlist[0].X == tlist[1].X) {
				l1->startPoint = tlist[0];
				l1->endPoint = tlist[1];
				l2->startPoint = tlist[1];
				l2->endPoint = tlist[0];
				tate = true;
			}
			else if (tlist[0].X == tlist[2].X) {
				l1->startPoint = tlist[0];
				l1->endPoint = tlist[2];
				l2->startPoint = tlist[2];
				l2->endPoint = tlist[0];
				tate = true;

			}
			else if (tlist[1].X == tlist[2].X) {
				l1->startPoint = tlist[1];
				l1->endPoint = tlist[2];
				l2->startPoint = tlist[2];
				l2->endPoint = tlist[1];
				tate = true;
			}
			//横線
			if (tlist[0].Y == tlist[1].Y) {
				l3->startPoint = tlist[0];
				l3->endPoint = tlist[1];
				l4->startPoint = tlist[1];
				l4->endPoint = tlist[0];
				yoko = true;
			}
			else if (tlist[0].Y == tlist[2].Y) {
				l3->startPoint = tlist[0];
				l3->endPoint = tlist[2];
				l4->startPoint = tlist[2];
				l4->endPoint = tlist[0];
				yoko = true;
			}
			else if (tlist[1].Y == tlist[2].Y) {
				l3->startPoint = tlist[1];
				l3->endPoint = tlist[2];
				l4->startPoint = tlist[2];
				l4->endPoint = tlist[1];
				yoko = true;
			}

			if (tate) {
				sublines->Add(l1);
				sublines->Add(l2);
				distinctlines->Add(l1);
				distinctlines->Add(l2);
			}
			if (yoko) {
				sublines->Add(l3);
				sublines->Add(l4);
				distinctlines->Add(l3);
				distinctlines->Add(l4);
			}
		}
	}

	//最小値
	double start_y;
	double start_x;
	int count = 0;

	//yの最小値
	for each (Point var in pointList)
	{
		if (count == 0) {
			start_y=var.Y;
		}else if (var.Y <= start_y) {
			start_y = var.Y;
		}
		count++;
	}

	count = 0;
	for each (Point var in pointList)
	{
		if (count == 0) {
			start_x = var.X;
		}
		if (var.Y == start_y&&var.X<start_x) {
			start_x = var.X;
		}
		count++;
	}

	//始点定義終了

	

	for each (rectangle_info^ var in infoList2)
	{
		if (var->cut) {
			checkContainsLine(var->lineList, lines);
		}
	}

	for (int i = 0; i < sublines->Count; i++) {
		for (int j = 0; j < lines->Count; j++) {
			if (sublines[i]->Equals(lines[j])) {
				//lines->Remove(lines[j]);
				lines->RemoveAt(j);

			}
		}
	}
	


	//同じx軸の座標を取得

	gr->DrawRectangles((gcnew Pen(Color::Blue)), rectList);
	
	for each (rectangle_line^ var in test2)
	{
		gr->DrawLine((gcnew Pen(Color::Yellow)), var->startPoint, var->endPoint);
	}
	for each (rectangle_line^ var in test)
	{
		gr->DrawLine((gcnew Pen(Color::Red)), var->startPoint, var->endPoint);
	}
	
	/*for each (rectangle_line^ var in sublines)
	{
		gr->DrawLine((gcnew Pen(Color::Yellow)), var->startPoint, var->endPoint);
	}
	for each (rectangle_line^ var in lines)
	{
		gr->DrawLine((gcnew Pen(Color::Red)), var->startPoint, var->endPoint);
	}*/
	

	pictureBox1->Image = bmp;

	return System::Void();
}

bool painttest1::MyForm::distinctCheck(Point^ p1, List<Point>^ p2)
{
		for each (Point var2 in p2) {
			if (p1->Equals(var2)) {
				return true;
			}
		}
	
	return false;
}

bool painttest1::MyForm::checkContainsLine(array<rectangle_line^>^ diff_r, List<rectangle_line^>^ total)
{
	sw = gcnew System::IO::StreamWriter("C:\\Users\\chach\\Desktop\\test.txt");
	bool diffline_horizon;
	bool totalline_horizon;
	double min;
	double max;
	List<rectangle_line^>^ add = gcnew List<rectangle_line^>;
	rectangle_line^ before = gcnew rectangle_line;
	rectangle_line^ before2 = gcnew rectangle_line;

	for each (rectangle_line^ var in diff_r)
	{

		//差分矩形の線分が横向きか縦向きか
		if (var->startPoint.Y == var->endPoint.Y) {
			if (var->startPoint.X > var->endPoint.X) {
				before = var;
				int temp;
				temp=var->startPoint.X;
				var->startPoint.X = var->endPoint.X;
				var->endPoint.X = temp;
			}
			diffline_horizon = true;
		}
		else {
			if (var->startPoint.Y > var->endPoint.Y) {
				before = var;
				int temp;
				temp = var->startPoint.Y;
				var->startPoint.Y = var->endPoint.Y;
				var->endPoint.Y = temp;
			}
			diffline_horizon = false;
		}
		for each (rectangle_line^ var2 in total)
		{
			//比較線分の向きを取得
			if (var2->startPoint.Y == var2->endPoint.Y) {
				if (var2->startPoint.X > var2->endPoint.X) {
					before2 = var2;
					int temp;
					temp = var2->startPoint.X;
					var2->startPoint.X = var2->endPoint.X;
					var2->endPoint.X = temp;
				}
				totalline_horizon = true;
			}
			else {
				if (var2->startPoint.Y > var2->endPoint.Y) {
					before2 = var2;
					int temp;
					temp = var2->startPoint.Y;
					var2->startPoint.Y = var2->endPoint.Y;
					var2->endPoint.Y = temp;
				}
				totalline_horizon = false;
			}
			//両方が横向きのとき
			if (diffline_horizon && totalline_horizon) {
				//同じY軸の線分を対象にする
				if (var->startPoint.Y == var2->startPoint.Y) {
					//総線分の終点のほうが値が大きい
					if (var2->startPoint.X < var2->endPoint.X) {
						if (var->startPoint.X == var2->startPoint.X&&var->endPoint.X == var2->endPoint.X) {
							//一致する線分を消去。sublinelistに加える
							sublines->Add(var);
							test2->Add(var);
							//sw->Write("横:完全一致:"+var+"\r\n");
						}
						else if (var->startPoint.X == var2->startPoint.X) {
							//一致する線分を消去。sublinelistに加える
							sublines->Add(var2);
							test2->Add(var2);
							//新たに線分を作成する
							if (distinctlines->Contains(before2)) {
								rectangle_line^ tmp_ = gcnew rectangle_line;
								tmp_->startPoint.X = var2->startPoint.X;
								tmp_->startPoint.Y = var->startPoint.Y;
								tmp_->endPoint.X = var->endPoint.X;
								tmp_->endPoint.Y = var->startPoint.Y;
								add->Add(tmp_);
							}
							else {
								rectangle_line^ tmp = gcnew rectangle_line;
								//追加線分の始点
								tmp->startPoint.X = var->endPoint.X;
								tmp->startPoint.Y = var->startPoint.Y;
								//追加線分の終点
								tmp->endPoint.X = var2->endPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;
								add->Add(tmp);
							}
						}
						else if (var->endPoint.X == var2->endPoint.X) {
							//一致する線分を消去。sublinelistに加える
							sublines->Add(var2);
							test2->Add(var2);
							if (distinctlines->Contains(before2)) {
								rectangle_line^ tmp_ = gcnew rectangle_line;
								tmp_->startPoint.X = var->startPoint.X;
								tmp_->startPoint.Y = var->startPoint.Y;
								tmp_->endPoint.X = var->endPoint.X;
								tmp_->endPoint.Y = var->startPoint.Y;
								add->Add(tmp_);
							}
							else {
								//新たに線分を作成する
								rectangle_line^ tmp = gcnew rectangle_line;
								//追加線分の始点
								tmp->startPoint.X = var2->startPoint.X;
								tmp->startPoint.Y = var->startPoint.Y;
								//追加線分の終点
								tmp->endPoint.X = var->startPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;
								add->Add(tmp);
							}
						}
						else if (var->startPoint.X < var2->startPoint.X||var->endPoint.X>var2->endPoint.X) {
							//アルゴリズム上、例外処理されるべき分岐
							//MessageBox::Show("線分の範囲が異常です");

						}
						else {
							//この分岐で完全にdiff線分がもとの線分に含まれている場合の処理を記述
							//一致する線分を消去。sublinelistに加える
							sublines->Add(var2);
							test2->Add(var2);
							if (distinctlines->Contains(before2)) {
								rectangle_line^ tmp_ = gcnew rectangle_line;
								tmp_->startPoint.X = var->startPoint.X;
								tmp_->startPoint.Y = var->startPoint.Y;
								tmp_->endPoint.X = var->endPoint.X;
								tmp_->endPoint.Y = var->startPoint.Y;
								add->Add(tmp_);
							}
							else {
								rectangle_line^ tmp = gcnew rectangle_line;
								//追加線分の始点
								tmp->startPoint.X = var2->startPoint.X;
								tmp->startPoint.Y = var->startPoint.Y;
								//追加線分の終点
								tmp->endPoint.X = var->startPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;

								rectangle_line^ tmp2 = gcnew rectangle_line;
								//追加線分の始点
								tmp2->startPoint.X = var->endPoint.X;
								tmp2->startPoint.Y = var->startPoint.Y;
								//追加線分の終点
								tmp2->endPoint.X = var2->endPoint.X;
								tmp2->endPoint.Y = var->startPoint.Y;

								add->Add(tmp);
								add->Add(tmp2);
							}
							
						}
					}
				}
			}
			else if (!diffline_horizon && !totalline_horizon) {
				//両方が縦向き
				if (var->startPoint.X == var2->startPoint.X) {
					if (var2->startPoint.Y < var2->endPoint.Y) {
						if (var->startPoint.Y == var2->startPoint.Y&&var->endPoint.Y == var2->endPoint.Y) {
							//一致する線分を消去。sublinelistに加える
							sublines->Add(var);
							test2->Add(var);
						}
						else if (var->startPoint.Y == var2->startPoint.Y) {
							//一致する線分を消去。sublinelistに加える
							sublines->Add(var2);
							test2->Add(var2);
							if (distinctlines->Contains(before2)) {
								rectangle_line^ tmp_ = gcnew rectangle_line;
								tmp_->startPoint.Y = var2->startPoint.Y;
								tmp_->startPoint.X = var->startPoint.X;
								tmp_->endPoint.Y = var->endPoint.Y;
								tmp_->endPoint.X = var->startPoint.X;
								add->Add(tmp_);
							}
							else {
								//新たに線分を作成する
								rectangle_line^ tmp = gcnew rectangle_line;
								//追加線分の始点
								tmp->startPoint.X = var->endPoint.X;
								tmp->startPoint.Y = var->endPoint.Y;
								//追加線分の終点
								tmp->endPoint.X = var2->endPoint.X;
								tmp->endPoint.Y = var2->endPoint.Y;
								add->Add(tmp);
							}
						}
						else if (var->endPoint.Y == var2->endPoint.Y) {
							//一致する線分を消去。sublinelistに加える
							sublines->Add(var2);
							test2->Add(var2);
							if (distinctlines->Contains(before2)) {
								rectangle_line^ tmp_ = gcnew rectangle_line;
								tmp_->startPoint.Y = var->startPoint.Y;
								tmp_->startPoint.X = var->startPoint.X;
								tmp_->endPoint.Y = var->endPoint.Y;
								tmp_->endPoint.X = var->startPoint.X;
								add->Add(tmp_);
							}
							else {
								//新たに線分を作成する
								rectangle_line^ tmp = gcnew rectangle_line;
								//追加線分の始点
								tmp->startPoint.X = var2->startPoint.X;
								tmp->startPoint.Y = var2->startPoint.Y;
								//追加線分の終点
								tmp->endPoint.X = var->startPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;
								add->Add(tmp);
							}
						}
						else if (var->startPoint.Y < var2->startPoint.Y || var->endPoint.Y>var2->endPoint.Y) {
							//アルゴリズム上、例外処理されるべき分岐
							//MessageBox::Show("線分の範囲が異常です");
						}
						else {
							//この分岐で完全にdiff線分がもとの線分に含まれている場合の処理を記述
							//一致する線分を消去。sublinelistに加える
							sublines->Add(var2);
							test2->Add(var2);
							if (distinctlines->Contains(before2)) {
								rectangle_line^ tmp_ = gcnew rectangle_line;
								tmp_->startPoint.Y = var->startPoint.Y;
								tmp_->startPoint.X = var->startPoint.X;
								tmp_->endPoint.Y = var->endPoint.Y;
								tmp_->endPoint.X = var->startPoint.X;
								add->Add(tmp_);
							}
							else {
								rectangle_line^ tmp = gcnew rectangle_line;
								//追加線分の始点
								tmp->startPoint.X = var2->startPoint.X;
								tmp->startPoint.Y = var2->startPoint.Y;
								//追加線分の終点
								tmp->endPoint.X = var->startPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;

								rectangle_line^ tmp2 = gcnew rectangle_line;
								//追加線分の始点
								tmp2->startPoint.X = var->endPoint.X;
								tmp2->startPoint.Y = var->endPoint.Y;
								//追加線分の終点
								tmp2->endPoint.X = var2->endPoint.X;
								tmp2->endPoint.Y = var2->endPoint.Y;

								add->Add(tmp);
								add->Add(tmp2);
							}
						}
					}
				}
			}

			

		}
		for each (rectangle_line^ var in add)
		{
			lines->Add(var);
			test->Add(var);
		}
		
	}
	sw->Close();
	return false;
}


