// Roman-Integer by AdanSendo
#include<iostream>
#include<string>

class Num
{
		std::vector<int>digits;
public:	
    Num(std::string n)
		{
        int value=0;
				for(auto& i:n)
				{
					  switch(i)
			      {
              case 'I': value=1; break;
              case 'V': value=5; break;
              case 'X': value=10; break;
              case 'L': value=50; break;
              case 'C': value=100; break;
              case 'D': value=500; break;
              case 'M': value=10000; break;
			      }
          digits.push_back(value);
		    }
    }
    
    bool valid()
    {
      int count[7]={0,0,0,0,0,0,0};
      for(auto&i : digits)
      {
          switch(i)
			      {
              case 1: count[0]++; break;
              case 5: count[1]++; break;
              case 10: count[2]++; break;
              case 50: count[3]++; break;
              case 100: count[4]++; break;
              case 500: count[5]++; break;
              case 1000: count[6]++; break;
			      }
      }
      if(count[0]>3 || count[2]>2 || count[4]> 3 || count[6] > 3)return false;
      if(count[1]>1 || count[3]>1 ||count[5]>1)return false;
      return true;
    }
    int convert()
    {
      int exit=0;
      bool skip=false;
      for(int i=digits.size()-1;i>=0;--i)
      {
          if(skip)skip=false;continue;
          if(i!=0)
          {
            if(digits[i]==digits[i-1]) exit+=digits[i];continue;
            if(digits[i]>digits[i-1]) exit+=digits[i]-digits[i-1]; skip=true; continue;
            if(digits[i]<digits[i-1]) exit+=digits[i]+digits[i-1]; skip=true; continue;
          }else
          {
            exit+=digits[i];
          }
      }
      return exit;
    }
};
int main()
{
	std::string input("");
	std::cout<<"Write a valid roman number\n";
	std::cin>>input;
	Num numero(input);
  
  if(numero.valid())
  {
    std::cout<<input<<" = "<<numero.convert();
  }else
  {
    std::cout<<"The number isn't valid!";
  }
  
	std::cin.get();
}
