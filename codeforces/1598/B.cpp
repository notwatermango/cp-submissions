/*
! expected no found yes
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    int arr[n][5];
    
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        cin >> arr[i][j];
      }
    }
    bool couted = false;

    for (int i = 0; i < 4; i++)
    {
      for (int j = i + 1; j < 5; j++)
      {
        int l,r,both;
        l = r = both = 0;
        for (int k = 0; k < n; k++)
        {
          if(arr[k][i] && arr[k][j]) {
            both++;
          } else {
            if(arr[k][i]){
              l++;
            } 
            if(arr[k][j]) {
              r++;
            } 
          }
        }

        // cout << i <<' ' <<j<<"\n" << l << ' ' << r << ' ' << both <<'\n';
        int minn = min(l,r);
        int maxx = max(l,r);

        int need1 = minn < n/2? abs(minn - n/2):0;
        
        minn += both >= need1? both:0;
        both -= both >= need1? need1:0;
        maxx += both;
        // cout <<"NEED "<<need1<<'\n';
        // cout<<minn << ' '<<maxx<<'\n';
        if(minn >= n/2 && maxx >= n/2){
          cout << "YES\n";
          couted = true;
          break;
        }
      }
      if(couted) break;
    }
    if(couted) continue;
    cout << "NO\n";
    

    
    
    
  }
  
  return 0;
}