//test.c
#include "test.h"
#include <stdlib.h>

void test::do_test(){
  wait(3);
  reset.write(1);
  wait(3);
  while(true) {  
    a.write(15);
    b.write(8);
    imm_val.write(3);
    local_count=rand()%2;
    if(local_count) is_imm.write(1);
    else is_imm.write(0);
    local_count=rand()%4;
    switch (local_count) {
      case 0: alu_op.write(0x0); break;
      case 1: alu_op.write(0x2); break;
      case 2: alu_op.write(0x4); break;
      case 3: alu_op.write(0xc); break;
    };
    wait(2);
  }
}
