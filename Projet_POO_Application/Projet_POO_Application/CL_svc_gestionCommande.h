#pragma once
#include "CL_CAD.h"
#include "CL_map_Commande.h"
#include "CL_map__Stock.h"
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_Svc {
	ref class Svc_commande
	{
	private:
		NS_Composants::CL_CAD^ cad;
		NS_Composants::CL_map_Commande^ Commande;
		DataSet^ DS;
		DataSet^ MontantHTDebut;
		DataSet^ PrixUni;
		DataTable^ DT;
	public:
		Svc_commande(void);
		DataTable^ TableCommande();
		DataSet^ listeCommande(String^);
		int ajouter(String^, String^, String^, String^, String^, String^, String^, int, String^, String^, String^, String^, String^, String^, int);
		double ajouterArticle(String^, String^, String^);
		int update(int,double, String^);
		void modifier(int, String^, String^, String^, String^, String^, String^, String^, int, String^, String^, String^, String^, String^, String^, int);
		void modifierSPrix(int, String^, String^, String^, String^, String^, String^, int, String^, String^, String^, String^, int);
		void modifierArticle(int, String^, String^, String^, String^, String^, String^, String^, int, String^, String^ , String^, String^, String^, String^, double);
		void supprimer(int);
		void supprimerArticle(int, int);
		
	};
}