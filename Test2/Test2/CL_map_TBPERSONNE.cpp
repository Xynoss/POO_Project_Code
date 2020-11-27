#include "CL_map_TBPERSONNE.h"
namespace NS_Composants
{

	CL_map_TBPERSONNE::CL_map_TBPERSONNE(void)
	{
		this->idTB_Personne = -1;
		this->nom = "RIEN";
		this->prenom = "RIEN";
	}
	String^ CL_map_TBPERSONNE::SELECT(void)
	{
		return "SELECT idTB_Personne, nom, prenom " + "FROM TB_PERSONNE;";
	}
	String^ CL_map_TBPERSONNE::INSERT(void)
	{
		return "INSERT INTO TB_PERSONNE " + "(nom, prenom) " + "VALUES('" + this->getNom() + "', '" + this->getPrenom() + "');SELECT @@IDENTITY;";
	}
	String^ CL_map_TBPERSONNE::UPDATE(void)
	{
		return "UPDATE TB_PERSONNE " + "SET nom = '" + this->getNom() + "', prenom = '" + this->getPrenom() + "' " + "WHERE(idTB_Personne = " + this->getId() + ");";
	}
	String^ CL_map_TBPERSONNE::DELETE(void)
	{
		return "DELETE FROM TB_PERSONNE " + "WHERE(idTB_Personne = " + this->getId() + ");";
	}
	void CL_map_TBPERSONNE::setID(int idTB_Personne)
	{
		if (idTB_Personne > 0)
		{
			this->idTB_Personne = idTB_Personne;
		}
	}

	void CL_map_TBPERSONNE::setPrenom(String^ prenom)
	{
		if (prenom != "")
		{
			this->prenom = prenom;
		}
	}

	void CL_map_TBPERSONNE::setNom(String^ nom)
	{
		if (nom != "")
		{
			this->nom = nom;
		}
	}

	int CL_map_TBPERSONNE::getId(void)
	{
		return this->idTB_Personne;
	}

	String^ CL_map_TBPERSONNE::getNom(void)
	{
		return this->nom;
	}

	String^ CL_map_TBPERSONNE::getPrenom(void)
	{
		return this->prenom;
	}
}