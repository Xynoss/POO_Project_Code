#include "Commande.h"


namespace NS_Composants
{
	Commande::Commande(void)
	{
		this->ID_Article =-1;
		this->ID_Facture = -1;
		this->QuantitéArticle =0;
		this->PrixUnitaire = 0;
		
	}

	String^ Commande::SELECT(void)
	{
		return "SELECT `Commande`.`ID_Facture`,`commande`.`QuantitéArticle`,`Commande`.`PrixUnitaire`, `Facture`.* , `Date`.`ID_Date`, `Date`.`DatePaiment`,`Date`.`MontantPayment`,`Date`.`MoyenPayment`,FROM `Commande` , `Facture`, `Date` WHERE `Commande`.`ID_Facture` = `Facture`.`ID_Facture` AND `Facture`.`ID_Facture` = `Date`.`ID_Facture` ORDER BY `Commande`.`ID_Facture` ASC";
	}

	String^ Commande::INSERTCommande(int ID_Article, int ID_Facture)
	{
		return "INSERT INTO Commande " + "( `ID_Article`, `ID_Facture`, `QuantitéArticle`,`PrixUnitaire`) " + "VALUES('" + this->getID_Article() + "', '" + this->getID_Facture() + "', '" + this->getQuantitéArticle() + "', '" + this->getPrixUnitaire()  + "');SELECT @@IDENTITY;";
	}
	String^ Commande::INSERTFacture(int ID_client)
	{
		return "INSERT INTO Facture " + "( `RefCommande`, `MontantTVA`,`DateLivraison`,`Remise`,`DateSolde`,`ID_Client`) " + "VALUES('" + this->getRefCommande() + "', '" + this->getMontantTVA() + "', '" + this->getRemise() + "','" + this->getDateSolde() + "', '" + ID_client + "');SELECT @@IDENTITY;";
	}
	String^ Commande::INSERTDate(int ID_Facture)
	{
		return "INSERT INTO Date " + "( `DatePaiment`, `MontantPayment`,`DateLivraison`,`MoyenPayment`,`ID_Facture`) " + "VALUES('" + this->getDatePaiment() + "', '" + this->getMontantPayment() + "', '" + this->getDateLivraison() + "', '" + this->getMoyenPayment() + "','" + ID_Facture + "');SELECT @@IDENTITY;";
	}


	String^ Commande::UPDATE(void)
	{
		return "UPDATE `region` " +
			"INNER JOIN `Facture` ON `Date`.`ID_Facture` = `Facture`.`ID_Facture`" +
			"INNER JOIN `Commande` ON `Facture`.`ID_Facture` = `Commande`.`ID_Facture`" +
			"SET" +
			"`Commande`.`QuantitéArticle` = '" + this->getQuantitéArticle() + "'," +
			"`Commande`.`PrixUnitaire` = '" + this->getPrixUnitaire() + "'," +
			"`Facture`.`RefCommande` = '" + this->getRefCommande() + "'," +
			"`Facture`.`MontantTVA` = '" + this->getMontantTVA() + "'," +
			"`Facture`.`DateLivraison` = '" + this->getDateLivraison() + "'," +
			"`Facture`.`Remise` = '" + this->getRemise() + "'," +
			"`Facture`.`DateSolde` = '" + this->getDateSolde() + "'," +
			"`Date`.`DatePaiment` = '" + this->getDatePaiment() + "'," +
			"`Date`.`MontantPayment` = '" + this->getMontantPayment() + "'," +
			"`Date`.`MoyenPayment` = '" + this->getMoyenPayment() + "'" +
			"WHERE" +
			"`Commande`.`ID_Facture` = " + this->getID_Facture() + ";";
	}

	String^ Commande::DELETE(void)
	{
		return "DELETE FROM Commande " + "WHERE(ID_Facture = " + this->getID_Facture() + ");";
	}

	void Commande::setID_Facture(int Reference)
	{
		if (ID_Facture >0)
		{
			this->ID_Facture = ID_Facture;
		}
		
	}

	void Commande::setID_Article(int ID_Article)
	{
		if (ID_Article >0)
		{
			this->ID_Article = ID_Article;
		}
	}

	void Commande::setQuantitéArticle(int QuantitéArticle)
	{
		if (QuantitéArticle > 0)
		{
			this->QuantitéArticle = QuantitéArticle;
		}
	}
	void Commande::setPrixUnitaire(int PrixUnitaire)
	{
		if (PrixUnitaire >0)
		{
			this->PrixUnitaire = PrixUnitaire;
		}
	}
	void Commande::setMoyenPayment(String^ MoyenPayment)
	{
		if (MoyenPayment != "")
		{
			this-> MoyenPayment = MoyenPayment;
		}
	}
	void Commande::setDateSolde(String^ DateSolde)
	{
		if (DateSolde != "")
		{
			this->DateSolde = DateSolde;
		}
	}
	void Commande::setMontantPayment(int MontantPaiment)
	{
		if (MontantPaiment > 0)
		{
			this->MontantPayment = MontantPaiment;
		}
	}
	void Commande::setMontantTVA(int MontantTVA)
	{
		if (MontantTVA > 0)
		{
			this->MontantTVA = MontantTVA;
		}
	}
	void Commande::setRefCommande(String^ RefCommande)
	{
		if (RefCommande != "")
		{
			this->RefCommande = RefCommande;
		}
	}
	void Commande::setDateLivraison(String^ DateLivraison)
	{
		if (DateLivraison != "")
		{
			this->DateLivraison = DateLivraison;
		}
	}
	void Commande::setRemise(int Remise)
	{
		if (Remise > 0)
		{
			this-> Remise= Remise;
		}
	}
	void Commande::setDatePaiment(String^ DatePaiment)
	{
		if (DatePaiment != "")
		{
			this->DatePaiment = DatePaiment;
		}
	}
	int Commande::getID_Facture(void)
	{
		return this->ID_Facture;
	}

	int Commande::getID_Article(void)
	{
		return this->ID_Article;
	}
	String^ Commande::getDateLivraison(void)
	{
		return this->DateLivraison;
	}
	String^ Commande::getDatePaiment(void)
	{
		return this->DatePaiment;
	}
	String^ Commande::getMoyenPayment(void)
	{
		return this->MoyenPayment;
	}
	String^ Commande::getDateSolde(void)
	{
		return this->DateSolde;
	}
	int Commande::getMontantPayment(void)
	{
		return this->MontantPayment;
	}
	int Commande::getQuantitéArticle(void)
	{
		return this->QuantitéArticle;
	}
	int Commande::getPrixUnitaire(void)
	{
		return this->PrixUnitaire;
	}
	String^ Commande::getRefCommande(void)
	{
		return this->RefCommande;
	}
	int Commande::getRemise(void)
	{
		return this-> Remise;
	}
	int Commande::getMontantTVA(void)
	{
		return this->MontantTVA;
	}
}


