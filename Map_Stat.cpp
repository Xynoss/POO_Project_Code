#include "Map_Stat.h"
#include "Commande.h"



namespace NS_Composants
{
	Map_Stat::Map_Stat(void)
	{
		this->Panier_moyen = 0;
		this->Chiffre_Affaire=0;
		this->MontantTA=0;
		this->ValComStock=0;
		this->ValAchatStock=0;

	}

	String^ Map_Stat::SELECT(void)
	{
		return "SELECT `statistique`.* FROM `statistique`";
	}

	
	
	String^ Map_Stat::getPanier_moyen(void)
	{
		return"SELECT AVG( (`Commmande`.`PrixUnitaire` *`Commande`. `QuantitéArticle`)-Facture.Remise )  FROM `Commande` AND `Facture` WHERE Facture.ID_Facture = Commande.ID_Facture";
	}
	String^ Map_Stat::getChiffre_Affaire(void)
	{

		return "SELECT SUM( `Commmande`.`PrixUnitaire` *`Commande`. `QuantitéArticle` ) FROM `Commande`";
	}
	
	String^ Map_Stat::getMontantTA(void)
	{

		return "SELECT AVG( (`Commmande`.`PrixUnitaire` *`Commande`. `QuantitéArticle`)-Facture.Remise ) FROM `Commande` AND `Facture` ";
	}
	
	
	String^ Map_Stat::getValComStock(void)
	{
		return "SELECT SUM((`Facture`.`MontantHT`*(1+`Commande`.`MontantTVA`)*`Commande`.`QuantitéArticle`) FROM `Commande` AND `Facture` WHERE `Commande`.`ID_Facture` = `Facture`.`ID_Facture`)`";
	}
    String^ Map_Stat::getValAchatStock(void)
	{
		return "SELECT SUM((`Facture`.`MontantHT`*`Commande`.`QuantitéArticle`) FROM `Commande` AND `Facture` WHERE `Commande`.`ID_Facture` = `Facture`.`ID_Facture`)`";
	}
	String^ Map_Stat::get10PV(void)
	{
		return "SELECT `Stock`.`nom_Article`, SUM(`Commande`.`QuantitéArticle`) FROM `Commande`GROUP BY `Stock`.`nom_Article` ODER BY SUM(`Commande`.`QuantitéArticle`) DESC LIMIT 10";
	}
	String^ Map_Stat::get10MV(void)
	{
		return "SELECT `Stock`.`nom_Article`, SUM(`Commande`.`QuantitéArticle`) FROM `Commande`GROUP BY `Stock`.`nom_Article` ODER BY SUM(`Commande`.`QuantitéArticle`) ASC LIMIT 10";
	}
	String^ Map_Stat::getCalculMontantClient(void)
	{
		return  "SELECT `client`.`nom_client`, `client`.`prenom_client`, SUM((`Date`.`MontantPaiement`)), FROM `Date`,`client`";
	
}
