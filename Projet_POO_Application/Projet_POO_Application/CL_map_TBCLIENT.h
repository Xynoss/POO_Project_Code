#pragma once

using namespace System;
namespace NS_Composants
{
	ref class CL_map_TBCLIENT
	{
	private:
		int idtb_client;
		String^ nom;
		String^ prenom;
		String^ DateNaissance;
		String^ AdresseClient;
		String^ Ville;
		String^ code_postal;
		String^ TypeAdresse;
	public:
		CL_map_TBCLIENT(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ INSERTA(String^ , String^);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setID(int);
		void setPrenom(String^);
		void setNom(String^);
		void setDateNaissance(String^);
		void setAdresse(String^);
		void setVille(String^);
		void setcodePostal(String^);
		void setTypeAdresse(String^);
		int getID(void);
		String^ getNom(void);
		String^ getPrenom(void);
		String^ getDateNaissance(void);
		String^ getAdresse(void);
		String^ getVille(void);
		String^ getcodePostal(void);
		String^ getTypeAdresse(void);
	};
}


