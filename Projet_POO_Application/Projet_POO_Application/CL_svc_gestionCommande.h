#pragma once
#include "CL_CAD.h"
#include "CL_map_Commande.h"
#include "CL_map_TBCLIENT.h"
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
		DataTable^ DT;
	public:
		Svc_commande(void);
		DataTable^ TableCommande();
		DataSet^ listeCommande(String^);
		int ajouter(String^, String^, String^, String^, String^, String^, String^, String^, int);
		void modifier(int, String^, String^, String^, String^, String^, String^, String^, String^, int);
		void supprimer(int);
	};
}

