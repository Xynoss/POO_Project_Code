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
	public:
		CL_map_TBCLIENT(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setID(int);
		void setPrenom(String^);
		void setNom(String^);
		void setDateNaissance(String^);
		int getID(void);
		String^ getNom(void);
		String^ getPrenom(void);
		String^ getDateNaissance(void);
	};
}


