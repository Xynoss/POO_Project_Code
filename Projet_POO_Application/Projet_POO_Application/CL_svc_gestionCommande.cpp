#include "CL_svc_gestionCommande.h"


namespace NS_Svc
{
	Svc_commande::Svc_commande(void)
	{
		this->cad = gcnew NS_Composants::CL_CAD();
		this->Commande = gcnew NS_Composants::CL_map_Commande(); 
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
		this->DT = this->cad->getRows(this->Commande->SELECTDGV());
		return this->DT;
	}

	int Svc_commande::ajouter(String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, int Client, String^ quantité, String^ PU,String^ PrenomClient,String^ NomClient,String^ CurentAnnee,String^ VilleClient, int Article)
	{
		int ID_facture;
		double QuatitArt;
		double PrixUnit;
		double montantHT;
		double montantTTC;
		double montantTVA;

		this->Commande->setQuantitéArticle(quantité);
		this->Commande->setPrixUnitaire(PU);
		QuatitArt = Convert::ToDouble(this->Commande->getQuantitéArticle());
		PrixUnit = Convert::ToDouble(this->Commande->getPrixUnitaire());
		this->Commande->setReference(RefCommande, PrenomClient, NomClient, CurentAnnee, VilleClient);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRemise(Remise);
		this->Commande->setMontantHT(QuatitArt, PrixUnit);
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

	void Svc_commande::modifier(int ID_Facture, String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, int Client, String^ quantité, String^ PU, String^ PrenomClient, String^ NomClient, String^ CurentAnnee, String^ VilleClient)
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
		this->Commande->setIDfacture(ID_Facture);
		this->Commande->setReference(RefCommande, PrenomClient, NomClient, CurentAnnee, VilleClient);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRemise(Remise);
		this->Commande->setQuantitéArticle(quantité);
		this->Commande->setPrixUnitaire(PU);
		this->Commande->setMontantHT(QuatitArt, PrixUnit);
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
		this->cad->actionRows(this->Commande->UPDATE(montantHT, montantTVA, montantTTC));
	}

	void Svc_commande::supprimer(int ID_Facture)
	{
		//this->Commande->setIDFacture(ID_Facture);
		this->cad->actionRows(this->Commande->DELETE());
	}
}
