#ifndef __FUCKSCREEN_H__
#define __FUCKSCREEN_H__

#include <iostream>
#include <vector>


class FuckScreen;

class FuckWindows_mgr
{

public:

    using ScreenIndex = std::vector<FuckScreen>::size_type;
    void Clear(ScreenIndex);

private:
    std::vector<FuckScreen> fuckscreen;//{FuckScreen(100, 100, ' ')}
};


class FuckScreen
{
    
public:
    using fuck = std::string::size_type;
    FuckScreen() = default;
    FuckScreen(fuck width_, fuck height_):
           width(width_),height(height_),contents(width_*height_, ' '){}
    FuckScreen(fuck width_, fuck height_, char c):
           width(width_),height(height_),contents(width_*height_,c){}
    char GetCursorContents() const; 
    char GetCursorContents(fuck line_, fuck rank_) const; 
    FuckScreen &Move(fuck line_, fuck rank_);        
    FuckScreen &SetContents(char c);
    FuckScreen &SetContents(fuck line_, fuck rank_, char c);
    FuckScreen &Display(std::ostream &os);
    const FuckScreen &Display(std::ostream &os) const;

private:
    fuck cursor;
    fuck width, height;
    std::string contents;

    void Do_Display(std::ostream &os) const
        {   
            for(int i =0,j = 1; i<(width*height); ++j)
            {   
                os<<contents[i++];
                if(j == width )
                {
                    os<<"\n";
                    j=0;
                }
            }
        }

};

inline char FuckScreen::GetCursorContents() const
    {
        return contents[cursor];
    }

inline char FuckScreen::GetCursorContents(fuck line_, fuck rank_) const
    {
        fuck arrange = line_ * width;

        return contents[arrange + rank_];  
    }

inline FuckScreen &FuckScreen::Move(fuck line_, fuck rank_)
    {
        fuck arrange = line_ * width;
        cursor = arrange + rank_;
        return *this;
    }

inline FuckScreen &FuckScreen::SetContents(char c)
    {
        contents[cursor] = c;
        return *this;
    }

inline FuckScreen &FuckScreen::SetContents(fuck line_, fuck rank_, char c)
    {
        contents[width * line_ + rank_] = c;
        return *this;
    }

inline    FuckScreen &FuckScreen::Display(std::ostream &os)
    {
        Do_Display(os); 
        
        return *this;
    }

inline    const FuckScreen &FuckScreen::Display(std::ostream &os) const
    {
        Do_Display(os); 
        
        return *this;

    }






class FuckAcount
{
public:
    void Calculate(){ amount += amount *interestRate; }
    static double rate_today() { return interestRate; }
    static void SetRate_Today(double &);

private:
    static  double interestRate ;
    static const int vecs = 9;
    static std::vector<double> vec;
    double amount;
};

void FuckAcount::SetRate_Today(double &rate_today_)
{
    interestRate = rate_today_;
}

double FuckAcount::interestRate = 9;
std::vector<double> FuckAcount::vec(10);

#endif