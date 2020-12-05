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
		this->DT = this->cad->getRows(this->Commande->SELECT());
		return this->DT;
	}

	int Svc_commande::ajouter(String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, double MontantTVA, int Client, String^ quantité, String^ PU,String^ PrenomClient,String^ NomClient,String^ CurentAnnee,String^ VilleClient)
	{
		int ID;
		this->Commande->setReference(RefCommande, PrenomClient, NomClient, CurentAnnee, VilleClient);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRemise(Remise);
		this->Commande->setQuantitéArticle(quantité);
		this->Commande->setMontantHT(Convert::ToDouble(this->Commande->getQuantitéArticle()), Convert::ToDouble(PU));
		this->Commande->setMontantTVA(this->Commande->getMontantHT());
		this->Commande->setMontantTTC(this->Commande->getMontantHT(), this->Commande->getMontantTVA());
		this->Commande->setDatePayement(DatePaiment);
		this->Commande->setMoyenPayement(MoyenPayment);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setIDClient(Client);
		ID = this->cad->actionRowsID(this->Commande->INSERT());
		this->cad->actionRowsID(this->Commande->INSERTDATE());
		return ID;
	}

	void Svc_commande::modifier(int ID_Facture, String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, String^ MontantTVA, int Client, String^ quantité, String^ PU, String^ PrenomClient, String^ NomClient, String^ CurentAnnee, String^ VilleClient)
	{
		this->Commande->setIDfacture(ID_Facture);
		this->Commande->setReference(RefCommande, PrenomClient, NomClient, CurentAnnee, VilleClient);
		this->Commande->setMontantHT(Convert::ToDouble(this->Commande->getQuantitéArticle()), Convert::ToDouble(PU));
		this->Commande->setMontantTVA(this->Commande->getMontantHT());
		this->Commande->setMontantTTC(Convert::ToDouble(this->Commande->getMontantHT()), Convert::ToDouble(MontantTVA));
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDatePayement(DatePaiment);
		this->Commande->setMoyenPayement(MoyenPayment);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setRemise(Remise);
		this->cad->actionRows(this->Commande->UPDATE());
	}

	void Svc_commande::supprimer(int ID_Facture)
	{
		//this->Commande->setIDFacture(ID_Facture);
		this->cad->actionRows(this->Commande->DELETE());
	}
}
