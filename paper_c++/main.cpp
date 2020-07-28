#include "function.cpp"

int main(int argc, char const *argv[]) {

  for (loop_n=0;loop_n<LOOP;loop_n++){

    boundaries();
    permutation();
    percolate();

  }

return 0;
}
