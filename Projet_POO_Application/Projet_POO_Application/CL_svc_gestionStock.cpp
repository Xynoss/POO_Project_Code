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



DataTable^ NS_Svc::CL_svc_gestionStock::TableStock()
{
    this->DT->Clear();
    this->DT = this->cad->getRows(this->Stock->SELECT());
    return this->DT;
}


int NS_Svc::CL_svc_gestionStock::ajouter(String^ NomArticle, String^ NatureArticle, String^ RefArticle, String^ CouleurArticle, int ID_Article, int NombreStock)
{
    int ID_Article;
    this->Stock->setNomArticle(nom);
    this->Stock->setNatureArticle(nature);
    this->Stock->setRefArticle(reference);
    this->Stock->setCouleurArticle(couleur);
    this->Stock->setNombreStock(nombre);
    ID_Article= this->cad->actionRowsID(this->Stock->INSERT());
    return ID_Article;
}


void NS_Svc::CL_svc_gestionStock::modifier(int ID_Article, int NombreStock, String^ NomArticle, String^ NatureArticle, String^ RefArticle, String^ CouleurArticle)
{
    this->Stock->setNomArticle(nom);
    this->Stock->setNatureArticle(nature);
    this->Stock->setRefArticle(reference);
    this->Stock->setCouleurArticle(couleur);
    this->Stock->setIDArticle(ID_Article);
    this->Stock->setNombreStock(nombre);
    this->cad->actionRows(this->Stock->UPDATE());
}


void NS_Svc::CL_svc_gestionStock::supprimer(int ID_Article)
{
    this->Stock->setIDArticle(ID_Article);
    this->cad->actionRows(this->Stock->DELETE());
}
