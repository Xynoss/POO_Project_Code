#pragma once
#include <iostream>
#include <string>
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;
namespace NS_Composants
{
	ref class CL_CAD
	{
	private:
		String^ cnx;
		String^ rq_sql;
		MySqlConnection^ CNX;
		MySqlCommand^ CMD;
		MySqlDataAdapter^ DA;
		DataSet^ DS;
		void setSQL(String^);
	public:
		CL_CAD(void);
		int actionRowsID(String^);
		void actionRows(String^);
		DataSet^ getRows(String^, String^);
	};

}


