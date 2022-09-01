// The keyword “const” indicates that the member function
// isFrequentFlyer is an accessor (only read class data)
#include<string>
#include<iostream>

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Passenger {
public:
 Passenger();                      // default constructor
 Passenger(const std::string& nm, MealType mp, const int& ffn = 0);
 Passenger(const Passenger& pass); // copy constructor
 bool isFrequentFlyer() const;
 void makeFrequentFlyer(const int& newFreqFlyerNo);
 void print();

private:
 std::string name;
 MealType mealPref;
 bool isFreqFlyer;
 int freqFlyerNo;
};

bool Passenger::isFrequentFlyer() const {
 return isFreqFlyer;
}

void Passenger::makeFrequentFlyer(const int& newFreqFlyerNo) {
 isFreqFlyer = true;
 freqFlyerNo = newFreqFlyerNo;
}
Passenger::Passenger() {
 name = "--NO NAME--";
 mealPref = NO_PREF; isFreqFlyer = false; freqFlyerNo = 0;
}

Passenger::Passenger(const std::string& nm, MealType mp, const int& ffn) {
 name = nm; mealPref = mp;
 isFreqFlyer = (ffn != 0); // true only if ffn given
 freqFlyerNo = ffn;
}

Passenger::Passenger(const Passenger& pass) {
 name = pass.name; mealPref = pass.mealPref;
 isFreqFlyer = pass.isFreqFlyer; freqFlyerNo = pass.freqFlyerNo;
}

void Passenger::print(){
    
    std::cout << "the passenger " << name << "\nmeal preference, frequent flyer status and number are below:\n"
        << mealPref << "\n" << isFreqFlyer << "\n" << freqFlyerNo << "\n" ;  

}

int main()
{
    // default constructor
    Passenger p1;

    // 2nd constructor
    Passenger p2("John Smith", VEGETARIAN, 293145);

    // 2nd constructor
    Passenger p3("Pocahontas", REGULAR);

    p3.print();

    // Copy constructor
    Passenger p4(p3);

    // Copy constructor
    Passenger p5 = p2;

    // default constructor
    Passenger* pp1 = new Passenger; 
    // pp1->print();

    // 2nd constructor
    Passenger* pp2 = new Passenger("JoeBlow", NO_PREF);

    // default constructor
    Passenger pa[20];

    return 0;
}