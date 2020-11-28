#include "CL_map_TBPERSONNE.h"

namespace NS_Composants
{
	CL_map_TBPERSONNE::CL_map_TBPERSONNE(void)
	{
		this->id_personne = -1;
		this->nom = "RIEN";
		this->prenom = "RIEN";
	}

	String^ CL_map_TBPERSONNE::SELECT(void)
	{
		return "SELECT id_personne, nom, prenom " + "FROM TB_PERSONNE;";
	}

	String^ CL_map_TBPERSONNE::INSERT(void)
	{
		return "INSERT INTO TB_PERSONNE " + "(nom, prenom) " + "VALUES('" + this->getNom() + "', '" + this->getPrenom() + "');SELECT @@IDENTITY;";
	}

	String^ CL_map_TBPERSONNE::UPDATE(void)
	{
		return "UPDATE TB_PERSONNE " + "SET nom = '" + this->getNom() + "', prenom = '" + this->getPrenom() + "' " + "WHERE(id_personne = " + this->getId() + ");";
	}

	String^ CL_map_TBPERSONNE::DELETE(void)
	{
		return "DELETE FROM TB_PERSONNE " + "WHERE(id_personne = " + this->getId() + ");";
	}

	void CL_map_TBPERSONNE::setID(int id_personne)
	{
		if (id_personne > 0)
		{
			this->id_personne = id_personne;
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
		return this->id_personne;
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