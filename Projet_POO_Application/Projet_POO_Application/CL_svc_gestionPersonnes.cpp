#include "CL_svc_gestionPersonnes.h"
namespace NS_Svc
{
	CL_svc_gestionPersonnes::CL_svc_gestionPersonnes(void)
	{

		this->cad = gcnew NS_Composants::CL_CAD();
		this->client = gcnew NS_Composants::CL_map_TBCLIENT();
		this->ds = gcnew Data::DataSet();
		this->dt = gcnew Data::DataTable();
	}

	DataSet^ CL_svc_gestionPersonnes::listeClient(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->client->SELECT(), dataTableName);
		return this->ds;
	}

	DataTable^ CL_svc_gestionPersonnes::TableClient()
	{
		this->dt->Clear();
		this->dt = this->cad->getRows(this->client->SELECT());
		return this->dt;
	}

	int CL_svc_gestionPersonnes::ajouter(String^ nom, String^ prenom, String^ date)
	{
		int id_client;
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		this->client->setDateNaissance(date);
		id_client = this->cad->actionRowsID(this->client->INSERT());
		return id_client;
	}

	void CL_svc_gestionPersonnes::modifier(int id_client, String^ nom, String^ prenom, String^ date)
	{
		this->client->setID(id_client);
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		this->client->setDateNaissance(date);
		this->cad->actionRows(this->client->UPDATE());
	}

	void CL_svc_gestionPersonnes::supprimer(int id_client)
	{
		this->client->setID(id_client);
		this->cad->actionRows(this->client->DELETE());
	}
}