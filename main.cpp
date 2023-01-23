#include <iostream>
#include <cmath>
#include "BSM_model.h"

using namespace std;

int main(){ 
        double spot{0}, strike{0}, rate{0}, time{0}, vol{0}; 
        char input_val;
        bool is_vol{true}, is_call{false};
        
        while(true){
                cout<<"Press P for PUT and C for CALL: ";
                cin>>input_val;
                if(input_val=='C' || input_val=='c' || input_val=='P' || input_val=='p'){
                        if(input_val=='C' || input_val=='c'){is_call = true; break;}
                        break;
                }
                else
                        cout<<"Incorrect Input"<<endl;
        }
        cout<<endl<<"Please Enter:"<<endl;
        cout<<"Spot Price: ";
        cin>>spot;
        cout<<"Strike Price: ";
        cin>>strike;
        cout<<"Risk free rate: ";
        cin>>rate;
        cout<<"Time to maturity(in years): ";
        cin>>time;
        cout<<"Enter Volatility: ";
        cin>>vol;
        
        
        Option c(spot, strike, rate, time, vol,is_vol,is_call);
        cout<<endl;
        if(is_call == true){cout << "Price and Greeks for call option: "<< endl;}
        else{cout << "Price and Greeks for put option: "<< endl;}
        c.summary();cout<<endl;
       
}