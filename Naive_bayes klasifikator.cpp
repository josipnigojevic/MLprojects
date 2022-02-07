#include <iostream>
#include <vector>
using namespace std;
//definition of the instances used in this practice dataset
//dataset : https://raw.githubusercontent.com/jbrownlee/Datasets/master/pima-indians-diabetes.csv
class Instance
{
    uint8_t pregnant; //number of times pregnant
    uint8_t plasma_glucose; //Plasma glucose concentration a 2 hours in an oral glucose tolerance test.
    uint8_t blood_pressure; //Diastolic blood pressure (mm Hg).
    uint8_t triceps_thickness; //Triceps skinfold thickness (mm).
    float insulin; //2-Hour serum insulin (mu U/ml).
    uint8_t BMI; //Body mass index (weight in kg/(height in m)^2)
    float Diabetes_pedigree; //Diabetes pedigree function.
    uint8_t age; //age in years
    bool classification; //output variable

    public:
    Instance(uint8_t x,uint8_t y,uint8_t z,uint8_t a,float b,uint8_t c,float d,uint8_t e,bool t)
{
    uint8_t pregnant=x; 
    uint8_t plasma_glucose=y; 
    uint8_t blood_pressure=z; 
    uint8_t triceps_thickness=a; 
    float insulin=b; 
    uint8_t BMI=c; 
    uint8_t age=e;
    float Diabetes_pedigree=d; 
    bool classification=t; 
} //parametrized constructor for adding instances

    double P_one(uint8_t x,uint8_t y,uint8_t z,uint8_t a,float b,uint8_t c,float d,uint8_t e);
    double P_zero(uint8_t x,uint8_t y,uint8_t z,uint8_t a,float b,uint8_t c,float d,uint8_t e);
    float avg_paramf(uint8_t x);
    //bool klasa; vratit se na definiciju ovoga

};
//Brief statistical analysis(taken from:https://raw.githubusercontent.com/jbrownlee/Datasets/master/pima-indians-diabetes.names):

//    Attribute number:    Mean:   Standard Deviation:
//    1.                     3.8     3.4
//    2.                   120.9    32.0
//    3.                    69.1    19.4
//    4.                    20.5    16.0
//    5.                    79.8   115.2
//    6.                    32.0     7.9
//    7.                     0.5     0.3
//    8.                    33.2    11.8
//    

double Instance::P_one(uint8_t x,uint8_t y,uint8_t z,uint8_t a,float b,uint8_t c,float d,uint8_t e)
{
    int i,p=0,preg_sum,plasma_sum,blood_sum,triceps_sum,BMI_sum,age_sum;
    float preg_avg,plasma_avg,blood_avg,triceps_avg,insulin_avg,BMI_avg,age_avg,insulin_sum,Diabetes_pedigree_sum,Diabetes_pedigree_avg;
    int att_1=0,att_2=0,att_3=0,att_4=0,att_5=0,att_6=0,att_7=0,att_8=0; //number of instances with values of each attribute in the "1" class
    //there are 30examples defined
    for(i=0;i<30;i++)
    {
        if(Inst[i].classification==1)
        {
        preg_sum+=Inst[i].pregnant;
        plasma_sum+=Inst[i].plasma_glucose;
        blood_sum+=Inst[i].blood_pressure;
        triceps_sum+=Inst[i].triceps_thickness;
        insulin_sum+=Inst[i].insulin;
        BMI_sum+=Inst[i].BMI;
        age_sum+=Inst[i].age;
        pedigree_sum+=Inst[i].Diabetes_pedigree;
        p++;
        }
    }
    preg_avg=preg_sum/p;
    plasma_avg=plasma_sum/p;
    blood_avg=blood_sum/p;
    triceps_avg=triceps_sum/p;
    insulin_avg=insulin_sum/p;
    triceps_avg=triceps_sum/p;
    age_avg=age_sum/p;
    Diabetes_pedigree_avg=Diabetes_pedigree_sum/p;
      for(i=0;i<30;i++)
    {
        if(t==1)
        {
            if(x<= preg_avg)
            att_1++;

            if(y<=plasma_avg)
            att_2++;

            if(z<=blood_avg)
            att_3++;

            if(a<=triceps_avg)
            att_4++;

            if(b<=insulin_avg)
            att_5++;

            if(c<=triceps_avg)
            att_6++;

            if(d<=Diabetes_pedigree_avg)
            att_7++;

            if(e<=age_avg)
            att_8++;
      
        }
    }
    double percent = ((att_1/p)*(att_2/p)*(att_3/p)*(att_4/p)*(att_5/p)*(att_6/p)*(att_7/p)*(att_8/p)*(p/i)); 
    return percent;

}
double Instance::P_zero(uint8_t x,uint8_t y,uint8_t z,uint8_t a,float b,uint8_t c,float d,uint8_t e)
{
    int i,p=0,preg_sum,plasma_sum,blood_sum,triceps_sum,BMI_sum,age_sum;
    float preg_avg,plasma_avg,blood_avg,triceps_avg,insulin_avg,BMI_avg,age_avg,insulin_sum,Diabetes_pedigree_sum,Diabetes_pedigree_avg;
    int att_1=0,att_2=0,att_3=0,att_4=0,att_5=0,att_6=0,att_7=0,att_8=0; //number of instances with values of each attribute in the "1" class
    //there are 30examples defined
    for(i=0;i<30;i++)
    {
        if(Inst[i].classification==0)
        {
        preg_sum+=Inst[i].pregnant;
        plasma_sum+=Inst[i].plasma_glucose;
        blood_sum+=Inst[i].blood_pressure;
        triceps_sum+=Inst[i].triceps_thickness;
        insulin_sum+=Inst[i].insulin;
        BMI_sum+=Inst[i].BMI;
        age_sum+=Inst[i].age;
        pedigree_sum+=Inst[i].Diabetes_pedigree;
        p++;
        }
    }
    preg_avg=preg_sum/p;
    plasma_avg=plasma_sum/p;
    blood_avg=blood_sum/p;
    triceps_avg=triceps_sum/p;
    insulin_avg=insulin_sum/p;
    triceps_avg=triceps_sum/p;
    age_avg=age_sum/p;
    Diabetes_pedigree_avg=Diabetes_pedigree_sum/p;
      for(i=0;i<30;i++)
    {
        if(t==1)
        {
            if(x > preg_avg)
            att_1++;

            if(y > plasma_avg)
            att_2++;

            if(z > blood_avg)
            att_3++;

            if(a > triceps_avg)
            att_4++;

            if(b > insulin_avg)
            att_5++;

            if(c > triceps_avg)
            att_6++;

            if(d > Diabetes_pedigree_avg)
            att_7++;

            if(e > age_avg)
            att_8++;
      
        }
    }
    double percent = ((att_1/p)*(att_2/p)*(att_3/p)*(att_4/p)*(att_5/p)*(att_6/p)*(att_7/p)*(att_8/p)*(p/i)); 
    return percent;

}

//dataset(samo je dio dataseta uvaljen, mozda nekih 30ak primjera, u datasetu ima priko 300, što ih se više nadoda preciznije funkcionira program)
vector<Instance> Inst;

Inst.push_back(Instance(6,148,72,35,0,33.6,0.627,50,1));
Inst.push_back(Instance(1,85,66,29,0,26.6,0.351,31,0));
Inst.push_back(Instance(8,183,64,0,0,23.3,0.672,32,1));
Inst.push_back(Instance(1,89,66,23,94,28.1,0.167,21,0));
Inst.push_back(Instance(0,137,40,35,168,43.1,2.288,33,1));
Inst.push_back(Instance(5,116,74,0,0,25.6,0.201,30,0));
Inst.push_back(Instance(3,78,50,32,88,31.0,0.248,26,1));
Inst.push_back(Instance(10,115,0,0,0,35.3,0.134,29,0));
Inst.push_back(Instance(2,197,70,45,543,30.5,0.158,53,1));
Inst.push_back(Instance(8,125,96,0,0,0.0,0.232,54,1));
Inst.push_back(Instance(4,110,92,0,0,37.6,0.191,30,0));
Inst.push_back(Instance(10,168,74,0,0,38.0,0.537,34,1));
Inst.push_back(Instance(10,139,80,0,0,27.1,1.441,57,0));
Inst.push_back(Instance(1,189,60,23,846,30.1,0.398,59,1));
Inst.push_back(Instance(5,166,72,19,175,25.8,0.587,51,1));
Inst.push_back(Instance(7,100,0,0,0,30.0,0.484,32,1));
Inst.push_back(Instance(0,118,84,47,230,45.8,0.551,31,1));
Inst.push_back(Instance(7,107,74,0,0,29.6,0.254,31,1));
Inst.push_back(Instance(1,103,30,38,83,43.3,0.183,33,0));
Inst.push_back(Instance(1,115,70,30,96,34.6,0.529,32,1));
Inst.push_back(Instance(3,126,88,41,235,39.3,0.704,27,0));
Inst.push_back(Instance(8,99,84,0,0,35.4,0.388,50,0));
Inst.push_back(Instance(7,196,90,0,0,39.8,0.451,41,1));
Inst.push_back(Instance(9,119,80,35,0,29.0,0.263,29,1));
Inst.push_back(Instance(11,143,94,33,146,36.6,0.254,51,1));
Inst.push_back(Instance(10,125,70,26,115,31.1,0.205,41,1));
Inst.push_back(Instance(7,147,76,0,0,39.4,0.257,43,1));
Inst.push_back(Instance(1,97,66,15,140,23.2,0.487,22,0));
Inst.push_back(Instance(13,145,82,19,110,22.2,0.245,57,0));
Inst.push_back(Instance(5,117,92,0,0,34.1,0.337,38,0));
Inst.push_back(Instance(5,109,75,26,0,36.0,0.546,60,0));

int main()
{
    uint8_t atribut_1,atribut_2,atribut_3,atribut_4,atribut_5,atribut_6;
    float atribut_7,atribut_8;
    double p_da,p_ne;
    cout<<"enter the parameters of the patient"<<endl;
    cout<<"number of times pregnant"<<endl;
    cin>>atribut_1;
    cout<<"Plasma glucose concentration a 2 hours in an oral glucose tolerance test."<<endl;
    cin>>atribut_2;
    cout<<"Diastolic blood pressure (mm Hg)."<<endl;
    cin>>atribut_3;
    cout<<"triceps skinfold thickness (mm)."<<endl;
    cin>>atribut_4;
    cout<<"2-Hour serum insulin (mu U/ml)."<<endl;
    cin>>atribut_7;
    cout<<"Body mass index (weight in kg/(height in m)^2)"<<endl;
    cin>>atribut_5;
    cout<<"Diabetes pedigree function."<<endl;
    cin>>atribut_8;
    cout<<"age in years"<<endl;
    cin>>atribut_6;


    p_da=P_one(atribut_1,atribut_2,atribut_3,atribut_4,atribut_7,atribut_5,,atribut_8,atribut_6);
    p_ne=P_zero(atribut_1,atribut_2,atribut_3,atribut_4,atribut_7,atribut_5,,atribut_8,atribut_6);

    if(p_da>p_ne)
    cout<<"imate dijabetes"<<endl;
    else
    cout<<"nemate dijabetes"<<endl;

    return 0;
}
