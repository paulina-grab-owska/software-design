#include "DB_connector.h"

DB_conn* DB_conn::instance = nullptr;

DB_conn* DB_conn::getInstance() {
	if (instance == nullptr)
	{
		instance = new DB_conn();
	}
	return instance;
}