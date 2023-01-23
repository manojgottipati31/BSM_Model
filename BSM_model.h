#include <string>
#include <iostream>
#include "Integration.h"
#pragma once

using namespace std;

class Option : public Integration{
public:

        Option(const double& S, const double& K, const double& r, const double& T, const double& x, const bool& is_vol, const bool& is_call);
        double get_price() {return price;}
        double get_rate() {return rate;}
        double get_time() {return time;}
        double get_vol() {return vol;}
        double get_strike() {return strike;}
        double get_spot() {return spot;}
        
        std::string option_type();
        
        double get_delta() {calc_delta();
        return delta;}
        double get_gamma() {calc_gamma();
        return gamma;}
        double get_vega() {calc_vega();
        return vega;}
        double get_rho() {calc_rho();
        return rho;}
        double get_theta() {calc_theta();
        return theta;}
        void summary(){
                cout<<"Option's price is: "<<price<<endl;

                get_delta();
                cout<<"Option's delta is: "<<delta<<endl;

                get_gamma();
                cout<<"Option's gamma is: "<<gamma<<endl;

                get_vega();
                cout<<"Option's vega is: "<<vega<<endl;

                get_rho();
                cout<<"Option's rho is: "<<rho<<endl;

                get_theta();
                cout<<"Option's theta is: "<<theta<<endl;   
        
        }

private:

        double spot, strike, rate, time, price, vol;
        double delta, gamma, vega, rho, theta;
        bool iscall;
        
        double call_price(const double&, const double&, const double&, const double&, const double&);
        double put_price(const double&, const double&, const double&, const double&, const double&);
        void calc_delta();
        void calc_gamma();
        void calc_vega();
        void calc_rho();
        void calc_theta();
};