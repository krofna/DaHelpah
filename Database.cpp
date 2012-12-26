/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include <fstream>
#include <cstdarg>
#include <sstream>
#include <algorithm>
#include <cctype>

#include "Database.hpp"

Database WorldDatabase;

Database::Database() : Driver(nullptr)
{
}

Database::~Database()
{
}

void Database::Connect()
{
    std::ifstream CfgFile("DaHelpah.conf");

    if(!CfgFile)
        throw std::runtime_error("Cannot open DaHelpah.conf");

    std::string Data[4];
    
    CfgFile >> Data[0] >> Data[1] >> Data[2] >> Data[3];
    
    Driver = get_driver_instance();
    Connection.reset(Driver->connect(Data[0], Data[1], Data[2]));
    Connection->setSchema(Data[3]);
    Statement.reset(Connection->createStatement());
}

void Database::PExecute(const char* sql, ...)
{
    va_list ArgList;
    char CQuery[MAX_QUERY_LEN];

    va_start(ArgList, sql);
    vsnprintf(CQuery, sizeof(CQuery), sql, ArgList);
    va_end(ArgList);

    Execute(CQuery);
}

void Database::Execute(const char* sql)
{
    Statement->execute(sql);
}

QueryResult Database::Query(const char* sql)
{
    PStatement.reset(Connection->prepareStatement(sql));
    return QueryResult(PStatement->executeQuery());
}

QueryResult Database::PQuery(const char* sql, ...)
{
    va_list ArgList;
    char CQuery[MAX_QUERY_LEN];

    va_start(ArgList, sql);
    vsnprintf(CQuery, MAX_QUERY_LEN, sql, ArgList);
    va_end(ArgList);

    return Query(CQuery);
}
