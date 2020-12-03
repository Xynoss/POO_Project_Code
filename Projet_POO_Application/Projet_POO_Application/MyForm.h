#pragma once
#include "CL_svc_gestionClient.h"
#include "CL_svc_gestionPersonnel.h"
#include "Svc_commande.h"
#include "CL_svc_gestionStock.h"

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
    private: NS_Svc::CL_svc_gestionPersonnel^ processusPersonnel;
    private: NS_Svc::CL_svc_gestionClient^ processusClients;
    private: NS_Svc::CL_svc_gestionStock^ processusStock;
    private: NS_Svc::CL_Svc_commande^ processusCommande;
    private: Data::DataSet^ dsClient;
    private: Data::DataSet^ dsPersonnel;
    private: Data::DataSet^ dsCommande;
    private: Data::DataSet^ dsStock;
    private: Data::DataTable^ dtClient;
    private: Data::DataTable^ dtPersonnel;
    private: Data::DataTable^ dtCommande;
    private: Data::DataTable^ dtStock;
    private: int index;
    private: String^ mode;
    private: String^ SelectedTable;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Button^ btn_refresh;

    private: System::Windows::Forms::TextBox^ txt_DateNaissance;
    private: System::Windows::Forms::Label^ lbl_DateNaissance;
    private: System::Windows::Forms::GroupBox^ groupTable;

    private: System::Windows::Forms::RadioButton^ radioButtonStock;
    private: System::Windows::Forms::RadioButton^ radioButtonCommande;
    private: System::Windows::Forms::RadioButton^ radioButtonPersonnel;
    private: System::Windows::Forms::RadioButton^ radioButtonClient;
    private: System::Windows::Forms::Label^ lbl_CodePostal;
    private: System::Windows::Forms::TextBox^ txt_CodePostal;


    private: System::Windows::Forms::TextBox^ txt_Ville;

    private: System::Windows::Forms::Label^ lbl_Ville;
    private: System::Windows::Forms::TextBox^ txt_Adresse;


    private: System::Windows::Forms::Label^ lbl_Adresse;
    private: System::Windows::Forms::Label^ lbl_TypeAdresse;
    private: System::Windows::Forms::TextBox^ txt_TypeAdresse;





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
            this->txt_DateNaissance = (gcnew System::Windows::Forms::TextBox());
            this->lbl_DateNaissance = (gcnew System::Windows::Forms::Label());
            this->groupTable = (gcnew System::Windows::Forms::GroupBox());
            this->radioButtonStock = (gcnew System::Windows::Forms::RadioButton());
            this->radioButtonCommande = (gcnew System::Windows::Forms::RadioButton());
            this->radioButtonPersonnel = (gcnew System::Windows::Forms::RadioButton());
            this->radioButtonClient = (gcnew System::Windows::Forms::RadioButton());
            this->lbl_CodePostal = (gcnew System::Windows::Forms::Label());
            this->txt_CodePostal = (gcnew System::Windows::Forms::TextBox());
            this->txt_Ville = (gcnew System::Windows::Forms::TextBox());
            this->lbl_Ville = (gcnew System::Windows::Forms::Label());
            this->txt_Adresse = (gcnew System::Windows::Forms::TextBox());
            this->lbl_Adresse = (gcnew System::Windows::Forms::Label());
            this->lbl_TypeAdresse = (gcnew System::Windows::Forms::Label());
            this->txt_TypeAdresse = (gcnew System::Windows::Forms::TextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->groupTable->SuspendLayout();
            this->SuspendLayout();
            // 
            // lbl_id
            // 
            this->lbl_id->AutoSize = true;
            this->lbl_id->Location = System::Drawing::Point(12, 141);
            this->lbl_id->Name = L"lbl_id";
            this->lbl_id->Size = System::Drawing::Size(47, 13);
            this->lbl_id->TabIndex = 0;
            this->lbl_id->Text = L"ID Client";
            // 
            // txt_idPersonne
            // 
            this->txt_idPersonne->Location = System::Drawing::Point(12, 157);
            this->txt_idPersonne->Name = L"txt_idPersonne";
            this->txt_idPersonne->ReadOnly = true;
            this->txt_idPersonne->Size = System::Drawing::Size(313, 20);
            this->txt_idPersonne->TabIndex = 1;
            // 
            // lbl_nom
            // 
            this->lbl_nom->AutoSize = true;
            this->lbl_nom->Location = System::Drawing::Point(12, 183);
            this->lbl_nom->Name = L"lbl_nom";
            this->lbl_nom->Size = System::Drawing::Size(29, 13);
            this->lbl_nom->TabIndex = 2;
            this->lbl_nom->Text = L"Nom";
            // 
            // txt_nom
            // 
            this->txt_nom->Location = System::Drawing::Point(12, 199);
            this->txt_nom->Name = L"txt_nom";
            this->txt_nom->Size = System::Drawing::Size(313, 20);
            this->txt_nom->TabIndex = 3;
            // 
            // lbl_prenom
            // 
            this->lbl_prenom->AutoSize = true;
            this->lbl_prenom->Location = System::Drawing::Point(12, 225);
            this->lbl_prenom->Name = L"lbl_prenom";
            this->lbl_prenom->Size = System::Drawing::Size(43, 13);
            this->lbl_prenom->TabIndex = 4;
            this->lbl_prenom->Text = L"Prénom";
            // 
            // txt_prenom
            // 
            this->txt_prenom->Location = System::Drawing::Point(12, 241);
            this->txt_prenom->Name = L"txt_prenom";
            this->txt_prenom->Size = System::Drawing::Size(313, 20);
            this->txt_prenom->TabIndex = 5;
            // 
            // lbl_message
            // 
            this->lbl_message->AutoSize = true;
            this->lbl_message->Location = System::Drawing::Point(5, 567);
            this->lbl_message->Name = L"lbl_message";
            this->lbl_message->Size = System::Drawing::Size(50, 13);
            this->lbl_message->TabIndex = 6;
            this->lbl_message->Text = L"Message";
            // 
            // txt_message
            // 
            this->txt_message->Location = System::Drawing::Point(12, 583);
            this->txt_message->Multiline = true;
            this->txt_message->Name = L"txt_message";
            this->txt_message->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->txt_message->Size = System::Drawing::Size(1254, 68);
            this->txt_message->TabIndex = 7;
            // 
            // btn_first
            // 
            this->btn_first->Location = System::Drawing::Point(154, 502);
            this->btn_first->Name = L"btn_first";
            this->btn_first->Size = System::Drawing::Size(46, 23);
            this->btn_first->TabIndex = 8;
            this->btn_first->Text = L"<<";
            this->btn_first->UseVisualStyleBackColor = true;
            this->btn_first->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_first_Click);
            // 
            // btn_previous
            // 
            this->btn_previous->Location = System::Drawing::Point(206, 502);
            this->btn_previous->Name = L"btn_previous";
            this->btn_previous->Size = System::Drawing::Size(46, 23);
            this->btn_previous->TabIndex = 9;
            this->btn_previous->Text = L"<";
            this->btn_previous->UseVisualStyleBackColor = true;
            this->btn_previous->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_previous_Click);
            // 
            // btn_next
            // 
            this->btn_next->Location = System::Drawing::Point(258, 502);
            this->btn_next->Name = L"btn_next";
            this->btn_next->Size = System::Drawing::Size(46, 23);
            this->btn_next->TabIndex = 10;
            this->btn_next->Text = L">";
            this->btn_next->UseVisualStyleBackColor = true;
            this->btn_next->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_next_Click);
            // 
            // btn_end
            // 
            this->btn_end->Location = System::Drawing::Point(310, 502);
            this->btn_end->Name = L"btn_end";
            this->btn_end->Size = System::Drawing::Size(46, 23);
            this->btn_end->TabIndex = 11;
            this->btn_end->Text = L">>";
            this->btn_end->UseVisualStyleBackColor = true;
            this->btn_end->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_end_Click);
            // 
            // btn_nouveau
            // 
            this->btn_nouveau->Location = System::Drawing::Point(67, 531);
            this->btn_nouveau->Name = L"btn_nouveau";
            this->btn_nouveau->Size = System::Drawing::Size(123, 46);
            this->btn_nouveau->TabIndex = 12;
            this->btn_nouveau->Text = L"Nouveau";
            this->btn_nouveau->UseVisualStyleBackColor = true;
            this->btn_nouveau->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_nouveau_Click);
            // 
            // btn_modifier
            // 
            this->btn_modifier->Location = System::Drawing::Point(196, 531);
            this->btn_modifier->Name = L"btn_modifier";
            this->btn_modifier->Size = System::Drawing::Size(123, 46);
            this->btn_modifier->TabIndex = 13;
            this->btn_modifier->Text = L"Modifier";
            this->btn_modifier->UseVisualStyleBackColor = true;
            this->btn_modifier->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_modifier_Click);
            // 
            // btn_sup
            // 
            this->btn_sup->Location = System::Drawing::Point(325, 531);
            this->btn_sup->Name = L"btn_sup";
            this->btn_sup->Size = System::Drawing::Size(123, 46);
            this->btn_sup->TabIndex = 14;
            this->btn_sup->Text = L"Supprimer";
            this->btn_sup->UseVisualStyleBackColor = true;
            this->btn_sup->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_sup_Click);
            // 
            // btn_enregistrer
            // 
            this->btn_enregistrer->BackColor = System::Drawing::SystemColors::Control;
            this->btn_enregistrer->Location = System::Drawing::Point(454, 531);
            this->btn_enregistrer->Name = L"btn_enregistrer";
            this->btn_enregistrer->Size = System::Drawing::Size(393, 46);
            this->btn_enregistrer->TabIndex = 15;
            this->btn_enregistrer->Text = L"ENREGISTRER";
            this->btn_enregistrer->UseVisualStyleBackColor = false;
            this->btn_enregistrer->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_enregistrer_Click);
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(454, 12);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(812, 513);
            this->dataGridView1->TabIndex = 16;
            // 
            // btn_refresh
            // 
            this->btn_refresh->Location = System::Drawing::Point(853, 531);
            this->btn_refresh->Name = L"btn_refresh";
            this->btn_refresh->Size = System::Drawing::Size(413, 46);
            this->btn_refresh->TabIndex = 17;
            this->btn_refresh->Text = L"Actualiser";
            this->btn_refresh->UseVisualStyleBackColor = true;
            this->btn_refresh->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_refresh_Click);
            // 
            // txt_DateNaissance
            // 
            this->txt_DateNaissance->Location = System::Drawing::Point(12, 288);
            this->txt_DateNaissance->Name = L"txt_DateNaissance";
            this->txt_DateNaissance->Size = System::Drawing::Size(313, 20);
            this->txt_DateNaissance->TabIndex = 19;
            // 
            // lbl_DateNaissance
            // 
            this->lbl_DateNaissance->AutoSize = true;
            this->lbl_DateNaissance->Location = System::Drawing::Point(12, 272);
            this->lbl_DateNaissance->Name = L"lbl_DateNaissance";
            this->lbl_DateNaissance->Size = System::Drawing::Size(157, 13);
            this->lbl_DateNaissance->TabIndex = 20;
            this->lbl_DateNaissance->Text = L"DateNaissance (YYYY-MM-DD)";
            // 
            // groupTable
            // 
            this->groupTable->Controls->Add(this->radioButtonStock);
            this->groupTable->Controls->Add(this->radioButtonCommande);
            this->groupTable->Controls->Add(this->radioButtonPersonnel);
            this->groupTable->Controls->Add(this->radioButtonClient);
            this->groupTable->Location = System::Drawing::Point(12, 12);
            this->groupTable->Name = L"groupTable";
            this->groupTable->Size = System::Drawing::Size(436, 123);
            this->groupTable->TabIndex = 21;
            this->groupTable->TabStop = false;
            this->groupTable->Text = L"Tables";
            // 
            // radioButtonStock
            // 
            this->radioButtonStock->AutoSize = true;
            this->radioButtonStock->Location = System::Drawing::Point(5, 90);
            this->radioButtonStock->Name = L"radioButtonStock";
            this->radioButtonStock->Size = System::Drawing::Size(53, 17);
            this->radioButtonStock->TabIndex = 3;
            this->radioButtonStock->Text = L"Stock";
            this->radioButtonStock->UseVisualStyleBackColor = true;
            // 
            // radioButtonCommande
            // 
            this->radioButtonCommande->AutoSize = true;
            this->radioButtonCommande->Location = System::Drawing::Point(6, 66);
            this->radioButtonCommande->Name = L"radioButtonCommande";
            this->radioButtonCommande->Size = System::Drawing::Size(78, 17);
            this->radioButtonCommande->TabIndex = 2;
            this->radioButtonCommande->Text = L"Commande";
            this->radioButtonCommande->UseVisualStyleBackColor = true;
            // 
            // radioButtonPersonnel
            // 
            this->radioButtonPersonnel->AutoSize = true;
            this->radioButtonPersonnel->Location = System::Drawing::Point(6, 42);
            this->radioButtonPersonnel->Name = L"radioButtonPersonnel";
            this->radioButtonPersonnel->Size = System::Drawing::Size(72, 17);
            this->radioButtonPersonnel->TabIndex = 1;
            this->radioButtonPersonnel->Text = L"Personnel";
            this->radioButtonPersonnel->UseVisualStyleBackColor = true;
            // 
            // radioButtonClient
            // 
            this->radioButtonClient->AutoSize = true;
            this->radioButtonClient->Checked = true;
            this->radioButtonClient->Location = System::Drawing::Point(6, 19);
            this->radioButtonClient->Name = L"radioButtonClient";
            this->radioButtonClient->Size = System::Drawing::Size(56, 17);
            this->radioButtonClient->TabIndex = 0;
            this->radioButtonClient->TabStop = true;
            this->radioButtonClient->Text = L"Clients";
            this->radioButtonClient->UseVisualStyleBackColor = true;
            // 
            // lbl_CodePostal
            // 
            this->lbl_CodePostal->AutoSize = true;
            this->lbl_CodePostal->Location = System::Drawing::Point(12, 407);
            this->lbl_CodePostal->Name = L"lbl_CodePostal";
            this->lbl_CodePostal->Size = System::Drawing::Size(64, 13);
            this->lbl_CodePostal->TabIndex = 27;
            this->lbl_CodePostal->Text = L"Code Postal";
            // 
            // txt_CodePostal
            // 
            this->txt_CodePostal->Location = System::Drawing::Point(12, 423);
            this->txt_CodePostal->Name = L"txt_CodePostal";
            this->txt_CodePostal->Size = System::Drawing::Size(313, 20);
            this->txt_CodePostal->TabIndex = 26;
            // 
            // txt_Ville
            // 
            this->txt_Ville->Location = System::Drawing::Point(12, 376);
            this->txt_Ville->Name = L"txt_Ville";
            this->txt_Ville->Size = System::Drawing::Size(313, 20);
            this->txt_Ville->TabIndex = 25;
            // 
            // lbl_Ville
            // 
            this->lbl_Ville->AutoSize = true;
            this->lbl_Ville->Location = System::Drawing::Point(12, 360);
            this->lbl_Ville->Name = L"lbl_Ville";
            this->lbl_Ville->Size = System::Drawing::Size(26, 13);
            this->lbl_Ville->TabIndex = 24;
            this->lbl_Ville->Text = L"Ville";
            // 
            // txt_Adresse
            // 
            this->txt_Adresse->Location = System::Drawing::Point(12, 334);
            this->txt_Adresse->Name = L"txt_Adresse";
            this->txt_Adresse->Size = System::Drawing::Size(313, 20);
            this->txt_Adresse->TabIndex = 23;
            // 
            // lbl_Adresse
            // 
            this->lbl_Adresse->AutoSize = true;
            this->lbl_Adresse->Location = System::Drawing::Point(12, 318);
            this->lbl_Adresse->Name = L"lbl_Adresse";
            this->lbl_Adresse->Size = System::Drawing::Size(45, 13);
            this->lbl_Adresse->TabIndex = 22;
            this->lbl_Adresse->Text = L"Adresse";
            // 
            // lbl_TypeAdresse
            // 
            this->lbl_TypeAdresse->AutoSize = true;
            this->lbl_TypeAdresse->Location = System::Drawing::Point(12, 451);
            this->lbl_TypeAdresse->Name = L"lbl_TypeAdresse";
            this->lbl_TypeAdresse->Size = System::Drawing::Size(80, 13);
            this->lbl_TypeAdresse->TabIndex = 29;
            this->lbl_TypeAdresse->Text = L"Type d\'Adresse";
            // 
            // txt_TypeAdresse
            // 
            this->txt_TypeAdresse->Location = System::Drawing::Point(12, 467);
            this->txt_TypeAdresse->Name = L"txt_TypeAdresse";
            this->txt_TypeAdresse->Size = System::Drawing::Size(313, 20);
            this->txt_TypeAdresse->TabIndex = 28;
            // 
            // FRM_Principal
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1278, 663);
            this->Controls->Add(this->lbl_TypeAdresse);
            this->Controls->Add(this->txt_TypeAdresse);
            this->Controls->Add(this->lbl_CodePostal);
            this->Controls->Add(this->txt_CodePostal);
            this->Controls->Add(this->txt_Ville);
            this->Controls->Add(this->lbl_Ville);
            this->Controls->Add(this->txt_Adresse);
            this->Controls->Add(this->lbl_Adresse);
            this->Controls->Add(this->groupTable);
            this->Controls->Add(this->lbl_DateNaissance);
            this->Controls->Add(this->txt_DateNaissance);
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
            this->Text = L"D";
            this->Load += gcnew System::EventHandler(this, &FRM_Principal::FRM_Principal_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->groupTable->ResumeLayout(false);
            this->groupTable->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void FRM_Principal_Load(System::Object^ sender, System::EventArgs^ e)
    {
        this->index = 0;
        this->mode = "RIEN";
        this->SelectedTable = "personnel";
        this->dsClient = gcnew Data::DataSet();
        this->dsPersonnel = gcnew Data::DataSet();
        this->dsCommande = gcnew Data::DataSet();
        this->dsStock = gcnew Data::DataSet();
        this->processusClients = gcnew NS_Svc::CL_svc_gestionClient();
        this->processusPersonnel = gcnew NS_Svc::CL_svc_gestionPersonnel();
        this->processusCommande = gcnew NS_Svc::CL_Svc_commande();
        this->processusStock = gcnew NS_Svc::CL_svc_gestionStock();
        this->loadData(this->index);
        this->Actualiser();
        this->txt_message->Text = "Data chargées";
    }
    private: void loadData(int index)
    {
        if (this->radioButtonClient->Checked) {

            this->dsClient->Clear();
            this->dsClient = this->processusClients->listeClient("liste");
            this->txt_idPersonne->Text = Convert::ToString(this->dsClient->Tables["liste"]->Rows[this->index]->ItemArray[0]);
            this->txt_nom->Text = Convert::ToString(this->dsClient->Tables["liste"]->Rows[this->index]->ItemArray[1]);
            this->txt_prenom->Text = Convert::ToString(this->dsClient->Tables["liste"]->Rows[this->index]->ItemArray[2]);
            this->txt_DateNaissance->Text = Convert::ToString(this->dsClient->Tables["liste"]->Rows[this->index]->ItemArray[3]);
            this->txt_Adresse->Text = Convert::ToString(this->dsClient->Tables["liste"]->Rows[this->index]->ItemArray[5]);
            this->txt_Ville->Text = Convert::ToString(this->dsClient->Tables["liste"]->Rows[this->index]->ItemArray[6]);
            this->txt_CodePostal->Text = Convert::ToString(this->dsClient->Tables["liste"]->Rows[this->index]->ItemArray[7]);
            this->txt_TypeAdresse->Text = Convert::ToString(this->dsClient->Tables["liste"]->Rows[this->index]->ItemArray[8]);
        }
        else if (this->radioButtonPersonnel->Checked) {

            this->dsPersonnel->Clear();
            this->dsPersonnel = this->processusPersonnel->ListePersonnel("liste");
            this->txt_idPersonne->Text = Convert::ToString(this->dsPersonnel->Tables["liste"]->Rows[this->index]->ItemArray[0]);
            this->txt_nom->Text = Convert::ToString(this->dsPersonnel->Tables["liste"]->Rows[this->index]->ItemArray[1]);
            this->txt_prenom->Text = Convert::ToString(this->dsPersonnel->Tables["liste"]->Rows[this->index]->ItemArray[2]);
            this->txt_DateNaissance->Text = Convert::ToString(this->dsPersonnel->Tables["liste"]->Rows[this->index]->ItemArray[3]); 
            this->txt_Adresse->Text = Convert::ToString(this->dsPersonnel->Tables["liste"]->Rows[this->index]->ItemArray[4]);
            this->txt_Ville->Text = Convert::ToString(this->dsPersonnel->Tables["liste"]->Rows[this->index]->ItemArray[5]);
        }
        else if (this->radioButtonCommande->Checked) {
            this->dsCommande->Clear();
            this->dsCommande = this->processusCommande->listeCommande("liste");
            this->txt_idPersonne->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[0]);
            this->txt_nom->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[1]);
            this->txt_prenom->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[2]);
            this->txt_DateNaissance->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[3]);
            this->txt_Adresse->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[4]);
            this->txt_Ville->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[5]);
        }
        else if (this->radioButtonStock->Checked) {
            this->dsStock->Clear();
            this->dsStock = this->processusStock->ListeArticle("liste");
            this->txt_idPersonne->Text = Convert::ToString(this->dsStock->Tables["liste"]->Rows[this->index]->ItemArray[0]);
            this->txt_nom->Text = Convert::ToString(this->dsStock->Tables["liste"]->Rows[this->index]->ItemArray[1]);
            this->txt_prenom->Text = Convert::ToString(this->dsStock->Tables["liste"]->Rows[this->index]->ItemArray[2]);
            this->txt_DateNaissance->Text = Convert::ToString(this->dsStock->Tables["liste"]->Rows[this->index]->ItemArray[3]);
            this->txt_Adresse->Text = Convert::ToString(this->dsStock->Tables["liste"]->Rows[this->index]->ItemArray[4]);
            this->txt_Ville->Text = Convert::ToString(this->dsStock->Tables["liste"]->Rows[this->index]->ItemArray[5]);
            this->txt_CodePostal->Text = Convert::ToString(this->dsStock->Tables["liste"]->Rows[this->index]->ItemArray[6]);
        }

    }


    private: void Actualiser() {
        if (this->radioButtonClient->Checked) {
            this->index = 0;
            this->dtClient = this->processusClients->TableClient();
            BindingSource^ bs = gcnew BindingSource();
            bs->DataSource = this->dtClient;
            dataGridView1->DataSource = bs;
            loadData(this->index);
            this->lbl_id->Text = "ID Client :";
            this->lbl_nom->Text = "Nom :";
            this->lbl_prenom->Text = "Prenom :";
            this->lbl_DateNaissance->Text = "DateNaissance :";
            this->lbl_Adresse->Text = "Adresse :";
            this->lbl_Ville->Text = "Ville :";
            this->lbl_CodePostal->Text = "Code Postal :";
            this->lbl_TypeAdresse->Text = "Type de l'adresse :";
            this->txt_message->Text = "update réussi Clients";
        }
        else if (this->radioButtonPersonnel->Checked) {
            this->index = 0;
            this->dtPersonnel = this->processusPersonnel->TablePersonnel();
            BindingSource^ bs = gcnew BindingSource();
            bs->DataSource = this->dtPersonnel;
            dataGridView1->DataSource = bs;
            loadData(this->index);
            this->lbl_id->Text = "ID Personnel :";
            this->lbl_nom->Text = "Nom :";
            this->lbl_prenom->Text = "Prenom :";
            this->lbl_DateNaissance->Text = "Adresse :";
            this->lbl_Adresse->Text = "Date d'embauche :";
            this->lbl_Ville->Text = "Identificateur du superviseur :";
            this->lbl_CodePostal->Text = "";
            this->txt_CodePostal->Text = "";
            this->txt_CodePostal->ReadOnly = true;
            this->lbl_TypeAdresse->Text = "";
            this->txt_TypeAdresse->Text = "";
            this->txt_TypeAdresse->ReadOnly = true;
            this->txt_message->Text = "update réussi personnel";
        }
        else if (this->radioButtonCommande->Checked) {
            this->index = 0;
            this->dtCommande = this->processusCommande->TableCommande();
            BindingSource^ bs = gcnew BindingSource();
            bs->DataSource = this->dtPersonnel;
            dataGridView1->DataSource = bs;
            loadData(this->index);
            this->lbl_id->Text = "ID Personnel :";
            this->lbl_nom->Text = "Prenom :";
            this->lbl_prenom->Text = "Adresse :";
            this->lbl_DateNaissance->Text = "Date d'embauche :";
            this->lbl_Adresse->Text = "Nom :";
            this->lbl_Ville->Text = "Identificateur du superviseur :";
            this->lbl_CodePostal->Text = "";
            this->txt_CodePostal->ReadOnly = true;
            this->lbl_TypeAdresse->Text = "";
            this->txt_TypeAdresse->ReadOnly = true;
            this->txt_message->Text = "update réussi commande";
        }
        else if (this->radioButtonStock->Checked) {
            this->index = 0;
            this->dtStock = this->processusStock->TableStock();
            BindingSource^ bs = gcnew BindingSource();
            bs->DataSource = this->dtStock;
            dataGridView1->DataSource = bs;
            loadData(this->index);
            this->lbl_id->Text = "ID Article :";
            this->lbl_nom->Text = "Nom de l'article :";
            this->lbl_prenom->Text = "Nature de l'aricle :";
            this->lbl_DateNaissance->Text = "Référence de l'article :";
            this->lbl_Adresse->Text = "Couleur de l'article";
            this->lbl_Ville->Text = "Nombre en Stock :";
            this->lbl_CodePostal->Text = "Prix Unitaire";
            this->txt_CodePostal->ReadOnly = false;
            this->lbl_TypeAdresse->Text = "";
            this->txt_TypeAdresse->Text = "";
            this->txt_TypeAdresse->ReadOnly = true;
            this->txt_message->Text = "update réussi Stock";
        }

    }


    private: System::Void btn_first_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->index = 0;
        this->loadData(this->index);
        this->txt_message->Text = "Enregistrement né : " + (this->index + 1);
    }

    private: System::Void btn_previous_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (this->index > 0)
        {
            this->index--;
            this->loadData(this->index);
            this->txt_message->Text = "Enregistrement né : " + (this->index + 1);
        }
    }

    private: System::Void btn_next_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (this->radioButtonClient->Checked)
        {
            if (this->index < this->dsClient->Tables["liste"]->Rows->Count - 1) {
                this->index++;
                this->loadData(this->index);
                this->txt_message->Text = "Client n° " + (this->index + 1);
            } 
        }
        else if (this->radioButtonPersonnel->Checked)
        {
            if (this->index < this->dsPersonnel->Tables["liste"]->Rows->Count - 1) {
                this->index++;
                this->loadData(this->index);
                this->txt_message->Text = "Personnel n° " + (this->index + 1);
            }
            
        }
        else if (this->radioButtonCommande->Checked) {
            if (this->index < this->dsCommande->Tables["liste"]->Rows->Count - 1) {
                this->index++;
                this->loadData(this->index);
                this->txt_message->Text = "numéro de la commande : " + (this->index + 1);
            }
        }
        else if (this->radioButtonStock->Checked) {
            if (this->index < this->dsStock->Tables["liste"]->Rows->Count - 1) {
                this->index++;
                this->loadData(this->index);
                this->txt_message->Text = "Article numéro : " + (this->index + 1);
            }
        }
    }

    private: System::Void btn_end_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (this->radioButtonClient->Checked) {
            this->index = this->dsClient->Tables["liste"]->Rows->Count - 1;
        }
        else if (this->radioButtonPersonnel->Checked) {
            this->index = this->dsPersonnel->Tables["liste"]->Rows->Count - 1;
        }
        else if (this->radioButtonCommande->Checked) {
            this->index = this->dsCommande->Tables["liste"]->Rows->Count - 1;
        }
        else if (this->radioButtonStock->Checked) {
            this->index = this->dsStock->Tables["liste"]->Rows->Count - 1;
        }
        
        this->loadData(this->index);
        this->txt_message->Text = "Enregistrement né : " + (this->index + 1);
    }

    private: System::Void btn_nouveau_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->txt_idPersonne->Clear();
        this->txt_nom->Clear();
        this->txt_prenom->Clear();
        this->txt_DateNaissance->Clear();
        this->txt_Adresse->Clear();
        this->txt_Ville->Clear();
        this->txt_CodePostal->Clear();
        this->txt_TypeAdresse->Clear();
        this->mode = "nouv";
        this->txt_message->Text = "Veuillez saisir les information de la nouvelle personne et enregistrer";
    }

    private: System::Void btn_modifier_Click(System::Object^ sender, System::EventArgs^ e)
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
        if (this->radioButtonClient->Checked) {
            if (this->mode == "nouv")
            {
                int Id;
                Id = this->processusClients->ajouter(this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text, this->txt_Adresse->Text, this->txt_Ville->Text, this->txt_CodePostal->Text, this->txt_TypeAdresse->Text);
                this->txt_message->Text = "L'ID généré est le : " + Id + ". ";
                this->mode = "RIEN";
            }
            else if (this->mode == "maj")
            {
                this->processusClients->modifier(Convert::ToInt32(this->txt_idPersonne->Text), this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text, this->txt_Adresse->Text, this->txt_Ville->Text, this->txt_CodePostal->Text, this->txt_TypeAdresse->Text);
                this->mode = "RIEN";
            }
            else if (this->mode == "sup")
            {
                this->processusClients->supprimer(Convert::ToInt32(this->txt_idPersonne->Text));
                this->mode = "RIEN";
            }
            this->index = 0;
            this->loadData(this->index);
            Actualiser();
            this->txt_message->Text += "Traitement terminé.";
        }
        else if (this->radioButtonPersonnel->Checked) {
            if (this->mode == "nouv")
            {
                if (this->txt_Ville->Text != "") {
                    int Id;
                    Id = this->processusPersonnel->ajouter(this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text, this->txt_Adresse->Text, Convert::ToInt32(this->txt_Ville->Text));
                    this->txt_message->Text = "L'ID généré est le : " + Id + ". ";
                }
                else {
                    int Id;
                    Id = this->processusPersonnel->ajouterSSup(this->txt_Adresse->Text, this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text);
                    this->txt_message->Text = "L'ID généré est le : " + Id + ". ";
                }
                this->mode = "RIEN";

            }
            else if (this->mode == "maj")
            {
                if (this->txt_Ville->Text != "") {
                    this->processusPersonnel->modifier(Convert::ToInt32(this->txt_idPersonne->Text), Convert::ToInt32(this->txt_Ville->Text), this->txt_Adresse->Text, this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text);
                }
                else {
                    this->processusPersonnel->modifierSSup(Convert::ToInt32(this->txt_idPersonne->Text), this->txt_Adresse->Text, this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text);
                }
                this->mode = "RIEN";

            }
            else if (this->mode == "sup")
            {
                this->processusPersonnel->supprimer(Convert::ToInt32(this->txt_idPersonne->Text));
                this->mode = "RIEN";
            }
            this->index = 0;
            this->loadData(this->index);
            Actualiser();
            this->txt_message->Text += "Traitement terminé.";
        }
        /*else if (this->radioButtonCommande->Checked) {
            if (this->mode == "nouv")
            {
                int Id;
                Id = this->processusCommande->ajouter(this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text, this->txt_Adresse->Text, this->txt_Ville->Text, this->txt_CodePostal->Text, this->txt_TypeAdresse->Text);
                this->txt_message->Text = "L'ID généré est le : " + Id + ". ";
                this->mode = "RIEN";
            }
            else if (this->mode == "maj")
            {
                this->processusCommande->modifier(Convert::ToInt32(this->txt_idPersonne->Text), this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text, this->txt_Adresse->Text, this->txt_Ville->Text, this->txt_CodePostal->Text, this->txt_TypeAdresse->Text);
                this->mode = "RIEN";
            }
            else if (this->mode == "sup")
            {
                this->processusCommande->supprimer(Convert::ToInt32(this->txt_idPersonne->Text));
                this->mode = "RIEN";
            }
            this->index = 0;
            this->loadData(this->index);
            Actualiser();
            this->txt_message->Text += "Traitement terminé.";
        }*/
        else if (this->radioButtonStock->Checked) {
            if (this->mode == "nouv")
            {
                int Id;
                Id = this->processusStock->ajouter(this->txt_nom->Text /*nom de l'article*/ , this->txt_prenom->Text /*Nature de l'article*/, this->txt_DateNaissance->Text /*reference de l'article*/, this->txt_Adresse->Text /*couleur de l'article*/, Convert::ToInt16(this->txt_Ville->Text)/*nombre en stock d'article X*/, this->txt_CodePostal->Text/*prix à l'unité*/);
                this->txt_message->Text = "L'ID généré est le : " + Id + ". ";
                this->mode = "RIEN";
            }
            else if (this->mode == "maj")
            {
                this->processusStock->modifier(Convert::ToInt16(this->txt_idPersonne->Text), this->txt_nom->Text /*nom de l'article*/, this->txt_prenom->Text /*Nature de l'article*/, this->txt_DateNaissance->Text /*reference de l'article*/, this->txt_Adresse->Text /*couleur de l'article*/, Convert::ToInt16(this->txt_Ville->Text)/*nombre en stock d'article X*/, this->txt_CodePostal->Text/*prix à l'unité*/);
                this->mode = "RIEN";
            }
            else if (this->mode == "sup")
            {
                this->processusStock->supprimer(Convert::ToInt32(this->txt_idPersonne->Text));
                this->mode = "RIEN";
            }
            this->index = 0;
            this->loadData(this->index);
            Actualiser();
            this->txt_message->Text += "Traitement terminé.";
        }
        
    }

    private: System::Void btn_refresh_Click(System::Object^ sender, System::EventArgs^ e) {
        Actualiser();
    }
    };

}