#ifndef RISCV_SIM_EXECUTOR_H
#define RISCV_SIM_EXECUTOR_H

#include "Instruction.h"

class Executor
{
public:
    void Execute(InstructionPtr& instr, Word ip)
    {
        /* YOUR CODE HERE */
        //Word result = 0;
        if (instr->_src1.has_value() && instr->_imm.has_value())
        {
            aluFunc(instr, instr->_imm.value());
        }else if (instr->_src1.has_value() && instr->_src2.has_value())
        {
            aluFunc(instr, instr->_src2Val);
        }
        /*
   	    switch(instr->_aluFunc)
   	    {
   	        case AluFunc::Add: result = instr->_src1Val + secondOperand; break;
   	        case AluFunc::Sub: result = instr->_src1Val + (~secondOperand + 1); break;
   	        case AluFunc::And: result = instr->_src1Val & secondOperand; break;
   	        case AluFunc::Or: result = instr->_src1Val | secondOperand; break;
   	        case AluFunc::Xor: result = instr->_src1Val ^ secondOperand; break;
   	        case AluFunc::Slt: result = signedLessThan(instr->_src1Val, secondOperand);
   	        case AluFunc::Sltu: result = instr->_src1Val < secondOperand; break;
   	        case AluFunc::Sll: result = instr->_src1Val << (secondOperand % 32); break;
            case AluFunc::Srl: result = instr->_src1Val >> (secondOperand % 32); break;
            case AluFunc::Sra: result = instr->_src1Val >> (secondOperand % 32); break;
        }
        if(instr->_type == IType::Ld || instr->_type == IType::St)
        {
        	instr->_addr = result;
        }*/
        if(instr->_type == IType::Ld || instr->_type == IType::St)
        {
        	instr->_addr = instr->_data;
        }
        
        //ITYPE CHECK
        //instr->_data = result;
        instr->_data = (instr->_type == IType::Csrr)? instr->_csrVal : instr->_data;
        instr->_data = (instr->_type == IType::Csrw)? instr->_src1Val : instr->_data;
        instr->_data = (instr->_type == IType::St)? instr->_src2Val : instr->_data;
        instr->_data = (instr->_type == IType::J)? ip + 4 : instr->_data;
        instr->_data = (instr->_type == IType::Jr)? ip + 4 : instr->_data;
        instr->_data = (instr->_type == IType::Auipc)? ip + instr->_imm.value() : instr->_data;
        
        //BRANCH CHECK
        bool condition = false;
        switch(instr->_brFunc)
        {
			case BrFunc::Eq: condition = instr->_src1Val == instr->_src2Val; break;
			case BrFunc::Neq: condition = instr->_src1Val != instr->_src2Val; break;
			case BrFunc::Lt: condition = signedLessThan(instr->_src1Val, instr->_src2Val); break;
			case BrFunc::Ltu: condition = instr->_src1Val < instr->_src2Val; break;
			case BrFunc::Ge: condition = !signedLessThan(instr->_src1Val, instr->_src2Val); break;
			case BrFunc::Geu: condition = !(instr->_src1Val < instr->_src2Val); break;
			case BrFunc::AT: condition = true; break;
			case BrFunc::NT: condition = false; break;
        }
        instr->_nextIp = ip + 4;
        if(condition)
        {
        	instr->_nextIp = (instr->_type == IType::Br)? ip + instr->_imm.value() : instr->_nextIp;
        	instr->_nextIp = (instr->_type == IType::J)? ip + instr->_imm.value() : instr->_nextIp;
        	instr->_nextIp = (instr->_type == IType::Jr)? instr->_src1Val + instr->_imm.value() : instr->_nextIp;
        }
    }

private:
    static bool checkIsNegative(Word w){
        return (w & (1u << 31u)) != 0;
    }

    static Word twosComplementAbs(Word w){
        if(checkIsNegative(w)){
            return ~w + 1;
        }
        return w;
    }
    
    static bool signedLessThan(Word fi, Word sec)
    {
        if(checkIsNegative(fi) && !checkIsNegative(sec)){
            return true;
        }
        if(!checkIsNegative(fi) && checkIsNegative(sec)){
            return false;
        }
        if(!checkIsNegative(fi) && !checkIsNegative(sec)){
            return fi < sec;
        }
        if(checkIsNegative(fi) && checkIsNegative(sec)){
            Word absFi = twosComplementAbs(fi);
            Word absSec = twosComplementAbs(sec);
            return absFi > absSec;
        }
    }
    
    static void aluFunc(InstructionPtr& instr, Word secondOperand) {
        switch (instr->_aluFunc) {
            case AluFunc::Add:
                instr->_data = instr->_src1Val + secondOperand;
                break;
            case AluFunc::Sub:
                instr->_data = instr->_src1Val + (~secondOperand + 1);
                break;
            case AluFunc::And:
                instr->_data = instr->_src1Val & secondOperand;
                break;
            case AluFunc::Or:
                instr->_data = instr->_src1Val | secondOperand;
                break;
            case AluFunc::Xor:
                instr->_data = instr->_src1Val ^ secondOperand;
                break;
            case AluFunc::Slt:
                instr->_data = signedLessThan(instr->_src1Val, secondOperand);
                break;
            case AluFunc::Sltu:
                instr->_data = instr->_src1Val < secondOperand;
                break;
            case AluFunc::Sll:
                instr->_data = instr->_src1Val << (secondOperand % 32);
                break;
            case AluFunc::Srl:
                instr->_data = instr->_src1Val >> (secondOperand % 32);
                break;
            case AluFunc::Sra:
                if (checkIsNegative(instr->_src1Val)) {
                    Word unsignedShift = instr->_src1Val >> (secondOperand % 32);
                    Word addedBits = (1u << 31u) - (1u << (31 - secondOperand % 32));
                    instr->_data = unsignedShift | addedBits | (1u << 31u);
                } else
                    instr->_data = instr->_src1Val >> (secondOperand % 32);
                break;
        }
    }
    /* YOUR CODE HERE */

};

#endif // RISCV_SIM_EXECUTOR_H
