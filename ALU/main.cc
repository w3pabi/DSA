#include "alu.h"
#include "test.h"

int sc_main(int artc, char** argv) {
  sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);

  sc_signal<int> alu_op;
  sc_signal<bool> is_imm, reset, zero;
  sc_signal<uint32_t> a, b, imm_val, result;
  
  sc_set_time_resolution(1, SC_NS);
  sc_set_default_time_unit(1, SC_NS);
  sc_clock CLK("clock", 10, SC_NS);

  alu ALU("ALU");
  ALU(a, b, imm_val, reset, is_imm, alu_op, result, zero);

  test TST("TST");
  TST(CLK, zero, result, a, b, imm_val, reset, is_imm, alu_op);
  
  sc_trace_file *tf = sc_create_vcd_trace_file("wave");
  ((vcd_trace_file*)tf)->sc_set_vcd_time_unit(-9);
  sc_trace(tf, CLK, "clock"); sc_trace(tf, reset, "reset");
  sc_trace(tf, alu_op, "alu_op"); sc_trace(tf, is_imm, "is_imm");
  sc_trace(tf, imm_val, "imm_val"); sc_trace(tf, a, "a");
  sc_trace(tf, b, "b"); sc_trace(tf, ALU.local_result, "ALU.local_result");

  sc_start(200, SC_NS);
  sc_close_vcd_trace_file(tf);

  return(0);
}
