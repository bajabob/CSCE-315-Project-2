all: main.o sql_relation.o sql_tuple.o sql_attribute.o sql_error_manager.o sql_storage_manager.o sql_query_builder.o sql_query_select.o sql_command.o json/jsoncpp.o 
	g++ -std=c++11 \
	sql_relation.o \
	sql_tuple.o \
	sql_attribute.o \
	sql_error_manager.o \
	sql_storage_manager.o \
	sql_query_builder.o \
	sql_query_select.o \
	sql_command.o \
	json/jsoncpp.o \
	main.o -o main

sql_relation.o: sql_relation.cpp
	g++ -std=c++11 -c sql_relation.cpp
	
sql_tuple.o: sql_tuple.cpp
	g++ -std=c++11 -c sql_tuple.cpp
		
sql_attribute.o: sql_attribute.cpp
	g++ -std=c++11 -c sql_attribute.cpp
	
sql_error_manager.o: sql_error_manager.cpp
	g++ -std=c++11 -c sql_error_manager.cpp	

sql_storage_manager.o: sql_storage_manager.cpp
	g++ -std=c++11 -c sql_storage_manager.cpp	

jsoncpp.o: json/jsoncpp.cpp	
	g++ -std=c++11 -c json/jsoncpp.cpp
	
sql_query_select.o: sql_query_select.cpp
	g++ -std=c++11 -c sql_query_select.cpp	
	
sql_query_builder.o: sql_query_builder.cpp
	g++ -std=c++11 -c sql_query_builder.cpp
	
sql_command.o: sql_command.cpp
	g++ -std=c++11 -c sql_command.cpp
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
clean:
	rm *.o json/*.o Lexer.c Lexer.h Parser.c Parser.h main
