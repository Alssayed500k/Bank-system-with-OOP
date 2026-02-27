#pragma once
#include <iostream>
#include<vector>

using namespace std;
class clsString
{
private:
    string _Value;
public:

    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    //Property setter.
    void setValue(string Value)
    {
        _Value = Value;
    }
    //Property getter.
    string getValue()
    {
        return _Value;
    }


    __declspec(property(get = getValue, put = setValue)) string Value;//set ,get value usinig '='
    //we used  static keyword  for accessible all methods without needing creat a object 

    static string ReadString(string Message = "" , short Width = 0)
    {
        string S;
        cout << Message;
        getline(cin >> ws, S);

        return  S;
    }
    static short CountWords(string S1)
    {
        string Word = "";
        string SpaceInString = " ";
        short Pos = 0;
        short Counter = 0;

        //Use find() function to get position of spaces.
        while ((Pos = S1.find(SpaceInString)) != std::string::npos)
        {
            Word = S1.substr(0, Pos);//add word

            if (Word != "")
            {
                Counter++;
            }

            S1.erase(0, Pos + SpaceInString.length());//Erase the counted word.
        }

        if (S1 != "")
        {
            Counter++; //counter last word
        }
        return Counter;

    }
    short CountWords()
    {
        return CountWords(_Value);

    }

    static vector<string> Split(string S1, string Separated)
    {
        vector<string>vS1;

        string Word = "";
        short Pos;

        while ((Pos = S1.find(Separated)) != std::string::npos)
        {
            Word = S1.substr(0, Pos);//Add a word..

            if (Word != "")
            {
                vS1.push_back(Word);
            }
            S1.erase(0, Pos + Separated.length());
        }
        if (S1 != "")
        {
            vS1.push_back(S1);//Add last a word..
        }
        return vS1;

    }
    vector<string> Split(string Separated)
    {
        return Split(_Value, Separated);
    }

    static string UpperAllString(string S1)
    {
        string S2 = "";
        for (short i = 0; i < S1.length(); i++)
        {
            S2 += toupper(S1[i]);
        }
        return S2;
    }
    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static string LowerAllString(string S1)
    {
        string S2 = "";
        for (short i = 0; i < S1.length(); i++)
        {
            S2 += tolower(S1[i]);
        }
        return S2;
    }
    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static string ReplaceWord(string Text, string OldStr, string NweStr)
    {
        string S2 = " ";
        vector <string>vS1;
        vS1 = Split(Text, " ");

        for (string S3 : vS1)
        {
            if (LowerAllString(S3) == LowerAllString(OldStr))
            {
                S3 = NweStr;
            }
            S2 = S2 + " " + S3;
        }
        return S2;
    }
    string ReplaceWord(string NewWord, string OldWord)
    {
        return ReplaceWord(_Value, OldWord, NewWord);
    }

    static string JoinString(vector <string> vS1, string Joined)
    {
        if (vS1.size() == 0)
        {
            return "";
        }
        string S2 = "";
        for (short i = 0; i < vS1.size(); i++)
        {
            S2 += vS1[i] + Joined;
        }
        return S2.substr(0, S2.length() - 1);

    }
    static string JoinString(string arr[], short Length, string Joined)
    {
        if (Length == 0)
        {
            return "";
        }
        string S2 = "";
        for (short i = 0; i < Length; i++)
        {
            S2 += arr[i] + Joined;
        }
        return S2.substr(0, S2.length() - 1);

    }

    static string ReverseWordsInStrin(string S1)
    {
        vector <string>vS;
        vS = Split(S1, " ");
        string S2 = "";
        vector<string>::iterator iter;
        iter = vS.end();

        if (vS.size() == 1)//in case the string is one word.
        {
            string S3 = vS[0];
            for (short i = S3.length() - 1; i >= 0; i--)
            {
                S2 += S3[i];
            }
            S2 += " ";
        }
        else//in case the string is more a word.
        {
            while (iter != vS.begin())
            {
                iter--;
                S2 += *iter + " ";
            }

        }
        return S2.substr(0, S2.length() - 1);

    }
    void ReverseWordsInString()
    {
        _Value = ReverseWordsInStrin(_Value);
    }

    static short CountCapitalLetters(string S1)
    {

        short Counter = 0;
        if (S1 == "")
        {
            return 0;
        }

        for (short i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Counter++;
        }
        return Counter;
    }
    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static bool IsVowelLetter(char char1)
    {
        char VowelLetters[] = { 'a' , 'e' , 'i' , 'o' , 'u' };
        for (char letter : VowelLetters)
        {
            if (tolower(letter) == tolower(char1))
                return true;
        }
        return false;
    }

    static short CountVowelsLetters(string S1)
    {
        short Counter = 0;

        if (S1 == "")
            return Counter;

        for (short i = 0; i < S1.length(); i++)
        {
            if (IsVowelLetter(S1[i]))
                Counter++;
        }
        return Counter;
    }
    short CountVowelsLetters()
    {
        return CountVowelsLetters(_Value);
    }

    enum enWahatToCount { Lowerletters = 0, CapitalLetters = 1, All = 2 };

    static short CountLetters(string S1, enWahatToCount WhatToCount = enWahatToCount::All)
    {
        if (S1 == "")
        {
            return 0;
        }
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                if (WhatToCount == enWahatToCount::CapitalLetters)
                    Counter++;
                else if (WhatToCount == enWahatToCount::Lowerletters)
                    Counter++;
                else
                    Counter++;

            }



        }
        return Counter;
    }
    short  CountLetters(enWahatToCount WhatToCount = enWahatToCount::All)
    {
        return CountLetters(_Value, WhatToCount);
    }

    static short CountSmallLetters(string S1)
    {

        short Counter = 0;
        if (S1 == "")
        {
            return 0;
        }

        for (short i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Counter++;
        }
        return Counter;
    }
    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static string UpperFirsLetterOfEachWord(string S1)
    {
        if (S1.empty())
        {
            return "";
        }
        string S2 = "";
        vector<string> vS2 = Split(S1, " ");

        for (string S3 : vS2)
        {
            S3[0] = toupper(S3[0]);
            S2 += S3 + " ";

        }
        return S2.substr(0, S2.length() - 1);
    }
    void UpperFirsLetterOfEachWord()
    {
        _Value = UpperFirsLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string S1)
    {
        if (S1.empty())
        {
            return "";
        }
        string S2 = "";
        vector<string> vS2 = Split(S1, " ");

        for (string S3 : vS2)
        {
            S3[0] = tolower(S3[0]);
            S2 += S3 + " ";

        }
        return S2.substr(0, S2.length() - 1);
    }
    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static char InvertLetterCase(char Chr1)
    {
        return isupper(Chr1) ? tolower(Chr1) : toupper(Chr1);
    }

    static short Length(string S1)
    {
        return S1.length();
    }
    short Length()
    {
        return _Value.length();
    }

    static string RemovePunctuations(string S1)
    {
        string S2 = "";

        if (S1 == "")
        {
            return S2;
        }

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
                S2 += S1[i];

        }
        return S2;
    }
    void  RemovePunctuations()//We don't need return any value becase we update  the object only.
    {
        _Value = RemovePunctuations(_Value);
    }
    short static CountSpecificLetter(string S1, char letter, bool Machcase = true)
    {
        if (S1 == "")
        {
            return 0;
        }
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (Machcase)
            {
                if (tolower(S1[i]) == tolower(letter))
                    Counter++;
            }
            else
            {
                if (S1[i] == letter)
                    Counter++;

            }


        }
        return Counter;
    }
    short CountSpecificLetter(char Char1, bool MachCase = false)
    {
        return CountSpecificLetter(_Value, Char1, MachCase);
    }

    
};
