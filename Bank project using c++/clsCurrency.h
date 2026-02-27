#pragma once 
#include <iostream>
#include "clsString.h"
#include <fstream>
#include <string>

using namespace std;

class clsCurrency
{
    private:
    enum _enMode{UpdateObject =1 , EmptyObject=2};
    
    _enMode _Mode;
    string _Country ;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate =0.0;
    
    static clsCurrency _GetEmptyObject()
    {
        return clsCurrency(_enMode::EmptyObject ,"","","",0);
    }
    
    static clsCurrency _ConvertCurrencyLineToObject(string Line , string Seperator="#//#")
    {
        vector<string> vCurrenciesLine;
        vCurrenciesLine = clsString::Split(Line , Seperator);
         
         if (vCurrenciesLine.size() !=4)
         {
             return  _GetEmptyObject();
         }
             
             
        return clsCurrency (
        _enMode::UpdateObject,
        vCurrenciesLine[0],//Country
        vCurrenciesLine[1],//CurrencyCode
        vCurrenciesLine[2],//CurrencyName
        stof(vCurrenciesLine[3])//Rate
        );
    }
    
    static string _ConvertObjectCurrencyToLine(clsCurrency CurrencyObject , string Seperator="#//#")
    {
        string CurrencyLine ;
        
        CurrencyLine = CurrencyObject.Country() + Seperator;
        CurrencyLine+=CurrencyObject.CurrencyCode()+Seperator;        CurrencyLine+=CurrencyObject.CurrencyName()+Seperator;
        CurrencyLine+=to_string(CurrencyObject.Rate())+Seperator;
        
        return CurrencyLine;
        
    }
    
    static vector <clsCurrency>_LoadCurrenciesFromFile(string FileName ="Currencies.txt",string Seperator="#//#")
    {
        vector <clsCurrency> vCurrencies;
        fstream Myfile;
        Myfile.open(FileName , ios::in);
        
        if (Myfile.is_open() )
        {
            string Line ;
            while(getline(Myfile , Line ))
            {
                clsCurrency CurrencyObject =_ConvertCurrencyLineToObject(Line);
                vCurrencies.push_back(CurrencyObject);
            }
            Myfile.close();
        }
            return vCurrencies;
        }
        
      
     static void _SaveAllCurrenciesDateInFile( vector <clsCurrency> vCurrencies, string FileName ="Currencies.txt")
      {
          fstream Myfile;
          Myfile.open (FileName , ios::out );//OverWrite
          string CurrencyLine;
          
          if (Myfile.is_open() )
          {
             for ( clsCurrency Currency : vCurrencies)
             {
                 CurrencyLine =_ConvertObjectCurrencyToLine(Currency);
                 Myfile<<CurrencyLine<<endl;
             }
            Myfile.close();
          }
      }
         
         
    
public:

clsCurrency(_enMode Mode , string Country , string CurrencyCode , string CurrrencyName , float Rate)
  {
        _Mode =Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrrencyName;
        _Rate  = Rate;
        
   }

 string Country ()
 {
    return _Country;
 }

  string CurrencyCode()
  {
      return _CurrencyCode;
   }

  string CurrencyName()
  {
      return _CurrencyName;
  }

  void Rate(float Rate)
  {
      _Rate = Rate;
  }

  float Rate()
  {
      return _Rate;
   }
   
  static  clsCurrency FindByCurrencyCode(string CurrencyCode )
   {
       
       fstream Myfile;
       Myfile.open("Currencies.txt"  , ios::in);
        
       if (Myfile.is_open())
       {
           string Line;
           while(getline(Myfile , Line))
           {
               clsCurrency CurrencyObject = _ConvertCurrencyLineToObject(Line);
               
               if (CurrencyObject.CurrencyCode() == clsString::UpperAllString(CurrencyCode) )
               {
                   Myfile.close();
                   return CurrencyObject;
               }
           }
           Myfile.close();
       }
       return _GetEmptyObject();
   }
   
   static clsCurrency FindByCurrencyByCountry(string CountryName )
   {
       
       fstream Myfile;
       Myfile.open("Currencies.txt"  , ios::in);//Read mode
        
       if (Myfile.is_open())
       {
           string Line;
           while(getline(Myfile , Line))
           {
               clsCurrency CurrencyObject = _ConvertCurrencyLineToObject(Line);
               
               if (CurrencyObject.Country() ==clsString::UpperFirsLetterOfEachWord(CountryName ))
               {
                   Myfile.close();
                   return CurrencyObject;
               }
           }
           Myfile.close();
       }
       return _GetEmptyObject();
   }
                 
   
   static vector <clsCurrency>GetCurrenciesList(string FileName ="Currencies.txt")
   {
       return _LoadCurrenciesFromFile();
   }
  
  //Update the rate only.
  bool Update(float NewRate)
  {
      vector<clsCurrency>vCurrencyList;
      vCurrencyList =GetCurrenciesList();
      if (NewRate !=0)
       {
          for(clsCurrency& Currency : vCurrencyList)
          {
              if(this ->CurrencyCode()== Currency.CurrencyCode())
             {
                 Currency.Rate(NewRate);
                 break;
                 
              }
          }
            _SaveAllCurrenciesDateInFile(vCurrencyList);
            return true;
       }
       return false;
  }
  float  ConvertCurrencyToUSD(float Amount)
  {
      return ((float)Amount / this->Rate());

  }

  float ConvertCurrencyToOtherCurrency(clsCurrency Currency2, float Amount)
  {
      float AmountInUSD = (float)ConvertCurrencyToUSD(Amount);

      if (Currency2.CurrencyCode() == "USD")
      {
          return AmountInUSD;
      }
      
      AmountInUSD = ((float)AmountInUSD * Currency2.Rate());
      return AmountInUSD;
  }
  
      bool IsEmptyObject()
      {
            return _Mode ==_enMode::EmptyObject;
      }
       
        static bool IsExsitsCurrency(string CurrencyCode)
        {
            clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode) ;
            return (!Currency.IsEmptyObject());
        }
       

            
   

};