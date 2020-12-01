#include "CL_map_Stock.h"

NS_Composants::CL_map_Stock::CL_map_Stock(void)
{
    throw gcnew System::NotImplementedException();
    this->TauxTVA = -1;
    this->TVA = -1;
    this->nmbArticle = -1;
    this->PrixUnitaire = -1;
    this->SeuilApprovisionnement = -1;
    this->NomArticle = "RIEN";
    this->NatureArticle = "RIEN";
    this->ReferenceArticle = "RIEN";
}

String^ NS_Composants::CL_map_Stock::SELECT(void)
{
    throw gcnew System::NotImplementedException();
    return "SELECT  TVA, PrixUnitaire, NomArticle, NatureArticle, ReferenceArticle" + "FROM Stock;";
}

String^ NS_Composants::CL_map_Stock::SELECT_STOCK(void)
{
    throw gcnew System::NotImplementedException();
    return "SELECT  TauxTVA, SeuilApprovisionnement, nmbArticle" + "FROM Stock;";
}

String^ NS_Composants::CL_map_Stock::INSERT(void)
{
    throw gcnew System::NotImplementedException();
    return "INSERT INTO Stock " + "( TVA, PrixUnitaire, NomArticle, NatureArticle, ReferenceArticle ) " + "VALUES('" + this->getTVA() + "', '" + this->getPrixUnitaire() + "', '" + this->getNomArticle() + "', '" + this->getNatureArticle() + "', '" + this->getReferenceArticle() + "';SELECT @@IDENTITY;";
}

String^ NS_Composants::CL_map_Stock::UPDATE(void)
{
    throw gcnew System::NotImplementedException();
    return "UPDATE Stock " + "SET NomArticle = '" + this->getNomArticle() + "' " + "', NatureArticle = '" + this->getNatureArticle() + "' " + "', TVA = '" + this->getTVA() + "' " + "', PrixUnitaire = '" + this->getPrixUnitaire() + "', RefrenceArticle = '" + this->getReferenceArticle() + "' " + "WHERE( RefrenceArticle = '" + this->getReferenceArticle() + ");";

}

String^ NS_Composants::CL_map_Stock::DELETE(void)
{
    throw gcnew System::NotImplementedException();
    return "DELETE FROM Stock " + "WHERE( ReferenceArticle = " + this->getReferenceArticle() + ");";
}


void NS_Composants::CL_map_Stock::setTauxTVA(int)
{
    if (TauxTVA > 0)
    {
        this->TauxTVA = TauxTVA;
    }
}

void NS_Composants::CL_map_Stock::setTVA(int)
{
    if (TVA > 0)
    {
        this->TVA = TVA;
    }
}

void NS_Composants::CL_map_Stock::setPrixUnitaire(int)
{
    if (PrixUnitaire > 0)
    {
        this->PrixUnitaire = PrixUnitaire;
    }
}

void NS_Composants::CL_map_Stock::setnmbArticle(int)
{
    if (nmbArticle > 0)
    {
        this->nmbArticle = nmbArticle;
    }
}

void NS_Composants::CL_map_Stock::setSeuilApprovisionnement(int)
{
    if (SeuilApprovisionnement > 0)
    {
        this->SeuilApprovisionnement = SeuilApprovisionnement;
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

void NS_Composants::CL_map_Stock::setReferenceArticle(String^)
{
    throw gcnew System::NotImplementedException();
    if (ReferenceArticle != "")
    {
        this->ReferenceArticle = ReferenceArticle;
    }
}


int NS_Composants::CL_map_Stock::getTauxTVA()
{
    return this->TauxTVA;
}

int NS_Composants::CL_map_Stock::getTVA()
{
    return this->TVA;
}

int NS_Composants::CL_map_Stock::getPrixUnitaire()
{
    return this->PrixUnitaire;
}

int NS_Composants::CL_map_Stock::getnmbArticle()
{
    return this->nmbArticle;
}

int NS_Composants::CL_map_Stock::getSeuilApprovisionnement()
{
    return this->SeuilApprovisionnement;
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

String^ NS_Composants::CL_map_Stock::getReferenceArticle(void)
{
    throw gcnew System::NotImplementedException();
    return this->ReferenceArticle;
}



