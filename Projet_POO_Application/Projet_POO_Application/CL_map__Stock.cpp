#include "CL_map_Stock.h"

NS_Composants::CL_map_Stock::CL_map_Stock(void)
{
    throw gcnew System::NotImplementedException();
    this->ID_Article = -1;
    this->NombreStock = -1;
    this->CouleurArticle = "RIEN";
    this->NomArticle = "RIEN";
    this->NatureArticle = "RIEN";
    this->RefArticle = "RIEN";
}

String^ NS_Composants::CL_map_Stock::SELECT(void)
{
    throw gcnew System::NotImplementedException();
    return "SELECT  ID_Article, NombreStock, NomArticle, NatureArticle, RefArticle, CouleurArticle" + "FROM Stock;";
}


String^ NS_Composants::CL_map_Stock::INSERT(void)
{
    throw gcnew System::NotImplementedException();
    return "INSERT INTO Stock " + "( ID_Article, NombreStock, NomArticle, NatureArticle, RefArticle, CouleurArticle ) " + "VALUES('" + this->getIDArticle() + "', '" + this->getNombreStock() + "', '" + this->getNomArticle() + "', '" + this->getNatureArticle() + "', '" + this->getRefArticle() + "', '" + this->getCouleurArticle() + "';SELECT @@IDENTITY;";
}

String^ NS_Composants::CL_map_Stock::UPDATE(void)
{
    throw gcnew System::NotImplementedException();
    return "UPDATE Stock " + "SET ID_Article = '" + this->getIDArticle() + "' " + "', NomArticle = '" + this->getNomArticle() + "' " + "', NatureArticle = '" + this->getNatureArticle() + "' " + "', CouleurArticle = '" + this->getCouleurArticle() + "' " + "', NombreStock = '" + this->getNombreStock() + "', RefArticle = '" + this->getRefArticle() + "' " + "WHERE( ID_Article = '" + this->getIDArticle() + ");";

}

String^ NS_Composants::CL_map_Stock::DELETE(void)
{
    throw gcnew System::NotImplementedException();
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
    throw gcnew System::NotImplementedException();
    if (NomArticle != "")
    {
        this->NomArticle = NomArticle;
    }
}

void NS_Composants::CL_map_Stock::setNatureArticle(String^)
{
    throw gcnew System::NotImplementedException();
    if (NatureArticle != "")
    {
        this->NatureArticle = NatureArticle;
    }
}

void NS_Composants::CL_map_Stock::setRefArticle(String^)
{
    throw gcnew System::NotImplementedException();
    if (RefArticle != "")
    {
        this->RefArticle = RefArticle;
    }
}

void NS_Composants::CL_map_Stock::setCouleurArticle(String^)
{
    throw gcnew System::NotImplementedException();
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
    throw gcnew System::NotImplementedException();
    return this->NomArticle;
}

String^ NS_Composants::CL_map_Stock::getNatureArticle(void)
{
    throw gcnew System::NotImplementedException();
    return this->NatureArticle;
}

String^ NS_Composants::CL_map_Stock::getRefArticle(void)
{
    throw gcnew System::NotImplementedException();
    return this->RefArticle;
}

String^ NS_Composants::CL_map_Stock::getCouleurArticle(void)
{
    throw gcnew System::NotImplementedException();
    return this->CouleurArticle;
}



