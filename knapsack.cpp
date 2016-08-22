#include<bits/stdc++.h>
using namespace std;
float x[100];
float w[100],p[100];
void knapsack(float m,int n){
    float U=m; int i;
    for(i=0;i<n;i++){
        if(w[i]>U) break;
        x[i]=1;
        U-=w[i];
    }
    if(i<n) x[i]=U/w[i];
}
int main(){
  int n; float m,a,b;
  cout<<"\nEnter the array size:\n";
  cin>>n;
  cout<<"\nEnter the profit and its weight:\n";
  for(int i=0;i<n;i++) cin>>p[i]>>w[i];
  cout<<"\nEnter the total weight:\n";
  cin>>m;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(p[i]/w[i]<p[j]/w[j]){
            a=p[j]; b=w[j];
            p[j]=p[i]; w[j]=w[i];
            p[i]=a; w[i]=b;
        }
    }

  }
  cout<<"\nSorted order :\n";
  for(int i=0;i<n;i++) cout<<w[i]<<" : "<<p[i]<<endl;
  knapsack(m,n);
  cout<<"\nFinal knapsack solution:\n";
  for(int i=0;i<n;i++) cout<<w[i]<<" : "<<x[i]<<endl;
 return 0;
}

