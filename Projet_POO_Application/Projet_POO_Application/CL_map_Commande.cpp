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
		this->MontantHT = "0";
		this->MontantTTC = "0";
		this->QuantitéArticle = "0";
		this->MontantPayement = "0";
	}

	String^ CL_map_Commande::SELECT(void)
	{
		return "SELECT `Facture`.`ID_Facture`, `Facture`.`RefCommande`, `client`.`ID_Client`, `Facture`.`MontantTVA`, `Facture`.`DateLivraison`, `Facture`.`Remise`, `Facture`.`DateSolde`, `Facture`.`MontantHT`, `Facture`.`MontantTTC`, `commande`.`QuantiteArticle`, `stock`.`PrixUnitaire`, `Date`.`ID_Date`, `Date`.`DatePaiment`, `Date`.`MontantPayment`, `Date`.`MoyenPayment`, `Client`.`NaissanceClient`, `region`.`Ville`, `stock`.`ID_Article` ,`client`.`PrenomClient`, `client`.`NomClient` FROM `Commande`, `Facture`, `Date`, `stock`, `client`, `region`, `appartient` WHERE `Commande`.`ID_Facture` = `Facture`.`ID_Facture` AND `Facture`.`ID_Facture` = `Date`.`ID_Facture` AND `stock`.`ID_Article` = `commande`.`ID_Article` AND `Facture`.`ID_Client` = `client`.`ID_Client` AND `region`.`ID_region` = `appartient`.`ID_region` AND `appartient`.`ID_Client` = `client`.`ID_Client` ORDER BY `Commande`.`ID_Facture` ASC";
	}
	String^ CL_map_Commande::SELECTCOM(void)
	{
		return "SELECT `commande`.`ID_Article`, `stock`.`PrixUnitaire` ,`commande`.`ID_Facture`, `QuantiteArticle`, `facture`.`RefCommande` FROM `commande`, `facture`,`stock` WHERE `commande`.`ID_Facture` = `facture`.`ID_Facture` AND `commande`.`ID_Article` = `stock`.`ID_Article`;";
	}


	String^ CL_map_Commande::SELECTDGV(void)
	{
		return "SELECT `Facture`.`ID_Facture`, `Facture`.`RefCommande`, `client`.`ID_Client`,  `Facture`.`MontantTVA`, `Facture`.`DateLivraison`, `Facture`.`Remise`, `Facture`.`DateSolde`, `Facture`.`MontantHT`,  `Facture`.`MontantTTC`, `commande`.`QuantiteArticle`, `stock`.`PrixUnitaire`,    `Date`.`ID_Date`,    `Date`.`DatePaiment`,    `Date`.`MontantPayment`,    `Date`.`MoyenPayment`, `Client`.`NaissanceClient`,    `region`.`Ville`,    `stock`.`ID_Article`FROM    `Commande`,    `Facture`,    `Date`,    `stock`,    `client`,    `region`,    `appartient` WHERE    `Commande`.`ID_Facture` = `Facture`.`ID_Facture` AND `Facture`.`ID_Facture` = `Date`.`ID_Facture` AND `stock`.`ID_Article` = `commande`.`ID_Article` AND `Facture`.`ID_Client` = `client`.`ID_Client` AND `region`.`ID_region` = `appartient`.`ID_region` AND `appartient`.`ID_Client` = `client`.`ID_Client` ORDER BY    `Commande`.`ID_Facture` ASC;";
	}

	String^ CL_map_Commande::SELECTPRIXHT(void)
	{
		return "SELECT MontantHT FROM `facture` WHERE (ID_facture = '" + this->getIDFacture() + "');";
	}

	String^ CL_map_Commande::SELECTPrixUni(int ID_Article)
	{
		return "SELECT PrixUnitaire FROM stock WHERE `stock`.`ID_Article` = '" + ID_Article + "';";
	}



	String^ CL_map_Commande::INSERT(double HT, double TVA, double TTC)
	{
		return "INSERT INTO facture (RefCommande, MontantTVA, DateLivraison, DateSolde, Remise, ID_Client, MontantHT, MontantTTC) " + "VALUES('" + this->getRefCommande() + "', '" + TVA + "', '" + this->getDateLivraison() + "', '" + this->getDateSolde() + "', '" + this->getRemise() + "', '" + this->getIDClient() + "', '" + HT + "','" + TTC + "');SELECT @@IDENTITY;";
			
		//INSERT INTO facture(RefCommande, MontantTVA, DateLivraison, DateSolde, Remise, ID_Client, MontantHT, MontantTTC) VALUES('MATH2020SAI2', '2.8', '04/12/2020', '04/12/2020', '5', (SELECT ID_Client FROM client WHERE client.NomClient =  AND client.PrenomClient = ), '14.6', '16.8')
	}

	String^ CL_map_Commande::INSERTCOMMANDE(int IDFACTURE) {
		return "INSERT INTO `commande` (`ID_Article`, `ID_Facture`, `QuantiteArticle`) VALUES ((SELECT ID_Article FROM Stock WHERE Stock.ID_Article = '" + this->getIDArticle() + "'), '" + IDFACTURE + "', '" + this->getQuantitéArticle() + "');SELECT @@IDENTITY;";
		//INSERT INTO `commande` (`ID_Article`, `ID_Facture`, `QuantiteArticle`) VALUES ((SELECT Stock.ID_Article FROM Stock WHERE Stock.ID_Article = '2'), '2', '12');
	}

	String^ CL_map_Commande::INSERTDATE(int IDFACTURE, double TTC) {
		return "INSERT INTO date (DatePaiment, MontantPayment, MoyenPayment, ID_Facture) VALUES ('"+this->getDatePayement() +"','"+ TTC +"','"+ this->getMoyenPayement() +"','"+ IDFACTURE +"');";
	}

	String^ CL_map_Commande::UPDATE(double HT, double TVA, double TTC)
	{
		return "UPDATE facture SET RefCommande = '"+this->getRefCommande()+"', DateLivraison = '"+ this->getDateLivraison()+"', DateSolde = '"+this->getDateSolde()+"', Remise = '" + this->getRemise() + "', ID_Client = '"+ this->getIDClient() +"', MontantTVA = '" + TVA + "', MontantHT = '" + HT + "', MontantTTC = '" + TTC + "' WHERE(ID_Facture = " + this->getIDFacture() + "); "+
			"UPDATE `date` SET `DatePaiment` = '"+this->getDatePayement()+"',`MontantPayment`='" + TTC + "',`MoyenPayment`='"+this->getMoyenPayement()+"' WHERE(ID_Facture = " + this->getIDFacture() + ");;";
	}

	String^ CL_map_Commande::UPDATESPrix()
	{
		return "UPDATE facture SET RefCommande = '" + this->getRefCommande() + "', DateLivraison = '" + this->getDateLivraison() + "', DateSolde = '" + this->getDateSolde() + "', ID_Client = '" + this->getIDClient() + "' WHERE(ID_Facture = " + this->getIDFacture() + "); " +
			"UPDATE `date` SET `DatePaiment` = '" + this->getDatePayement() + "',`MoyenPayment`='" + this->getMoyenPayement() + "' WHERE(ID_Facture = " + this->getIDFacture() + ");;";
	}

	String^ CL_map_Commande::UPDATEARTICLE(double HT, double TVA, double TTC)
	{
		return "UPDATE facture SET MontantTVA = '" + TVA + "', MontantHT = '" + HT + "', MontantTTC = '" + TTC + "'WHERE(ID_Facture = " + this->getIDFacture() + "); ";
	}

	String^ CL_map_Commande::UPDATEARTICLE2()
	{
		return "UPDATE Commande SET QuantiteArticle = '" + this->getQuantitéArticle() + "' WHERE(ID_Facture = " + this->getIDFacture() + " AND ID_Article = " +this->getIDArticle() +");";
	}
	

	String^ CL_map_Commande::DELETE(void)
	{
		return "DELETE FROM date WHERE(ID_Facture = '" + this->getIDFacture() +"');"+
			"DELETE FROM Commande " + "WHERE(ID_Facture = " + this->getIDFacture() + ");"+
			"DELETE FROM facture WHERE (ID_Facture ='"+ this->getIDFacture()+"');";
	}

	String^ CL_map_Commande::DELETEArticle(void) {
		return "DELETE FROM Commande " + "WHERE(ID_Facture = " + this->getIDFacture() + " AND ID_Article = " + this->getIDArticle() + ");";
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
		String^ V = Ville->Substring(0,3);

		Reference = P + N + annee + V;
		this->RefCommande = Reference;
		
	}

	void CL_map_Commande::setDateCommande(String^ DateCommande)
	{
		if (DateCommande != "")
		{
			String^ D = DateCommande->Substring(0,2);//jours
			String^ M = DateCommande->Substring(4,2);//mois
			String^ Y = DateCommande->Substring(7,4);//année
			this->DateCommande = Y + "-" + M + "-" + D;
		}
	}

	void CL_map_Commande::setDateLivraison(String^ DateLivraison)
	{
		if (DateLivraison != "")
		{
			String^ D = DateLivraison->Substring(0, 2);//jours
			String^ M = DateLivraison->Substring(3, 2);//mois
			String^ Y = DateLivraison->Substring(6, 4);//année
			this->DateLivraison = Y + "-" + M + "-" + D;
		}
	}
	void CL_map_Commande::setDatePayement(String^ DatePayement)
	{
		if (DatePayement != "")
		{
			String^ D = DatePayement->Substring(0, 2);//jours
			String^ M = DatePayement->Substring(3, 2);//mois
			String^ Y = DatePayement->Substring(6, 4);//année
			this->DatePayement = Y + "-" + M + "-" + D;
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
			String^ D = DateSolde->Substring(0, 2);//jours
			String^ M = DateSolde->Substring(3, 2);//mois
			String^ Y = DateSolde->Substring(6, 4);//année
			this->DateSolde = Y + "-" + M + "-" + D;
		}
	}

	void CL_map_Commande::setRemise(String^ remise)
	{
		if (remise != "")
		{
			this->Remise = remise;
		}
	}

	void CL_map_Commande::setMontantTVA(double MontantHT)
	{
		if (MontantHT > 0)
		{
			double TVA = MontantHT * 0.2;
			this->MontantTVA = Convert::ToString(TVA);
		}
	}

	void CL_map_Commande::setMontantHT(double QA, double PU)
	{
		if (QA > 0 && PU > 0) {
			double result = QA * PU;
			this->MontantHT = Convert::ToString(result); //ici faut qu'on fasse PrixUnitaire*Quantité
		}
	}

	void CL_map_Commande::setMontantHT2(double HT)
	{
		if(HT > 0) {
			this->MontantHT2 = Convert::ToString(HT);
		}
	}

	void CL_map_Commande::setMontantHT3(double HT, double HTD)
	{
		if (HT > 0 && HTD > 0) {
			this->MontantHT3 = Convert::ToString(HT + HTD);
		}
	}

	void CL_map_Commande::setMontantTTC(double MHT, double MTVA, double Rem)
	{
		if (MHT > 0 && MTVA > 0) {
			this->MontantTTC = Convert::ToString( MHT + MTVA - Rem); //ici faut qu'on fasse MontantHT + MontantTVA pour avoir le prix TTC 
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
	String^ CL_map_Commande::getMontantTVA(void)
	{
		return this->MontantTVA;
	}

	String^ CL_map_Commande::getMontantHT(void)
	{
		return this->MontantHT;
	}
	String^ CL_map_Commande::getMontantHT2(void)
	{
		return this->MontantHT2;
	}
	String^ CL_map_Commande::getMontantHT3(void)
	{
		return this->MontantHT3;
	}
	String^ CL_map_Commande::getMontantTTC(void)
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
