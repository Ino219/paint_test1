#pragma once

namespace painttest1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::AntiqueWhite;
			this->pictureBox1->Location = System::Drawing::Point(22, 28);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(233, 194);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	ref struct rectangle_line {
		Point startPoint;
		Point endPoint;
	};

	ref struct rectangle_info {
		Point p1;
		Point p2;
		Point p3;
		Point p4;
		rectangle_line^ line1;
		rectangle_line^ line2;
		rectangle_line^ line3;
		rectangle_line^ line4;
		bool cut;
		array<Point>^ pList;
		array<rectangle_line^>^ lineList;
	};
	private:List<rectangle_info^>^ infoList;
	private:List<rectangle_info^>^ infoList2;
	private:List<rectangle_line^>^ lines;
	private:List<rectangle_line^>^ sublines;
	private:List<rectangle_line^>^ distinctlines = gcnew List<rectangle_line^>;
	private:List<rectangle_line^>^ test = gcnew List<rectangle_line^>;
	private:List<rectangle_line^>^ test2 = gcnew List<rectangle_line^>;
	private:List<Point>^ tlist;
	private:System::IO::StreamWriter^ sw;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: bool distinctCheck(Point^ p1, List<Point>^ p2);
	private: bool checkContainsLine(array<rectangle_line^>^ diff_r, List<rectangle_line^>^ total);
	//private:System::Void rectangle_line_Delete(List<rectangle_line^>^ list, rectangle_line^ line);
	};
}
