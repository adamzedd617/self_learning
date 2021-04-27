// //tickets - 1  child inheritance
// class premium: public tickets{
//   private:
//     void calculateTotal(void);

//   public:
//     //Constructor
//     premium(string FN, string LN, int NOT);
// };

// premium:tickets(){ // constructor
//   //  firstname = FN;
//   //  lastname = LN;
//   //  numOfTickets = NOT;
//    seatType = "PREMIUM";
// };

// void tickets::calculateTotal(void){
//    total = price*numOfTickets;
// }

//  tickets::tickets(string FN, string LN, int NOT){ // constructor
//    firstname = FN;
//    lastname = LN;
//    numOfTickets = NOT;
   
//  }
 
//  void tickets::displayOrder(void){
//    calculateTotal();
//    cout << firstname << ", " << lastname << ": " << numOfTickets << endl;
//    cout << "Seats: " << seatType;
//    cout << "Total Price is " << total << endl;
//  }


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
