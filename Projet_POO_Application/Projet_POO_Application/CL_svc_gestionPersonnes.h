#pragma once

#include "CL_map_TBPERSONNE.h"
#include "CL_svc_General.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Svc
{
	ref class CL_svc_gestionPersonnes : public NS_Svc::CL_svc_General
	{
	private:
		NS_Composants::CL_map_TBPERSONNE^ personne;
	public:
		CL_svc_gestionPersonnes(void);
		DataSet^ listePersonnes(String^);
		DataTable^ TablePersonnes();
		int ajouter(String^, String^);
		void modifier(int, String^, String^);
		void supprimer(int);
	};
}