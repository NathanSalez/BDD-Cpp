//
// Created by nsalez on 12/04/19.
//

#include "SQLRequesterTest.h"


SQLRequesterTest::SQLRequesterTest(std::string const& BDD_name, std::string const& user, std::string const& password)
        : SQLRequester(BDD_name,user,password)
{

}


int SQLRequesterTest::insertUser( const User& u) const
{
    sql::SQLString requete = "INSERT INTO `users` (`id_user`, `pseudo`, `mdp`, `admin`) VALUES (?, ?, ?, ?)";
    std::unique_ptr<sql::PreparedStatement> pStmt ( con->prepareStatement(requete) );
    pStmt->setInt(1,u.id); // les index commencent à 1
    pStmt->setString(2,u.pseudo);
    pStmt->setString(3,u.password);
    pStmt->setBoolean(4,u.admin);
    return  pStmt->executeUpdate() ;
}


std::unique_ptr<sql::ResultSet> SQLRequesterTest::testPreparedStatement() const
{
    sql::SQLString requete = "SELECT * FROM users WHERE pseudo = ? AND mdp = ?";
    std::unique_ptr<sql::PreparedStatement> pStmt ( con->prepareStatement(requete) );
    pStmt->setString(1,"Naysson' OR 1=1 OR (''='");
    pStmt->setString(2,"test') or ''='");
    return std::unique_ptr<sql::ResultSet>(pStmt->executeQuery());
}


std::unique_ptr<sql::ResultSet> SQLRequesterTest::testStatement() const
{
    std::ostringstream requete;
    requete << "SELECT * FROM users WHERE pseudo = '";
    requete << "Naysson' OR 1=1 OR (''='"; // pseudo
    requete << "' AND mdp = '";
    requete << "test') or ''='"; // mdp
    requete << "'";
    std::string requeteInfectee = requete.str();
    std::unique_ptr<sql::Statement> stmt ( con->createStatement() );
    return std::unique_ptr<sql::ResultSet>(stmt->executeQuery(requeteInfectee));
}