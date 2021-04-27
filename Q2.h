#include <iostream>
#include<string>
#include <iomanip> //setprecision - decimal point

#define SIZE 100

// #include "declare.h" //- library file

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
      cout << firstname << ", " << lastname << ": " << numOfTickets << "  [ Prog 2: The Musical ]" << endl;
      cout << "Seats         : " << seatType << endl;
      cout << "Total Price is  " << fixed << setprecision(2) << price << endl;
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
    
    cout << " PREMIUM Seats                                   --> Press 1" <<endl;
    cout << " STANDARD Seats                                  --> Press 2" <<endl;
    cout << "Key in Seat Type          : ";cin >> seatType[i];
    
    cout << "Insert Customer First Name: ";
    cin >> firstname;
    cout << "Insert Customer Last Name : ";
    cin >> lastname;
    cout << "Insert Number of Ticket   : ";
    cin >> numOfTickets;
    
    //selection codition
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
    //tickets array data store
    t[i] = { test[i] };
   
  }



  //display
  cout << "Re-display Order: " <<endl;
  for(int x = 0; x<nums;x++){
    cout << "Order " << x+1 <<endl;
    //from selection to calculate
    test[x]->displayOrder();
    //present as data store
    t[x] = { test[x] };
  }
    
    system("pause");
}
