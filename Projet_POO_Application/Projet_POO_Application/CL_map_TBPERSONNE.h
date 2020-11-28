#pragma once

using namespace System;
namespace NS_Composants
{
	ref class CL_map_TBPERSONNE
	{
	private:int idTB_personne;
		   String^ nom;
		   String^ prenom;
	public:CL_map_TBPERSONNE(void);
		  String^ SELECT(void);
		  String^ INSERT(void);
		  String^ UPDATE(void);
		  String^ DELETE(void);
		  void setID(int);
		  void setPrenom(String^);
		  void setNom(String^);
		  int getId(void);
		  String^ getNom(void);
		  String^ getPrenom(void);
	};
}