#include "sql_tuple.h"

SQLTuple::SQLTuple( Json::Value node, vector<SQLAttribute> &attributes,
		SQLErrorManager &em ) {
	vector<string> j_keys = node.getMemberNames();
	for ( int i = 0; i < j_keys.size(); ++i ) {

		for ( int j = 0; j < attributes.size(); ++j ) {
			SQLAttribute &at = attributes[j];
			if ( at.get_name() == j_keys[i] ) {
				keys.push_back( j_keys[i] );
				this->data.insert(
						pair<string, SQLTypeData>( j_keys[i],
								SQLTypeData( at, em,
										node[j_keys[i]].asString() ) ) );
				break;
			}
		}
	}
}

void SQLTuple::add_attribute( SQLAttribute &attr, string data,
		SQLErrorManager &em ) {
	this->data.insert(
			pair<string, SQLTypeData>( attr.get_name(),
					SQLTypeData( attr, em, data ) ) );
	this->keys.push_back( attr.get_name() );
}

bool SQLTuple::has_matching_data( string key, string data ) {
	SQLTypeData s = this->data.find( key )->second;
	return data == s.get_data();
}

Json::Value SQLTuple::to_json() {
	Json::Value node;
	for ( auto &col : this->keys ) {
		node[col] = this->data.find( col )->second.get_data();
	}
	return node;
}

string SQLTuple::get_data(string attr){
	map<string, SQLTypeData>::iterator it = data.find(attr);
	if(it==data.end()){ cout<< "\ndata not_found";}
	return it->second.get_data();
}

void SQLTuple::update_data(SQLAttribute &attr, SQLErrorManager &em, string new_data){
	map<string, SQLTypeData>::iterator it = data.find(attr.get_name());
	it->second.set_data(new_data);					//update date with new value
}


void SQLTuple::delete_data(string attr){ 
	data.erase(data.find(attr));
	keys.erase(find(keys.begin(), keys.end(), attr));
}

void SQLTuple::rename_attr(string attr, string new_attr){
	vector<string>::iterator it = find(keys.begin(), keys.end(), attr);
	if(it == keys.end() ){
		cout<<"\nIn sql_tuple can not find this attribute for rename";
		return;
	} else{
		keys.erase(it);
	}
	keys.push_back(new_attr);
	map<string, SQLTypeData>::iterator it_2 = data.find(attr);
	SQLTypeData typedata = it_2->second;
	data.erase(it_2);
	data.insert(pair<string, SQLTypeData>(new_attr, typedata));
}

vector<string> SQLTuple::get_keys() const {
	vector<string> copy(this->keys);

	// need to sort as keys may be out of order in relation
	//  to others accross the table
	sort(copy.begin(), copy.end());

	return copy;
}




