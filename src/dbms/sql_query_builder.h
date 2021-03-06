
#ifndef SRC_DBMS_SQL_QUERY_BUILDER_H_
#define SRC_DBMS_SQL_QUERY_BUILDER_H_

#include <string>
#include <vector>
#include "sql_relation.h"
#include "sql_query_select.h"
#include "sql_attribute.h"

using namespace std;

/**
 * The Query Builder is the entry point for performing queries on the
 *  database. It takes care of selecting, updating, deleting, etc.
 * When the query builder is first created it is given a reference to
 *  the relation (table) it is currently operating on. BY DEFAULT the query builder
 *  at that moment is ready to run any base command. For instance a
 *  "run_select" will run a default "SELECT * FROM table". It isn't
 *  until an "add_select" is called that you can change what attributes
 *  (columns) are selected.
 *
 *  Typical work flow
 *  - Create a new query builder for a specific table
 *  - call various "add_..." functions like "add_select" to refine search
 *  - call "run_..." on the query to run, like "run_select"
 *  - query builder performs operations on table and saves the
 *     new table if needed
 */
 
class SQLQueryBuilder{

public:

	SQLQueryBuilder(SQLRelation &rel,SQLQuerySelect &sel);
	

	/**
	 * Add an altered select to this query
	 */
	void add_select();
	void add_where();
	bool is_duplicate(where_obj& data ,vector<where_obj> &wher);	
	/**
	 * Run the now built query if unaltered flag is true otherwise run altered
	 */
	SQLRelation run_select(bool unaltered = true);
	
private:
	
	SQLRelation relation;
	vector<string> query_attr;
	vector<string> attributes;
	vector<where_obj> where;
	SQLQuerySelect select;
	
};



#endif
