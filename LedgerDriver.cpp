#include <iostream>
#include "Ledger.h"
#include "Node.h"
#include "Transaction.h"

using namespace std;

int main () {
    Transaction t1 = Transaction("Albert", "Bob", 100);
    Transaction t2 = Transaction("James", "Alice", 50);
    Transaction t3 = Transaction("Dean", "Amy", 100);
    Transaction t4 = Transaction("Jack", "Herb", 100);
    Transaction t5 = Transaction("Bartholomew", "EXTERNAL", 900);

    Ledger myLedger;
    myLedger += t1;
    myLedger += t2;
    myLedger += Transaction("Albert", "Bob", 100);
    myLedger += Transaction("Albert", "Bob", 100);


//    cout << myLedger;

//
//	Transaction t1 = Transaction("alice", "EXTERNAL", 100);
//	Transaction t2 = Transaction("bob", "EXTERNAL", 10);
//	Transaction t3 = Transaction("fred", "EXTERNAL", 50);
//
//	// test adding money
//	myLedger += t1;
//	myLedger += t2;
//	myLedger += t3;
//
//	myLedger += Transaction("alice", "fred", 50);
//	myLedger += Transaction("bob", "fred", 100);
//	myLedger += Transaction("sam", "alice", 100);
//	myLedger += Transaction("alice", "fred", 30);
//	Transaction t4 = Transaction("fred", "bob", 2) ;
//	myLedger += t4;
//
//
//
//	myLedger -= t4;
//
	for (int i = 0; i < 18; i++) {
        myLedger += Transaction("fred", "carol", 1);
	}
    myLedger += t4;
    myLedger += t5;
//    myLedger -= t4;

    cout << endl;
    cout << myLedger;
    cout << endl;
//
//	cout << myLedger << endl;
//	cout << endl << endl;
	myLedger.Settle();
	cout << endl << endl;
	myLedger.InTheBlack();
	cout << endl << endl;
	myLedger.InTheRed();


    cout << "Before clear()" << endl;

	myLedger.Clear();

    cout << "Before printing empty ledger" << endl;
	cout << myLedger << endl;
    cout << "After printing empty ledger" << endl;
    return 0;

}
