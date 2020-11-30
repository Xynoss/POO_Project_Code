#pragma once
using namespace System;
namespace NS_Composants{
	ref class CL_map_Personnel
	{
	private:
		int ID_personnel;
		int ID_Superieur;
		String^ PrenomPersonnel;
		String^ NomPersonnel;
		String^ AdressePersonnel;
		String^ DateDembauche;
	public:
		CL_map_Personnel(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setID(int);
		void setIDSup(int);
		void setPrenomPersonnel(String^);
		void setNomPersonnel(String^);
		void setAdressePersonnel(String^);
		void setDateDembauche(String^);
		int getID();
		int getIDSup();
		String^ getNomPersonnel(void);
		String^ getPrenomPersonnel(void);
		String^ getAdressePersonnel(void);
		String^ getDateDembauche(void);
	};
}


