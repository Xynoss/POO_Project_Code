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
		this->MontantTVA = 0;
		this->MontantHT = 0;
		this->MontantTTC = 0;
		this->QuantitéArticle = "0";
		this->MontantPayement = "0";
	}

	String^ CL_map_Commande::SELECT(void)
	{
		return "SELECT `Facture`.`ID_Facture`, `Facture`.`RefCommande`, `client`.`ID_Client`,  `Facture`.`MontantTVA`, `Facture`.`DateLivraison`, `Facture`.`Remise`, `Facture`.`DateSolde`, `Facture`.`MontantHT`,  `Facture`.`MontantTTC`, `commande`.`QuantiteArticle`, `commande`.`PrixUnitaire`,    `Date`.`ID_Date`,    `Date`.`DatePaiment`,    `Date`.`MontantPayment`,    `Date`.`MoyenPayment`, `Client`.`NaissanceClient`,    `region`.`Ville`,    `stock`.`ID_Article`FROM    `Commande`,    `Facture`,    `Date`,    `stock`,    `client`,    `region`,    `appartient` WHERE    `Commande`.`ID_Facture` = `Facture`.`ID_Facture` AND `Facture`.`ID_Facture` = `Date`.`ID_Facture` AND `stock`.`ID_Article` = `commande`.`ID_Article` AND `Facture`.`ID_Client` = `client`.`ID_Client` AND `region`.`ID_region` = `appartient`.`ID_region` AND `appartient`.`ID_Client` = `client`.`ID_Client` ORDER BY    `Commande`.`ID_Facture` ASC;";
	}

	String^ CL_map_Commande::INSERT(void)
	{
		return "INSERT INTO facture (RefCommande, MontantTVA, DateLivraison, DateSolde, Remise, ID_Client, MontantHT, MontantTTC) " + "VALUES('" + this->getRefCommande() + "', '" + this->getMontantTVA() + "', '" + this->getDateLivraison() + "', '" + this->getDateSolde() + "', '" + this->getRemise() + "', '" + this->getIDClient() + "', '"+ this->getMontantHT() +"','"+ this->getMontantTTC() +"');SELECT @@IDENTITY;"+
			"INSERT INTO `commande` (`ID_Article`, `ID_Facture`, `QuantiteArticle`, `PrixUnitaire`) VALUES ('" + this->getIDArticle() + "', '" + this->getIDFacture() + "', '" + this->getQuantitéArticle() + "'', '" + this->getPrixUnitaire() + "');";
		//INSERT INTO facture(RefCommande, MontantTVA, DateLivraison, DateSolde, Remise, ID_Client, MontantHT, MontantTTC) VALUES('MATH2020SAI2', '2.8', '04/12/2020', '04/12/2020', '5', (SELECT ID_Client FROM client WHERE client.NomClient =  AND client.PrenomClient = ), '14.6', '16.8')
	}

	String^ CL_map_Commande::INSERTDATE(void) {
		return "INSERT INTO date (DatePaiment, MontantPayment, MoyenPayment, ID_Facture) VALUES ('"+this->getDatePayement() +"','"+ this->getMontantTTC() +"','"+ this->getMoyenPayement() +"','"+ this->getIDFacture() +"');SELECT @@IDENTITY;;;";
	}

	String^ CL_map_Commande::UPDATE(void)
	{
		return "UPDATE facture SET RefCommande = '"+this->getRefCommande()+"', MontantTVA = '"+ this->getMontantTVA()+"', DateLivraison = '"+ this->getDateLivraison()+"', DateSolde = '"+this->getDateSolde()+"', Remise = '"+this->getRemise()+"', ID_Client = '"+ this->getIDClient() +"', MontantHT = '"+ this->getMontantHT() +"', MontantTTC = '"+ this->getMontantTTC() + "'WHERE(Reference = " + this->getIDFacture() + "); "+
			"UPDATE Commande SET QuantiteArticle = '" + this->getQuantitéArticle() + "' WHERE(Reference = " + this->getIDFacture() + ");"+
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

	void CL_map_Commande::setReference(String^ Reference, String^ Prenom, String^ Nom, String^ annee, String^ Ville)
	{
		String^ P = Prenom->Substring(0,2);
		String^ N = Nom->Substring(0, 2);
		String^ V = Ville->Substring(0, 3);

		Reference = P + N + annee + V;
		this->RefCommande = Reference;
		
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

	void CL_map_Commande::setMontantTVA(double MontantHT)
	{
		MontantHT = this->getMontantHT();
		if (MontantHT > 0)
		{
			this->MontantTVA = Convert::ToDouble(MontantHT)*0.2;
		}
	}

	void CL_map_Commande::setMontantHT(double MHT)
	{
		if (MHT > 0) {
			this->MontantHT = MHT; //ici faut qu'on fasse PrixUnitaire*Quantité
		}
	}

	void CL_map_Commande::setMontantTTC(double MHT, double MTVA)
	{
		if (MHT > 0 && MTVA > 0) {
			this->MontantTTC = MHT + MTVA - Convert::ToDouble(this->Remise); //ici faut qu'on fasse MontantHT + MontantTVA pour avoir le prix TTC 
		}
	}

	void CL_map_Commande::setIDClient(int ID_Client)
	{
		if (ID_Client > 0)
		{
			this->ID_Client = ID_Client;
		}
	}

	void CL_map_Commande::setIDArticle(int ID_Article)
	{
		if (ID_Article > 0)
		{
			this->ID_Article = ID_Article;
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

	void CL_map_Commande::setPrixUnitaire(String^ PU)
	{
		if (PU != "0")
		{
			this->PrixUnitaire = PU;
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

	int CL_map_Commande::getIDArticle(void)
	{
		return this->ID_Article;
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
	double CL_map_Commande::getMontantTVA(void)
	{
		return this->MontantTVA;
	}

	double CL_map_Commande::getMontantHT(void)
	{
		return this->MontantHT;
	}
	double CL_map_Commande::getMontantTTC(void)
	{
		return this->MontantTTC;
	}
	String^ CL_map_Commande::getMontantPayment(void)
	{
		return this->MontantPayement;
	}
	String^ CL_map_Commande::getPrixUnitaire(void)
	{
		return this->PrixUnitaire;
	}
}
