#pragma once

namespace Wykres {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OknoGlowne
	/// </summary>
	public ref class OknoGlowne : public System::Windows::Forms::Form
	{
	public:
		OknoGlowne(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OknoGlowne()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^  labelX;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownX;
	private: System::Windows::Forms::Label^  labelY;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownY;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OknoGlowne::typeid));
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->numericUpDownX = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->numericUpDownY = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->BeginInit();
			this->SuspendLayout();
			// 
			// labelX
			// 
			this->labelX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelX->AutoSize = true;
			this->labelX->Location = System::Drawing::Point(729, 9);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(30, 13);
			this->labelX->TabIndex = 1;
			this->labelX->Text = L"Oœ X";
			// 
			// numericUpDownX
			// 
			this->numericUpDownX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownX->Location = System::Drawing::Point(732, 25);
			this->numericUpDownX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownX->Name = L"numericUpDownX";
			this->numericUpDownX->Size = System::Drawing::Size(40, 20);
			this->numericUpDownX->TabIndex = 2;
			this->numericUpDownX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownX->ValueChanged += gcnew System::EventHandler(this, &OknoGlowne::numericUpDownX_ValueChanged);
			// 
			// labelY
			// 
			this->labelY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelY->AutoSize = true;
			this->labelY->Location = System::Drawing::Point(729, 63);
			this->labelY->Name = L"labelY";
			this->labelY->Size = System::Drawing::Size(30, 13);
			this->labelY->TabIndex = 3;
			this->labelY->Text = L"Oœ Y";
			// 
			// numericUpDownY
			// 
			this->numericUpDownY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownY->Location = System::Drawing::Point(732, 79);
			this->numericUpDownY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownY->Name = L"numericUpDownY";
			this->numericUpDownY->Size = System::Drawing::Size(40, 20);
			this->numericUpDownY->TabIndex = 4;
			this->numericUpDownY->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownY->ValueChanged += gcnew System::EventHandler(this, &OknoGlowne::numericUpDownY_ValueChanged);
			// 
			// OknoGlowne
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->numericUpDownY);
			this->Controls->Add(this->labelY);
			this->Controls->Add(this->numericUpDownX);
			this->Controls->Add(this->labelX);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"OknoGlowne";
			this->Text = L"Wykres";
			this->Activated += gcnew System::EventHandler(this, &OknoGlowne::OknoGlowne_Activated);
			this->Move += gcnew System::EventHandler(this, &OknoGlowne::OknoGlowne_Move);
			this->Resize += gcnew System::EventHandler(this, &OknoGlowne::OknoGlowne_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

Color kolOsi = Color::Black;

private: System::Void Rysuj(){
			this->Invalidate();
			Application::DoEvents();
			Graphics^ g = this->CreateGraphics();

			int szerokosc = static_cast<int>(g->VisibleClipBounds.Width);
			int wysokosc = static_cast<int>(g->VisibleClipBounds.Height);
			if (wysokosc < 47) return;
			Bitmap^ b = gcnew Bitmap(szerokosc, wysokosc);

			int d = 40; // odsuniêcie osi od krawêdzi
			int m = 10; // margines
			int zeroY = wysokosc - d; // punkt 0 na Y (po³o¿enie osi X) w pikselach
			int xMax = static_cast<int>(numericUpDownX->Value); // maksymalna wartoœæ argumentu
			int yMax = static_cast<int>(numericUpDownY->Value);
			float jednostkaX = (szerokosc - 2.f * d) / xMax; // jednostka osi X w pikselach
			float jednostkaY = (wysokosc - 2.f * d) / yMax;

			for (int i = m; i <= szerokosc - m; i++) b->SetPixel(i, zeroY, kolOsi); // rysuje oœ X
			for (int i = m; i <= wysokosc - m; i++) b->SetPixel(d, i, kolOsi); // rysuje oœ Y

			for (int i = 3; i < 20; i++)
			{
				b->SetPixel(szerokosc - m - i, zeroY + i * 2 / 5, kolOsi); // grot dolny osi X
				b->SetPixel(szerokosc - m - i, zeroY - i * 2 / 5, kolOsi); // grot górny osi X
				b->SetPixel(d + i * 2 / 5, m + i, kolOsi); // grot prawy osi Y
				b->SetPixel(d - i * 2 / 5, m + i, kolOsi); // grot lewy osi Y
			}
			for (int i = 1; i <= xMax;i++) // skala osi X
				for (int j = -5; j <= 5; j++)
					b->SetPixel(d + static_cast<int>(i*jednostkaX), zeroY + j, kolOsi);
			for (int i = 1; i <= yMax; i++) // skala osi Y
				for (int j = -5; j <= 5; j++)
					b->SetPixel(d + j, zeroY - static_cast<int>(i*jednostkaY), kolOsi);

			float dx = 1 / (jednostkaX * 10.f); // czêœæ jednostki na piksel
			for (float x = 0; x <= xMax; x += dx){
				int xx = d + static_cast<int>(x * jednostkaX);
				int yy = zeroY - static_cast<int>(f(x) * jednostkaY);
				if (0 <= yy && yy <= wysokosc) b->SetPixel(xx, yy, Color::Blue);
			}

			for (int i = 1; i <= xMax; i++) g->DrawString(i.ToString(), Font, Brushes::Black, d + i * jednostkaX - 5, zeroY + 8.f);
			for (int i = 1; i <= yMax; i++) g->DrawString(i.ToString(), Font, Brushes::Black, d - 20.f, zeroY - i * jednostkaY - 6);

			g->DrawImage(b, 0, 0);
}

private: System::Double f(double x){
	return x * Math::Sin(x) * Math::Sin(x);
}
private: System::Void numericUpDownX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	Rysuj();
}
private: System::Void numericUpDownY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	Rysuj();
}
private: System::Void OknoGlowne_Resize(System::Object^  sender, System::EventArgs^  e) {
	Rysuj();
}
private: System::Void OknoGlowne_Activated(System::Object^ sender, System::EventArgs^ e) {
	Rysuj();
}
private: System::Void OknoGlowne_Move(System::Object^  sender, System::EventArgs^  e) {
	static int x1, y1;
	int x = this->Location.X, y = this->Location.Y;
	if (x1 < 0 && x1 < x // okno wychodzi z lewej krawêdzi ekranu
		|| Screen::PrimaryScreen->WorkingArea.Width < x1 + this->Size.Width && x < x1 // okno wychodzi z prawej krawêdzi
		|| Screen::PrimaryScreen->WorkingArea.Height < y1 + this->Size.Height && y < y1 // okno wychodzi z dolnej krawêdzi
		) Rysuj();
	x1 = x, y1 = y;
}
};
}
