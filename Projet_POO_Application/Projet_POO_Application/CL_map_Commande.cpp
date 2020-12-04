#include "CL_map_Commande.h"


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
		this->Remise = "0";
		this->MontantTVA = "0";
	}

	String^ CL_map_Commande::SELECT(void)
	{
		return "SELECT `Facture`.`ID_Facture`,`Facture`.`RefCommande`, `client`.`NomClient`, `Facture`.`MontantTVA`, `Facture`.`DateLivraison`, `Facture`.`Remise`, `Facture`.`DateSolde`, `Facture`.`MontantHT`, `Facture`.`MontantTTC`, `commande`.`QuantiteArticle`, `stock`.`PrixUnitaire`, `Date`.`ID_Date`, `Date`.`DatePaiment`, `Date`.`MontantPayment`, `Date`.`MoyenPayment` FROM `Commande`, `Facture`, `Date`, `stock`, `client` WHERE `Commande`.`ID_Facture` = `Facture`.`ID_Facture` AND `Facture`.`ID_Facture` = `Date`.`ID_Facture` AND `stock`.`ID_Article` = `commande`.`ID_Article` AND `Facture`.`ID_Client` = `client`.`ID_Client` ORDER BY `Commande`.`ID_Facture` ASC;";
	}

	String^ CL_map_Commande::INSERT(void)
	{
		return "INSERT INTO facture (RefCommande, MontantTVA, DateLivraison, DateSolde, Remise, ID_Client, MontantHT, MontantTTC) " + "VALUES('" + this->getRefCommande() + "', '" + this->getMontantTVA() + "', '" + this->getDateLivraison() + "', '" + this->getDateSolde() + "', '" + this->getRemise() + "', '" + this->getIDClient() + "', '"+ this->getMontantHT() +"','"+ this->getMontantTTC() +"');SELECT @@IDENTITY;"+
			"INSERT INTO `commande` (`ID_Article`, `ID_Facture`, `QuantiteArticle`) VALUES ('" + this->getIDClient() + "', '" + this->getIDFacture() + "', '" + this->getQuantitéArticle() + "');";
	}

	String^ CL_map_Commande::INSERTDATE(void) {
		return "INSERT INTO date (DatePaiment, MontantPayment, MoyenPayment, ID_Facture) VALUES ('"+this->getDatePayement() +"','"+ this->getMontantTTC() +"','"+ this->getMoyenPayement() +"','"+ this->getIDFacture() +"');SELECT @@IDENTITY;;;";
	}

	String^ CL_map_Commande::UPDATE(void)
	{
		return "UPDATE facture SET RefCommande = '"+this->getRefCommande()+"', MontantTVA = '"+ this->getMontantTVA()+"', DateLivraison = '"+ this->getDateLivraison()+"', DateSolde = '"+this->getDateSolde()+"', Remise = '"+this->getRemise()+"', ID_Client = '"+ this->getIDClient() +"', MontantHT = '"+ this->getMontantHT() +"', MontantTTC = '"+ this->getMontantTTC() + "'WHERE(Reference = " + this->getIDFacture() + "); "+
			"UPDATE Commande SET ID_Article = '" + this->getIDClient() + "',  QuantiteArticle = '" + this->getQuantitéArticle() + "' WHERE(Reference = " + this->getIDFacture() + ");"+
			"UPDATE `date` SET `DatePaiment` = '"+this->getDatePayement()+"',`MontantPayment`='"+this->getMontantPayment()+"',`MoyenPayment`='"+this->getMoyenPayement()+"';";
	}

	String^ CL_map_Commande::DELETE(void)
	{
		return "DELETE FROM date WHERE(ID_Facture = '" + this->getIDFacture() +"');"+
			"DELETE FROM Commande " + "WHERE(ID_Facture = " + this->getIDFacture() + ");"+
			"DELETE FROM facture WHERE (ID_Facture ='"+ this->getIDFacture()+"');";
	}

	void CL_map_Commande::setIDfacture(int idfac)
	{
		if (idfac > 0) {
			this->ID_Facture = idfac;
		}
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

	void CL_map_Commande::setRemise(String^ remise)
	{
		if (remise != "0")
		{
			this->Remise = remise;
		}
	}

	void CL_map_Commande::setMontantTVA(String^ MontantTVA)
	{
		if (MontantTVA != "0")
		{
			this->MontantTVA = MontantTVA;
		}
	}

	void CL_map_Commande::setMontantHT(String^ mht)
	{
		if (mht != "0") {
			this->MontantHT = mht;
		}
	}

	void CL_map_Commande::setMontantTTC(String^ mttc)
	{
		if (mttc != "0") {
			this->MontantTTC = mttc;
		}
	}

	void CL_map_Commande::setIDClient(int ID_Client)
	{
		if (ID_Client > 0)
		{
			this->ID_Client = ID_Client;
		}
	}

	void CL_map_Commande::setQuantitéArticle(String^ Qa)
	{
		if (Qa != "0") {
			this->QuantitéArticle = Qa;
		}
	}

	void CL_map_Commande::setMontantPayment(String^ mt)
	{
		if (mt != "0") {
			this->MontantPayement = mt;
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
	String^ CL_map_Commande::getQuantitéArticle(void)
	{
		return QuantitéArticle;
	}
	String^ CL_map_Commande::getRemise(void)
	{
		return this->Remise;
	}
	String^ CL_map_Commande::getMontantTVA(void)
	{
		return this->MontantTVA;
	}

	String^ CL_map_Commande::getMontantHT(void)
	{
		return this->MontantHT;
	}
	String^ CL_map_Commande::getMontantTTC(void)
	{
		return this->MontantTTC;
	}
	String^ CL_map_Commande::getMontantPayment(void)
	{
		return this->MontantPayement;
	}
}
