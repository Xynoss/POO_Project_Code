#include "CL_map__Stock.h"

NS_Composants::CL_map_Stock::CL_map_Stock(void)
{
    this->ID_Article = -1;
    this->NombreStock = -1;
    this->CouleurArticle = "RIEN";
    this->NomArticle = "RIEN";
    this->NatureArticle = "RIEN";
    this->RefArticle = "RIEN";
}

String^ NS_Composants::CL_map_Stock::SELECT(void)
{
    return "SELECT `stock`.* , `commande`.`PrixUnitaire` FROM Stock, commande WHERE `stock`.`ID_Article` = `commande`.`ID_Article`;";
}


String^ NS_Composants::CL_map_Stock::INSERT(void)
{
    return "INSERT INTO Stock " + "( NombreStock, NomArticle, NatureArticle, RefArticle, CouleurArticle ) " + "VALUES('" + this->getNombreStock() + "', '" + this->getNomArticle() + "', '" + this->getNatureArticle() + "', '" + this->getRefArticle() + "', '" + this->getCouleurArticle() + "';";
}

String^ NS_Composants::CL_map_Stock::UPDATE(void)
{
    return "UPDATE Stock " + "SET  NomArticle = '" + this->getNomArticle() + "' " + "', NatureArticle = '" + this->getNatureArticle() + "' " + "', CouleurArticle = '" + this->getCouleurArticle() + "' " + "', NombreStock = '" + this->getNombreStock() + "', RefArticle = '" + this->getRefArticle() + "' " + "WHERE( ID_Article = '" + this->getIDArticle() + ");";

}

String^ NS_Composants::CL_map_Stock::DELETE(void)
{
    
    return "DELETE FROM Stock " + "WHERE( ID_Article = " + this->getIDArticle() + ");";
}


void NS_Composants::CL_map_Stock::setIDArticle(int)
{
    if (ID_Article > 0)
    {
        this->ID_Article = ID_Article;
    }
}

void NS_Composants::CL_map_Stock::setNombreStock(int)
{
    if (NombreStock > 0)
    {
        this->NombreStock = NombreStock;
    }
}


void NS_Composants::CL_map_Stock::setNomArticle(String^)
{
    if (NomArticle != "")
    {
        this->NomArticle = NomArticle;
    }
}

void NS_Composants::CL_map_Stock::setNatureArticle(String^)
{
    if (NatureArticle != "")
    {
        this->NatureArticle = NatureArticle;
    }
}

void NS_Composants::CL_map_Stock::setRefArticle(String^)
{
    if (RefArticle != "")
    {
        this->RefArticle = RefArticle;
    }
}

void NS_Composants::CL_map_Stock::setCouleurArticle(String^)
{
    if (CouleurArticle != "")
    {
        this->CouleurArticle = CouleurArticle;
    }
}

int NS_Composants::CL_map_Stock::getNombreStock()
{
    return this->NombreStock;
}

int NS_Composants::CL_map_Stock::getIDArticle()
{
    return this->ID_Article;
}


String^ NS_Composants::CL_map_Stock::getNomArticle(void)
{
    
    return this->NomArticle;
}

String^ NS_Composants::CL_map_Stock::getNatureArticle(void)
{
    
    return this->NatureArticle;
}

String^ NS_Composants::CL_map_Stock::getRefArticle(void)
{
    
    return this->RefArticle;
}

String^ NS_Composants::CL_map_Stock::getCouleurArticle(void)
{
    
    return this->CouleurArticle;
}



