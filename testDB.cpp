#include <iostream>
#include "SQLRequesterTest.h"

const std::string pseudo = "root";
const std::string mdp = "inserezVotreMdp";

void testInsert()
{
    User u {4,"Clement","8cm",false};
    SQLRequesterTest r("mon_site",pseudo,mdp);
    std::cout << "Nombre de lignes modifiées : " << r.insertUser(u) << std::endl;
}


void testSelect()
{
    // Etape 1 : Récupérer le driver nécessaire à l'utilisation de la BDD
    // Etape 2 : Connexion à un SGBD (ici mySQL)
    // Etape 3 : Connexion à la BDD à utiliser
    // Etape 4 : création d'un objet qui permet d'effectuer des requêtes sur la BDD
    SQLRequester r("mon_site",pseudo,mdp);


    // Etape 5 : exécution de la requête à effectuer
    std::unique_ptr<sql::ResultSet> res = r.executeSimpleQuery("SELECT * FROM users");

    // Etape 6 : exploitation du résultat de la requête
    while (res->next()) {
        std::cout
                << res->getInt("id_user")
                << " - "
                << res->getString("pseudo")
                << " - "
                << res->getString("mdp")
                << " - "
                << res->getInt("admin")
                << std::endl;
    }
}

void testInjectionSQL1()
{
    std::cout << "Injection SQL avec requête préparée" << std::endl;
    SQLRequesterTest r("mon_site","root",mdp);

    std::unique_ptr<sql::ResultSet> res = r.testPreparedStatement();
    while (res->next()) {
        std::cout
                << res->getInt("id_user")
                << " - "
                << res->getString("pseudo")
                << " - "
                << res->getString("mdp")
                << " - "
                << res->getInt("admin")
                << std::endl;
    }

}


void testInjectionSQL2()
{
    std::cout << "Injection SQL avec requête simple" << std::endl;
    SQLRequesterTest r("mon_site","root",mdp);

    std::unique_ptr<sql::ResultSet> res = r.testStatement();
    while (res->next()) {
        std::cout
                << res->getInt("id_user")
                << " - "
                << res->getString("pseudo")
                << " - "
                << res->getString("mdp")
                << " - "
                << res->getInt("admin")
                << std::endl;
    }
}

int main()
{
    std::cout << "Test d'utilisation d'une base de données" << std::endl;

    try {
        testSelect();
        //testInsert();
        //testInjectionSQL1();
        //testInjectionSQL2();
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "# ERR: " << e.what();
        std::cerr << " (code erreur MySQL: " << e.getErrorCode();
        std::cerr << ", EtatSQL: " << e.getSQLState() << " )" << std::endl;
    }

    return 0;
}
