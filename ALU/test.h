//test.h
#include "systemc.h"
# include <stdint.h>

SC_MODULE(test) {
  //input
  sc_in<bool> clk, zero;
  sc_in<uint32_t> result;
  
  //output
  sc_out<uint32_t> a, b, imm_val;
  sc_out<bool> reset, is_imm;
  sc_out<int> alu_op;

  void do_test();
  int local_count;

  SC_CTOR(test) {
    SC_CTHREAD(do_test, clk.pos());
    reset.initialize(0);
    a.initialize(0);
    b.initialize(0);
    imm_val.initialize(0);
    is_imm.initialize(0);
    alu_op.initialize(0);
  }
};
