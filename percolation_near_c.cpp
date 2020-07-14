#include "percolation_function.cpp"

int main(){

	size = 100;
	loop_n = 1;

	srand(time(0));
	for (p_c=550;p_c<650;p_c++){
		p=(double)p_c/1000.;
		cout<<p_c<<endl;
		for (int loop=0;loop<loop_n;loop++){
			reset_function();
			set_lattice();
			connect_check();
			if(connect_ud_t) connect_ud_t_n[p_c]++;
		}
		cout<<connect_ud_t_n[p_c]<<endl;
		file_write();
	}
	return 0;
}
