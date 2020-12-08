#include "CL_svc_gestionCommande.h"


namespace NS_Svc
{
	Svc_commande::Svc_commande(void)
	{
		this->cad = gcnew NS_Composants::CL_CAD();
		this->Commande = gcnew NS_Composants::CL_map_Commande(); 
		this->DS = gcnew Data::DataSet();
		this->DT = gcnew Data::DataTable();
		this->MontantHTDebut = gcnew Data::DataSet();
		this->PrixUni = gcnew Data::DataSet();
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
		this->DT = this->cad->getRows(this->Commande->SELECTDGV());
		return this->DT;
	}

	int Svc_commande::ajouter(String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, int Client, String^ QArticle,String^ PU, String^ PrenomClient, String^ NomClient, String^ CurentAnnee, String^ VilleClient, int Article)
	{
		int ID_facture;
		double montantHT;
		double montantTTC;
		double montantTVA;
		this->Commande->setQuantitéArticle(QArticle);
		this->Commande->setPrixUnitaire(PU);
		this->Commande->setReference(RefCommande, PrenomClient, NomClient, CurentAnnee, VilleClient);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRemise(Remise);
		this->Commande->setMontantHT(Convert::ToDouble(this->Commande->getQuantitéArticle()), Convert::ToDouble(this->Commande->getPrixUnitaire()));
		montantHT = Convert::ToDouble(this->Commande->getMontantHT());
		this->Commande->setMontantTVA(montantHT);
		montantTVA = Convert::ToDouble(this->Commande->getMontantTVA());
		double remise = Convert::ToDouble(this->Commande->getRemise());
		this->Commande->setMontantTTC(montantHT, montantTVA, remise);
		montantTTC = Convert::ToDouble(this->Commande->getMontantTTC());
		this->Commande->setDatePayement(DatePaiment);
		this->Commande->setMoyenPayement(MoyenPayment);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setIDClient(Client);
		this->Commande->setIDArticle(Article);
		ID_facture = this->cad->actionRowsID(this->Commande->INSERT(montantHT, montantTVA, montantTTC));
		this->cad->actionRowsID(this->Commande->INSERTCOMMANDE(ID_facture));
		this->cad->actionRowsID(this->Commande->INSERTDATE(ID_facture, montantTTC));
		return ID_facture;
	}

	double Svc_commande::ajouterArticle(String^ id_Article, String^ id_Facture, String^ Quant_)
	{
		this->PrixUni = this->cad->getRows(this->Commande->SELECTPrixUni(Convert::ToInt16(id_Article)), "datatable");
		this->Commande->setPrixUnitaire(Convert::ToString(this->PrixUni->Tables["datatable"]->Rows[0]->ItemArray[0]));
		int ID_facture;
		double QuatitArt;
		double PrixUnit;
		double montantHT;
		double montantHTArticle;
		this->Commande->setIDfacture(Convert::ToInt16(id_Facture));
		ID_facture = this->Commande->getIDFacture();
		this->Commande->setIDArticle(Convert::ToInt16(id_Article));
		this->Commande->setQuantitéArticle(Quant_);
		QuatitArt = Convert::ToDouble(this->Commande->getQuantitéArticle());
		PrixUnit = Convert::ToDouble(this->Commande->getPrixUnitaire());
		montantHT = QuatitArt * PrixUnit;
		this->Commande->setMontantHT2(montantHT);
		this->cad->actionRowsID(this->Commande->INSERTCOMMANDE(ID_facture));
		montantHTArticle = Convert::ToDouble(this->Commande->getMontantHT2());
		return montantHTArticle;
	}

	int Svc_commande::update(int idf, double HT, String^ Remise)
	{
		double montantHT;
		double montantTVA;
		double remise;
		double montantTTC;
		this->Commande->setIDfacture(idf);
		this->Commande->setRemise(Remise);
		this->Commande->setMontantHT2(HT);
		montantHT = Convert::ToDouble(this->Commande->getMontantHT2());
		this->Commande->setMontantTVA(montantHT);
		montantTVA = Convert::ToDouble(this->Commande->getMontantTVA());
		remise = Convert::ToDouble(Remise);
		this->Commande->setMontantTTC(montantHT, montantTVA, remise);
		montantTTC = Convert::ToDouble(this->Commande->getMontantTTC());

		this->cad->actionRows(this->Commande->UPDATEARTICLE(montantHT, montantTVA, montantTTC));
		return idf;
	}



	void Svc_commande::modifier(int ID_Facture, String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, int Client, String^ quantité, String^ PU, String^ PrenomClient, String^ NomClient, String^ CurentAnnee, String^ VilleClient, int Article)
	{
		double QuatitArt;
		double PrixUnit;
		double montantHT;
		double montantTTC;
		double montantTVA;
		this->Commande->setQuantitéArticle(quantité);
		this->Commande->setPrixUnitaire(PU);
		QuatitArt = Convert::ToDouble(this->Commande->getQuantitéArticle());
		PrixUnit = Convert::ToDouble(this->Commande->getPrixUnitaire());
		this->Commande->setMontantHT(QuatitArt, PrixUnit);
		this->Commande->setIDfacture(ID_Facture);
		this->Commande->setReference(RefCommande, PrenomClient, NomClient, CurentAnnee, VilleClient);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRemise(Remise);
		montantHT = Convert::ToDouble(this->Commande->getMontantHT());
		this->Commande->setMontantTVA(montantHT);
		montantTVA = Convert::ToDouble(this->Commande->getMontantTVA());
		double remise = Convert::ToDouble(this->Commande->getRemise());
		this->Commande->setMontantTTC(montantHT, montantTVA, remise);
		montantTTC = Convert::ToDouble(this->Commande->getMontantTTC());
		this->Commande->setDatePayement(DatePaiment);
		this->Commande->setMoyenPayement(MoyenPayment);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setIDClient(Client);
		this->Commande->setIDArticle(Article);
		this->cad->actionRows(this->Commande->UPDATE(montantHT, montantTVA, montantTTC));
		this->cad->actionRows(this->Commande->UPDATEARTICLE2());
	}

	void Svc_commande::modifierSPrix(int ID_Facture, String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, int Client, String^ PrenomClient, String^ NomClient, String^ CurentAnnee, String^ VilleClient, int Article)
	{
		this->Commande->setIDfacture(ID_Facture);
		this->Commande->setReference(RefCommande, PrenomClient, NomClient, CurentAnnee, VilleClient);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setDatePayement(DatePaiment);
		this->Commande->setMoyenPayement(MoyenPayment);
		this->Commande->setIDClient(Client);
		this->Commande->setIDArticle(Article);
		this->cad->actionRows(this->Commande->UPDATESPrix());
	}

	void Svc_commande::modifierArticle(int ID_Facture, String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, int Client, String^ quantité, String^ PU, String^ PrenomClient, String^ NomClient, String^ CurentAnnee, String^ VilleClient, double HT)
	{
		this->MontantHTDebut = this->cad->getRows(this->Commande->SELECTPRIXHT(), "datatable");
		this->Commande->setMontantHT3(HT, Convert::ToDouble(this->MontantHTDebut->Tables["datatable"]->Rows[0]->ItemArray[0]));
		double montantTTC;
		double montantTVA;
		this->Commande->setIDfacture(ID_Facture);
		this->Commande->setReference(RefCommande, PrenomClient, NomClient, CurentAnnee, VilleClient);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRemise(Remise);
		double montantHT = Convert::ToDouble(this->Commande->getMontantHT3());
		this->Commande->setMontantTVA(montantHT);
		montantTVA = Convert::ToDouble(this->Commande->getMontantTVA());
		double remise = Convert::ToDouble(this->Commande->getRemise());
		this->Commande->setMontantTTC(montantHT, montantTVA, remise);
		montantTTC = Convert::ToDouble(this->Commande->getMontantTTC());
		this->Commande->setDatePayement(DatePaiment);
		this->Commande->setMoyenPayement(MoyenPayment);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setIDClient(Client);
		this->cad->actionRows(this->Commande->UPDATE(montantHT, montantTVA, montantTTC));
	}

	void Svc_commande::supprimer(int ID_Facture)
	{
		this->Commande->setIDfacture(ID_Facture);
		this->cad->actionRows(this->Commande->DELETE());
	}
}
