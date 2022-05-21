/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class LoanServ{//Class for all the customers of our loaning service
private:
    int id;
    float balance;
    float lend;
    float borr;
    void isAvail(int amt);
public:
    void setId(void){
        cout<<"Enter the Id"<<endl;
        cin>>id;
    }
    int getId(void){
        return id;
    }
    void setBal(void){
        cout<<"Enter the Balance"<<endl;
        cin>>balance;
    }
    void getBal(void){
        cout<<"Balance : "<< balance <<endl;
        
    }
    void setLend(void){
        cout<<"Enter the Total Money Lended"<<endl;
        cin>>lend;
    }
    void getLend(void){
        cout<<"Money Lended : "<< lend <<endl;
        
    }
    void setBorr(void){
        cout<<"Enter the Total Money Borrowed"<<endl;
        cin>>borr;
    }
    void getBorr(void){
        cout<<"Money Borrowed : "<< borr <<endl;
        
    }
    void LendMon(float amt);
    void BorrMon(float amt);
    void DispCust(void);
};
void LoanServ :: isAvail(int amt){//Would be a private function
    if (balance<amt){
        cout<<"Unavailable Balance"<<endl;
        exit(0);
    }
}
void LoanServ :: LendMon(float val){
    isAvail(val);//Checking that the lender has enough balance
    balance-=val;
    lend+=val;
    
}
void LoanServ :: BorrMon(float val){
    
    balance+=val;
    borr+=val;
    
}
void LoanServ :: DispCust(void){
    cout<<"Id :"<<id<<endl;
    getBal();
    getLend();
    getBorr();
    
}
int main()
{
    int actb, actl, bin, lin;
    float amt;
    LoanServ ppl[4];//Taking the data of the customers in the system
    for (int i = 0; i<4; i++){
    cout<<"Customer No: "<<i+1<<endl;
    ppl[i].setId();
    ppl[i].setBal();
    ppl[i].setLend();
    ppl[i].setBorr();
    }
    cout<<"Enter the Id of the borrower"<<endl;
    cin>>actb;
    for (int j = 0; j<4; j++){
        if(ppl[j].getId() == actb) bin = j;//For recognising the index of the borrower
    }
    cout<<"Enter the Id of the Lender"<<endl;
    cin>>actl;
    for (int k = 0; k<4; k++){
        if(ppl[k].getId() == actl) lin = k;//For recognising the index of the borrower
    }
    cout<<"Active Borrower"<<endl;//Before the transaction
    ppl[bin].DispCust();
    cout<<"Active Lender"<<endl;
    ppl[lin].DispCust();
    cout<<"Enter the amount"<<endl;
    cin>>amt;
    ppl[lin].LendMon(amt);
    ppl[bin].BorrMon(amt);
    cout<<"After Transaction"<<endl;
    cout<<"Active Borrower"<<endl;
    ppl[bin].DispCust();
    cout<<"Active Lender"<<endl;
    ppl[lin].DispCust();
    
    
    
    return 0;
}
