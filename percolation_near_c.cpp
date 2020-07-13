#include "percolation_function.cpp"

int main(){

	size = 1000;
	loop_n = 100;

	srand(time(0));					
	int check_top;
	for (int p_c=550;p_c<650;p_c++){
		p=(double)p_c/1000.;				
		cout<<p_c<<endl;
		ofstream writeFile;
		sprintf(file_name,"data_1k_100/p_%.3f_size_%d.txt",p,size);
		writeFile.open(file_name);		
		for (int loop=0;loop<loop_n;loop++){
			reset_function();
			set_lattice();
			connect_check();					
			if(connect_ud_t) connect_ud_t_n[p_c]++;	 
		}		
		cout<<connect_ud_t_n[p_c]<<endl;
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
	return 0;		
}
