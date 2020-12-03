Svc_commande::Svc_commande(void)
	{

		this->cad = gcnew NS_Composants::CL_CAD();
		this->Commande = gcnew NS_Composants::Commande();
		this->DS = gcnew Data::DataSet();
		this->DT = gcnew Data::DataTable();
	}

	DataSet^ Svc_commande::listeCommande(String^ dataTableName)
	{
		this->DS->Clear();
		this->DS = this->cad->getRows(this->Commande->SELECT(), dataTableName);
		return this->DS;
	}

	DataTable^ Svc_commande::TableCommande()
	{
		this->DT->Clear();
		this->DT = this->cad->getRows(this->Commande->SELECT());
		return this->DT;
	}

	int Svc_commande::ajouter(int ID_Article, int ID_Facture, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ RefCommande, int MontantPayment, int Remise, int QuantitéArticle,int MontantTVA,int PrixUnitaire )
	{
		
		this-> Commande-> setID_Article(ID_Article);
		this->Commande->setID_Facture(ID_Facture);
		this->Commande-> setDateLivraison(DateLivraison);
		this->Commande->setDatePaiment(DatePaiment);
		this->Commande->setMoyenPayment(MoyenPayment);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRefCommande(RefCommande);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setRemise(Remise);
		this->Commande->setQuantitéArticle(QuantitéArticle);
		this->Commande->setMontantTVA(MontantTVA);
		this->Commande->setPrixUnitaire(PrixUnitaire);
		ID_Facture= this->cad->actionRowsID(this->Commande->INSERT());
		return ID_Facture;
	}

	void Svc_commande::modifier(int ID_Article, int ID_Facture, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ RefCommande, int MontantPayment, int Remise, int QuantitéArticle, int MontantTVA, int PrixUnitaire)
	{
		this->Commande->setID_Article(ID_Article);
		this->Commande->setID_Facture(ID_Facture);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDatePaiment(DatePaiment);
		this->Commande->setMoyenPayment(MoyenPayment);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRefCommande(RefCommande);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setRemise(Remise);
		this->Commande->setQuantitéArticle(QuantitéArticle);
		this->Commande->setMontantTVA(MontantTVA);
		this->Commande->setPrixUnitaire(PrixUnitaire);
		this->cad->actionRows(this->Commande->UPDATE());
	}

	void Svc_commande::supprimer(int ID_Facture)
	{
		this->Commande->setID_Facture(ID_Facture);
		this->cad->actionRows(this->Commande->DELETE());
	}
}

