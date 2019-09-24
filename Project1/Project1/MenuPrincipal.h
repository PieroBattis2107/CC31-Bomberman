#pragma once
#include "Juego.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btnInstruccionesDesaparece;
	private: System::Windows::Forms::Button^  btnInstruccionesAparece;
	protected:


	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  Jugar;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnInstruccionesDesaparece = (gcnew System::Windows::Forms::Button());
			this->btnInstruccionesAparece = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Jugar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(473, 193);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnInstruccionesDesaparece
			// 
			this->btnInstruccionesDesaparece->Location = System::Drawing::Point(351, 305);
			this->btnInstruccionesDesaparece->Name = L"btnInstruccionesDesaparece";
			this->btnInstruccionesDesaparece->Size = System::Drawing::Size(112, 29);
			this->btnInstruccionesDesaparece->TabIndex = 1;
			this->btnInstruccionesDesaparece->Text = L"Instrucciones";
			this->btnInstruccionesDesaparece->UseVisualStyleBackColor = true;
			this->btnInstruccionesDesaparece->Click += gcnew System::EventHandler(this, &MenuPrincipal::InstruccionesDesaparece_Click);
			// 
			// btnInstruccionesAparece
			// 
			this->btnInstruccionesAparece->Location = System::Drawing::Point(351, 305);
			this->btnInstruccionesAparece->Name = L"btnInstruccionesAparece";
			this->btnInstruccionesAparece->Size = System::Drawing::Size(112, 29);
			this->btnInstruccionesAparece->TabIndex = 2;
			this->btnInstruccionesAparece->Text = L"Instrucciones";
			this->btnInstruccionesAparece->UseVisualStyleBackColor = true;
			this->btnInstruccionesAparece->Click += gcnew System::EventHandler(this, &MenuPrincipal::InstruccionesAparece_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(640, -27);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(250, 250);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MenuPrincipal::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(648, 315);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(295, 202);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(707, 273);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 39);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Arriba";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(578, 359);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 39);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Izquierda";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(862, 359);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 39);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Derecha";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(772, 520);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 39);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Abajo";
			// 
			// Jugar
			// 
			this->Jugar->Location = System::Drawing::Point(351, 362);
			this->Jugar->Name = L"Jugar";
			this->Jugar->Size = System::Drawing::Size(112, 32);
			this->Jugar->TabIndex = 9;
			this->Jugar->Text = L"Jugar";
			this->Jugar->UseVisualStyleBackColor = true;
			this->Jugar->Click += gcnew System::EventHandler(this, &MenuPrincipal::Jugar_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 592);
			this->Controls->Add(this->Jugar);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btnInstruccionesAparece);
			this->Controls->Add(this->btnInstruccionesDesaparece);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox3);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void InstruccionesAparece_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Width = 800;
	btnInstruccionesDesaparece->Visible = true;
	btnInstruccionesAparece->Visible = false;
}
private: System::Void InstruccionesDesaparece_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Width = 400;
	btnInstruccionesDesaparece->Visible = false;
	btnInstruccionesAparece->Visible = true;
}
private: System::Void MenuPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Jugar_Click(System::Object^  sender, System::EventArgs^  e) {
	Juego^ frm = gcnew Juego();
	this->Visible = false;
	frm->Show();
}
};
}
