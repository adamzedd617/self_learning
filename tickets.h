class tickets{
  protected:
    string firstname, lastname, seatType;
    int numOfTickets;
    float price,total;

    virtual void calculateTotal(void){
      total = price*numOfTickets;
    }
 
 
  public:
    tickets(string FN, string LN, int NOT){
      numOfTickets = NOT;
      firstname = FN;
      lastname = LN;
    }

    void displayOrder(){
    calculateTotal();
    cout << endl << endl;
    cout << firstname << ", " << lastname << ": " << numOfTickets << endl;
    cout << "Seats: " << seatType << endl;
    cout << "Total Price is " << price << endl;
    }

};

//inherit class PREMIUM : TICKETS
class premium : public tickets {  
  private:
    void calculateTotal(void){
      price = numOfTickets * 150.0 * 115/100;
    }
  public:
  //inherit constructor child : parent
    premium(string FN, string LN, int NOT):tickets(FN,LN,NOT) {
      seatType = "PREMIUM";
    }
};

//inherit class STANDARD : TICKETS
class standard : public tickets {  
  private:
    void calculateTotal(void){
      price = numOfTickets * 100.0 * 110/100;
    }
  public:
  //inherit constructor child : parent
    standard(string FN, string LN, int NOT):tickets(FN,LN,NOT) {
      seatType = "STANDARD";
    }
};