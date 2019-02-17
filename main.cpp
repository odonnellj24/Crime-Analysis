/*main.cpp*/

//
// Chicago Crime Analysis program in modern C++.
//
// <<YOUR NAME>>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "classes.h"

using namespace std;


int main()
{
  string  crimeCodesFilename, crimesFilename, line, iucr, primary, second, date, iucr2, arrest;
  
  string domestic, ward, community, year, beat, district;
  
  bool Arrest2, Domestic2;
  int counter, counter2, counter3;

  cin >> crimeCodesFilename;
  cout << crimeCodesFilename << endl;
  
  cin >> crimesFilename;
  cout << crimesFilename << endl;

  ifstream  codesFile(crimeCodesFilename);
  ifstream  crimesFile(crimesFilename);

  cout << std::fixed;
  cout << std::setprecision(2);

  if (!codesFile.good())
  {
    cout << "**ERROR: cannot open crime codes file: '" << crimeCodesFilename << "'" << endl;
    return -1;
  }
  if (!crimesFile.good())
  {
    cout << "**ERROR: cannot open crimes file: '" << crimesFilename << "'" << endl;
    return -1;
  }
    getline(codesFile,line);
  vector<CrimeCode> crimecode;
  vector<CrimeReport> crimereport;
    while (getline(codesFile,line))
    {
      stringstream ss(line);
      
      getline(ss,iucr, ',');
      getline(ss,primary,',');
      getline(ss,second);
      
      CrimeCode C(iucr,primary,second, counter);
      
      crimecode.push_back(C);
      
    }
    
    
    string line2;
    int i = 0;
    getline(crimesFile,line2);
    while (getline(crimesFile,line2))
    {
      
      stringstream ss(line2);
      
      getline(ss,date, ',');
      getline(ss,iucr2,',');
      getline(ss,arrest, ',');
      getline(ss,domestic, ',');
      getline(ss,beat, ',');
      getline(ss,district, ',');
      getline(ss,ward,',');
      getline(ss,community,',');
      getline(ss,year);
      
      Arrest2 = (arrest == "TRUE" || arrest =="true");
      Domestic2 = (domestic == "TRUE"|| domestic == "true");
      CrimeReport D(date, iucr2, Arrest2, Domestic2, stoi(beat), stoi(district), stoi(ward), stoi(community), stoi(year));
      
      for(CrimeCode& q : crimecode ){
        if (iucr2 == q.getIUCR())
        {
          q.setCounter();
        }
      }
  
      crimereport.push_back(D);
    }
    
    int hi = crimereport.size() -1;
    int hi2= crimecode.size();
    cout << "** Crime Analysis **"<<endl;
    cout << "Date range: " << crimereport[1].getDate()<<" - "<< crimereport[hi].getDate()<< endl;
    
    cout << "# of crime codes: "<< hi2 << endl;
    std::sort(crimecode.begin(), crimecode.end(), []( CrimeCode c1, CrimeCode c2)
    {
      if (
        c1.getIUCR() < c2.getIUCR())
      {
        return true;
      }
      else if (c2.getIUCR()< c1.getIUCR()){
        return false;
      }
      else{
        return false;
      }
    });
    
    for( int k = 0; k<3; k++){
      cout << crimecode[k].getIUCR() << ":  " << crimecode[k].getPrimary() <<":"<<crimecode[k].getSecondary()<< endl; 
    }
    
    cout << "..."<<endl;
    
    for(int k = hi2 - 3; k<hi2; k++){
      cout << crimecode[k].getIUCR() << ":  " << crimecode[k].getPrimary() <<":"<<crimecode[k].getSecondary()<< endl; 
    }
    hi = hi+1;
    cout << "# of crimes: "<< hi << endl;
    
    for(int k = 0; k<3; k++){
      cout << crimereport[k].getIUCR2() << ": " << crimereport[k].getDate() <<", "<<crimereport[k].getBeat()<<", "<< crimereport[k].getDistrict()<<", "<< crimereport[k].getWard()<<", "<< crimereport[k].getCommunity()<<endl; 
      
      if (crimereport[k].getArrest() == true){
        cout << ", "<< "arrested"<<endl;
      }
       if (crimereport[k].getDomestic() == true){
        cout << ", "<< "domestic violence"<<endl;
      }
    }
    cout << "..."<< endl;
    for(int k = hi-3; k<hi; k++){
      cout << crimereport[k].getIUCR2() << ": " << crimereport[k].getDate() <<", "<<crimereport[k].getBeat()<<", "<< crimereport[k].getDistrict()<<", "<< crimereport[k].getWard()<<", "<< crimereport[k].getCommunity()<<endl; 
      
      if (crimereport[k].getArrest() == true){
        cout << ", "<< "arrested"<<endl;
      }
       if (crimereport[k].getDomestic() == true){
        cout << ", "<< "domestic violence"<<endl;
      }
    }

    std::sort(crimecode.begin(), crimecode.end(), []( CrimeCode c1, CrimeCode c2)
    {
      if (
        c1.getCounter() > c2.getCounter())
      {
        return true;
      }
      else if (c2.getCounter()> c1.getCounter()){
        return false;
      }
      else{
        return false;
      }
    });
    cout << "** Top-5 Crimes **" << endl << "Code:  Total, Description"<<endl;
    
    for (int i =0; i<5; i++)
    {
      cout << crimecode[i].getIUCR() << ":  " << crimecode[i].getCounter() << ", "<<crimecode[i].getPrimary()<<": "<<crimecode[i].getSecondary()<<endl;
    }
    
     cout<< "** Done **" << endl;
   
 
 
   return 0;
}
