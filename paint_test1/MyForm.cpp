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

	//rectangle�̔z�񂩂�infoList���쐬
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

	//�ŏ��̃��N�g�A���O��s����
	//�|�C���g�̍��v��
	int match = 0;
	//���|�C���g���X�g
	List<Point>^ totallist = gcnew List<Point>;
	//rectangle�̐ړ_�|�C���g�̃��X�g
	tlist = gcnew List<Point>;
	//���������X�g
	lines = gcnew List<rectangle_line^>;
	//�����������X�g
	sublines = gcnew List<rectangle_line^>;

	for each (Point^ var in infoList[0]->pList)
	{
		//�d�����Ă��Ȃ���΁A���|�C���g���X�g�ɒǉ�
		if (!distinctCheck(var, totallist)) {
			totallist->Add((Point)var);
		}
		for each (Point^ var2 in infoList[1]->pList)
		{
			if (!distinctCheck(var2, totallist)) {
				totallist->Add((Point)var2);
			}
			//�|�C���g�����v����΁Atlist�ɒǉ�
			if (var->Equals(var2)) {
				tlist->Add((Point)var);
				match++;
			}
		}
	}

	//���������X�g���쐬
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

	//��������������X�g���쐬
	sublines->Add(l1);
	sublines->Add(l2);
	distinctlines->Add(l1);
	distinctlines->Add(l2);

	//--------------------------------------------------------------

	for (int i = 2; i < 7; i++) {

		//�ړ_����Ȃ�A�ȉ��̏����Ŗ��Ȃ����A�O�ƂȂ�ƁA�ʏ������K�v

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

			//�c���̋K��
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
			//����
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

	//�ŏ��l
	double start_y;
	double start_x;
	int count = 0;

	//y�̍ŏ��l
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

	//�n�_��`�I��

	

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
	


	//����x���̍��W���擾

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

		//������`�̐��������������c������
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
			//��r�����̌������擾
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
			//�������������̂Ƃ�
			if (diffline_horizon && totalline_horizon) {
				//����Y���̐�����Ώۂɂ���
				if (var->startPoint.Y == var2->startPoint.Y) {
					//�������̏I�_�̂ق����l���傫��
					if (var2->startPoint.X < var2->endPoint.X) {
						if (var->startPoint.X == var2->startPoint.X&&var->endPoint.X == var2->endPoint.X) {
							//��v��������������Bsublinelist�ɉ�����
							sublines->Add(var);
							test2->Add(var);
							//sw->Write("��:���S��v:"+var+"\r\n");
						}
						else if (var->startPoint.X == var2->startPoint.X) {
							//��v��������������Bsublinelist�ɉ�����
							sublines->Add(var2);
							test2->Add(var2);
							//�V���ɐ������쐬����
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
								//�ǉ������̎n�_
								tmp->startPoint.X = var->endPoint.X;
								tmp->startPoint.Y = var->startPoint.Y;
								//�ǉ������̏I�_
								tmp->endPoint.X = var2->endPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;
								add->Add(tmp);
							}
						}
						else if (var->endPoint.X == var2->endPoint.X) {
							//��v��������������Bsublinelist�ɉ�����
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
								//�V���ɐ������쐬����
								rectangle_line^ tmp = gcnew rectangle_line;
								//�ǉ������̎n�_
								tmp->startPoint.X = var2->startPoint.X;
								tmp->startPoint.Y = var->startPoint.Y;
								//�ǉ������̏I�_
								tmp->endPoint.X = var->startPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;
								add->Add(tmp);
							}
						}
						else if (var->startPoint.X < var2->startPoint.X||var->endPoint.X>var2->endPoint.X) {
							//�A���S���Y����A��O���������ׂ�����
							//MessageBox::Show("�����͈̔͂��ُ�ł�");

						}
						else {
							//���̕���Ŋ��S��diff���������Ƃ̐����Ɋ܂܂�Ă���ꍇ�̏������L�q
							//��v��������������Bsublinelist�ɉ�����
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
								//�ǉ������̎n�_
								tmp->startPoint.X = var2->startPoint.X;
								tmp->startPoint.Y = var->startPoint.Y;
								//�ǉ������̏I�_
								tmp->endPoint.X = var->startPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;

								rectangle_line^ tmp2 = gcnew rectangle_line;
								//�ǉ������̎n�_
								tmp2->startPoint.X = var->endPoint.X;
								tmp2->startPoint.Y = var->startPoint.Y;
								//�ǉ������̏I�_
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
				//�������c����
				if (var->startPoint.X == var2->startPoint.X) {
					if (var2->startPoint.Y < var2->endPoint.Y) {
						if (var->startPoint.Y == var2->startPoint.Y&&var->endPoint.Y == var2->endPoint.Y) {
							//��v��������������Bsublinelist�ɉ�����
							sublines->Add(var);
							test2->Add(var);
						}
						else if (var->startPoint.Y == var2->startPoint.Y) {
							//��v��������������Bsublinelist�ɉ�����
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
								//�V���ɐ������쐬����
								rectangle_line^ tmp = gcnew rectangle_line;
								//�ǉ������̎n�_
								tmp->startPoint.X = var->endPoint.X;
								tmp->startPoint.Y = var->endPoint.Y;
								//�ǉ������̏I�_
								tmp->endPoint.X = var2->endPoint.X;
								tmp->endPoint.Y = var2->endPoint.Y;
								add->Add(tmp);
							}
						}
						else if (var->endPoint.Y == var2->endPoint.Y) {
							//��v��������������Bsublinelist�ɉ�����
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
								//�V���ɐ������쐬����
								rectangle_line^ tmp = gcnew rectangle_line;
								//�ǉ������̎n�_
								tmp->startPoint.X = var2->startPoint.X;
								tmp->startPoint.Y = var2->startPoint.Y;
								//�ǉ������̏I�_
								tmp->endPoint.X = var->startPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;
								add->Add(tmp);
							}
						}
						else if (var->startPoint.Y < var2->startPoint.Y || var->endPoint.Y>var2->endPoint.Y) {
							//�A���S���Y����A��O���������ׂ�����
							//MessageBox::Show("�����͈̔͂��ُ�ł�");
						}
						else {
							//���̕���Ŋ��S��diff���������Ƃ̐����Ɋ܂܂�Ă���ꍇ�̏������L�q
							//��v��������������Bsublinelist�ɉ�����
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
								//�ǉ������̎n�_
								tmp->startPoint.X = var2->startPoint.X;
								tmp->startPoint.Y = var2->startPoint.Y;
								//�ǉ������̏I�_
								tmp->endPoint.X = var->startPoint.X;
								tmp->endPoint.Y = var->startPoint.Y;

								rectangle_line^ tmp2 = gcnew rectangle_line;
								//�ǉ������̎n�_
								tmp2->startPoint.X = var->endPoint.X;
								tmp2->startPoint.Y = var->endPoint.Y;
								//�ǉ������̏I�_
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


