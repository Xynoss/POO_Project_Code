#include "Commande.h"


namespace NS_Composants
{
	CL_map_Commande::CL_map_Commande(void)
	{
		this->Reference ="Rien";
		this->DateCommande = "RIEN";
		this->DateLivraison = "RIEN";
		this->DatePayement = "RIEN";
		this->MoyenPayement = "RIEN";
		this->DateSolde = "RIEN";
		this->MontantHT = 0;
		this->MontantTVA = 0;
		this->MontantTTC = 0;
	}

	String^ CL_map_Commande::SELECT(void)
	{
		return "SELECT *" + "FROM facture;";
	}

	String^ CL_map_Commande::INSERT(void)
	{
		return "INSERT INTO facture " + "( Reference, DateCommande, DateLivraison,DatePayement,MoyenPayement,DateSolde,MontantHT,MontantTVA,MontantTTC) " + "VALUES('" + this->getReference() + "', '" + this->getDateCommande() + "', '" + this->getDateLivraison() + "', '" + this->getDatePayement() + "', '" + this->getMoyenPayement() + "', '" + this->getDateSolde() + "', '" + this->getMontantHT() + "', '" + this->getMontantTVA() + "', '" + this->getMontantTTC() + "');SELECT @@IDENTITY;";
	}

	String^ CL_map_Commande::UPDATE(void)
	{
		return "UPDATE Commande " + "SET DateCommande = '" + this->getDateCommande() + "',  DateLivraison = '" + this->getDateLivraison() + "',  DatePayement = '" + this->getDatePayement() + "',  MoyenPayement = '" + this->getMoyenPayement() + "',  DateSolde = '" + this->getDateSolde() + "', MontantHT = '" + this->getMontantHT() + "',  MontantTVA = '" + this->getMontantTVA() + "',MontantTTC = '" + this->getMontantTTC() + "'" + "WHERE(Reference = " + this->getReference() + ");";
	}

	String^ CL_map_Commande::DELETE(void)
	{
		return "DELETE FROM Commande " + "WHERE(Reference = " + this->getReference() + ");";
	}

	void CL_map_Commande::setReference(String^ Reference)
	{
		if (Reference != "")
		{
			this->Reference = Reference;
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
	void CL_map_Commande::setMontantHT(int MontantHT)
	{
		if (MontantHT > 0)
		{
			this->MontantHT = MontantHT;
		}
	}
	void CL_map_Commande::setMontantTVA(int MontantTVA)
	{
		if (MontantTVA > 0)
		{
			this->MontantTVA = MontantTVA;
		}
	}
	void CL_map_Commande::setMontantTTC(int MontantTTC)
	{
		if (MontantTTC > 0)
		{
			this->MontantTTC = MontantTTC;
		}
	}
	

	String^ CL_map_Commande::getReference(void)
	{
		return this->Reference;
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
	int CL_map_Commande::getMontantHT(void)
	{
		return this->MontantHT;
	}
	int CL_map_Commande::getMontantTVA(void)
	{
		return this->MontantTVA;
	}
	int CL_map_Commande::getMontantTTC(void)
	{
		return this->MontantTTC;
	}
}
