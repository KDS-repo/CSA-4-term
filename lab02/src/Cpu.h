
#ifndef RISCV_SIM_CPU_H
#define RISCV_SIM_CPU_H

#include "Memory.h"
#include "Decoder.h"
#include "RegisterFile.h"
#include "CsrFile.h"
#include "Executor.h"

class Cpu
{
public:
    Cpu(Memory& mem)
        : _mem(mem)
    {

    }

    void ProcessInstruction()
    {
        Word _word = _mem.Request(_ip);

        _instruction = _decoder.Decode(_word);

        _csrf.Read(_instruction);
        _rf.Read(_instruction);

        _exe.Execute(_instruction, _ip);

        _mem.Request(_instruction);

        _rf.Write(_instruction);
        _csrf.Write(_instruction);

        _csrf.InstructionExecuted();
        _ip = _instruction->_nextIp;
    }

    void Reset(Word ip)
    {
        _csrf.Reset();
        _ip = ip;
    }

    std::optional<CpuToHostData> GetMessage()
    {
        return _csrf.GetMessage();
    }

private:
    Reg32 _ip;
    Decoder _decoder;
    RegisterFile _rf;
    CsrFile _csrf;
    Executor _exe;
    Memory& _mem;
    InstructionPtr _instruction;
};


#endif //RISCV_SIM_CPU_H
