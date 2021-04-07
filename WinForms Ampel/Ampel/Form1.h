#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Timer^ timer1;

	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(30, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 125);
			this->label1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Yellow;
			this->label2->Location = System::Drawing::Point(30, 177);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(125, 125);
			this->label2->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Green;
			this->label3->Location = System::Drawing::Point(30, 320);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 125);
			this->label3->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(229, 44);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 49);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(229, 120);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 49);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 486);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Ampel";
			this->ResumeLayout(false);

		}
#pragma endregion
	int nTimer = 0;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = true;
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		switch (nTimer) {

		case 0: label1->Visible = true;
				label2->Visible = false;
				label3->Visible = false;
				timer1->Interval = 5000;
				break;

		case 1:	label1->Visible = true;
				label2->Visible = true;
				label3->Visible = false;
				timer1->Interval = 2000;
				break;

		case 2: label1->Visible = false;
				label2->Visible = false;
				label3->Visible = true;
				timer1->Interval = 5000;
				break;

		case 3: label1->Visible = false;
				label2->Visible = true;
				label3->Visible = false;
				nTimer = 0;
				timer1->Interval = 2000;
				break;

				return;
		}
		nTimer = nTimer + 1;
	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e){
		timer1->Enabled = false;
		label1->Visible = true;
		label2->Visible = true;
		label3->Visible = true;
		timer1->Interval = 200;
		nTimer = 0;
	}

};
}
