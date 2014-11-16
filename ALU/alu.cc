//alu.c
#include "alu.h"

void alu::do_alu() {
  if(reset == 0) {
     local_result = 0;
     zero = 0;
  } 
  else {
    if(is_imm) oprand = imm_val;
    else oprand = b;

    local_op = alu_op & 0xF;
    switch (local_op) {
      case 0x0 :local_result = a & oprand;break;
      case 0x2 :local_result = a - oprand;break;
      case 0x4 :local_result = a + oprand;break;
      case 0xc : local_result = a | oprand; break;
      default :
        local_result = 0; 
        cout << "error: don't calculate alu" <<endl;
        break;
    }
  }
  cout << "["<<sc_simulation_time() << "]" << (unsigned short)local_result << endl;
  result.write(local_result);
}
