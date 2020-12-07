#include "CL_map_TBPERSONNEL.h"

NS_Composants::CL_map_Personnel::CL_map_Personnel(void)
{
    this->ID_personnel = -1;
    this->ID_personnel_supervise = -1;
    this->NomPersonnel = "RIEN";
    this->PrenomPersonnel = "RIEN";
    this->AdressePersonnel = "RIEN";
    this->DateDembauche = "RIEN";
}

String^ NS_Composants::CL_map_Personnel::SELECT(void)
{
    return "SELECT  ID_personnel, NomPersonnel, PrenomPersonnel, AdressePersonnel, DateDembauche, ID_personnel_supervise " + "FROM projet_01.personnel;";
}

String^ NS_Composants::CL_map_Personnel::INSERT(void)
{
    return "INSERT INTO Personnel " + "(NomPersonnel, PrenomPersonnel, AdressePersonnel, DateDembauche, ID_personnel_supervise) " + "VALUES('" + this->getNomPersonnel() + "', '" + this->getPrenomPersonnel() + "', '" + this->getAdressePersonnel() + "', '" + this->getDateDembauche() + "', '" + this->getIDSup() + "');SELECT @@IDENTITY;";
}

String^ NS_Composants::CL_map_Personnel::INSERTSSup(void)
{
    return "INSERT INTO Personnel (NomPersonnel, PrenomPersonnel, AdressePersonnel, DateDembauche) " + "VALUES('" + this->getNomPersonnel() + "', '" + this->getPrenomPersonnel() + "', '" + this->getAdressePersonnel() + "', '" + this->getDateDembauche() + "');SELECT @@IDENTITY;";
}

String^ NS_Composants::CL_map_Personnel::UPDATE(void)
{
    return "UPDATE Personnel " + "SET NomPersonnel = '" + this->getNomPersonnel() + "', PrenomPersonnel = '" + this->getPrenomPersonnel() + "', AdressePersonnel = '" + this->getAdressePersonnel() + "', DateDembauche = '" + this->getDateDembauche() + "', ID_personnel_supervise = '" + this->getIDSup() + "' WHERE( ID_personnel = " + this->getID() + ");";
}

String^ NS_Composants::CL_map_Personnel::UPDATESSup(void)
{
    return "UPDATE Personnel " + "SET NomPersonnel = '" + this->getNomPersonnel() + "', PrenomPersonnel = '" + this->getPrenomPersonnel() + "', AdressePersonnel = '" + this->getAdressePersonnel() + "', DateDembauche = '" + this->getDateDembauche() + "' WHERE( ID_personnel = " + this->getID() + ");";
}
String^ NS_Composants::CL_map_Personnel::DELETE(void)
{
    return "DELETE FROM Personnel " + "WHERE( ID_Personnel = " + this->getID() + ");";
}

void NS_Composants::CL_map_Personnel::setID(int ID_personnel)
{
    if (ID_personnel > 0)
    {
        this->ID_personnel = ID_personnel;
    }
}

void NS_Composants::CL_map_Personnel::setIDSup(int ID_personnel_supervise)
{
    if (ID_personnel_supervise > 0)
    {
        this->ID_personnel_supervise = ID_personnel_supervise;
    }
}

void NS_Composants::CL_map_Personnel::setPrenomPersonnel(String^ PrenomPersonnel)
{
    if (PrenomPersonnel != "")
    {
        this->PrenomPersonnel = PrenomPersonnel;
    }
}

void NS_Composants::CL_map_Personnel::setNomPersonnel(String^ NomPersonnel)
{
    if (NomPersonnel != "")
    {
        this->NomPersonnel = NomPersonnel;
    }
}

void NS_Composants::CL_map_Personnel::setAdressePersonnel(String^ AdressePersonnel)
{
    if (AdressePersonnel != "")
    {
        this->AdressePersonnel = AdressePersonnel;
    }
}

void NS_Composants::CL_map_Personnel::setDateDembauche(String^ DateDembauche)
{
    if (DateDembauche != "")
    {
        String^ D = DateDembauche->Substring(0, 2);//jours
        String^ M = DateDembauche->Substring(3, 2);//mois
        String^ Y = DateDembauche->Substring(6, 4);//année
        this->DateDembauche = Y + "-" + M + "-" + D;
    }
}

int NS_Composants::CL_map_Personnel::getID(void)
{
    return this->ID_personnel;
}

int NS_Composants::CL_map_Personnel::getIDSup(void)
{
    return this->ID_personnel_supervise;
}

String^ NS_Composants::CL_map_Personnel::getNomPersonnel(void)
{
    return this->NomPersonnel;
}

String^ NS_Composants::CL_map_Personnel::getPrenomPersonnel(void)
{
    return this->PrenomPersonnel;
}

String^ NS_Composants::CL_map_Personnel::getAdressePersonnel(void)
{
    return this->AdressePersonnel;
}

String^ NS_Composants::CL_map_Personnel::getDateDembauche(void)
{
    return this->DateDembauche;
}
