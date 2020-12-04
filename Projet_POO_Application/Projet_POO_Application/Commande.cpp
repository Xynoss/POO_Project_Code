#include "Commande.h"


namespace NS_Composants
{
	CL_map_Commande::CL_map_Commande(void)
	{
		this->RefCommande ="RIEN";
		this->DateCommande = "RIEN";
		this->DateLivraison = "RIEN";
		this->DatePayement = "RIEN";
		this->MoyenPayement = "RIEN";
		this->DateSolde = "RIEN";
		this->Remise = 0;
		this->MontantTVA = 0;
	}

	String^ CL_map_Commande::SELECT(void)
	{
		return "SELECT ID_Facture, RefCommande, ID_CLient, DateLivraison, DateSolde, MontantTVA, Remise" + "FROM facture;";
	}

	String^ CL_map_Commande::INSERT(void)
	{
		return "INSERT INTO facture " + "(RefCommande,DateLivraison,DateSolde,MontantTVA,Remise,ID_Client) " + "VALUES('" + this->getRefCommande() + "', '" + this->getDateLivraison() + "', '" + this->getDateSolde() + "', '" + this->getMontantTVA() + "', '" + this->getRemise() + "', '" + this->getIDClient() + "');SELECT @@IDENTITY;";
	}

	String^ CL_map_Commande::UPDATE(void)
	{
		return "UPDATE Commande " + "SET DateCommande = '" + this->getDateCommande() + "',  DateLivraison = '" + this->getDateLivraison() + "',  DatePayement = '" + this->getDatePayement() + "',  MoyenPayement = '" + this->getMoyenPayement() + "',  DateSolde = '" + this->getDateSolde() + "',  MontantTVA = '" + this->getMontantTVA() + "WHERE(Reference = " + this->getIDFacture() + ");";
	}

	String^ CL_map_Commande::DELETE(void)
	{
		return "DELETE FROM Commande " + "WHERE(Reference = " + this->getIDFacture() + ");";
	}

	void CL_map_Commande::setReference(String^ Reference)
	{
		if (Reference != "")
		{
			this->RefCommande = Reference;
		}
		
	}

	void CL_map_Commande::setDateCommande(String^ DateCommande)
	{
		if (DateCommande != "")
		{
			this->DateCommande = DateCommande;
		}
	}

	void CL_map_Commande::setDateLivraison(String^ DateLivraison)
	{
		if (DateLivraison != "")
		{
			this->DateLivraison = DateLivraison;
		}
	}
	void CL_map_Commande::setDatePayement(String^ DatePayement)
	{
		if (DatePayement != "")
		{
			this->DatePayement = DatePayement;
		}
	}
	void CL_map_Commande::setMoyenPayement(String^ MoyenPayement)
	{
		if (MoyenPayement != "")
		{
			this->MoyenPayement = MoyenPayement;
		}
	}
	void CL_map_Commande::setDateSolde(String^ DateSolde)
	{
		if (DateSolde != "")
		{
			this->DateSolde = DateSolde;
		}
	}

	void CL_map_Commande::setRemise(int remise)
	{
		if (remise > 0)
		{
			this->Remise = remise;
		}
	}

	void CL_map_Commande::setMontantTVA(int MontantTVA)
	{
		if (MontantTVA > 0)
		{
			this->MontantTVA = MontantTVA;
		}
	}

	void CL_map_Commande::setIDClient(int ID_Client)
	{
		if (ID_Client > 0)
		{
			this->ID_Client = ID_Client;
		}
	}

	int CL_map_Commande::getIDFacture(void)
	{
		return this->ID_Facture;
	}

	int CL_map_Commande::getIDClient(void)
	{
		return this->ID_Client;
	}

	int CL_map_Commande::getIDDate(void)
	{
		return this->ID_Date;
	}
	

	String^ CL_map_Commande::getRefCommande(void)
	{
		return this->RefCommande;
	}

	String^ CL_map_Commande::getDateCommande(void)
	{
		return this->DateCommande;
	}
	String^ CL_map_Commande::getDateLivraison(void)
	{
		return this->DateLivraison;
	}
	String^ CL_map_Commande::getDatePayement(void)
	{
		return this->DatePayement;
	}
	String^ CL_map_Commande::getMoyenPayement(void)
	{
		return this->MoyenPayement;
	}
	String^ CL_map_Commande::getDateSolde(void)
	{
		return this->DateSolde;
	}
	int CL_map_Commande::getRemise(void)
	{
		return this->Remise;
	}
	int CL_map_Commande::getMontantTVA(void)
	{
		return this->MontantTVA;
	}
}
