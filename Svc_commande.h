#pragma once
#include "CL_CAD.h"
#include "Commande.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_Svc {
	ref class Svc_commande
	{
	private:
		NS_Composants::CL_CAD^ cad;
		NS_Composants::Commande^ Commande;
		DataSet^ DS;
		DataTable^ DT;
	public:

		Svc_commande(void);
		DataTable^ TableCommande();
		DataSet^ listeCommande(String^);
		int ajouter(int, int, String^, String^, String^, String^, String^,int, int, int, int,int);
		void modifier(int, int, String^, String^, String^, String^, String^, int, int, int, int, int);
		void supprimer(int);
	};
}

