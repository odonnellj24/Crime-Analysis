/*classes.h*/

//
// Classes for use with Chicago Crime Analysis program, e.g. "CrimeReport" 
// and "CrimeCode".
//
// << YOUR NAME >>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#pragma once

#include <iostream>
#include <string>

using namespace std;


class CrimeCode
{
private:
string IUCR;
string Primary;
string Second;
int Counter;
public:
CrimeCode (string iucr, string primary, string second, int counter)
          : IUCR(iucr), Primary(primary), Second(second), Counter(counter)
          { }
void setCounter(){
   Counter = Counter +1;
   
 }
 int getCounter(){
   return Counter;
 }
string getIUCR(){
  return IUCR;
}
string getPrimary(){
  return Primary;
}

string getSecondary(){
  return Second;
}


};

class CrimeReport
{
private:
string Date;
string IUCR2;
bool Arrest;
bool Domestic;
int Beat;
int District;
int Ward;
int Community;
int Year;

public:

CrimeReport (string date, string iucr2, bool arrest, bool domestic, int beat, int district, int ward, int community, int year)
          : Date(date), IUCR2(iucr2), Arrest(arrest), Domestic(domestic), Beat(beat), District(district), Ward(ward), Community(community), Year(year)
          { }
          
          
  string getDate(){
   return Date; 
  }
  
  string getIUCR2(){
    return IUCR2;
  }
  bool getArrest(){
    return Arrest;
  }
  bool getDomestic(){
    return Domestic;
  }
  int getBeat(){
    return Beat;
  }
  int getDistrict(){
    return District;
  }
  int getWard(){
    return Ward;
  }
  int getCommunity(){
    return Community;
  }
  int getYear(){
    return Year;
  }

};





