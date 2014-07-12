// Program Money manipulates instances of class Money.

// From here through the line of asterisks should be in the
// specification file.

class Money
{
public:
    void  Initialize(long, long);
    long  DollarsAre() const;
    long  CentsAre() const;
    Money  Add(Money) const;
private:
    long  dollars;
    long  cents;
};

//**********************************************************

// From here through the next line of asterisks should be in
// the client file.
// The client file must include the specification file.

#include <iostream>
using namespace std;

int main ()
{
    Money  money1;
    Money  money2;
    Money  money3;
    money1.Initialize(10, 59);
    money2.Initialize(20, 70);
    money3 = money1.Add(money2);
    cout << "$"  << money3.DollarsAre() << "."
	 << money3.CentsAre()  << endl;
    return 0;
}

//********************************************************

// From here through the rest of the file should be in the
// implementation file.
// The implementation file must include the specification file.

void  Money::Initialize(long newDollars, long newCents)
// Post: dollars is set to newDollars; cents is set to
//       newCents.
{
    dollars = newDollars;
    cents = newCents;
}

//********************************************************


long  Money::DollarsAre() const
// Post: Class member dollars is returned.
{
    return dollars;
}

//********************************************************

long  Money::CentsAre() const
// Post: Class member cents is returned.
{
    return cents;
}

//********************************************************

Money Money::Add(Money  value) const
// Pre:  Both operands have been initialized.
// Post: value + self is returned.
{
    Money  result;
    result.cents = cents + value.cents;
    result.dollars = dollars + value.dollars;
    return result;
}
