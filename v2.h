#include <iostream>
#include<string>

#define SIZE 100
//library file
// #include "declare.h"

using namespace std;

class tickets{
  protected:
    string firstname, lastname, seatType;
    int numOfTickets;
    float price,total;

    virtual int calculateTotal(void){
        return price = 0;
    }
 
 
  public:
    tickets(const string FN,const string LN,const int NOT){
    }
    
    void getInput(string FN, string LN, int NOT){
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
    int calculateTotal(void){
      return price = numOfTickets * 150.0 * 115/100;
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
    int calculateTotal(void){
      return price = numOfTickets * 100.0 * 110/100;
    }
  public:
  //inherit constructor child : parent
    standard(string FN, string LN, int NOT):tickets(FN,LN,NOT) {
      seatType = "STANDARD";
    }
};


int main() {
  string firstname, lastname;
  int numOfTickets, nums, seatType[SIZE];
  
  // tickets *t[SIZE];
  
//   premium a(firstname,lastname,numOfTickets);
//   standard b(firstname,lastname,numOfTickets);
  tickets **test;
  tickets *t[SIZE];
  test = new tickets*[SIZE];
  
  

  
  cout << "Total of orders: ";
  cin >> nums;
  
  for(int i = 0; i < nums ; i++ ){
    cout<< endl<< "------------------------------------------------------------------" <<endl;
    cout << "Order " << i+1 <<endl;
    
    cout << " PREMIUM Seats          --> Press 1" <<endl;
    cout << " STANDARD Seats         --> Press 2" <<endl;
    cout << "Key in Seat Type: ";cin >> seatType[i];
    
    cout << "Key in 1stname: ";
    cin >> firstname;
    cout << "Key in Lastname: ";
    cin >> lastname;
    cout << "Number Ticket Order: ";
    cin >> numOfTickets;
    
    
    for(int u=i;u<nums; u++){
      if(seatType[i] == 1){
        test[u] = new premium(firstname,lastname,numOfTickets);
        test[u]->getInput(firstname,lastname,numOfTickets);
      }
      else if(seatType[i] == 2){
        test[u] = new standard(firstname,lastname,numOfTickets);
        test[u]->getInput(firstname,lastname,numOfTickets);
      } 
       
    } 
    t[i] = { test[i] };
   
  }



  //display
  for(int x = 0; x<nums;x++){
    test[x]->displayOrder();
    t[x] = { test[x] };
  }
    
}
