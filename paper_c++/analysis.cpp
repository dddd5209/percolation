#include "function.cpp"




int main(int argc, char const *argv[]) {
  int l=10;
  ifstream readFile[LOOP];
  string line;
  int a;
  char c;
  int sum_a=0;

  for (loop_n=0;loop_n<LOOP;loop_n++){

    sprintf(file_name,"data_L_%d/data_L_%d_%d.txt",l,l,loop_n);
    readFile[loop_n].open(file_name);

}

for (int i = 0; i < 100; i++) {

sum_a=0;

  for (loop_n=0;loop_n<LOOP;loop_n++){

    getline(readFile[loop_n],line);
    istringstream iss(line);
    iss>>a>>c;
    sum_a+=a;
  }

cout<<sum_a<<endl;

}

  /*
  while (getline(readFile,line)){
    istringstream iss(line);
    iss>>cluster>>c>>weight>>c>>p_per;
    occ_N += (double)cluster*(double)weight;
    if ( pass_count<loop_n ) {
      p_inf[p_c]+=(double)cluster*(double)weight/(double)size/(double)size;
      pass_count+=weight;
      if (pass_count>loop_n){
        p_inf[p_c]-=(double)cluster*((double)pass_count-(double)loop_n )
        /(double)size/(double)size;
        sum_square += pow((double)cluster,2.)*
        ((double)pass_count-(double)loop_n);
      }
    continue;// delete occupied by infinite cluster
    }
  sum_square += pow((double)cluster,2.)*(double)weight;
  }
*/

  return 0;
}
