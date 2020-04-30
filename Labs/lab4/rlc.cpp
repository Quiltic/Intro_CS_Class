#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
const double Q = pow(10,-9);
const double k = 9*pow(10,9);

double Efield(double r, double a = 1){

    if (r >= a){
        return((k*Q)/pow(r,2));
    }else{
        return(k*Q*(r/pow(a,3)));

    }


}

*/

double Circular_line_frequency(double f){
    return(2*M_PI*f);
    //ω=2πf=100π, rad/sec
}

double AC_period(double f){
    return(1/f);
    //T=1f=0.02 sec
}

double V(double Eo,double w,double t){
    return(Eo*(sin(w*t)* (180.0/3.141592653589793238463)));
}

double Amplitude(double Eo,double w,double c, double r, double L) {
    double A = (w*Eo);
    double B = sqrt(pow((L*(w*w) - 1/(c)),2) + (r*r)*(w*w));
    return((A/B));
}

double Current_Phase_Angle(double w, double c, double r, double L){
    double Q = atan(((L*w)/r) - 1/(r*c*w));
    return((Q * (180.0/3.141592653589793238463)));
}

double Total_Current(double Amp, double w, double t, double Phase_Angle){
    return(Amp*sin((w*t-Phase_Angle)));
}
//It     =A sinωt-ϕ, amps
double Resistor_Voltage_Drop(double r, double Amp, double w, double t, double Phase_Angle){
    return(r*Amp*sin((w*t-Phase_Angle)));
}
// VRt  =R A sinωt-ϕ,    V
double Inductor_Voltage_Drop(double L, double Amp, double w, double t, double Phase_Angle){
    return(L*w*Amp*sin((w*t-Phase_Angle)));
}
// VLt  =Lω A cosωt-ϕ, V
double Capacitor_Voltage_Drop(double C, double Amp, double w, double t, double Phase_Angle){
    return((-Amp/(C*w))*sin((w*t-Phase_Angle)));
}
//VCt=-A Cω  cosωt-ϕ,  V

double Voltage_Total(double Vr,double VL,double VC){
    //Vt=VRt+VLt+VCt
    return((Vr+VL+VC));
}


int main() {
    double r, L, c, f, Eo;  // T, Δt;
    int nstep; // #timesteps/cycle
    Eo = 25;
    f = 50;
    r = 50;
    L = .3;
    c = 0.000015;
    nstep = 37;


    /* Input
    cout << "Give: Applied voltage amplitude (Eo) in volts" << endl;
    cin >> Eo;
    cout << "Give: Line frequency (f) in hertz (= 1/sec)" << endl;
    cin >> f;
    cout << "Give: Resistor value (r) in ohms (W)" << endl;
    cin >> r;
    cout << "Give: Inductor value (L) in henrys" << endl;
    cin >> L;
    cout << "Give: Capacitor value (c) in F" << endl;
    cin >> c;
    cout << "Give: pts/AC period (nstep)" << endl;
    cin >> nstep;
    //*/
    double w = Circular_line_frequency(f);
    double t = AC_period(f);
    double Amp = Amplitude(Eo,w,c,r,L);
    double Phase_Angle = Current_Phase_Angle(w,c,r,L);


    cout << "Current Amplitude: " << Amp << "-amps" << endl;
    cout << "Phase Angle: " << Phase_Angle << "-degrees" <<endl;

    cout << setw(10) << "Step" << setw(10) << "Time" << setw(10) << "AV" << setw(10) << "I" << setw(10) << "VR" << setw(10) << "VL" << setw(10) << "VC" <<setw(10) << "VT" <<setw(10) << "VDif"<< endl;


    double Tdelta = t*2 - t;

    double Vt, Vr, VL, VC;


    double timetime = 0;
    for(int steps = 0; steps < nstep; steps++){

        Vt = V(Eo, w, t);
        Vr = Resistor_Voltage_Drop(r, Amp ,w ,timetime ,Phase_Angle);
        VL = Inductor_Voltage_Drop(L,Amp,w,timetime,Phase_Angle);
        VC = Capacitor_Voltage_Drop(c,Amp,w,timetime,Phase_Angle);

        cout  << fixed << setprecision(3) <<setw(10) << steps <<setw(10) << timetime <<setw(10) << Vt <<setw(10) << Total_Current(Amp, w, t, Phase_Angle) <<setw(10) << Vr <<setw(10) << VL <<setw(10) << VC <<setw(10) << Vt <<setw(10) << Vt - Voltage_Total(Vr, VL, VC) << endl;

        timetime += .001; //Tdelta;
    }


    /*
    cout << "Total Voltage: " << Voltage_Total(Vr, VL, VC) << " V" << endl; //Vt
    cout << "Total Current: " << Total_Current(Amp, w, t, Phase_Angle) << " amps" << endl; //It
    cout << "Resistor Voltage Drop: " << Vr << " V" << endl; //VRt
    cout << "Inductor Voltage Drop: " << VL << " V" << endl; //VLt
    cout << "Capacitor Voltage Drop: " << VC << " V" << endl; //VCt
    cout << "Voltage Difference: " << Vt - Voltage_Total(Vr, VL, VC) << " V" << endl;
    //*/


   //cout << "Efield: " << Efield(r,a) << endl;

   return 0;
}
