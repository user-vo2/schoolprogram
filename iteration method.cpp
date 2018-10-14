#include <bits/stdc++.h>

using namespace std;
 
int main(){
	int n;
	cin>>n;
	vector < vector < double > > v(n);
	for (int i=0;i<n;i++){
		v[i].resize(n+1);
		for (int j=0;j<(n+1);j++){
			cin>>v[i][j];
			if (i==j){
				swap(v[i][j],v[i][0]);
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=1;j<(n+1);j++){
			v[i][j]/=v[i][0];
			v[i][j]=-v[i][j];
		}
		v[i][0]=0;
	}
	int cnt=0;
	bool success=false;
	vector <double> a(n,0);
	while (!success){
		success=true;
		for (int i=0;i<n;i++){
			for (int j=0;j<(n);j++){
				if (i==j){
					v[i][0]+=a[0]*v[i][j];
				}
				v[i][0]+=a[i]*v[i][j];
			}
			v[i][0]-=v[i][n];
			if (a[i]!=v[i][0]){
				success=false;
			}
		}
		cnt++;
		for (int i=0;i<n;i++){
			a[i]=v[i][0];
			v[i][0]=0;
		}
	}
	for(int i=0;i<n;i++){
		cout<<"root "<<i+1<<':'<<a[i]<<endl;
	}
	return 0;
}
