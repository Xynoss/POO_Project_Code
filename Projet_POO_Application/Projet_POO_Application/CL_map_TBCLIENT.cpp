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
		return "SELECT `client`.*, `region`.* , `appartient`.`Type_adresse` FROM `client` , `region`, `appartient` WHERE `region`.`ID_region` = `appartient`.`ID_region` AND `client`.`ID_Client` = `appartient`.`ID_Client` ORDER BY `client`.`ID_Client` ASC";
	}


	String^ CL_map_TBCLIENT::INSERT(void)
	{
		return "INSERT INTO client(`NomClient`, `PrenomClient`, `NaissanceClient`) VALUES('" + this->getNom() + "','" + this->getPrenom() + "','" + this->getDateNaissance() + "'); SELECT @@IDENTITY; "+
			"INSERT INTO region(`AdresseClient`,`Ville`,`code_postal`) VALUES('" + this->getAdresse() + "', '" + this->getVille() + "', '" + this->getcodePostal() + "'); SELECT @@IDENTITY; ";
	}

	String^ CL_map_TBCLIENT::INSERTA(String^ idclient, String^ idregion)
	{
		return "INSERT INTO appartient(`ID_client`,`ID_region`,`Type_adresse`) VALUES('" + idclient + "','" + idregion + "','" + this->getTypeAdresse() + "');";
	}

	String^ CL_map_TBCLIENT::UPDATE(void)
	{
		return "UPDATE client " + "SET NomClient = '" + this->getNom() + "', PrenomClient = '" + this->getPrenom() + "', NaissanceClient = '" + this->getDateNaissance() + "'  " + "WHERE(ID_Client = " + this->getID() + ");" +
			"UPDATE region SET  AdresseClient = '" + this->getAdresse() + "', Ville = '" + this->getVille() + "', code_postal = '" + this->getcodePostal() + "' WHERE region.ID_region = appartient.ID_region AND client.ID_Client = appartient.ID_Client; ";
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

	void CL_map_TBCLIENT::setAdresse(String^ A)
	{
		if (A != "") {
			this->AdresseClient = A;
		}
	}

	void CL_map_TBCLIENT::setVille(String^ V)
	{
		if (V != "") {
			this->Ville = V;
		}
	}

	void CL_map_TBCLIENT::setcodePostal(String^ cp)
	{
		if (cp != "") {
			this->code_postal = cp;
		}
	}

	void CL_map_TBCLIENT::setTypeAdresse(String^ tA)
	{
		if (tA != "") {
			this->TypeAdresse = tA;
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

	String^ CL_map_TBCLIENT::getAdresse(void)
	{
		return this->AdresseClient;
	}

	String^ CL_map_TBCLIENT::getVille(void)
	{
		return this->Ville;
	}

	String^ CL_map_TBCLIENT::getcodePostal(void)
	{
		return this->code_postal;
	}

	String^ CL_map_TBCLIENT::getTypeAdresse(void)
	{
		return this->TypeAdresse;
	}

}
