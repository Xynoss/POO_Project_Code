#include "Svc_commande.h"
namespace NS_Svc
{
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

	String^ Svc_commande::ajouter(String^Reference, String^ DateCommande, String^ DateLivraison, String^ DatePayement, String^ MoyenPayement, String^ DateSolde, int MontantHT, int MontantTVA, int MontantTTC )
	{
		this->Commande->setReference(Reference);
		this->Commande->setDateCommande(DateCommande);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDatePayement(DatePayement);
		this->Commande->setMoyenPayement(MoyenPayement);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setMontantHT(MontantHT);
		this->Commande->setMontantTVA(MontantTVA);
		this->Commande->setMontantTTC(MontantTTC);
		Reference = this->cad->actionRowsID(this->Commande->INSERT());
		return Reference;
	}

	void Svc_commande::modifier(String^ Reference, String^ DateCommande, String^ DateLivraison, String^ DatePayement, String^ MoyenPayement, String^ DateSolde, int MontantHT,int MontantTVA,int MontantTTC)
	{
		this->Commande->setReference(Reference);
		this->Commande->setDateCommande(DateCommande);
		this->Commande->setDateLivraison(DateLivraison);
		this->Commande->setDatePayement(DatePayement);
		this->Commande->setMoyenPayement(MoyenPayement);
		this->Commande->setDateSolde(DateSolde);
		this->Commande->setMontantHT(MontantHT);
		this->Commande->setMontantTVA(MontantTVA);
		this->Commande->setMontantTTC(MontantTTC);
		this->cad->actionRows(this->Commande->UPDATE());
	}

	void Svc_commande::supprimer(String^ Reference)
	{
		this->Commande->setReference(Reference);
		this->cad->actionRows(this->Commande->DELETE());
	}
}
