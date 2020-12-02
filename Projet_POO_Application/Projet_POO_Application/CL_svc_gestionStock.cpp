#include "CL_svc_gestionStock.h"

NS_Svc::CL_svc_gestionStock::CL_svc_gestionStock(void)
{
    this->cad = gcnew NS_Composants::CL_CAD();
    this->Stock = gcnew NS_Composants::CL_map_Stock();
    this->DS = gcnew Data::DataSet();
    this->DT = gcnew Data::DataTable();
}

DataSet^ NS_Svc::CL_svc_gestionStock::ListeArticle(String^ dataTableName)
{
    this->DS->Clear();
    this->DS = this->cad->getRows(this->Stock->SELECT(), dataTableName);
    return this->DS;
}



DataTable^ NS_Svc::CL_svc_gestionStock::TableArticle()
{
    this->DT->Clear();
    this->DT = this->cad->getRows(this->Stock->SELECT());
    return this->DT;
}

DataTable^ NS_Svc::CL_svc_gestionStock::TableStock()
{
    this->DT->Clear();
    this->DT = this->cad->getRows(this->Stock->SELECT_STOCK());
    return this->DT;
}

int NS_Svc::CL_svc_gestionStock::ajouter(String^ NomArticle, String^ NatureArticle, String^ ReferenceArticle, int PrixUnitaire, int TVA)
{
    int ID_personnel;
    this->Stock->setNomArticle(nom);
    this->Stock->setNatureArticle(nature);
    this->Stock->setReferenceArticle(reference);
    this->Stock->setNomPersonnel(nom);
    this->Stock->setTVA(TVA);
    this->Stock->setPrixUnitaire(PrixUnitaire);
    ID_personnel = this->cad->actionRowsID(this->Stock->INSERT());
    return ID_personnel;
}


void NS_Svc::CL_svc_gestionStock::modifier(int PrixUnitaire, int TVA, String^ NomArticle, String^ NatureArticle, String^ ReferenceArticle)
{
    this->Stock->setNomArticle(nom);
    this->Stock->setNatureArticle(nature);
    this->Stock->setReferenceArticle(reference);
    this->Stock->setTVA(TVA);
    this->Stock->setPrixUnitaire(PrixUnitaire);
    this->cad->actionRows(this->Stock->UPDATE());
}

void NS_Svc::CL_svc_gestionStock::supprimer(String^)
{
    throw gcnew System::NotImplementedException();
}

void NS_Svc::CL_svc_gestionStock::supprimer(String^ ReferenceArticle)
{
    this->Stock->setReferenceArticle(Reference);
    this->cad->actionRows(this->Stock->DELETE());
