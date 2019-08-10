all : exe

exe : SQLRequesterTest.o SQLRequester.o
	g++ *.o testDB.cpp -o testcppsql.exe -lmysqlcppconn

SQLRequesterTest.o : SQLRequesterTest.cpp
	g++ -c SQLRequesterTest.cpp

SQLRequester.o : SQLRequester.cpp
	g++ -c SQLRequester.cpp

clean : 
	rm -rf *.o *.exe
