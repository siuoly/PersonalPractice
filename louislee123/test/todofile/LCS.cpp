#include<iostream>
#include<vector>
#include<stack>
//#define TEST2
using namespace std;
typedef vector<int> v;
typedef vector<char> vc;
typedef vector<vector<pair<int,int>>> vvp;
typedef stack<char> sc;

// arrow for record , lu: left up
enum dir{ left , up , lu};

// initial the s matrix size
void LCSinit( vector<vector< pair<int,int> >>& s , int m ,int n)
{
  s.resize(m);
  for(int i=0 ;  i<m ; i++)
    for(int j=0; j<n ; j++)
      s[i].resize(n);
}

// s: LCS solution ; r: LCS path ; a,b:sequence
void LCS(vvp& s, vc& a, vc& b){

  // initial s size(m,n)
  LCSinit(s, a.size()+1 , b.size()+1 );
  
  // initial matrix left col an up row 
  for(int i =0; i < a.size()+1;i++) s[i][0].first=0;
  for(int i =0; i < b.size()+1;i++) s[0][i].first=0;

  for(int i=1; i< a.size()+1 ; i++)
  {
    s[i][0].first = 0;
    for( int j=1 ; j<b.size()+1 ; j++)
    {
        // increase common subseq length
       if( a[i-1] == b[j-1])
       {  
        s[i][j].first = s[i-1][j-1].first+1 ;
        s[i][j].second = dir::lu; 
       }
       //  left > up
       else if(s[i][j-1].first > s[i-1][j].first){
        s[i][j].first = s[i][j-1].first ; 
        s[i][j].second = dir::left ; 
       } 
       // up >= left
       else{
        s[i][j].first = s[i-1][j].first ; 
        s[i][j].second = dir::up; 
       } 
       #ifdef TEST
       //cout <<"s[" << i << "][" << j << "]= " << s[i][j].first <<endl;
       //getchar();
       #endif
    }
  }
}

// get LCS string, s:LCS matrix , c: LCS string
void getLCS(vvp &s , vector<char>& c , vc source){
  sc r; // for push to string
  int row = s.size() , col = s[0].size();
  int i=row-1 ,j=col-1 ;
  
  // search from right bottom to left top
  while( i!=0 &&  j!=0)
  {
    #ifdef TEST2
      cout << "i:" << i <<" j:"<<j<< endl;
      getchar();
    #endif

    switch(s[i][j].second)
    {
      case dir::lu: 
        r.push(source[i-1]);  i--; j--;
        break;
      case dir::left :
        j--;
        break;
      case dir::up :
        i--;
        break;
    }
  }

  // stack reverse the order , get the LCS string
  while(!r.empty())
  { c.push_back( r.top() ) ; r.pop(); }
}


int main(){
  vc a ;
  vc b ;char ch;
  freopen("in" , "r" , stdin);
  while((ch = getchar())!='\n' )  a.push_back(ch);
  while((ch = getchar())!='\n' )  b.push_back(ch);
    
  vvp s; vc str;
  LCS(s,a,b); 
  getLCS(s ,str ,a);

  for(char ch :str) cout << ch<<' ';
  cout << endl;

}
