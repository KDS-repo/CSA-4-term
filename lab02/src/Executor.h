
#ifndef RISCV_SIM_EXECUTOR_H
#define RISCV_SIM_EXECUTOR_H

#include "Instruction.h"

class Executor
{
public:
    void Execute(InstructionPtr& instr, Word ip)
    {
        /* YOUR CODE HERE */
        switch(instr._aluFunc)
        {
            case AluFunc::Add: instr._data = _src1
            case AluFunc::Sub: instr._data = 
            case AluFunc::And: instr._data = 
            case AluFunc::Or: instr._data = 
            case AluFunc::Xor: instr._data = 
            case AluFunc::Slt: instr._data = 
            case AluFunc::Sltu: instr._data = 
            case AluFunc::Sll: instr._data = 
            case AluFunc::Srl: instr._data = 
            case AluFunc::Sra: instr._data = 
        }
        instr._addr = 
        instr._nextIp
    }

private:
    /* YOUR CODE HERE */

};

#endif // RISCV_SIM_EXECUTOR_H
