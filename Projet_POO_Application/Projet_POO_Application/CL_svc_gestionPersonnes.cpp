#include "CL_svc_gestionPersonnes.h"
namespace NS_Svc
{
	CL_svc_gestionPersonnes::CL_svc_gestionPersonnes(void)
	{

		this->cad = gcnew NS_Composants::CL_CAD();
		this->personne = gcnew NS_Composants::CL_map_TBPERSONNE();
		this->ds = gcnew Data::DataSet();
		this->dt = gcnew Data::DataTable();
	}

	DataSet^ CL_svc_gestionPersonnes::listePersonnes(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->personne->SELECT(), dataTableName);
		return this->ds;
	}

	DataTable^ CL_svc_gestionPersonnes::TablePersonnes()
	{
		this->dt->Clear();
		this->dt = this->cad->getRows(this->personne->SELECT());
		return this->dt;
	}

	int CL_svc_gestionPersonnes::ajouter(String^ nom, String^ prenom)
	{
		int id_personne;
		this->personne->setNom(nom);
		this->personne->setPrenom(prenom);
		id_personne = this->cad->actionRowsID(this->personne->INSERT());
		return id_personne;
	}

	void CL_svc_gestionPersonnes::modifier(int id_personne, String^ nom, String^ prenom)
	{
		this->personne->setID(id_personne);
		this->personne->setNom(nom);
		this->personne->setPrenom(prenom);
		this->cad->actionRows(this->personne->UPDATE());
	}

	void CL_svc_gestionPersonnes::supprimer(int id_personne)
	{
		this->personne->setID(id_personne);
		this->cad->actionRows(this->personne->DELETE());
	}
}