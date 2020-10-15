// link :: https://www.spoj.com/problems/BISHOPS/
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std; 
 
 
int1024_t boost_sub(int1024_t A, long long B) 
{ 
    int1024_t ans = (int1024_t) A - B; 
    return ans; 
}
 
int1024_t boost_mult(int1024_t A, long long B) 
{ 
    int1024_t ans = (int1024_t) A * B; 
    return ans; 
}
int main() 
{  
    int1024_t temp;
    int i;
    string str;
    while(cin>>temp){
//    	if(str.length() == 1 && str[0] == '1'){
//    		cout<<1<<endl;
//    	}
        if(temp == 1){
            cout<<1<<endl;
            continue;
        }
        if(temp == 0){
        	cout<<0<<endl;
        	continue;
        }
//    	temp = 0;
//    	for(i=0;i<str.length();i++){
//    		temp = boost_mult(temp,10) + (str[i] - '0');
//    	}
    	temp = boost_mult(temp,2);
    	temp = boost_sub(temp,2);
        cout<<temp<<endl;
    }
    return 0; 
} 
