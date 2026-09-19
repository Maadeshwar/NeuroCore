// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsoc_tb__pch.h"

//============================================================
// Constructors

Vsoc_tb::Vsoc_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsoc_tb__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsoc_tb::Vsoc_tb(const char* _vcname__)
    : Vsoc_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsoc_tb::~Vsoc_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsoc_tb___024root___eval_debug_assertions(Vsoc_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vsoc_tb___024root___eval_static(Vsoc_tb___024root* vlSelf);
void Vsoc_tb___024root___eval_initial(Vsoc_tb___024root* vlSelf);
void Vsoc_tb___024root___eval_settle(Vsoc_tb___024root* vlSelf);
void Vsoc_tb___024root___eval(Vsoc_tb___024root* vlSelf);

void Vsoc_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsoc_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsoc_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsoc_tb___024root___eval_static(&(vlSymsp->TOP));
        Vsoc_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vsoc_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsoc_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsoc_tb::eventsPending() { return false; }

uint64_t Vsoc_tb::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsoc_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsoc_tb___024root___eval_final(Vsoc_tb___024root* vlSelf);

VL_ATTR_COLD void Vsoc_tb::final() {
    Vsoc_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsoc_tb::hierName() const { return vlSymsp->name(); }
const char* Vsoc_tb::modelName() const { return "Vsoc_tb"; }
unsigned Vsoc_tb::threads() const { return 1; }
void Vsoc_tb::prepareClone() const { contextp()->prepareClone(); }
void Vsoc_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
