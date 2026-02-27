#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"clsDate.h";

using namespace std;
class clsUtil
{
public:

    enum enCharType
    {
        SamallLetter = 1,    // Represents lowercase letters (ASCII 97 to 122).
        CapitalLetter = 2,   // Represents uppercase letters (ASCII 65 to 90).
        // SpecialCharacter = 3,// Represents special characters (ASCII 33 to 47).
        Digit = 3,// Represents digits (ASCII 48 to 57).
        Mix = 4 //  
    };

   // Key section generation...
    static void Srand()
    {
        srand( (unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        // Calculate a random number in the range [From, To]:
    // rand() % (To - From + 1) gives a value between 0 and (To - From),
    // then adding From shifts this range to [From, To].
        int randNum = rand() % (To - From + 1) + From;
        return randNum;  // Return the generated random number.
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        // Use a switch-case to handle the different character types.
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            // Generate a random lowercase letter (ASCII codes 97 to 122).
            return char(RandomNumber(97, 122));
            break;  // break is not strictly needed after a return.
        }
        case enCharType::CapitalLetter:
        {
            // Generate a random uppercase letter (ASCII codes 65 to 90).
            return char( RandomNumber(65, 90));
            break;
        }
        case enCharType::Mix:
        {
            return GetRandomCharacter(enCharType(RandomNumber(1, 4)));
            break;
        }
        case enCharType::Digit:
        {
            // Generate a random digit (ASCII codes 48 to 57).
            return char(RandomNumber(48, 57));
            break;
        }
        }
        // If an invalid type is passed, return a null character.
        return '\0';
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;  // Initialize an empty string to build the word.

        // Loop for the number of characters specified by Length.
        for (int i = 1; i <= Length; i++)
        {
            // Append a random character of the specified type to the word.
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string Key = "";  // Initialize an empty key string.

        // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(enCharType CharType, short NumberOfKeys)
    {
        // Loop from 1 to NumberOfKeys.
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            // Print the current key number and the generated key.
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    };


//Swap Section ....

    //int Swap
   static void Swap(int& A, int& B)
    {
        int Temp = 0;
        Temp = A;
        A = B ;
        B = Temp;

    }
    //float Swap
   static void Swap(float& A, float& B)
    {
        float Temp = 0;
        Temp = A;
        A = B;
        B = Temp;

    }
    //double Swap
   static void Swap(double& A, double& B)
    {
        double Temp = 0;
        Temp = A;
        A = B;
        B = Temp;

    }
    //String Swap
   static void Swap(string& A, string& B)
    {
        string Temp = "";
        Temp = A;
        A = B;
        B = Temp;

    }
   //Character swap
   void Swap(char& A, char& B)
   {
       char Temp = 0;
       Temp = A;
       A = B;
       B = Temp;

   }
    //clsdate swap
   static void Swap(clsDate& A, clsDate& B )
    {
        clsDate Temp;
        Temp = A;
        A = B;
        B = Temp;

    }
   
   //Array section
   static void FillArrayWithRandomNumber(int arr[], short Length, short From, short To)
   {
       for (short i = 0; i < Length; i++)
       {
           arr[i] = RandomNumber(From, To);
       }
       return ;
   }
   static void FillArrayWithRandomKey(string Arr[], short Length , enCharType CharType)
   {
       for (short i = 0; i < Length; i++)
       {
           Arr[i] = GenerateKey(CharType);
       }
       return;
   }
   static void FillArrayWithRandomWords(string Arr[], short Length , enCharType CharType)
   {
       for (short i = 0; i < Length; i++)
       {
           Arr[i] = GenerateWord(enCharType::Mix , 4);
       }
       return;
   }
   //Shuffle int arr
   static void ShuffleArrElements(int arr[], short Length)
   {
       for (short i = 0; i < Length; i++)
       {
           swap(arr[RandomNumber(i, Length -1 )] , arr[RandomNumber(i , Length -1)]);
       }
   }
   //Shuffle string array
   static void ShuffleArrElements(string  arr[], short Length)
   {
       for (short i = 0; i < Length; i++)
       {
           swap(arr[RandomNumber(i, Length - 1)], arr[RandomNumber(i, Length - 1)]);
       }
   }

   //Taps
   static string Taps(short NumTaps)
   {
       string Taps = "";
       for (short i = 1 ; i <= NumTaps; i++)
       {
           Taps += " ";
       }
       return Taps;
   }

   //Encryption section and decryption
   static string EncryptText(string S1, short EncryptionKey=2)
   {
       string TextEncrypted = "";
       for (short i = 0; i < clsString::Length(S1); i++)
       {
           TextEncrypted += char (S1[i] + EncryptionKey);
       }
       return TextEncrypted;
   }
   static string DecryptText(string S1, short DecryptionKey=2)
   {
       string TextDecrypted = "";
       for (short i = 0; i < clsString::Length(S1); i++)
       {
           TextDecrypted += char(S1[i] - DecryptionKey);
       }
       return TextDecrypted;
   }


   static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }


   }
};