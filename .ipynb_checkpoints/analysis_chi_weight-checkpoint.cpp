#include "percolation_function.cpp"

int main(){
	size = 500;
	loop_n = 100;
	char data_char[10];
	int data_int;
	double occ_N;
	double sum_square;
	double chi[1000];
	double chi_variance[1000];
	int pass_count;
	double p_inf[1000];
	char save_i[10];
	char save_chi[10];
	char save_p[10];	
	char save_p_percolation[10];
	char save_error[10];
	int cluster;
	int weight;
	double p_per;
	double p_percolation[1000];
	char c;
	
	string line;	
	for (int p_c=550;p_c<650;p_c++){
		p=(double)p_c/1000.;		
		sprintf(file_name,"data_500_100/p_%.3f_size_%d.txt",p,size);		
		ifstream readFile(file_name);
		occ_N = 0;
		sum_square = 0;
		p_inf[p_c] = 0;
		pass_count = 0;
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
		p_percolation[p_c]=p_per;
	    p_inf[p_c] /=(double)loop_n;
	    chi[p_c] = sum_square
		/(double)loop_n/(occ_N/(double)loop_n-p_inf[p_c]*(double)size*(double)size);
	}
	ofstream writeFile;
	sprintf(file_name,"result/n_%d_delta_p_%.3f_size_%d.txt",loop_n,0.001,size);
	writeFile.open(file_name);
	for (int i=550;i<650;i++){
		cout<< chi[i] <<"  "<< p_inf[i] <<" "<< p_percolation[i] <<endl;   
		sprintf(save_i,"%.3f",(double)i/1000.);
		sprintf(save_chi,"%.8f",chi[i]);
		sprintf(save_p,"%.8f",p_inf[i]);		
		sprintf(save_p_percolation,"%.3f",p_percolation[i]);		
		
		writeFile.write(save_i,5);
		writeFile.write(" ",1);	
		writeFile.write(save_chi,9);
		writeFile.write(" ",1);
		writeFile.write(save_p,9);	
		writeFile.write(" ",1);
		writeFile.write(save_p_percolation,4);	
		writeFile.write(ch_line,1);	
					
	}
	writeFile.close();		
	return 0;		
}
