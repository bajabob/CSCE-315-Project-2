
#ifndef SRC_DBMS_SQL_COMMAND_H_
#define SRC_DBMS_SQL_COMMAND_H_

#include <string>
#include <vector>
#include "sql_relation.h"
#include "sql_query_select.h"
#include "sql_query_builder.h"
#include "sql_attribute.h"
#include "sql_tuple.h"
#include "sql_storage_manager.h"

class SQLCommand{

public:
	SQLCommand();

	SQLRelation select(string name, vector<string> ops);
	void delete_row(string name, vector<string> constraint);
	void update_data(string name, vector<string> constraint,vector<where_obj> updata);

	SQLRelation create_table(string name, vector<SQLAttribute> attrs);
	void insert_row(SQLRelation &relation, vector<string> tuples);
	void assign_table(string name, SQLRelation assign_from);
	void open_table(string name);
	void save_table();//write table to db
	void show_table(string name);
	void close_table();
	

	
	

private:
	SQLRelation *table;
	SQLErrorManager error_manager;
};




#endif