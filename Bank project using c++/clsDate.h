#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"clsString.h"


using namespace std;

class clsDate
{

private:
    int _Year = 0;
    int _Month = 0;
    int _Day = 0;

public:

    clsDate(int Day, int Month, int Year)
    {
        //Date initialized costructor
        _Year = Year;
        _Month = Month;
        _Day = Day;
    }

    clsDate(string Date)
    {
        //Date of string
        vector<string> vDate;
        vDate = clsString::Split(Date, "/");

        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);

    }

    clsDate()
    {
        //Get system date ..

        time_t t = time(0);
        tm now;
        localtime_s(&now, &t);

        _Day = now.tm_mday;
        _Month = now.tm_mon + 1;
        _Year = now.tm_year + 1900;
    }

    clsDate(short Days, short Year)
    {
        clsDate Date = GetDateFromDayOrderInYear(Days, Year);
        //Get Date From Day Order In Year
        _Day = Date.Day;
        _Month = Date.Month;
        _Year = Date.Year;

    }

    //property setter.
    void setDay(short Day)
    {
        _Day = Day;
    }
    //Property getter.
    short getDay()
    {
        return _Day;

    }
    __declspec(property(get = getDay, put = setDay)) short Day;//set ,get value usinig '='

    //property setter.
    void setMonth(short Month)
    {
        _Month = Month;
    }
    //Property getter.
    short getMonth()
    {
        return _Month;

    }
    __declspec(property(get = getMonth, put = setMonth)) short Month;//set ,get value usinig '='

    //property setter.
    void setYear(short Year)
    {
        _Year = Year;
    }
    //Property getter.
    short getYear()
    {
        return _Year;

    }
    __declspec(property(get = getYear, put = setYear)) short Year;//set ,get value usinig '='

    void Print()
    {
        cout << DateToString(clsDate(_Day, _Month, _Year))<<endl;

    }

    static bool IsLeapYear(int Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
    }
    bool IsLeapYear()
    {
        return IsLeapYear(this->_Year);
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return IsLeapYear(Year) ? 366 : 365;
    }
    short NumberOfDaysInAYear()
    {
        return IsLeapYear(this->_Year) ? 366 : 365;
    }

    static short NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }
    short NumberOfHoursInAYear()
    {
        return  NumberOfHoursInAYear(this->_Day);
    }

    static  clsDate GetSystemTime()
    {
        //Get system date ..
        int Hour, Mintues, Seconds;
            
        time_t t = time(0);
        tm now;
        localtime_s(&now, &t);
        Hour = now.tm_hour;//system hour
        Mintues = now.tm_min;//system mins
        Seconds = now.tm_sec;//system sec
        return clsDate(Hour, Mintues, Seconds);

 
   }

    static clsDate GetSystemDate()
    {
        //Get system date ..
        int Day, Month, Year;
        time_t t = time(0);
        tm now;
        localtime_s(&now, &t);

        Day = now.tm_mday;
        Month = now.tm_mon + 1;
        Year = now.tm_year + 1900;
        return clsDate(Day, Month, Year);
    }

    static string DateTimeToString()
    {
        clsDate Date = clsDate::GetSystemDate();
        //In a Object Time has members(Day,month,year) represent(hour,mins,sec).. 
        clsDate Time = clsDate::GetSystemTime();
        return
            (
                to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year) +
                " - " + to_string(Time._Day) + ":" + to_string(Time._Month) + ":" + to_string(Time._Year)
             );
    }

    static short  NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }
    short  NumberOfMinutesInAYear()
    {
        return NumberOfMinutesInAYear(this->_Day);
    }

    static int NumberOfSecondsInAYear(short Year)
    {
        return NumberOfMinutesInAYear(Year) * 60;
    }
    int NumberOfSecondsInAYear()
    {
        return  NumberOfSecondsInAYear(this->_Day);
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month>12)
            return  0;
        if (Month == 2)
        {
            return  IsLeapYear(Year) ? 29 : 28;
        }
        short arr31Days[7] = { 1,3,5,7,8,10,12 };
        for (short i = 1; i <= 7; i++)
        {
            if (arr31Days[i - 1] == Month)
                return 31;
        }
        //if you reach here then its 30 days. 
        return  30;
    }
    short NumberOfDaysInAMonth()
    {
        return NumberOfDaysInAMonth(this->_Month, this->_Year);
    }

    static short NumberOfHoursInAMonth(short Month, short Year)
    {
        return NumberOfDaysInAMonth(Month, Year) *
            24;
    }
    short NumberOfHoursInAMonth()
    {
        return  NumberOfHoursInAMonth(_Month, _Year);
    }

    static int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return NumberOfHoursInAMonth(Month, Year) * 60;
    }
    int NumberOfMinutesInAMonth()
    {
        return  NumberOfMinutesInAMonth(_Month, _Year);
    }

    static int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return NumberOfMinutesInAMonth(Month, Year)
            * 60;
    }
    int NumberOfSecondsInAMonth()
    {
        return  NumberOfSecondsInAMonth(_Month, _Year);
    }

    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a, y, m;

        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;

        // Gregorian: 
        //0:sun, 1:Mon, 2:Tue...etc.  
        return (Day + y + (y / 4) -
            (y / 100) + (y / 400) + ((31 * m) /
                12)) % 7;
    }
    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder - 1];
    }
    string DayShortName()
    {
        return DayShortName(_Day);
    }

    static string MonthShortName(short MonthNumber)
    {
        string Months[12] =
        {
         "Jan", "Feb", "Mar",
         "Apr", "May", "Jun",
         "Jul", "Aug", "Sep",
         "Oct", "Nov", "Dec"
        };
        return (Months[MonthNumber - 1]);
    }
    string MonthShortName()
    {
        return  MonthShortName(_Month);
    }

    static void PrintMonthCalendar(short Month, short Year)
    {
        int NumberOfDays;

        // Index of the day from 0 to 6 
        int current = DayOfWeekOrder(0, Month, Year);

        NumberOfDays = NumberOfDaysInAMonth(Month, Year);

        // Print the current month name 
        printf("\n _______________%s__________________\n\n",
            MonthShortName(Month).c_str());

        // Print the columns 
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces 
        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
        printf("\n ____________________________________\n");
    }
    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Month, _Year);
    }

    void static  PrintYearCalendar(short Year)
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");

        for (short i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, Year);
        }
    }
    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }

    static short NumberOfDaysFromTheBeginingOfTheYear(clsDate Date)
    {
        short TotalDays = 0;

        for (int i = 1; i <= Date._Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, Date._Year);
        }
        TotalDays += Date._Day;

        return TotalDays;
    }
    short NumberOfDaysFromTheBeginingOfTheYear()
    {
        return  NumberOfDaysFromTheBeginingOfTheYear(*this);
    }

    static clsDate DateAddDays(short Days, clsDate Date)
    {
        short RemainingDays = Days +
            NumberOfDaysFromTheBeginingOfTheYear(Date);
        short MonthDays = 0;
        Date._Month = 1;
        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Date._Month, Date._Year);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date._Month++;
                if (Date._Month > 12)
                {
                    Date._Month = 1;
                    Date._Year++;
                }
            }
            else
            {
                Date._Day = RemainingDays;
                break;
            }
        }
        return Date;
    }
    void  DateAddDays(short Days)
    {
        *this = DateAddDays(Days, *this);//Update Current object ..
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return  (Date1._Year < Date2._Year) ? true :
            ((Date1._Year == Date2._Year) ?
                (Date1._Month < Date2._Month ? true :
                    (Date1._Month == Date2._Month ?
                        Date1._Day < Date2._Day : false))
                : false);
    }
    bool IsDate1BeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year == Date2._Year) ? (
            (
                Date1._Month == Date2._Month) ? ((Date1._Day ==
                    Date2._Day) ? true : false) : false) : false;
    }
    bool IsDate1EqualDate2(clsDate Date2)
    {
        return  IsDate1EqualDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));
    }
    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }
    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(_Month);
    }

    static clsDate IncreaseDateByOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date._Month))
            {
                Date._Month = 1;
                Date._Day = 1;
                Date._Year++;
            }
            else
            {
                Date._Day = 1;
                Date._Month++;
            }
        }
        else
        {
            Date._Day++;
        }
        return Date;
    }
    //update the current object
    void IncreaseDateByOneDay()
    {

        *this = IncreaseDateByOneDay(*this);
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days : Days;
    }
    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    static void SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate TempDate;

        TempDate._Year = Date1._Year;
        TempDate._Month = Date1._Month;
        TempDate._Day = Date1._Day;

        Date1._Year = Date2._Year;
        Date1._Month = Date2._Month;
        Date1._Day = Date2._Day;

        Date2._Year = TempDate._Year;
        Date2._Month = TempDate._Month;
        Date2._Day = TempDate._Day;

    }
    void SwapDates(clsDate& Date2)
    {
        SwapDates(*this, Date2);
    }

    static clsDate IncreaseDateByXDays(short Days, clsDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    void  IncreaseDateByXDays(short Days)
    {
        *this = IncreaseDateByXDays(Days, *this);
    }

    static clsDate IncreaseDateByOneWeek(clsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    void IncreaseDateByOneWeek()
    {
        *this = IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }
    void IncreaseDateByXWeeks(short Weeks)
    {
        *this = IncreaseDateByXWeeks(Weeks, *this);
    }

    static clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (Date._Month == 12)
        {
            Date._Month = 1;
            Date._Year++;
        }
        else
        {
            Date._Month++;
        }
        //last check day in date should not exceed max days in the current month 
       // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
            // be 28/2/2022 
        short NumberOfDaysInCurrentMonth =
            NumberOfDaysInAMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    void  IncreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXMonths(short Months, clsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }
    void IncreaseDateByXMonths(short Months)
    {
        *this = IncreaseDateByXMonths(Months, *this);
    }

    static clsDate IncreaseDateByOneYear(clsDate Date)
    {
        Date._Year++;
        return Date;
    }
    void IncreaseDateByOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByOneYear(short Years, clsDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    void IncreaseDateByOneYear(short Years)
    {
        *this = IncreaseDateByOneYear(Years, *this);
    }

    static clsDate IncreaseDateByXYears(short Years, clsDate Date)
    {
        Date._Year += Years;
        return Date;
    }
    void IncreaseDateByXYearsFaster(short Years)
    {
        *this = IncreaseDateByXYears(Years, *this);
    }

    static clsDate IncreaseDateByOneDecade(clsDate Date)
    {
        //Period of 10 years 
        Date._Year += 10;
        return Date;
    }
    void IncreaseDateByOneDecade()
    {
        *this = IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecades(short Decade, clsDate Date)
    {
        //This way is fastter..
        Date._Year += 10 * Decade;
        return Date;
    }
    void IncreaseDateByXDecades(short& Decade)
    {
        IncreaseDateByXDecades(Decade, *this);
    }

    static clsDate IncreaseDateByOneCentery(clsDate& Date)
    {
        Date._Year += 100;
        return Date;
    }
    void IncreaseDateByOneCentery()
    {
        IncreaseDateByOneCentery(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate& Date)
    {
        //Period of 1000 years 
        Date._Year += 1000;
        return Date;
    }
    void IncreaseDateByOneMillennium()
    {
        IncreaseDateByOneMillennium(*this);
    }

    static clsDate DecreaseDateByOneDay(clsDate& Date)
    {

        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Day = 31;
                Date._Year--;
            }
            else
            {
                Date._Month--;
                Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
            }
        }
        else
        {
            Date._Day--;
        }
        return Date;
    }
    void DecreaseDateByOneDay()
    {
        DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    void DecreaseDateByXDays(short Days)
    {
        DecreaseDateByXDays(Days, *this);
    }

    static clsDate DecreaseDateByOneWeek(clsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    void DecreaseDateByOneWeek()
    {
        *this = DecreaseDateByOneWeek(*this);
    }

    clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }
    void DecreaseDateByXWeeks(short Weeks)
    {
        *this = DecreaseDateByXWeeks(Weeks, *this);
    }

    static clsDate DecreaseDateByOneMonth(clsDate Date)
    {
        if (Date._Month == 1)
        {
            Date._Month = 12;
            Date._Year--;
        }
        else
        {
            Date._Month--;
        }
        short NumberOfDaysInCurrentMonth =
            NumberOfDaysInAMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    void DecreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }
    void DecreaseDateByXMonths(short Month)
    {
        *this = IncreaseDateByXMonths(Month, *this);
    }

    static clsDate DecreaseDateByOneYear(clsDate Date)
    {
        Date._Year--;
        return Date;
    }
    void DecreaseDateByOneYear()
    {
        *this = DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(short Years, clsDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }
    void DecreaseDateByXYears(short Years)
    {
        *this = DecreaseDateByXYears(Years, *this);

    }

    static short DayOfWeekOrder(clsDate& Date)
    {
        return DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
    }
    static bool IsEndOfWeek(clsDate Date)
    {
        return DayOfWeekOrder(Date) == 6;
    }
    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        // Weekends are Fri and Sat 
        short DayIndex = DayOfWeekOrder(Date);
        return (DayIndex == 6 || DayIndex == 5);
    }
    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        // Weekends are Sun , Mon , Tue , Wed and Thur 

        /*
        * this another method....

        short DayIndex = DayOfWeekOrder(Date);
        return ( DayIndex >= 0 && DayIndex <= 4 );
        */

        return !IsWeekEnd(Date);
    }
    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date);
    }
    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(clsDate Date)
    {


        /*clsDate EndOfMonthDate;
        EndOfMonthDate._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
        EndOfMonthDate._Month = Date._Month;
        EndOfMonthDate._Year = Date._Year;
        return GetDifferenceInDays(Date, EndOfMonthDate, true);*/

        //This the method is fastter...
        short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
        return (DaysInMonth - Date._Day) + 1;
    }
    short DaysUntilTheEndOfMonth()
    {
        return  DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(clsDate Date)
    {
        clsDate EndOfMonthDate;

        EndOfMonthDate._Day = 31;
        EndOfMonthDate._Month = 12;
        EndOfMonthDate._Year = Date._Year;

        return GetDifferenceInDays(Date, EndOfMonthDate, true);
    }
    short DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(*this);
    }
    static string DateToString(clsDate Date)
    {
        return  to_string(Date._Day) + "/" +
            to_string(Date._Month) + "/" +
            to_string(Date._Year);
    }
   static  string TimeToString(clsDate Time)
    {
        return to_string(Time._Day) + ":" +//Hour
               to_string(Time._Month) + ":" +//Mins
               to_string(Time._Year);//Sec

    }

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        short DaysCount = 0;

        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                DaysCount++;
            DateFrom = IncreaseDateByOneDay(DateFrom);

        }

        return DaysCount;
    }

    static clsDate CalculateVacationReturnDate(clsDate& DateFrom, short VacationDays)
    {

        short WeekEndCounter = 0;

        //in case the data  is weekend keep adding one day util you reach business day
            //we get rid of all weekends before the first business day 
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        //    //here we increase the vacation dates to add all weekends to it. 

        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {

            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        //in case the return date is week end keep adding one day util you reach  business day
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DateFrom;
    }

    static bool IsDate1AfterDate2(clsDate& Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2)
            && !IsDate1EqualDate2(Date1, Date2));
    }
    bool IsDate1AfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    static bool IsValidDate(clsDate& Date)
    {
        ///*if (Date._Day < 1 || Date._Day > 31)
        //    return false;

        //if (Date._Month < 1 || Date._Month>12)
        //    return false;
        //return true;


        //if (Date._Month == 2)
        //{
        //    if
        //        (IsLeapYear(Date._Year))
        //    {
        //        if (Date._Day > 29)
        //            return false;
        //    }
        //    else
        //    {
        //        if (Date._Day > 28)
        //            return false;
        //    }
        //}*/*/

        if (Date._Month > 12)
            return false;

        short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);

        if (Date._Day > DaysInMonth || Date._Day < 1)
            return false;

        return true;

    }

    bool IsValidDate()
    {
        return IsValidDate(*this);
    }

    clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;

        Date.Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Month, Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Month++;
            }
            else
            {
                Day = RemainingDays;
                break;
            }
        }
        return Date;

    }
    static enum enDateCompare {
        Before = -1, Equal = 0, After
        = 1
    };
    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;
        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;
        /* if (IsDate1AfterDate2(Date1,Date2))
        return enDateCompare::After;*/

        //this is faster 
        return enDateCompare::After;
    }



};


