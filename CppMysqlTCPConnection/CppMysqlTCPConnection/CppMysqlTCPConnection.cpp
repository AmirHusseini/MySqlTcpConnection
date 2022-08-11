/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include the headers */
#include <mysql/jdbc.h>

#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>

#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

using namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://yourservername(for example:127.0.0.1):3306";
const string username = "servername(root)";
const string password = "password";

int main(void)
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* add;
	sql::PreparedStatement* read;
	sql::PreparedStatement* delet;
	sql::PreparedStatement* updato;
	sql::ResultSet* result;

	try
	{
		// Connect to the server
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	/* Connect to the MySQL uppgift database */
	con->setSchema("uppgift");
	cout << "Connected to the Mysql database" << endl;

	// To create table and some values inside the table

	/*stmt = con->createStatement();
	stmt->execute("DROP TABLE IF EXISTS bilar");
	cout << "Finished dropping table (if existed)" << endl;
	stmt->execute("CREATE TABLE bilar (id serial PRIMARY KEY, bil VARCHAR(50), bilmarke VARCHAR(50), armodell INTEGER, pris INTEGER);");
	cout << "Finished creating table" << endl;
	delete stmt;*/


	int choice;
	string bilc, bilmarkec;
	int armodellc, prisc;
	do
	{
		//options to choose
		cout << "Pleas choose your option!" << endl;
		cout << "1. Add new data" << endl;
		cout << "2. Read the data" << endl;
		cout << "3. Delete a car" << endl;
		cout << "4. Update information (Price)" << endl;
		cout << "0. Exit" << endl;
		cout << "Choose: ";
		cin >> choice;
		system("CLS");
		if (choice == 1)
		{
			//Add to the database using INSERT
			cout << "Which car: ";
			cin >> bilc;
			cout << "Which modell: ";
			cin >> bilmarkec;
			cout << "Which year: ";
			cin >> armodellc;
			cout << "What is the price: ";
			cin >> prisc;
			add = con->prepareStatement("INSERT INTO bilar(bil, bilmarke, armodell, pris) VALUES(?,?,?,?)");
			add->setString(1, bilc);
			add->setString(2, bilmarkec);
			add->setInt(3, armodellc);
			add->setInt(4, prisc);
			add->execute();
			cout << "Information has been saved." << endl;

			//delete pstmt;
			//delete con;
			system("pause");
			system("CLS");
		}
		if (choice == 2)
		{
			// Read the database using SELECT  
			read = con->prepareStatement("SELECT * FROM bilar;");
			result = read->executeQuery();

			while (result->next())
				printf("Reading from table=(%d, %s,, %s, %d, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getInt(4), result->getInt(5));

			//delete result;
			//delete read;
			//delete con;
			system("pause");
			system("CLS");
		}
		if (choice == 3)
		{
			//Delete from database using DELETE
			string deletedbil;
			cout << "Which car do you want to remove: ";
			cin >> deletedbil;

			//delete
			delet = con->prepareStatement("DELETE FROM bilar WHERE bil = ?");
			delet->setString(1, deletedbil);
			result = delet->executeQuery();
			printf("The car is removed from database!\n");

			system("pause");
			system("CLS");
		}
		if (choice == 4)
		{
			//Update the database
			string updatobil;
			int nypris;
			cout << "Which car do you want to change price for: ";
			cin >> updatobil;
			cout << "What is the new price: ";
			cin >> nypris;

			//update
			updato = con->prepareStatement("UPDATE bilar SET pris = ? WHERE bil = ?");
			updato->setInt(1, nypris);
			updato->setString(2, updatobil);
			updato->executeQuery();
			printf("The new price of the car is now updated!\n");

			system("pause");
			system("CLS");
		}
		else
		{
			cout << "Wrong choice bro!\n" << endl;
		}

	} while (choice != 0);



	system("pause");
	return 0;
}