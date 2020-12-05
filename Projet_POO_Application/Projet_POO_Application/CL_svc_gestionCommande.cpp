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

	int Svc_commande::ajouter(String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, String^ MontantTVA, int Client, double quantit�, double prixuni)
	{
		int ID;
		this->Commande->setReference(RefCommande);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setRemise(Remise);
		this->Commande->setMontantTVA(MontantTVA);
		this->Commande->setDatePayement(DatePaiment);
		this->Commande->setMoyenPayement(MoyenPayment);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setMontantHT(quantit�, prixuni);
		this->Commande->setMontantTTC(Convert::ToDouble(this->Commande->getMontantHT()), Convert::ToDouble(MontantTVA));
		this->Commande->setIDClient(Client);
		ID = this->cad->actionRowsID(this->Commande->INSERT());
		this->cad->actionRowsID(this->Commande->INSERTDATE());
		return ID;
	}

	void Svc_commande::modifier(int ID_Facture, String^ RefCommande, String^ DateLivraison, String^ DatePaiment, String^ MoyenPayment, String^ DateSolde, String^ MontantPayment, String^ Remise, String^ MontantTVA, int Client)
	{
		this->Commande->setIDfacture(ID_Facture);
		this->Commande->setReference(RefCommande);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDatePayement(DatePaiment);
		this->Commande->setMoyenPayement(MoyenPayment);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setMontantPayment(MontantPayment);
		this->Commande->setRemise(Remise);
		this->Commande->setMontantTVA(MontantTVA);
		this->cad->actionRows(this->Commande->UPDATE());
	}

	void Svc_commande::supprimer(int ID_Facture)
	{
		//this->Commande->setIDFacture(ID_Facture);
		this->cad->actionRows(this->Commande->DELETE());
	}
}
