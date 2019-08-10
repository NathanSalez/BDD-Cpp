//
// Created by nsalez on 07/04/19.
//

#ifndef DB_LIBSQL_H
#define DB_LIBSQL_H

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <memory>

/**
 * On définit un destructeur qui ne fait rien ( ~Driver() est une fonction virtuelle protégée)
 */
class DriverDeleter
{
public:
    void operator()(sql::Driver * d) const
    {

    }
};


class SQLRequester
{

protected :
    std::unique_ptr<sql::Driver, DriverDeleter > driver;
    std::unique_ptr<sql::Connection> con;

public:
    SQLRequester(std::string const& BDD_name, std::string const& user, std::string const& password);

    std::unique_ptr<sql::ResultSet> executeSimpleQuery(std::string const& request) const;

};

#endif //DB_LIBSQL_H

