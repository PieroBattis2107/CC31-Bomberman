#pragma once
#include "Controladora.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{

	private:
		CControladora* oControladora;
		Bitmap^ bmpSolido = gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^ bmpSuelo = gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Bitmap^ bmpJugador = gcnew Bitmap("Imagenes\\Jugador.png");
		Bitmap^ bmpBomba = gcnew Bitmap("Imagenes\\bomba.png");
		Bitmap^ bmpExplosion = gcnew Bitmap("Imagenes\\explosion.png");
		Bitmap^ bmpMejoras = gcnew Bitmap("Imagenes\\bmpMejoras.png");
		Bitmap^ bmpEnemigo = gcnew Bitmap("Imagenes\\bmpEnemigo.png");
		SolidBrush^ brocha;
		System::Drawing::Font^ font;

	public:
		Juego(void)
		{
			InitializeComponent();
			oControladora = new CControladora();
			//
			//TODO: agregar código de constructor aquí
			//
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0, 0));
			brocha = gcnew SolidBrush(Color::White);
			font = gcnew System::Drawing::Font("Arial", 30);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblNivel;
	private: System::Windows::Forms::ProgressBar^ pbCarga;
	private: System::Windows::Forms::Timer^ trCarga;
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblNivel = (gcnew System::Windows::Forms::Label());
			this->pbCarga = (gcnew System::Windows::Forms::ProgressBar());
			this->trCarga = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// lblNivel
			// 
			this->lblNivel->AutoSize = true;
			this->lblNivel->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNivel->ForeColor = System::Drawing::Color::White;
			this->lblNivel->Location = System::Drawing::Point(212, 237);
			this->lblNivel->Name = L"lblNivel";
			this->lblNivel->Size = System::Drawing::Size(52, 25);
			this->lblNivel->TabIndex = 0;
			this->lblNivel->Text = L"Nivel: ";
			// 
			// pbCarga
			// 
			this->pbCarga->Location = System::Drawing::Point(191, 279);
			this->pbCarga->Name = L"pbCarga";
			this->pbCarga->Size = System::Drawing::Size(161, 23);
			this->pbCarga->TabIndex = 1;
			// 
			// trCarga
			// 
			this->trCarga->Enabled = true;
			this->trCarga->Interval = 2500;
			this->trCarga->Tick += gcnew System::EventHandler(this, &Juego::TrCarga_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(848, 736);
			this->Controls->Add(this->pbCarga);
			this->Controls->Add(this->lblNivel);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Juego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::MantenerTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::UltimaTeclaPresionada);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		oControladora->dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpBomba, bmpExplosion, bmpDestruible, bmpJugador, bmpMejoras, bmpEnemigo);
		buffer->Graphics->DrawString("BOMBAS: " + Convert::ToString(oControladora->getoJugador()->getBomba()->lon()), font, brocha, 585, 20);
		//oControladora->CambiarNivel(); activen si quieren q cambie progresivamente
		this->Text = "" + oControladora->getoJugador()->getVidas();
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void Juego_Load(System::Object^  sender, System::EventArgs^  e) {
		lblNivel->Text = "Nivel: " + oControladora->getNivel();
		oControladora->CambiarNivel();

	}
	private: System::Void MantenerTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up:
			oControladora->getoJugador()->setDireccion(Direcciones::Arriba);
			break;
		case Keys::Down:
			oControladora->getoJugador()->setDireccion(Direcciones::Abajo);
			break;
		case Keys::Left:
			oControladora->getoJugador()->setDireccion(Direcciones::Izquierda);
			break;
		case Keys::Right:
			oControladora->getoJugador()->setDireccion(Direcciones::Derecha);
			break;
		}
	}
	private: System::Void UltimaTeclaPresionada(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Space:
			if (!oControladora->getoJugador()->getBomba()->isEmpty())
				oControladora->getoJugador()->prenderBomba();
			break;
		case Keys::Q:
			oControladora->getoJugador()->addBomba();
		case Keys::Escape:
			oControladora->guardar();
		default:
			oControladora->getoJugador()->setDireccion(Direcciones::Ninguna);
			break;
		}
	}
	private: System::Void TrCarga_Tick(System::Object^ sender, System::EventArgs^ e) {
		lblNivel->Text = "Nivel: " + oControladora->getNivel();
		pbCarga->Increment(10);
		if (trCarga->Interval == 2500 && oControladora->getoArrEnemigos()->getarregloEnemigos()->longitud()<oControladora->getNivel()) {
			oControladora->crear_enemigos_y_mejoras();
		}
		else {
			trCarga->Enabled = false;
			timer1->Enabled = true;

			lblNivel->Visible = false;
			lblNivel->Enabled = false;
			pbCarga->Visible = false;
			pbCarga->Enabled = false;
		}
	}
	};
}
