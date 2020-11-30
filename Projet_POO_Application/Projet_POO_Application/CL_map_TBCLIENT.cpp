#include "CL_map_TBCLIENT.h"
namespace NS_Composants {
	CL_map_TBCLIENT::CL_map_TBCLIENT(void)
	{
		this->idtb_client = -1;
		this->nom = "RIEN";
		this->prenom = "RIEN";
	}

	String^ CL_map_TBCLIENT::SELECT(void)
	{
		return "SELECT * " + "FROM projet_01.client;";
	}

	String^ CL_map_TBCLIENT::INSERT(void)
	{
		return "INSERT INTO client " + "(NomClient, PrenomClient,NaissanceClient) " + "VALUES('" + this->getNom() + "', '" + this->getPrenom() + "','" + this->getDateNaissance() + "');SELECT @@IDENTITY;";
	}

	String^ CL_map_TBCLIENT::UPDATE(void)
	{
		return "UPDATE client " + "SET NomClient = '" + this->getNom() + "', PrenomClient = '" + this->getPrenom() + "', NaissanceClient = '" + this->getDateNaissance() + "'  " + "WHERE(ID_Client = " + this->getID() + "); ";
	}

	String^ CL_map_TBCLIENT::DELETE(void)
	{
		return "DELETE FROM client " + "WHERE( idtb_client = " + this->getID() + ");";
	}

	void CL_map_TBCLIENT::setID(int id_TBCLIENT)
	{
		if (id_TBCLIENT > 0) {
			this->idtb_client = id_TBCLIENT;
		}
	}

	void CL_map_TBCLIENT::setPrenom(String^ prenom)
	{
		if (prenom != "")
		{
			this->prenom = prenom;
		}
	}

	void CL_map_TBCLIENT::setNom(String^ nom)
	{
		if (nom != "")
		{
			this->nom = nom;
		}
	}

	void CL_map_TBCLIENT::setDateNaissance(String^ date)
	{
		if (date != "") {
			this->DateNaissance = date;
		}
	}

	int CL_map_TBCLIENT::getID(void)
	{
		return this->idtb_client;
	}

	String^ CL_map_TBCLIENT::getNom(void)
	{
		return this->nom;
	}

	String^ CL_map_TBCLIENT::getPrenom(void)
	{
		return this->prenom;
	}

	String^ CL_map_TBCLIENT::getDateNaissance(void)
	{
		return this->DateNaissance;
	}

}
