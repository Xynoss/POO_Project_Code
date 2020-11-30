﻿#pragma once
#include "CL_svc_gestionClient.h"
#include "CL_svc_gestionPersonnes.h"
#include "CL_svc_General.h"

namespace A2POOCorb6
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de FRM_Principal
	/// </summary>

	public ref class FRM_Principal : public System::Windows::Forms::Form
	{
	public:
		FRM_Principal(void)
		{
			InitializeComponent();
			////TODO: ajoutez ici le code du constructeur//
		}protected:
			/// <summary>
			/// Nettoyage des ressources utilisées.
			/// </summary>
			~FRM_Principal()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^ lbl_id;
		private: System::Windows::Forms::TextBox^ txt_idPersonne;
		private: System::Windows::Forms::Label^ lbl_nom;
		private: System::Windows::Forms::TextBox^ txt_nom;
		private: System::Windows::Forms::Label^ lbl_prenom;
		private: System::Windows::Forms::TextBox^ txt_prenom;
		private: System::Windows::Forms::Label^ lbl_message;
		private: System::Windows::Forms::TextBox^ txt_message;
		private: System::Windows::Forms::Button^ btn_first;
		private: System::Windows::Forms::Button^ btn_previous;
		private: System::Windows::Forms::Button^ btn_next;
		private: System::Windows::Forms::Button^ btn_end;
		private: System::Windows::Forms::Button^ btn_nouveau;
		private: System::Windows::Forms::Button^ btn_modifier;
		private: System::Windows::Forms::Button^ btn_sup;
		private: System::Windows::Forms::Button^ btn_enregistrer;
		private: NS_Svc::CL_svc_gestionPersonnes^ processusPersonnes;
		private: NS_Svc::CL_svc_gestionClient^ processusClients;
		private: Data::DataSet^ ds;
		private: Data::DataTable^ dt;
		private: int index;
		private: String^ mode;
		private: System::Windows::Forms::DataGridView^ dataGridView1;
		private: System::Windows::Forms::Button^ btn_refresh;
		private: System::Windows::Forms::ComboBox^ SelecterTable;
		private: System::Windows::Forms::TextBox^ txt_DateNaissance;
		private: System::Windows::Forms::Label^ lbl_DateNaissance;
		private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur -ne modifiez pas
		/// /// le contenu de cette méthode avec l'éditeur de code.
		/// /// </summary>
		void InitializeComponent(void)
		{
			this->lbl_id = (gcnew System::Windows::Forms::Label());
			this->txt_idPersonne = (gcnew System::Windows::Forms::TextBox());
			this->lbl_nom = (gcnew System::Windows::Forms::Label());
			this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			this->lbl_prenom = (gcnew System::Windows::Forms::Label());
			this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			this->lbl_message = (gcnew System::Windows::Forms::Label());
			this->txt_message = (gcnew System::Windows::Forms::TextBox());
			this->btn_first = (gcnew System::Windows::Forms::Button());
			this->btn_previous = (gcnew System::Windows::Forms::Button());
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->btn_end = (gcnew System::Windows::Forms::Button());
			this->btn_nouveau = (gcnew System::Windows::Forms::Button());
			this->btn_modifier = (gcnew System::Windows::Forms::Button());
			this->btn_sup = (gcnew System::Windows::Forms::Button());
			this->btn_enregistrer = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btn_refresh = (gcnew System::Windows::Forms::Button());
			this->SelecterTable = (gcnew System::Windows::Forms::ComboBox());
			this->txt_DateNaissance = (gcnew System::Windows::Forms::TextBox());
			this->lbl_DateNaissance = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->Location = System::Drawing::Point(9, 19);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(47, 13);
			this->lbl_id->TabIndex = 0;
			this->lbl_id->Text = L"ID Client";
			// 
			// txt_idPersonne
			// 
			this->txt_idPersonne->Location = System::Drawing::Point(12, 35);
			this->txt_idPersonne->Name = L"txt_idPersonne";
			this->txt_idPersonne->ReadOnly = true;
			this->txt_idPersonne->Size = System::Drawing::Size(202, 20);
			this->txt_idPersonne->TabIndex = 1;
			// 
			// lbl_nom
			// 
			this->lbl_nom->AutoSize = true;
			this->lbl_nom->Location = System::Drawing::Point(9, 61);
			this->lbl_nom->Name = L"lbl_nom";
			this->lbl_nom->Size = System::Drawing::Size(29, 13);
			this->lbl_nom->TabIndex = 2;
			this->lbl_nom->Text = L"Nom";
			// 
			// txt_nom
			// 
			this->txt_nom->Location = System::Drawing::Point(12, 77);
			this->txt_nom->Name = L"txt_nom";
			this->txt_nom->Size = System::Drawing::Size(202, 20);
			this->txt_nom->TabIndex = 3;
			// 
			// lbl_prenom
			// 
			this->lbl_prenom->AutoSize = true;
			this->lbl_prenom->Location = System::Drawing::Point(9, 103);
			this->lbl_prenom->Name = L"lbl_prenom";
			this->lbl_prenom->Size = System::Drawing::Size(43, 13);
			this->lbl_prenom->TabIndex = 4;
			this->lbl_prenom->Text = L"Prénom";
			// 
			// txt_prenom
			// 
			this->txt_prenom->Location = System::Drawing::Point(12, 119);
			this->txt_prenom->Name = L"txt_prenom";
			this->txt_prenom->Size = System::Drawing::Size(202, 20);
			this->txt_prenom->TabIndex = 5;
			// 
			// lbl_message
			// 
			this->lbl_message->AutoSize = true;
			this->lbl_message->Location = System::Drawing::Point(9, 249);
			this->lbl_message->Name = L"lbl_message";
			this->lbl_message->Size = System::Drawing::Size(50, 13);
			this->lbl_message->TabIndex = 6;
			this->lbl_message->Text = L"Message";
			// 
			// txt_message
			// 
			this->txt_message->Location = System::Drawing::Point(12, 265);
			this->txt_message->Multiline = true;
			this->txt_message->Name = L"txt_message";
			this->txt_message->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_message->Size = System::Drawing::Size(812, 68);
			this->txt_message->TabIndex = 7;
			// 
			// btn_first
			// 
			this->btn_first->Location = System::Drawing::Point(12, 223);
			this->btn_first->Name = L"btn_first";
			this->btn_first->Size = System::Drawing::Size(46, 23);
			this->btn_first->TabIndex = 8;
			this->btn_first->Text = L"<<";
			this->btn_first->UseVisualStyleBackColor = true;
			this->btn_first->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_first_Click);
			// 
			// btn_previous
			// 
			this->btn_previous->Location = System::Drawing::Point(64, 223);
			this->btn_previous->Name = L"btn_previous";
			this->btn_previous->Size = System::Drawing::Size(46, 23);
			this->btn_previous->TabIndex = 9;
			this->btn_previous->Text = L"<";
			this->btn_previous->UseVisualStyleBackColor = true;
			this->btn_previous->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_previous_Click);
			// 
			// btn_next
			// 
			this->btn_next->Location = System::Drawing::Point(116, 223);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(46, 23);
			this->btn_next->TabIndex = 10;
			this->btn_next->Text = L">";
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_next_Click);
			// 
			// btn_end
			// 
			this->btn_end->Location = System::Drawing::Point(168, 223);
			this->btn_end->Name = L"btn_end";
			this->btn_end->Size = System::Drawing::Size(46, 23);
			this->btn_end->TabIndex = 11;
			this->btn_end->Text = L">>";
			this->btn_end->UseVisualStyleBackColor = true;
			this->btn_end->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_end_Click);
			// 
			// btn_nouveau
			// 
			this->btn_nouveau->Location = System::Drawing::Point(220, 19);
			this->btn_nouveau->Name = L"btn_nouveau";
			this->btn_nouveau->Size = System::Drawing::Size(228, 36);
			this->btn_nouveau->TabIndex = 12;
			this->btn_nouveau->Text = L"Nouveau";
			this->btn_nouveau->UseVisualStyleBackColor = true;
			this->btn_nouveau->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_nouveau_Click);
			// 
			// btn_modifier
			// 
			this->btn_modifier->Location = System::Drawing::Point(220, 61);
			this->btn_modifier->Name = L"btn_modifier";
			this->btn_modifier->Size = System::Drawing::Size(228, 36);
			this->btn_modifier->TabIndex = 13;
			this->btn_modifier->Text = L"Modifier";
			this->btn_modifier->UseVisualStyleBackColor = true;
			this->btn_modifier->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_modifier_Click);
			// 
			// btn_sup
			// 
			this->btn_sup->Location = System::Drawing::Point(220, 104);
			this->btn_sup->Name = L"btn_sup";
			this->btn_sup->Size = System::Drawing::Size(228, 35);
			this->btn_sup->TabIndex = 14;
			this->btn_sup->Text = L"Supprimer";
			this->btn_sup->UseVisualStyleBackColor = true;
			this->btn_sup->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_sup_Click);
			// 
			// btn_enregistrer
			// 
			this->btn_enregistrer->BackColor = System::Drawing::SystemColors::Control;
			this->btn_enregistrer->Location = System::Drawing::Point(220, 147);
			this->btn_enregistrer->Name = L"btn_enregistrer";
			this->btn_enregistrer->Size = System::Drawing::Size(228, 99);
			this->btn_enregistrer->TabIndex = 15;
			this->btn_enregistrer->Text = L"ENREGISTRER";
			this->btn_enregistrer->UseVisualStyleBackColor = false;
			this->btn_enregistrer->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_enregistrer_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(454, 25);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(370, 168);
			this->dataGridView1->TabIndex = 16;
			// 
			// btn_refresh
			// 
			this->btn_refresh->Location = System::Drawing::Point(454, 200);
			this->btn_refresh->Name = L"btn_refresh";
			this->btn_refresh->Size = System::Drawing::Size(370, 46);
			this->btn_refresh->TabIndex = 17;
			this->btn_refresh->Text = L"ActualiserClients";
			this->btn_refresh->UseVisualStyleBackColor = true;
			this->btn_refresh->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_refresh_Click);
			// 
			// SelecterTable
			// 
			this->SelecterTable->FormattingEnabled = true;
			this->SelecterTable->Location = System::Drawing::Point(579, 1);
			this->SelecterTable->Name = L"SelecterTable";
			this->SelecterTable->Size = System::Drawing::Size(121, 21);
			this->SelecterTable->TabIndex = 18;
			this->SelecterTable->SelectedIndexChanged += gcnew System::EventHandler(this, &FRM_Principal::SelecterTable_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->txt_DateNaissance->Location = System::Drawing::Point(12, 166);
			this->txt_DateNaissance->Name = L"textBox1";
			this->txt_DateNaissance->Size = System::Drawing::Size(202, 20);
			this->txt_DateNaissance->TabIndex = 19;
			// 
			// label1
			// 
			this->lbl_DateNaissance->AutoSize = true;
			this->lbl_DateNaissance->Location = System::Drawing::Point(9, 150);
			this->lbl_DateNaissance->Name = L"label1";
			this->lbl_DateNaissance->Size = System::Drawing::Size(157, 13);
			this->lbl_DateNaissance->TabIndex = 20;
			this->lbl_DateNaissance->Text = L"DateNaissance (YYYY-MM-DD)";
			// 
			// FRM_Principal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(833, 345);
			this->Controls->Add(this->lbl_DateNaissance);
			this->Controls->Add(this->txt_DateNaissance);
			this->Controls->Add(this->SelecterTable);
			this->Controls->Add(this->btn_refresh);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btn_enregistrer);
			this->Controls->Add(this->btn_sup);
			this->Controls->Add(this->btn_modifier);
			this->Controls->Add(this->btn_nouveau);
			this->Controls->Add(this->btn_end);
			this->Controls->Add(this->btn_next);
			this->Controls->Add(this->btn_previous);
			this->Controls->Add(this->btn_first);
			this->Controls->Add(this->txt_message);
			this->Controls->Add(this->lbl_message);
			this->Controls->Add(this->txt_prenom);
			this->Controls->Add(this->lbl_prenom);
			this->Controls->Add(this->txt_nom);
			this->Controls->Add(this->lbl_nom);
			this->Controls->Add(this->txt_idPersonne);
			this->Controls->Add(this->lbl_id);
			this->Name = L"FRM_Principal";
			this->Text = L"ERP GESTION";
			this->Load += gcnew System::EventHandler(this, &FRM_Principal::FRM_Principal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FRM_Principal_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = 0;
		this->mode = "RIEN";
		this->ds = gcnew Data::DataSet();
		this->processusClients = gcnew NS_Svc::CL_svc_gestionClient();
		this->loadDataClient(this->index);
		this->txt_message->Text = "Data chargées";
	}
	private: void loadDataClient(int index)
	{
		this->ds->Clear();
		this->ds = this->processusClients->listeClient("liste");
		this->txt_idPersonne->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[0]);
		this->txt_nom->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[1]);
		this->txt_prenom->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[2]);
		this->txt_DateNaissance->Text = Convert::ToString(this->ds->Tables["liste"]->Rows[this->index]->ItemArray[3]);
	}

	private: void ActualiserClients() {
		this->FillCombo();
		this->dt = this->processusClients->TableClient();
		BindingSource^ bs = gcnew BindingSource();
		bs->DataSource = this->dt;
		dataGridView1->DataSource = bs;
		this->txt_message->Text += '\n'+"update réussi";
	}

	private:void FillCombo() {
		SelecterTable->Items->Add("Clients");
		SelecterTable->Items->Add("Personnels");
		SelecterTable->Items->Add("Commandes");
		SelecterTable->Items->Add("Stock");
	}

	private: System::Void btn_first_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = 0;
		this->loadDataClient(this->index);
		this->txt_message->Text = "Enregistrement né : " + (this->index + 1);
	}

	private: System::Void btn_previous_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index > 0)
		{
			this->index--;
			this->loadDataClient(this->index);
			this->txt_message->Text = "Enregistrement né : " + (this->index + 1);
		}
	}private: System::Void btn_next_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index < this->ds->Tables["liste"]->Rows->Count - 1)
		{
			this->index++;
			this->loadDataClient(this->index);
			this->txt_message->Text = "Enregistrement né : " + (this->index + 1);
		}
	}private: System::Void btn_end_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = this->ds->Tables["liste"]->Rows->Count - 1;
		this->loadDataClient(this->index);
		this->txt_message->Text = "Enregistrement né : " + (this->index + 1);
	}private: System::Void btn_nouveau_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->txt_idPersonne->Clear();
		this->txt_nom->Clear();
		this->txt_prenom->Clear();
		this->mode = "nouv";
		this->txt_message->Text = "Veuillez saisir les information de la nouvelle personne et enregistrer";
	}private: System::Void btn_modifier_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->mode = "maj";
		this->txt_message->Text = "Veuillez modifier les information de la nouvelle courante et enregistrer.";
	}
	private: System::Void btn_sup_Click(System::Object^ sender, System::EventArgs^ e)
	{

		this->mode = "sup";

		this->txt_message->Text = "Veuillez confirmer la suppression de la personne en cours en enregistrant.";

	}
	private: System::Void btn_enregistrer_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->mode == "nouv")
		{
			int Id;
			Id = this->processusClients->ajouter(this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text);
			this->txt_message->Text = "L'ID généré est le : " + Id + ". ";
		}
		else if (this->mode == "maj")
		{
			this->processusClients->modifier(Convert::ToInt32(this->txt_idPersonne->Text), this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text);
		}
		else if (this->mode == "sup")
		{
			this->processusPersonnes->supprimer(Convert::ToInt32(this->txt_idPersonne->Text));
		}
		this->index = 0;
		this->loadDataClient(this->index);
		ActualiserClients();
		this->txt_message->Text += "Traitement terminé.";
	}

	private: System::Void btn_refresh_Click(System::Object^ sender, System::EventArgs^ e) {
		ActualiserClients();
	}

	private: System::Void SelecterTable_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
		if (this->SelecterTable->SelectedText == "Clients") {
			ActualiserClients();
		}
		else if (this->SelecterTable->SelectedText == "Personnels") {
			
		}
		
	}
};

}