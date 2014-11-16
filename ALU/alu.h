// alu.h
#include "systemc.h"
#include <stdint.h>

SC_MODULE(alu) {
  //clock input
  sc_in<uint32_t> a, b, imm_val;
  //test_bench input
  sc_in<bool> reset, is_imm;
  sc_in<int> alu_op;
  //output
  sc_out<uint32_t> result;
  sc_out<bool> zero;

  void do_alu();
  uint32_t local_result, oprand;
  int local_op;
  
  SC_CTOR(alu) {
    SC_METHOD(do_alu);
    sensitive << reset << alu_op << is_imm << imm_val << a << b;
    result.initialize(0);
    zero.initialize(0);
    local_result=0;
  }
};
