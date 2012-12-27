/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#ifndef DATABASE_H
#define DATABASE_H

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <memory>

#define MAX_QUERY_LEN 2048

typedef std::unique_ptr<sql::ResultSet> QueryResult;
typedef std::unique_ptr<sql::Connection> ConnectionPtr;
typedef std::unique_ptr<sql::Statement> StatementPtr;
typedef std::unique_ptr<sql::PreparedStatement> PStatementPtr;

class Database
{
    public:
        Database();
        ~Database();

        void Connect();

        QueryResult Query(const char* sql);
        QueryResult PQuery(const char* sql, ...);
        void Execute(const char* sql);
        void PExecute(const char* sql, ...);

    private:
        sql::Driver* Driver;
        ConnectionPtr Connection;
        StatementPtr Statement;
        PStatementPtr PStatement;
};

#endif
