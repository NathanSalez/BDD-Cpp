//
// Created by nsalez on 07/04/19.
//
#include "SQLRequester.h"

SQLRequester::SQLRequester(std::string const& BDD_name, std::string const& user, std::string const& password)
        : driver(get_driver_instance(), DriverDeleter()), con( driver->connect("tcp://127.0.0.1:3306", user, password) )
{
    con->setSchema(BDD_name);
}


std::unique_ptr<sql::ResultSet> SQLRequester::executeSimpleQuery(std::string const& request) const
{
    std::unique_ptr<sql::Statement> stmt ( con->createStatement() );
    std::unique_ptr<sql::ResultSet> res( stmt->executeQuery(request) );
    return res;
}
