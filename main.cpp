#include <iostream>
#include<string>
#include <iomanip> //setprecision - decimal point

#define SIZE 100


using namespace std;

class worker{
  protected:
    string name, type;
    int numOfTickets;
    float sales,total,salary;
    float bonus = 0;

    virtual int calculateTotal(float S){
      return sales = S;
    }
 
 
  public:
    worker(const string N){
        name = N; 
    }
    
    void getInput(string N,float S,float B){
        name = N; 
        sales = S;
        bonus = B;

    }
    
    void displayOrder(){
      getInput(name,sales,bonus);  
      calculateTotal(sales);
      cout << "Name           : "<< name << endl;
      cout << "Status         : " << type << endl;
      cout << "Sales          : " << fixed << setprecision(2) << sales << endl;
      cout << "Bonus          : " << fixed << setprecision(2) << bonus << endl;
      cout << "Total salary is  " << fixed << setprecision(2) << salary << endl;
    }

    
};


class fulltime : public worker {  
  private:
    int calculateTotal(float sales){
      if(sales >= 500){
        bonus = sales * 0.3;
        return salary = 1000 + sales + bonus;
      }else{
        bonus = 0;
        return salary = 1000 + sales + bonus;
      }
      
    }
  public:
    fulltime(string N):worker(N) {
      type = "FULL TIME";
    }
    
};


class parttime : public worker {  
  private:
    int calculateTotal(float sales){
      getInput(name,sales,bonus);
      if(sales >= 500){
        bonus = (sales * 0.3);
        return salary = 500 + sales + bonus;
      }else{
        bonus = 0;
        return salary = 500 + sales + bonus;
      }
      
    }
  public:
    parttime(string N):worker(N) {
      type = "PART TIME";

    }
    
};


int main() {
  string name;
  float sales,bonus, nums = 1, type[SIZE];
  worker **person;
  worker *w[SIZE];
  person = new worker*[SIZE];
  
  cout<< "***Welcome to Salesman Salary Calculator" << endl;
  
  for(int i = 0; i < nums ; i++ ){
    cout<< endl<< "------------------------------------------------------------------" <<endl;
    cout << "Order " << i+1 <<endl;
    
    cout << " FULL TIME                                   --> Press 1" <<endl;
    cout << " PART TIME                                   --> Press 2" <<endl;
    cout << "Enter Your Status           : ";cin >> type[i];
    
    cout << "Name    : ";
    cin >> name;
    cout << "Sales   : ";
    cin >> sales;
    
    //selection codition
    for(int u=i;u<nums; u++){
      if(type[i] == 1){
        person[u] = new fulltime(name);
        person[u]->getInput(name,sales,bonus);
      }
      else if(type[i] == 2){
        person[u] = new parttime(name);
        person[u]->getInput(name,sales,bonus);
      } 
       
    } 
    //tickets array data store
    w[i] = { person[i] };
   
  }



  //display
  cout<<endl<<endl;
  cout << "Display : " <<endl;
  for(int x = 0; x<nums;x++){
    cout << "Output " << x+1 <<endl;
    //from selection to calculate
    person[x]->displayOrder();
    //present as data store
    w[x] = { person[x] };
  }
    
}
