//
// Created by nsalez on 12/04/19.
//

#ifndef DB_SQLREQUESTERTEST_H
#define DB_SQLREQUESTERTEST_H

#include "SQLRequester.h"
#include <sstream>

struct User
{
    unsigned int id;
    std::string pseudo;
    std::string password;
    bool admin;
};

class SQLRequesterTest : public SQLRequester {

public:
    SQLRequesterTest(std::string const& BDD_name, std::string const& user, std::string const& password);
    int insertUser( const User& u) const;
    std::unique_ptr<sql::ResultSet> testPreparedStatement() const;
    std::unique_ptr<sql::ResultSet> testStatement() const;
};


#endif //DB_SQLREQUESTERTEST_H
