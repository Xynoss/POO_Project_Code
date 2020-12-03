#include "CL_map__Stock.h"

NS_Composants::CL_map_Stock::CL_map_Stock(void)
{
    this->ID_Article = -1;
    this->NombreStock = -1;
    this->CouleurArticle = "RIEN";
    this->NomArticle = "RIEN";
    this->NatureArticle = "RIEN";
    this->RefArticle = "RIEN";
    this->PrixUnitaire = "";
}

String^ NS_Composants::CL_map_Stock::SELECT(void)
{
    return "SELECT ID_Article, NomArticle, NatureArticle, RefArticle,  CouleurArticle,  NombreStock, PrixUnitaire FROM Stock ;";
}


String^ NS_Composants::CL_map_Stock::INSERT(void)
{
    return "INSERT INTO Stock (RefArticle, NatureArticle, CouleurArticle, NomArticle, NombreStock, PrixUnitaire) VALUES('"+ this->getRefArticle() +"', '"+ this->getNatureArticle() +"', '"+ this->getCouleurArticle() +"', '"+ this->getNomArticle() +"', '"+this->getNombreStock()+"','"+this->getPrixUnitaire()+"');";
}

String^ NS_Composants::CL_map_Stock::UPDATE(void)
{
    return "UPDATE Stock SET  NomArticle = '" + this->getNomArticle() + "', NatureArticle = '" + this->getNatureArticle() + "', CouleurArticle = '" + this->getCouleurArticle()+ "', NombreStock = '" + this->getNombreStock() + "', RefArticle = '" + this->getRefArticle() + "', PrixUnitaire = '"+ this->getPrixUnitaire() +"' WHERE( ID_Article = '" + this->getIDArticle() + "');";
}

String^ NS_Composants::CL_map_Stock::DELETE(void)
{
    
    return "DELETE FROM Stock " + "WHERE( ID_Article = '" + this->getIDArticle() + "');";
}


void NS_Composants::CL_map_Stock::setIDArticle(int idA)
{
    if (idA > 0)
    {
        this->ID_Article = idA;
    }
}

void NS_Composants::CL_map_Stock::setNombreStock(int nbS)
{
    if (nbS > 0)
    {
        this->NombreStock = nbS;
    }
}


void NS_Composants::CL_map_Stock::setNomArticle(String^ NomA)
{
    if (NomA != "")
    {
        this->NomArticle = NomA;
    }
}

void NS_Composants::CL_map_Stock::setNatureArticle(String^ NatA)
{
    if (NatA != "")
    {
        this->NatureArticle = NatA;
    }
}

void NS_Composants::CL_map_Stock::setRefArticle(String^ RefA)
{
    if (RefA != "")
    {
        this->RefArticle = RefA;
    }
}

void NS_Composants::CL_map_Stock::setCouleurArticle(String^ CoulA)
{
    if (CoulA != "")
    {
        this->CouleurArticle = CoulA;
    }
}

void NS_Composants::CL_map_Stock::setPrixUnitaire(String^ pu)
{
    if (pu != "")
    {
        this->PrixUnitaire = pu;
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

String^ NS_Composants::CL_map_Stock::getPrixUnitaire(void)
{
    return this->PrixUnitaire;
}