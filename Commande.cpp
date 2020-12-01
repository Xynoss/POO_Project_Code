#include "Commande.h"


namespace NS_Composants
{
	Commande::Commande(void)
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

	String^ Commande::SELECT(void)
	{
		return "SELECT Reference, DateCommande, DateLivraison,DatePayement,MoyenPayement,DateSolde,MontantHT,MontantTVA,MontantTTC" + "FROM Commande;";
	}

	String^ Commande::INSERT(void)
	{
		return "INSERT INTO Commande " + "( Reference, DateCommande, DateLivraison,DatePayement,MoyenPayement,DateSolde,MontantHT,MontantTVA,MontantTTC) " + "VALUES('" + this->getReference() + "', '" + this->getDateCommande() + "', '" + this->getDateLivraison() + "', '" + this->getDatePayement() + "', '" + this->getMoyenPayement() + "', '" + this->getDateSolde() + "', '" + this->getMontantHT() + "', '" + this->getMontantTVA() + "', '" + this->getMontantTTC() + "');SELECT @@IDENTITY;";
	}

	String^ Commande::UPDATE(void)
	{
		return "UPDATE Commande " + "SET DateCommande = '" + this->getDateCommande() + "',  DateLivraison = '" + this->getDateLivraison() + "',  DatePayement = '" + this->getDatePayement() + "',  MoyenPayement = '" + this->getMoyenPayement() + "',  DateSolde = '" + this->getDateSolde() + "', MontantHT = '" + this->getMontantHT() + "',  MontantTVA = '" + this->getMontantTVA() + "',MontantTTC = '" + this->getMontantTTC() + "'" + "WHERE(Reference = " + this->getReference() + ");";
	}

	String^ Commande::DELETE(void)
	{
		return "DELETE FROM Commande " + "WHERE(Reference = " + this->getReference() + ");";
	}

	void Commande::setReference(String^ Reference)
	{
		if (Reference != "")
		{
			this->Reference = Reference;
		}
		
	}

	void Commande::setDateCommande(String^ DateCommande)
	{
		if (DateCommande != "")
		{
			this->DateCommande = DateCommande;
		}
	}

	void Commande::setDateLivraison(String^ DateLivraison)
	{
		if (DateLivraison != "")
		{
			this->DateLivraison = DateLivraison;
		}
	}
	void Commande::setDatePayement(String^ DatePayement)
	{
		if (DatePayement != "")
		{
			this->DatePayement = DatePayement;
		}
	}
	void Commande::setMoyenPayement(String^ MoyenPayement)
	{
		if (MoyenPayement != "")
		{
			this->MoyenPayement = MoyenPayement;
		}
	}
	void Commande::setDateSolde(String^ DateSolde)
	{
		if (DateSolde != "")
		{
			this->DateSolde = DateSolde;
		}
	}
	void Commande::setMontantHT(int MontantHT)
	{
		if (MontantHT > 0)
		{
			this->MontantHT = MontantHT;
		}
	}
	void Commande::setMontantTVA(int MontantTVA)
	{
		if (MontantTVA > 0)
		{
			this->MontantTVA = MontantTVA;
		}
	}
	void Commande::setMontantTTC(int MontantTTC)
	{
		if (MontantTTC > 0)
		{
			this->MontantTTC = MontantTTC;
		}
	}
	

	String^ Commande::getReference(void)
	{
		return this->Reference;
	}

	String^ Commande::getDateCommande(void)
	{
		return this->DateCommande;
	}
	String^ Commande::getDateLivraison(void)
	{
		return this->DateLivraison;
	}
	String^ Commande::getDatePayement(void)
	{
		return this->DatePayement;
	}
	String^ Commande::getMoyenPayement(void)
	{
		return this->MoyenPayement;
	}
	String^ Commande::getDateSolde(void)
	{
		return this->DateSolde;
	}
	int Commande::getMontantHT(void)
	{
		return this->MontantHT;
	}
	int Commande::getMontantTVA(void)
	{
		return this->MontantTVA;
	}
	int Commande::getMontantTTC(void)
	{
		return this->MontantTTC;
	}
}
