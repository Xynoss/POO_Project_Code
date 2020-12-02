#pragma once

#include "CL_map_TBCLIENT.h"
#include "CL_CAD.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Svc
{
	ref class CL_svc_gestionClient
	{
	private:
		NS_Composants::CL_map_TBCLIENT^ client;
		NS_Composants::CL_CAD^ cad;
		DataSet^ ds;
		DataTable^ dt;
	public:
		CL_svc_gestionClient(void);
		DataSet^ listeClient(String^);
		DataTable^ TableClient();
		int ajouter(String^, String^, String^, String^, String^, String^, String^);
		void modifier(int, String^, String^, String^, String^, String^, String^, String^);
		void supprimer(int);
	};
}