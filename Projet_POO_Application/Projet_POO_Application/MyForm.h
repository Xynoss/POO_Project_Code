#pragma once
#include "CL_svc_gestionClient.h"
#include "CL_svc_gestionPersonnel.h"
#include "CL_svc_gestionCommande.h"
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
    private: NS_Svc::Svc_commande^ processusCommande;
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
    private: System::Windows::Forms::TextBox^ textBox9;

    private: System::Windows::Forms::TextBox^ textBox10;

    private: System::Windows::Forms::TextBox^ textBox11;

    private: System::Windows::Forms::TextBox^ textBox12;

    private: System::Windows::Forms::TextBox^ textBox13;

    private: System::Windows::Forms::TextBox^ textBox14;

    private: System::Windows::Forms::TextBox^ textBox15;

    private: System::Windows::Forms::Label^ label9;

    private: System::Windows::Forms::Label^ label10;

    private: System::Windows::Forms::Label^ label11;

    private: System::Windows::Forms::Label^ label12;

    private: System::Windows::Forms::Label^ label13;

    private: System::Windows::Forms::Label^ label14;

    private: System::Windows::Forms::Label^ label15;

    private: String^ PrixUnitaire = "0";
private: System::Windows::Forms::TextBox^ textBox16;

private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::TextBox^ textBox17;







private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ textBoxA1;
private: System::Windows::Forms::TextBox^ textBoxA2;
private: System::Windows::Forms::TextBox^ textBoxA3;





private: System::Windows::Forms::Label^ labelA1;
private: System::Windows::Forms::Label^ labelA2;
private: System::Windows::Forms::Label^ labelA3;





private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::Button^ buttonValider;


private: double montantTotalHT;
private: System::Windows::Forms::CheckBox^ checkBoxAjout;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::Button^ button2;


















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
            this->textBox9 = (gcnew System::Windows::Forms::TextBox());
            this->textBox10 = (gcnew System::Windows::Forms::TextBox());
            this->textBox11 = (gcnew System::Windows::Forms::TextBox());
            this->textBox12 = (gcnew System::Windows::Forms::TextBox());
            this->textBox13 = (gcnew System::Windows::Forms::TextBox());
            this->textBox14 = (gcnew System::Windows::Forms::TextBox());
            this->textBox15 = (gcnew System::Windows::Forms::TextBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->textBox16 = (gcnew System::Windows::Forms::TextBox());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->textBox17 = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->textBoxA1 = (gcnew System::Windows::Forms::TextBox());
            this->textBoxA2 = (gcnew System::Windows::Forms::TextBox());
            this->textBoxA3 = (gcnew System::Windows::Forms::TextBox());
            this->labelA1 = (gcnew System::Windows::Forms::Label());
            this->labelA2 = (gcnew System::Windows::Forms::Label());
            this->labelA3 = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->buttonValider = (gcnew System::Windows::Forms::Button());
            this->checkBoxAjout = (gcnew System::Windows::Forms::CheckBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->groupTable->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->SuspendLayout();
            // 
            // lbl_id
            // 
            this->lbl_id->AutoSize = true;
            this->lbl_id->Location = System::Drawing::Point(10, 146);
            this->lbl_id->Name = L"lbl_id";
            this->lbl_id->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->lbl_id->Size = System::Drawing::Size(47, 13);
            this->lbl_id->TabIndex = 0;
            this->lbl_id->Text = L"ID Client";
            this->lbl_id->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // txt_idPersonne
            // 
            this->txt_idPersonne->Location = System::Drawing::Point(183, 143);
            this->txt_idPersonne->Name = L"txt_idPersonne";
            this->txt_idPersonne->ReadOnly = true;
            this->txt_idPersonne->Size = System::Drawing::Size(266, 20);
            this->txt_idPersonne->TabIndex = 1;
            // 
            // lbl_nom
            // 
            this->lbl_nom->AutoSize = true;
            this->lbl_nom->Location = System::Drawing::Point(10, 172);
            this->lbl_nom->Name = L"lbl_nom";
            this->lbl_nom->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->lbl_nom->Size = System::Drawing::Size(29, 13);
            this->lbl_nom->TabIndex = 2;
            this->lbl_nom->Text = L"Nom";
            this->lbl_nom->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // txt_nom
            // 
            this->txt_nom->Location = System::Drawing::Point(183, 169);
            this->txt_nom->Name = L"txt_nom";
            this->txt_nom->Size = System::Drawing::Size(266, 20);
            this->txt_nom->TabIndex = 3;
            // 
            // lbl_prenom
            // 
            this->lbl_prenom->AutoSize = true;
            this->lbl_prenom->Location = System::Drawing::Point(10, 195);
            this->lbl_prenom->Name = L"lbl_prenom";
            this->lbl_prenom->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->lbl_prenom->Size = System::Drawing::Size(43, 13);
            this->lbl_prenom->TabIndex = 4;
            this->lbl_prenom->Text = L"Prénom";
            this->lbl_prenom->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // txt_prenom
            // 
            this->txt_prenom->Location = System::Drawing::Point(183, 195);
            this->txt_prenom->Name = L"txt_prenom";
            this->txt_prenom->Size = System::Drawing::Size(266, 20);
            this->txt_prenom->TabIndex = 5;
            // 
            // lbl_message
            // 
            this->lbl_message->AutoSize = true;
            this->lbl_message->Location = System::Drawing::Point(9, 807);
            this->lbl_message->Name = L"lbl_message";
            this->lbl_message->Size = System::Drawing::Size(50, 13);
            this->lbl_message->TabIndex = 6;
            this->lbl_message->Text = L"Message";
            // 
            // txt_message
            // 
            this->txt_message->Location = System::Drawing::Point(8, 823);
            this->txt_message->Multiline = true;
            this->txt_message->Name = L"txt_message";
            this->txt_message->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->txt_message->Size = System::Drawing::Size(1841, 68);
            this->txt_message->TabIndex = 7;
            // 
            // btn_first
            // 
            this->btn_first->Location = System::Drawing::Point(475, 783);
            this->btn_first->Name = L"btn_first";
            this->btn_first->Size = System::Drawing::Size(46, 23);
            this->btn_first->TabIndex = 8;
            this->btn_first->Text = L"<<";
            this->btn_first->UseVisualStyleBackColor = true;
            this->btn_first->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_first_Click);
            // 
            // btn_previous
            // 
            this->btn_previous->Location = System::Drawing::Point(527, 783);
            this->btn_previous->Name = L"btn_previous";
            this->btn_previous->Size = System::Drawing::Size(46, 23);
            this->btn_previous->TabIndex = 9;
            this->btn_previous->Text = L"<";
            this->btn_previous->UseVisualStyleBackColor = true;
            this->btn_previous->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_previous_Click);
            // 
            // btn_next
            // 
            this->btn_next->Location = System::Drawing::Point(579, 783);
            this->btn_next->Name = L"btn_next";
            this->btn_next->Size = System::Drawing::Size(46, 23);
            this->btn_next->TabIndex = 10;
            this->btn_next->Text = L">";
            this->btn_next->UseVisualStyleBackColor = true;
            this->btn_next->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_next_Click);
            // 
            // btn_end
            // 
            this->btn_end->Location = System::Drawing::Point(631, 783);
            this->btn_end->Name = L"btn_end";
            this->btn_end->Size = System::Drawing::Size(46, 23);
            this->btn_end->TabIndex = 11;
            this->btn_end->Text = L">>";
            this->btn_end->UseVisualStyleBackColor = true;
            this->btn_end->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_end_Click);
            // 
            // btn_nouveau
            // 
            this->btn_nouveau->Location = System::Drawing::Point(694, 771);
            this->btn_nouveau->Name = L"btn_nouveau";
            this->btn_nouveau->Size = System::Drawing::Size(123, 46);
            this->btn_nouveau->TabIndex = 12;
            this->btn_nouveau->Text = L"Nouveau";
            this->btn_nouveau->UseVisualStyleBackColor = true;
            this->btn_nouveau->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_nouveau_Click);
            // 
            // btn_modifier
            // 
            this->btn_modifier->Location = System::Drawing::Point(823, 771);
            this->btn_modifier->Name = L"btn_modifier";
            this->btn_modifier->Size = System::Drawing::Size(123, 46);
            this->btn_modifier->TabIndex = 13;
            this->btn_modifier->Text = L"Modifier";
            this->btn_modifier->UseVisualStyleBackColor = true;
            this->btn_modifier->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_modifier_Click);
            // 
            // btn_sup
            // 
            this->btn_sup->Location = System::Drawing::Point(952, 771);
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
            this->btn_enregistrer->Location = System::Drawing::Point(1081, 771);
            this->btn_enregistrer->Name = L"btn_enregistrer";
            this->btn_enregistrer->Size = System::Drawing::Size(381, 46);
            this->btn_enregistrer->TabIndex = 15;
            this->btn_enregistrer->Text = L"ENREGISTRER";
            this->btn_enregistrer->UseVisualStyleBackColor = false;
            this->btn_enregistrer->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_enregistrer_Click);
            // 
            // dataGridView1
            // 
            this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(454, 12);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(1395, 753);
            this->dataGridView1->TabIndex = 16;
            // 
            // btn_refresh
            // 
            this->btn_refresh->Location = System::Drawing::Point(1468, 771);
            this->btn_refresh->Name = L"btn_refresh";
            this->btn_refresh->Size = System::Drawing::Size(381, 46);
            this->btn_refresh->TabIndex = 17;
            this->btn_refresh->Text = L"Actualiser";
            this->btn_refresh->UseVisualStyleBackColor = true;
            this->btn_refresh->Click += gcnew System::EventHandler(this, &FRM_Principal::btn_refresh_Click);
            // 
            // txt_DateNaissance
            // 
            this->txt_DateNaissance->Location = System::Drawing::Point(183, 221);
            this->txt_DateNaissance->Name = L"txt_DateNaissance";
            this->txt_DateNaissance->Size = System::Drawing::Size(266, 20);
            this->txt_DateNaissance->TabIndex = 19;
            // 
            // lbl_DateNaissance
            // 
            this->lbl_DateNaissance->AutoSize = true;
            this->lbl_DateNaissance->Location = System::Drawing::Point(10, 221);
            this->lbl_DateNaissance->Name = L"lbl_DateNaissance";
            this->lbl_DateNaissance->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->lbl_DateNaissance->Size = System::Drawing::Size(80, 13);
            this->lbl_DateNaissance->TabIndex = 20;
            this->lbl_DateNaissance->Text = L"DateNaissance";
            this->lbl_DateNaissance->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // groupTable
            // 
            this->groupTable->Controls->Add(this->radioButtonStock);
            this->groupTable->Controls->Add(this->radioButtonCommande);
            this->groupTable->Controls->Add(this->radioButtonPersonnel);
            this->groupTable->Controls->Add(this->radioButtonClient);
            this->groupTable->Location = System::Drawing::Point(12, 12);
            this->groupTable->Name = L"groupTable";
            this->groupTable->Size = System::Drawing::Size(436, 112);
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
            this->lbl_CodePostal->Location = System::Drawing::Point(10, 299);
            this->lbl_CodePostal->Name = L"lbl_CodePostal";
            this->lbl_CodePostal->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->lbl_CodePostal->Size = System::Drawing::Size(64, 13);
            this->lbl_CodePostal->TabIndex = 27;
            this->lbl_CodePostal->Text = L"Code Postal";
            this->lbl_CodePostal->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // txt_CodePostal
            // 
            this->txt_CodePostal->Location = System::Drawing::Point(183, 299);
            this->txt_CodePostal->Name = L"txt_CodePostal";
            this->txt_CodePostal->Size = System::Drawing::Size(265, 20);
            this->txt_CodePostal->TabIndex = 26;
            // 
            // txt_Ville
            // 
            this->txt_Ville->Location = System::Drawing::Point(183, 273);
            this->txt_Ville->Name = L"txt_Ville";
            this->txt_Ville->Size = System::Drawing::Size(266, 20);
            this->txt_Ville->TabIndex = 25;
            // 
            // lbl_Ville
            // 
            this->lbl_Ville->AutoSize = true;
            this->lbl_Ville->Location = System::Drawing::Point(10, 273);
            this->lbl_Ville->Name = L"lbl_Ville";
            this->lbl_Ville->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->lbl_Ville->Size = System::Drawing::Size(26, 13);
            this->lbl_Ville->TabIndex = 24;
            this->lbl_Ville->Text = L"Ville";
            this->lbl_Ville->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // txt_Adresse
            // 
            this->txt_Adresse->Location = System::Drawing::Point(183, 247);
            this->txt_Adresse->Name = L"txt_Adresse";
            this->txt_Adresse->Size = System::Drawing::Size(266, 20);
            this->txt_Adresse->TabIndex = 23;
            // 
            // lbl_Adresse
            // 
            this->lbl_Adresse->AutoSize = true;
            this->lbl_Adresse->Location = System::Drawing::Point(10, 247);
            this->lbl_Adresse->Name = L"lbl_Adresse";
            this->lbl_Adresse->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->lbl_Adresse->Size = System::Drawing::Size(45, 13);
            this->lbl_Adresse->TabIndex = 22;
            this->lbl_Adresse->Text = L"Adresse";
            this->lbl_Adresse->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lbl_TypeAdresse
            // 
            this->lbl_TypeAdresse->AutoSize = true;
            this->lbl_TypeAdresse->Location = System::Drawing::Point(10, 325);
            this->lbl_TypeAdresse->Name = L"lbl_TypeAdresse";
            this->lbl_TypeAdresse->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->lbl_TypeAdresse->Size = System::Drawing::Size(80, 13);
            this->lbl_TypeAdresse->TabIndex = 29;
            this->lbl_TypeAdresse->Text = L"Type d\'Adresse";
            this->lbl_TypeAdresse->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // txt_TypeAdresse
            // 
            this->txt_TypeAdresse->Location = System::Drawing::Point(183, 325);
            this->txt_TypeAdresse->Name = L"txt_TypeAdresse";
            this->txt_TypeAdresse->Size = System::Drawing::Size(265, 20);
            this->txt_TypeAdresse->TabIndex = 28;
            // 
            // textBox9
            // 
            this->textBox9->Location = System::Drawing::Point(183, 351);
            this->textBox9->Name = L"textBox9";
            this->textBox9->Size = System::Drawing::Size(265, 20);
            this->textBox9->TabIndex = 30;
            // 
            // textBox10
            // 
            this->textBox10->Location = System::Drawing::Point(183, 377);
            this->textBox10->Name = L"textBox10";
            this->textBox10->Size = System::Drawing::Size(265, 20);
            this->textBox10->TabIndex = 31;
            // 
            // textBox11
            // 
            this->textBox11->Location = System::Drawing::Point(183, 403);
            this->textBox11->Name = L"textBox11";
            this->textBox11->Size = System::Drawing::Size(265, 20);
            this->textBox11->TabIndex = 32;
            // 
            // textBox12
            // 
            this->textBox12->Location = System::Drawing::Point(183, 429);
            this->textBox12->Name = L"textBox12";
            this->textBox12->Size = System::Drawing::Size(265, 20);
            this->textBox12->TabIndex = 33;
            // 
            // textBox13
            // 
            this->textBox13->Location = System::Drawing::Point(183, 455);
            this->textBox13->Name = L"textBox13";
            this->textBox13->Size = System::Drawing::Size(265, 20);
            this->textBox13->TabIndex = 34;
            // 
            // textBox14
            // 
            this->textBox14->Location = System::Drawing::Point(183, 481);
            this->textBox14->Name = L"textBox14";
            this->textBox14->Size = System::Drawing::Size(265, 20);
            this->textBox14->TabIndex = 35;
            // 
            // textBox15
            // 
            this->textBox15->Location = System::Drawing::Point(183, 507);
            this->textBox15->Name = L"textBox15";
            this->textBox15->Size = System::Drawing::Size(265, 20);
            this->textBox15->TabIndex = 36;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(10, 351);
            this->label9->Name = L"label9";
            this->label9->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->label9->Size = System::Drawing::Size(35, 13);
            this->label9->TabIndex = 37;
            this->label9->Text = L"label1";
            this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(10, 377);
            this->label10->Name = L"label10";
            this->label10->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->label10->Size = System::Drawing::Size(35, 13);
            this->label10->TabIndex = 38;
            this->label10->Text = L"label2";
            this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(10, 403);
            this->label11->Name = L"label11";
            this->label11->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->label11->Size = System::Drawing::Size(35, 13);
            this->label11->TabIndex = 39;
            this->label11->Text = L"label3";
            this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(10, 429);
            this->label12->Name = L"label12";
            this->label12->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->label12->Size = System::Drawing::Size(35, 13);
            this->label12->TabIndex = 40;
            this->label12->Text = L"label4";
            this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Location = System::Drawing::Point(10, 455);
            this->label13->Name = L"label13";
            this->label13->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->label13->Size = System::Drawing::Size(35, 13);
            this->label13->TabIndex = 41;
            this->label13->Text = L"label5";
            this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Location = System::Drawing::Point(10, 481);
            this->label14->Name = L"label14";
            this->label14->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->label14->Size = System::Drawing::Size(35, 13);
            this->label14->TabIndex = 42;
            this->label14->Text = L"label6";
            this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Location = System::Drawing::Point(10, 507);
            this->label15->Name = L"label15";
            this->label15->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->label15->Size = System::Drawing::Size(41, 13);
            this->label15->TabIndex = 43;
            this->label15->Text = L"label15";
            this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // textBox16
            // 
            this->textBox16->Location = System::Drawing::Point(183, 534);
            this->textBox16->Name = L"textBox16";
            this->textBox16->Size = System::Drawing::Size(265, 20);
            this->textBox16->TabIndex = 44;
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Location = System::Drawing::Point(9, 534);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(41, 13);
            this->label16->TabIndex = 46;
            this->label16->Text = L"label16";
            // 
            // textBox17
            // 
            this->textBox17->Location = System::Drawing::Point(183, 561);
            this->textBox17->Name = L"textBox17";
            this->textBox17->Size = System::Drawing::Size(265, 20);
            this->textBox17->TabIndex = 47;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(0, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(35, 13);
            this->label1->TabIndex = 51;
            this->label1->Text = L"label1";
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Location = System::Drawing::Point(9, 561);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(41, 13);
            this->label17->TabIndex = 52;
            this->label17->Text = L"label17";
            // 
            // textBoxA1
            // 
            this->textBoxA1->Location = System::Drawing::Point(99, 16);
            this->textBoxA1->Name = L"textBoxA1";
            this->textBoxA1->Size = System::Drawing::Size(100, 20);
            this->textBoxA1->TabIndex = 53;
            // 
            // textBoxA2
            // 
            this->textBoxA2->Location = System::Drawing::Point(99, 42);
            this->textBoxA2->Name = L"textBoxA2";
            this->textBoxA2->Size = System::Drawing::Size(100, 20);
            this->textBoxA2->TabIndex = 54;
            // 
            // textBoxA3
            // 
            this->textBoxA3->Location = System::Drawing::Point(99, 67);
            this->textBoxA3->Name = L"textBoxA3";
            this->textBoxA3->Size = System::Drawing::Size(100, 20);
            this->textBoxA3->TabIndex = 55;
            // 
            // labelA1
            // 
            this->labelA1->AutoSize = true;
            this->labelA1->Location = System::Drawing::Point(4, 17);
            this->labelA1->Name = L"labelA1";
            this->labelA1->Size = System::Drawing::Size(42, 13);
            this->labelA1->TabIndex = 57;
            this->labelA1->Text = L"labelA1";
            // 
            // labelA2
            // 
            this->labelA2->AutoSize = true;
            this->labelA2->Location = System::Drawing::Point(4, 42);
            this->labelA2->Name = L"labelA2";
            this->labelA2->Size = System::Drawing::Size(42, 13);
            this->labelA2->TabIndex = 58;
            this->labelA2->Text = L"labelA2";
            // 
            // labelA3
            // 
            this->labelA3->AutoSize = true;
            this->labelA3->Location = System::Drawing::Point(4, 68);
            this->labelA3->Name = L"labelA3";
            this->labelA3->Size = System::Drawing::Size(42, 13);
            this->labelA3->TabIndex = 59;
            this->labelA3->Text = L"labelA3";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->buttonValider);
            this->groupBox1->Controls->Add(this->labelA3);
            this->groupBox1->Controls->Add(this->labelA2);
            this->groupBox1->Controls->Add(this->labelA1);
            this->groupBox1->Controls->Add(this->textBoxA3);
            this->groupBox1->Controls->Add(this->textBoxA2);
            this->groupBox1->Controls->Add(this->textBoxA1);
            this->groupBox1->Location = System::Drawing::Point(18, 666);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(352, 99);
            this->groupBox1->TabIndex = 61;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Article";
            // 
            // buttonValider
            // 
            this->buttonValider->Location = System::Drawing::Point(255, 66);
            this->buttonValider->Name = L"buttonValider";
            this->buttonValider->Size = System::Drawing::Size(75, 23);
            this->buttonValider->TabIndex = 61;
            this->buttonValider->Text = L"Valider";
            this->buttonValider->UseVisualStyleBackColor = true;
            this->buttonValider->Click += gcnew System::EventHandler(this, &FRM_Principal::buttonValider_Click);
            // 
            // checkBoxAjout
            // 
            this->checkBoxAjout->AutoSize = true;
            this->checkBoxAjout->Location = System::Drawing::Point(25, 643);
            this->checkBoxAjout->Name = L"checkBoxAjout";
            this->checkBoxAjout->Size = System::Drawing::Size(91, 17);
            this->checkBoxAjout->TabIndex = 62;
            this->checkBoxAjout->Text = L"Ajouter Article";
            this->checkBoxAjout->UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(242, 587);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(142, 23);
            this->button1->TabIndex = 63;
            this->button1->Text = L"Réinitialiser à un article";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &FRM_Principal::button1_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(242, 616);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(142, 23);
            this->button2->TabIndex = 64;
            this->button2->Text = L"Supprimer un article";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &FRM_Principal::button2_Click);
            // 
            // FRM_Principal
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1852, 896);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->checkBoxAjout);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->label17);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox17);
            this->Controls->Add(this->label16);
            this->Controls->Add(this->textBox16);
            this->Controls->Add(this->label15);
            this->Controls->Add(this->label14);
            this->Controls->Add(this->label13);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->txt_CodePostal);
            this->Controls->Add(this->textBox15);
            this->Controls->Add(this->txt_idPersonne);
            this->Controls->Add(this->lbl_TypeAdresse);
            this->Controls->Add(this->textBox14);
            this->Controls->Add(this->lbl_CodePostal);
            this->Controls->Add(this->txt_nom);
            this->Controls->Add(this->lbl_Ville);
            this->Controls->Add(this->textBox13);
            this->Controls->Add(this->lbl_Adresse);
            this->Controls->Add(this->txt_prenom);
            this->Controls->Add(this->groupTable);
            this->Controls->Add(this->textBox12);
            this->Controls->Add(this->lbl_DateNaissance);
            this->Controls->Add(this->txt_DateNaissance);
            this->Controls->Add(this->btn_refresh);
            this->Controls->Add(this->textBox11);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->txt_Adresse);
            this->Controls->Add(this->btn_enregistrer);
            this->Controls->Add(this->textBox10);
            this->Controls->Add(this->btn_sup);
            this->Controls->Add(this->txt_Ville);
            this->Controls->Add(this->btn_modifier);
            this->Controls->Add(this->textBox9);
            this->Controls->Add(this->btn_nouveau);
            this->Controls->Add(this->txt_TypeAdresse);
            this->Controls->Add(this->btn_end);
            this->Controls->Add(this->btn_next);
            this->Controls->Add(this->btn_previous);
            this->Controls->Add(this->btn_first);
            this->Controls->Add(this->txt_message);
            this->Controls->Add(this->lbl_message);
            this->Controls->Add(this->lbl_prenom);
            this->Controls->Add(this->lbl_nom);
            this->Controls->Add(this->lbl_id);
            this->Name = L"FRM_Principal";
            this->Text = L"D";
            this->Load += gcnew System::EventHandler(this, &FRM_Principal::FRM_Principal_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->groupTable->ResumeLayout(false);
            this->groupTable->PerformLayout();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void FRM_Principal_Load(System::Object^ sender, System::EventArgs^ e)
    {
        this->index = 0;
        this->mode = "RIEN";
        this->SelectedTable = "personnel";
        this->groupBox1->Visible = false;
        this->dsClient = gcnew Data::DataSet();
        this->dsPersonnel = gcnew Data::DataSet();
        this->dsCommande = gcnew Data::DataSet();
        this->dsStock = gcnew Data::DataSet();
        this->processusClients = gcnew NS_Svc::CL_svc_gestionClient();
        this->processusPersonnel = gcnew NS_Svc::CL_svc_gestionPersonnel();
        this->processusCommande = gcnew NS_Svc::Svc_commande();
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
            this->txt_idPersonne->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[0]);//id facture
            this->txt_nom->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[1]);//ref facture
            this->txt_prenom->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[2]);//id client
            this->txt_DateNaissance->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[4]);//date livraison
            this->txt_Adresse->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[5]);//remise
            this->txt_Ville->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[6]);//date solde
            this->txt_CodePostal->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[9]);//quantité d'article
            this->txt_TypeAdresse->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[10]);//prix unité
            this->textBox9->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[12]);//date du payement
            this->textBox10->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[13]);//montant réglé
            this->textBox11->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[14]);//moyen de payement
            this->textBox12->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[15]);//anniversaire du client
            this->textBox13->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[16]);//Ville du client
            this->textBox14->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[17]);//id de l'article commander
            this->textBox15->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[18]);//prenom du client  
            this->textBox16->Text = Convert::ToString(this->dsCommande->Tables["liste"]->Rows[this->index]->ItemArray[19]);//nom du client
            
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
        checkBoxAjout->Visible = false;
        button1->Visible = false;
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
            this->label9->Text = "";
            this->textBox9->Text = "";
            this->textBox9->ReadOnly = true;
            this->label10->Text = "";
            this->textBox10->Text = "";
            this->textBox10->ReadOnly = true;
            this->label11->Text = "";
            this->textBox11->Text = "";
            this->textBox11->ReadOnly = true;
            this->label12->Text = "";
            this->textBox12->Text = "";
            this->textBox12->ReadOnly = true;
            this->label13->Text = "";
            this->textBox13->Text = "";
            this->textBox13->ReadOnly = true;
            this->label14->Text = "";
            this->textBox14->Text = "";
            this->textBox14->ReadOnly = true;
            this->label15->Text = "";
            this->textBox15->Text = "";
            this->textBox15->ReadOnly = true;
            this->label16->Text = "";
            this->textBox16->Text = "";
            this->textBox16->ReadOnly = true;
            this->label17->Text = "";
            this->textBox17->ReadOnly = true;
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
            this->label9->Text = "";
            this->textBox9->Text = "";
            this->textBox9->ReadOnly = true;
            this->label10->Text = "";
            this->textBox10->Text = "";
            this->textBox10->ReadOnly = true;
            this->label11->Text = "";
            this->textBox11->Text = "";
            this->textBox11->ReadOnly = true;
            this->label12->Text = "";
            this->textBox12->Text = "";
            this->textBox12->ReadOnly = true;
            this->label13->Text = "";
            this->textBox13->Text = "";
            this->textBox13->ReadOnly = true;
            this->label14->Text = "";
            this->textBox14->Text = "";
            this->textBox14->ReadOnly = true;
            this->label15->Text = "";
            this->textBox15->Text = "";
            this->textBox15->ReadOnly = true;
            this->label16->Text = "";
            this->textBox16->Text = "";
            this->textBox16->ReadOnly = true;
            this->label17->Text = "";
            this->textBox17->ReadOnly = true;
            this->txt_message->Text = "update réussi personnel";
        }
        else if (this->radioButtonCommande->Checked) {
            checkBoxAjout->Visible = true;
            button1->Visible = true;
            if (this->checkBoxAjout->Checked) {
                this->groupBox1->Visible = true;
                this->labelA1->Text = "id article";
                this->labelA2->Text = "id facture";
                this->labelA3->Text = "Quantité de l'article";
            }
            else {
                this->groupBox1->Visible = false;
            }
            this->index = 0;
            this->dtCommande = this->processusCommande->TableCommande();
            BindingSource^ bs = gcnew BindingSource();
            bs->DataSource = this->dtCommande;
            dataGridView1->DataSource = bs;
            loadData(this->index);
            this->lbl_id->Text = "ID Facture :";
            this->lbl_nom->Text = "Reference de la commande :";
            this->lbl_prenom->Text = "ID du client :";
            this->lbl_DateNaissance->Text = "Date de livraison :";
            this->lbl_Adresse->Text = "remise :";
            this->lbl_Ville->Text = "Date limite du solde :";
            this->lbl_CodePostal->Text = "Quantité d'article :";
            this->txt_CodePostal->ReadOnly = false;
            this->lbl_TypeAdresse->Text = "prix à l'unité :";
            this->txt_TypeAdresse->ReadOnly = false;
            this->label9->Text = "Date du paiement :";
            this->label10->Text = "Montant réglé :";
            this->label11->Text = "Moyen de paiement :";
            this->label12->Text = "anniversaire du client :";
            this->label13->Text = "Ville du client :";
            this->label14->Text = "ID de l'article commander :";
            this->label15->Text = "Prenom du client :";
            this->label16->Text = "Nom du client :";
            this->label17->Text = "Année actuelle :";
            this->textBox9->ReadOnly = false;
            this->textBox10->ReadOnly = false;
            this->textBox11->ReadOnly = false;
            this->textBox12->ReadOnly = false;
            this->textBox13->ReadOnly = false;
            this->textBox14->ReadOnly = false;
            this->textBox15->ReadOnly = false;
            this->textBox16->ReadOnly = false;
            this->textBox17->ReadOnly = false;
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
            this->label9->Text = "";
            this->textBox9->Text = "";
            this->textBox9->ReadOnly = true;
            this->label10->Text = "";
            this->textBox10->Text = "";
            this->textBox10->ReadOnly = true;
            this->label11->Text = "";
            this->textBox11->Text = "";
            this->textBox11->ReadOnly = true;
            this->label12->Text = "";
            this->textBox12->Text = "";
            this->textBox12->ReadOnly = true;
            this->label13->Text = "";
            this->textBox13->Text = "";
            this->textBox13->ReadOnly = true;
            this->label14->Text = "";
            this->textBox14->Text = "";
            this->textBox14->ReadOnly = true;
            this->label15->Text = "";
            this->textBox15->Text = "";
            this->textBox15->ReadOnly = true;
            this->label16->Text = "";
            this->textBox16->Text = "";
            this->textBox16->ReadOnly = true;
            this->label17->Text = "";
            this->textBox17->ReadOnly = true;
            this->txt_message->Text = "update réussi Stock";
        }

    }


    private: System::Void btn_first_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->index = 0;
        this->loadData(this->index);
        this->txt_message->Text = "Enregistrement n° : " + (this->index + 1);
    }

    private: System::Void btn_previous_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (this->index > 0)
        {
            this->index--;
            this->loadData(this->index);
            this->txt_message->Text = "Enregistrement n° : " + (this->index + 1);
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
        this->textBox9->Clear();
        this->textBox10->Clear();
        this->textBox11->Clear();
        this->textBox12->Clear();
        this->textBox13->Clear();
        this->textBox14->Clear();
        this->textBox15->Clear();
        this->textBox16->Clear();
        this->textBox17->Clear();

        this->mode = "nouv";
        this->txt_message->Text = "Veuillez saisir les information de la nouvelle personne et enregistrer";
        if (this->radioButtonCommande->Checked) {
            this->dtStock = this->processusStock->TableStock();
            BindingSource^ bs = gcnew BindingSource();
            bs->DataSource = this->dtStock;
            dataGridView1->DataSource = bs;
        }
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
                    Id = this->processusPersonnel->ajouterSSup(this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text, this->txt_Adresse->Text);
                    this->txt_message->Text = "L'ID généré est le : " + Id + ". ";
                }
                this->mode = "RIEN";

            }
            else if (this->mode == "maj")
            {
                if (this->txt_Ville->Text != "") {
                    this->processusPersonnel->modifier(Convert::ToInt32(this->txt_idPersonne->Text), Convert::ToInt32(this->txt_Ville->Text), this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text, this->txt_Adresse->Text);
                }
                else {
                    this->processusPersonnel->modifierSSup(Convert::ToInt32(this->txt_idPersonne->Text), this->txt_nom->Text, this->txt_prenom->Text, this->txt_DateNaissance->Text, this->txt_Adresse->Text);
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
        else if (this->radioButtonCommande->Checked) {
            
            if (this->mode == "nouv")
            {
                int Id;
                Id = this->processusCommande->ajouter(this->txt_nom->Text/*Reference*/, this->txt_DateNaissance->Text/*Date de livraison*/, this->textBox9->Text/*Date Paiement*/, this->textBox11->Text/*Moyen de paiement*/, this->txt_Ville->Text/*Date de solde*/, this->textBox10->Text/*montant paiement*/, this->txt_Adresse->Text/*Remise*/,Convert::ToInt16(this->txt_prenom->Text)/*ID du client*/, this->txt_CodePostal->Text/*quantité*/, this->txt_TypeAdresse->Text/*quantité*/, this->textBox15->Text/*PrenomClient*/, this->textBox16->Text/*NomClient*/,this->textBox17->Text/*CurentAnnee*/ ,this->textBox13->Text/*VilleClient*/, Convert::ToInt16(this->textBox14->Text)/*id de l'article commandé*/);
                this->txt_message->Text = "L'ID généré est le : " + Id + ". ";
                this->mode = "RIEN";
            }
            else if (this->mode == "maj")
            {
                if (this->checkBoxAjout->Checked) {
                    this->processusCommande->modifierArticle(Convert::ToInt32(this->txt_idPersonne->Text), this->txt_nom->Text/*Reference*/, this->txt_DateNaissance->Text/*Date de livraison*/, this->textBox9->Text/*Date Paiement*/, this->textBox11->Text/*Moyen de paiement*/, this->txt_Ville->Text/*Date de solde*/, this->textBox10->Text/*montant paiement*/, this->txt_Adresse->Text/*Remise*/, Convert::ToInt16(this->txt_prenom->Text)/*ID du client*/, this->txt_CodePostal->Text /*quantité de l'article*/, this->txt_TypeAdresse->Text /*PrixUnitaire*/, this->textBox15->Text/*PrenomClient*/, this->textBox16->Text/*NomClient*/, this->textBox17->Text/*CurentAnnee*/, this->textBox13->Text/*VilleClient*/, this->montantTotalHT);
                    this->mode = "RIEN";
                    this->checkBoxAjout->Checked = false;
                }
                else {
                    this->processusCommande->modifierSPrix(Convert::ToInt32(this->txt_idPersonne->Text), this->txt_nom->Text/*Reference*/, this->txt_DateNaissance->Text/*Date de livraison*/, this->textBox9->Text/*Date Paiement*/, this->textBox11->Text/*Moyen de paiement*/, this->txt_Ville->Text/*Date de solde*/, this->txt_Adresse->Text/*Remise*/, Convert::ToInt16(this->txt_prenom->Text)/*ID du client*/, this->textBox15->Text/*PrenomClient*/, this->textBox16->Text/*NomClient*/, this->textBox17->Text/*CurentAnnee*/, this->textBox13->Text/*VilleClient*/, Convert::ToInt16(this->textBox14->Text));
                    this->mode = "RIEN";
                }
            }
            else if (this->mode == "sup")
            {
                this->processusCommande->supprimer(Convert::ToInt32(this->txt_idPersonne->Text));
                this->mode = "RIEN";
            }
            else if (this->mode == "supart") {
                this->processusCommande->supprimerArticle(Convert::ToInt32(this->txt_idPersonne->Text), Convert::ToInt16(this->textBox14->Text));
                this->mode = "RIEN";
            }
            this->index = 0;
            this->loadData(this->index);
            Actualiser();
            this->txt_message->Text += "Traitement terminé.";
        }
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
    private: System::Void buttonValider_Click(System::Object^ sender, System::EventArgs^ e) {
        this->montantTotalHT += this->processusCommande->ajouterArticle(this->textBoxA1->Text/*id de l'article*/, this->textBoxA2->Text/*id de la facture*/, this->textBoxA3->Text/*quantité de l'article*/);
        this->txt_message->Text = Convert::ToString(this->montantTotalHT);
        this->textBoxA1->Clear();
        this->textBoxA2->Clear();
        this->textBoxA3->Clear();
    }
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    this->processusCommande->modifier(Convert::ToInt32(this->txt_idPersonne->Text), this->txt_nom->Text/*Reference*/, this->txt_DateNaissance->Text/*Date de livraison*/, this->textBox9->Text/*Date Paiement*/, this->textBox11->Text/*Moyen de paiement*/, this->txt_Ville->Text/*Date de solde*/, this->textBox10->Text/*montant paiement*/, this->txt_Adresse->Text/*Remise*/, Convert::ToInt16(this->txt_prenom->Text)/*ID du client*/, this->txt_CodePostal->Text /*quantité de l'article*/, this->txt_TypeAdresse->Text /*PrixUnitaire*/, this->textBox15->Text/*PrenomClient*/, this->textBox16->Text/*NomClient*/, this->textBox17->Text/*CurentAnnee*/, this->textBox13->Text/*VilleClient*/, Convert::ToInt16(this->textBox14->Text));
    Actualiser();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    this->mode = "supart";
    this->txt_message->Text = "Veuillez confirmer la suppression de l'article en cours en enregistrant.";
}
};
}