#include "CL_map_Personnel.h"

NS_Composants::CL_map_Personnel::CL_map_Personnel(void)
{
    throw gcnew System::NotImplementedException();
    this->ID_personnel = -1;
    this->ID_Superieur = -1;
    this->NomPersonnel = "RIEN";
    this->PrenomPersonnel = "RIEN";
    this->AdressePersonnel = "RIEN";
    this->DateDembauche = "RIEN";
}

String^ NS_Composants::CL_map_Personnel::SELECT(void)
{
    throw gcnew System::NotImplementedException();
    return "SELECT  ID_personnel, ID_Superieur, NomPersonnel, PreNomPersonnelPersonnel, AdressePersonnel, DateDembauche " + "FROM Personnel;";
}

String^ NS_Composants::CL_map_Personnel::INSERT(void)
{
    throw gcnew System::NotImplementedException();
    return "INSERT INTO Personnel " + "(ID_Superviseur, NomPersonnel, PreNomPersonnelPersonnel, AdressePersonnel, DateDembauche) " + "VALUES('" + this->getIDSup() + "', '" + this->getNomPersonnel() + "', '" + this->getPrenomPersonnel() + "', '" + this->getAdressePersonnel() +  "', '" + this->getDateDembauche() + "');SELECT @@IDENTITY;";
}

String^ NS_Composants::CL_map_Personnel::UPDATE(void)
{
    throw gcnew System::NotImplementedException();
    return "UPDATE Personnel " + "SET ID_Superieur = '" + this->getIDSup() + "', NomPersonnel = '" + this->getNomPersonnel() + "' " + "', PreNomPersonnelPersonnel = '" + this->getPrenomPersonnel() + "' " + "', AdressePersonnel = '" + this->getAdressePersonnel() + "' " + "', DateDembauche = '" + this->getDateDembauche() + "' " + "WHERE( ID_personnel = " + this->getID() + ");";
}

String^ NS_Composants::CL_map_Personnel::DELETE(void)
{
    throw gcnew System::NotImplementedException();
    return "DELETE FROM Personnel " + "WHERE( ID_Personnel = " + this->getID() + ");";
}

void NS_Composants::CL_map_Personnel::setID(int)
{
    throw gcnew System::NotImplementedException();
    if (ID_personnel > 0)
    {
        this->ID_personnel = ID_personnel;
    }
}

void NS_Composants::CL_map_Personnel::setIDSup(int)
{
    if (ID_Superieur > 0)
    {
        this->ID_Superieur = ID_Superieur;
    }
}

void NS_Composants::CL_map_Personnel::setPrenomPersonnel(String^)
{
    throw gcnew System::NotImplementedException();
    if (PrenomPersonnel != "")
    {
        this->PrenomPersonnel = PrenomPersonnel;
    }
}

void NS_Composants::CL_map_Personnel::setNomPersonnel(String^)
{
    throw gcnew System::NotImplementedException();
    if (NomPersonnel != "")
    {
        this->NomPersonnel = NomPersonnel;
    }
}

void NS_Composants::CL_map_Personnel::setAdressePersonnel(String^)
{
    throw gcnew System::NotImplementedException();
    if (AdressePersonnel != "")
    {
        this->AdressePersonnel = AdressePersonnel;
    }
}

void NS_Composants::CL_map_Personnel::setDateDembauche(String^)
{
    throw gcnew System::NotImplementedException();
    if (DateDembauche != "")
    {
        this->DateDembauche = DateDembauche;
    }
}

int NS_Composants::CL_map_Personnel::getID()
{
    throw gcnew System::NotImplementedException();
    return this->ID_personnel;
}

int NS_Composants::CL_map_Personnel::getIDSup()
{
    return this->ID_Superieur;
}

String^ NS_Composants::CL_map_Personnel::getNomPersonnel(void)
{
    throw gcnew System::NotImplementedException();
    return this->NomPersonnel;
}

String^ NS_Composants::CL_map_Personnel::getPrenomPersonnel(void)
{
    throw gcnew System::NotImplementedException();
    return this->PrenomPersonnel;
}

String^ NS_Composants::CL_map_Personnel::getAdressePersonnel(void)
{
    throw gcnew System::NotImplementedException();
    return this->AdressePersonnel;
}

String^ NS_Composants::CL_map_Personnel::getDateDembauche(void)
{
    throw gcnew System::NotImplementedException();
    return this->DateDembauche;
}
