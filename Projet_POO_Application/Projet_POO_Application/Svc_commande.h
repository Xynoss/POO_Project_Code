#pragma once
#include "CL_CAD.h"
#include "Commande.h"
#include "CL_map_TBCLIENT.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_Svc {
	ref class CL_Svc_commande
	{
	private:
		NS_Composants::CL_CAD^ cad;
		NS_Composants::CL_map_Commande^ Commande;
		NS_Composants::CL_map_TBCLIENT^ ClientClé;
		DataSet^ DS;
		DataTable^ DT;
	public:

		CL_Svc_commande(void);
		DataTable^ TableCommande();
		DataSet^ listeCommande(String^);
		String^ ajouter(String^, String^, String^, String^, String^, String^,int, int, int);
		void modifier(String^, String^, String^, String^, String^, String^,int , int, int);
		void supprimer(String^);
	};
}
