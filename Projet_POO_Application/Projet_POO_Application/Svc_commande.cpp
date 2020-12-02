#include "Svc_commande.h"


namespace NS_Svc
{
	CL_Svc_commande::CL_Svc_commande(void)
	{

		this->cad = gcnew NS_Composants::CL_CAD();
		this->Commande = gcnew NS_Composants::CL_map_Commande();
		this->DS = gcnew Data::DataSet();
		this->DT = gcnew Data::DataTable();
	}

	DataSet^ CL_Svc_commande::listeCommande(String^ dataTableName)
	{
		this->DS->Clear();
		this->DS = this->cad->getRows(this->Commande->SELECT(), dataTableName);
		return this->DS;
	}

	DataTable^ CL_Svc_commande::TableCommande()
	{
		this->DT->Clear();
		this->DT = this->cad->getRows(this->Commande->SELECT());
		return this->DT;
	}

	String^ CL_Svc_commande::ajouter(String^Reference, String^ DateCommande, String^ DateLivraison, String^ DatePayement, String^ MoyenPayement, String^ DateSolde, int MontantHT, int MontantTVA, int MontantTTC )
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
		int lastID = this->cad->actionRowsID(this->Commande->INSERT());
		return Convert::ToString(lastID);
	}

	void CL_Svc_commande::modifier(String^ Reference, String^ DateCommande, String^ DateLivraison, String^ DatePayement, String^ MoyenPayement, String^ DateSolde, int MontantHT,int MontantTVA,int MontantTTC)
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

	void CL_Svc_commande::supprimer(String^ Reference)
	{
		this->Commande->setReference(Reference);
		this->cad->actionRows(this->Commande->DELETE());
	}
}
