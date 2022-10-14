#include <iostream>
#include <string>
#include <regex>

class BetterString {        
  public:              
    std::string raw;
    BetterString(std::string x) { // Constructor with parameters
      raw = x;
  
    }

    int length(){
      return raw.length();
    }

    char at(int index){
      return raw[index];
    }

    BetterString& operator = (const BetterString& a) {
      raw=a.raw;
      return *this;
    }

    std::string replace(std::string sub,std::string replace){
      return std::regex_replace(raw, std::regex(sub), replace);
    }

    std::string remove(int index){
      std::string b="";
      for(int i=0;i<raw.length();i++){
        if(i==index){
          continue;
        }
        b+=raw[i];
      }

      return b;
    }
    BetterString& operator+=(const BetterString& rhs){

      this->raw += rhs.raw;
      return *this;
    }



    int Count(const std::string& sub)
    {
        if (sub.length() == 0) return 0;
        int count = 0;
        for (size_t offset = raw.find(sub); offset != std::string::npos;
         offset = raw.find(sub, offset + sub.length()))
        {
            ++count;
        }
        return count;
    }
};

std::ostream& operator<<(std::ostream &strm, const BetterString &a) {
  return strm << a.raw;
}

bool operator==(const BetterString& lhs, const BetterString& rhs)
{
    return lhs.raw==rhs.raw;
}



template <typename T>
void print(T t)
{

  std::cout << t << std::flush;
}

template<typename T, typename... Args>
void print(T t, Args... args)
{
  std::cout << t << " ";
  print(args...) ;

}

