#include <iostream>
#include <cstdlib>
#include <queue>
#include <random>


using namespace std;

int check_top;
int p_c;
#ifndef L
#define L 1000
#endif

#ifndef EMPTY
#define EMPTY (-N-1)
#endif

#ifndef N
#define N (L*L)
#endif

int ptr[N];
int nn[N][4];
int order[N];

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<double> drand(0, 1);

int findroot(int i){
  if(ptr[i]<0) return i;
  return findroot(ptr[i]);
}

void boundaries(){
  //neighbor define
  int i;
  for(i=0;i<N;i++){
    nn[i][0] = (i+1)%N;
    nn[i][1] = (i+N+1)%N;
    nn[i][2] = (i+L)%N;
    nn[i][3] = (i+N-L)%N;
    if (i%L==0) nn[i][1]=i+L-1;
    if ((i+1)%L==0) nn[i][0]=i-L+1;
  }
}

void permutation(){

  int i,j;
  int temp;
  for (i = 0; i < N; i++) order[i] = i;
  for (i = 0; i < N; i++){
    j = i+(N-i)*drand(gen);
    temp = order[i];
    order[i] = order[j];
    order[j] = temp ;
  }
}

void percolate(){
  int i,j;
  int s1,s2;
  int r1,r2;
  int big = 0;
  for (i = 0; i < N; i++) ptr[i]=EMPTY;
  for (i = 0; i < N; i++) {
    r1 = s1 = order[i];
    ptr[s1] = -1;
    for (j = 0; j < 4; j++) {
      s2 = nn[s1][j];
      if(ptr[s2]!=EMPTY){
        r2=findroot(s2);
        if(r2!=r1){
          if(ptr[r1]>ptr[r2]){
            ptr[r2]+=ptr[r1];
            ptr[r1] = r2;
            r1=r2;
          }
          else {
            ptr[r1] += ptr[r2];
            ptr[r2] = r1;
          }
        if (-ptr[r1]>big) big = -ptr[r1];
        }
      }
    }
    cout<<i+1<<" "<<big<<endl;
  }
}
