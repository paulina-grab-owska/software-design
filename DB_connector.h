#pragma once
#include "jdbc/mysql_connection.h"
#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/exception.h"
#include "jdbc/cppconn/prepared_statement.h"

using namespace std;

class DB_conn
{
protected:
	static DB_conn* instance;

	DB_conn() {

		const string server = "tcp://127.0.0.1:3306";
		const string username = "user";
		const string password = "root";

		try
		{
			driver = get_driver_instance();
			con = driver->connect(server, username, password);
		}
		catch (sql::SQLException e)
		{
			cout << "Could not connect to server. Error message: " << e.what() << endl;
			system("pause");
			exit(1);
		}

		con->setSchema("db_test_software_design");
	}

public:

	sql::Driver* driver;
	sql::Connection* con;

	static DB_conn* getInstance();

};
