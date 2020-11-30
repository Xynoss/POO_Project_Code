#include "CL_svc_gestionPersonnel.h"

NS_Svc::CL_svc_gestionPersonnel::CL_svc_gestionPersonnel(void)
{
    throw gcnew System::NotImplementedException();
    this->cad = gcnew NS_Composants::CL_CAD();
    this->Personnel = gcnew NS_Composants::CL_map_Personnel();
    this->DS = gcnew Data::DataSet();
    this->DT = gcnew Data::DataTable();
}

DataTable^ NS_Svc::CL_svc_gestionPersonnel::TablePersonnel()
{
    throw gcnew System::NotImplementedException();
    this->DT->Clear();
    this->DT = this->cad->getRows(this->Personnel->SELECT());
    return this->DT;
}

int NS_Svc::CL_svc_gestionPersonnel::ajouter(int IDSup, String^ nom, String^ prenom, String^ adresse, String^ date)
{
    int ID_personnel;
    //voir pour la clé étrangère
    this->Personnel->setNomPersonnel(nom);
    this->Personnel->setPrenomPersonnel(prenom);
    this->Personnel->setAdressePersonnel(adresse);
    this->Personnel->setDateDembauche(date);
    ID_personnel = this->cad->actionRowsID(this->Personnel->INSERT());
    return ID_personnel;

}

void NS_Svc::CL_svc_gestionPersonnel::modifier(int id_personnel, int idsup, String^ nom, String^ prenom, String^ adresse, String^ date)
{
    throw gcnew System::NotImplementedException();
    this->Personnel->setID(id_personnel);
    this->Personnel->setIDSup(idsup);
    this->Personnel->setNomPersonnel(nom);
    this->Personnel->setPrenomPersonnel(prenom);
    this->Personnel->setAdressePersonnel(adresse);
    this->Personnel->setDateDembauche(date);
    this->cad->actionRows(this->Personnel->UPDATE());

}

void NS_Svc::CL_svc_gestionPersonnel::supprimer(int id_personnel)
{
    this->Personnel->setID(id_personnel);
    this->cad->actionRows(this->Personnel->DELETE());
}
