#include<iostream>
#include<math.h>
#include<string>

using namespace std;

static string _ERROR_0_="incompatible dimensions";




struct MATRIX{
	int rows;
	int columns;
	int mat[20][20]; 
};

MATRIX m_multiply(MATRIX a,MATRIX b);
MATRIX m_input();

void err_kill(int flag);

int main(){
	MATRIX a=m_input();
	MATRIX b=m_input();
	MATRIX c=m_multiply(a,b);
	for(int i=0;i<c.rows;i++){
		for(int j=0;j<c.columns;j++){
			cout<<c.mat[i][j]<<'\t';
		}
		cout<<endl;
	}

	system("pause");
	return 0;
}

MATRIX m_multiply(MATRIX a,MATRIX b){
	MATRIX c;
	if(a.columns != b.rows){
		return;
	}
	else{
		for(int i=0;i<a.rows;i++){
			for(int j=0;j<b.columns;j++){
				for(int k=0;k<a.columns;k++){
				c.mat[i][j]=c.mat[i][j]+a.mat[i][k]*b.mat[k][j];
				}
				c.columns=j;
			}
			c.rows=i;
		}
		return c;
	}
}


MATRIX m_input(){
	MATRIX a;
	int i=0;
	int j=0;
	int flag=0;
	cout<<"Input rows"<<endl;
	cin>>a.rows;
	cout<<"Input columns"<<endl;
	cin>>a.columns;
	cout<<"You can jump to naxt row by ctrl+z"<<endl;
	while(i<a.rows){
		while(cin){
			cin>>a.mat[i][j];
			j++;
			
		}
		if(j<a.columns-1){
			for(int k=j;k<a.rows;k++){
				a.mat[i][k]=0;
			}
		}
		j=0;
		i++;
	}
	return a;
}
