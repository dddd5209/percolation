#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

int check_top;
int p_c;
int size = 1000; //default size
int loop_n = 100; //default loop time
bool lattice[10000][10000];
int connect[10000][10000];
bool check[10000][10000];
bool connect_ud[10000][10000];
bool connect_ud_t;
int connect_ud_t_n[1000];
int connect_n=0;
int x_vector[4] = {1,-1,0,0};
int y_vector[4] = {0,0,1,-1};
double p;
int x;
int y;
int weight;

queue<int> myq_x;
queue<int> myq_y;
priority_queue<int> myq_n;
char file_name[50];
char save_n[10];
char ch_line[2] = "\n";
char word_sp[2] = " ";


int digit(int n){
	int c=0;
	while (n>0){
		n/=10;
		c++;
	}
	return c;
}


void set_lattice(){
	for (int i=0;i<size;i++){
		for (int j=0;j<size;j++){
			if (p>(double)rand()/(double)RAND_MAX) lattice[i][j] = true;
			else lattice[i][j] = false;
		}
	}
}

void reset_function(){
	connect_ud_t=false;
	for (int i=0;i<size;i++){
		for (int j=0;j<size;j++){
			lattice[i][j] = false;
			check[i][j]=false;
			connect[i][j]=0;
			connect_ud[i][j]=false;
		}
		connect_ud[0][i]=true;
	}
}

void connect_check(){
	for (int i=0;i<size;i++){
		for (int j=0;j<size;j++){
			if(!lattice[i][j]) continue;
			if(check[i][j]) continue;
			myq_x.push(j);
			myq_y.push(i);
			connect_n=0;
			while(true){
				x=myq_x.front();
				y=myq_y.front();
				myq_x.pop();
				myq_y.pop();
				for (int n=0;n<4;n++){
					if (lattice[y+y_vector[n]][x+x_vector[n]]
					&&!check[y+y_vector[n]][x+x_vector[n]]
					&&y+y_vector[n]<size
					&&x+x_vector[n]<size
					&&y+y_vector[n]>=0
					&&x+x_vector[n]>=0
					) {
						myq_x.push(x+x_vector[n]);
						myq_y.push(y+y_vector[n]);
						connect_n++;
						connect[y+y_vector[n]][x+x_vector[n]]=connect_n;
						if (connect_ud[y][x]&&!connect_ud_t){
							connect_ud[y+y_vector[n]][x+x_vector[n]]=true;
							if(y+y_vector[n]==size-1) connect_ud_t = true;
						}
					}
					check[y+y_vector[n]][x+x_vector[n]]=true;
				}
				if(myq_x.empty()){
					if (connect_n==0) {
						connect_n=1;
						connect[y][x]=connect_n;
					}
					myq_n.push(connect_n);
					break;
				}
			}
		}
	}
}

void file_write(){
	ofstream writeFile;
	sprintf(file_name,"data/p_%.3f_size_%d.txt",p,size);
	writeFile.open(file_name);
	while (!myq_n.empty()){
		sprintf(save_n,"%d",myq_n.top());
		writeFile.write(save_n,digit(myq_n.top())+1);
		check_top=myq_n.top();
		writeFile.write(word_sp,0);
		myq_n.pop();
		weight = 1;
		while (myq_n.top()==check_top&&!myq_n.empty()) {
			myq_n.pop();
			weight++;
		}
		sprintf(save_n,"%d",weight);
		writeFile.write(save_n,digit(weight)+1);
		writeFile.write(word_sp,0);
		sprintf(save_n,"%.2f",(double)connect_ud_t_n[p_c]/(double)loop_n);
		writeFile.write(save_n,4);
		writeFile.write(ch_line,1);
	}
	writeFile.close();
}

