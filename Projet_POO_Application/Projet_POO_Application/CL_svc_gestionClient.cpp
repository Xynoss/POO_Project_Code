#include "CL_svc_gestionClient.h"
namespace NS_Svc
{
	CL_svc_gestionClient::CL_svc_gestionClient(void)
	{

		this->cad = gcnew NS_Composants::CL_CAD();
		this->client = gcnew NS_Composants::CL_map_TBCLIENT();
		this->ds = gcnew Data::DataSet();
		this->dt = gcnew Data::DataTable();
	}

	DataSet^ CL_svc_gestionClient::listeClient(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->client->SELECT(), dataTableName);
		return this->ds;
	}

	DataTable^ CL_svc_gestionClient::TableClient()
	{
		this->dt->Clear();
		this->dt = this->cad->getRows(this->client->SELECT());
		return this->dt;
	}

	int CL_svc_gestionClient::ajouter(String^ nom, String^ prenom, String^ date, String^ adresse, String^ ville, String^ codepostal, String^ typeadresse)
	{
		int id_client;
		int id_region;
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		this->client->setDateNaissance(date);
		this->client->setAdresse(adresse);
		this->client->setVille(ville);
		this->client->setcodePostal(codepostal);
		this->client->setTypeAdresse(typeadresse);
		id_client = this->cad->actionRowsID(this->client->INSERTCLIENT());
		id_region = this->cad->actionRowsID(this->client->INSERTREGION());
		this->cad->actionRowsID(this->client->INSERTAPPARTIENT(id_client,id_region));
		return id_client;
	}

	void CL_svc_gestionClient::modifier(int id_client, String^ nom, String^ prenom, String^ date, String^ adresse, String^ ville, String^ codepostal, String^ typeadresse)
	{
		this->client->setID(id_client);
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		this->client->setDateNaissance(date);
		this->client->setAdresse(adresse);
		this->client->setVille(ville);
		this->client->setcodePostal(codepostal);
		this->client->setTypeAdresse(typeadresse);
		this->cad->actionRows(this->client->UPDATE());
		//this->cad->actionRows(this->client->UPDATEA(id_client, ));
	}

	void CL_svc_gestionClient::supprimer(int id_client)
	{
		this->client->setID(id_client);
		this->cad->actionRows(this->client->DELETE());
	}
}