// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_tb.h for the primary calling header

#include "Vsoc_tb__pch.h"
#include "Vsoc_tb___024root.h"

VL_INLINE_OPT void Vsoc_tb___024root___nba_sequent__TOP__3(Vsoc_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_tb___024root___nba_sequent__TOP__3\n"); );
    Vsoc_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT____VdfgRegularize_ha81a4cf2_1_2) 
         & (7U == (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                   >> 0x1cU)))) {
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0U] 
            = vlSelfRef.soc_tb__DOT__dut__DOT__bus_wdata;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[1U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[2U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[3U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[4U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[5U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[6U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[7U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[8U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[9U] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xaU] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xbU] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xcU] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xdU] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xeU] = 0U;
        vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xfU] = 0U;
        vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0 
            = (0x3ffU & (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                         >> 4U));
        vlSelfRef.__VdlySet__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0 = 1U;
    }
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0U] 
        = (IData)((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                    [0x10U][1U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][0U]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[1U] 
        = (IData)(((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][1U])) 
                     << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                 [0x10U]
                                                 [0U]))) 
                   >> 0x20U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[2U] 
        = (IData)((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                    [0x10U][3U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][2U]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[3U] 
        = (IData)(((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][3U])) 
                     << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                 [0x10U]
                                                 [2U]))) 
                   >> 0x20U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[4U] 
        = (IData)((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                    [0x10U][5U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][4U]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[5U] 
        = (IData)(((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][5U])) 
                     << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                 [0x10U]
                                                 [4U]))) 
                   >> 0x20U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[6U] 
        = (IData)((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                    [0x10U][7U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][6U]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[7U] 
        = (IData)(((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][7U])) 
                     << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                 [0x10U]
                                                 [6U]))) 
                   >> 0x20U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[8U] 
        = (IData)((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                    [0x10U][9U])) << 0x20U) 
                   | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][8U]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[9U] 
        = (IData)(((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][9U])) 
                     << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                 [0x10U]
                                                 [8U]))) 
                   >> 0x20U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xaU] 
        = (IData)((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                    [0x10U][0xbU])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                [0x10U]
                                                [0xaU]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xbU] 
        = (IData)(((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][0xbU])) 
                     << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                 [0x10U]
                                                 [0xaU]))) 
                   >> 0x20U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xcU] 
        = (IData)((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                    [0x10U][0xdU])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                [0x10U]
                                                [0xcU]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xdU] 
        = (IData)(((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][0xdU])) 
                     << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                 [0x10U]
                                                 [0xcU]))) 
                   >> 0x20U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xeU] 
        = (IData)((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                    [0x10U][0xfU])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                [0x10U]
                                                [0xeU]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xfU] 
        = (IData)(((((QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                     [0x10U][0xfU])) 
                     << 0x20U) | (QData)((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__psum_wire
                                                 [0x10U]
                                                 [0xeU]))) 
                   >> 0x20U));
    if (vlSelfRef.rst_n) {
        if (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__bus_req) 
             & (1U == (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                       >> 0x1cU)))) {
            if ((1U & (~ (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__bus_we)))) {
                vlSelfRef.soc_tb__DOT__dut__DOT__dram_rdata_reg 
                    = vlSelfRef.soc_tb__DOT__dut__DOT__data_ram
                    [(0x3fffU & (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                                 >> 2U))];
            }
        }
        if ((((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__bus_req) 
              & (5U == (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                        >> 0x1cU))) & (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__bus_we))) {
            vlSelfRef.soc_tb__DOT__dut__DOT__pool_en 
                = (1U & (vlSelfRef.soc_tb__DOT__dut__DOT__bus_wdata 
                         >> 6U));
            vlSelfRef.soc_tb__DOT__dut__DOT__relu_en 
                = (1U & (vlSelfRef.soc_tb__DOT__dut__DOT__bus_wdata 
                         >> 5U));
            vlSelfRef.soc_tb__DOT__dut__DOT__quant_shift 
                = (0x1fU & vlSelfRef.soc_tb__DOT__dut__DOT__bus_wdata);
        }
    } else {
        vlSelfRef.soc_tb__DOT__dut__DOT__pool_en = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__relu_en = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__quant_shift = 0U;
    }
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__14__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xeU];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__13__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xdU];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__12__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xcU];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__11__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xbU];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__10__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0xaU];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__9__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[9U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__8__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[8U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__7__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[7U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__6__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[6U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__5__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[5U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__4__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[4U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__3__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[3U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__2__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[2U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__1__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[1U];
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_unskew_psum__DOT__unskew_row__BRA__0__KET____DOT__genblk1__DOT__delay_line[0U] 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__npu_psum_out[0U];
    if (vlSelfRef.__VdlySet__soc_tb__DOT__dut__DOT__data_ram__v0) {
        vlSelfRef.soc_tb__DOT__dut__DOT__data_ram[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v0] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__data_ram__v0;
    }
    if (vlSelfRef.__VdlySet__soc_tb__DOT__dut__DOT__data_ram__v1) {
        vlSelfRef.soc_tb__DOT__dut__DOT__data_ram[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v1] 
            = ((0xffffff00U & vlSelfRef.soc_tb__DOT__dut__DOT__data_ram
                [vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v1]) 
               | (IData)(vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__data_ram__v1));
    }
    if (vlSelfRef.__VdlySet__soc_tb__DOT__dut__DOT__data_ram__v2) {
        vlSelfRef.soc_tb__DOT__dut__DOT__data_ram[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v2] 
            = ((0xffff00ffU & vlSelfRef.soc_tb__DOT__dut__DOT__data_ram
                [vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v2]) 
               | ((IData)(vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__data_ram__v2) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__soc_tb__DOT__dut__DOT__data_ram__v3) {
        vlSelfRef.soc_tb__DOT__dut__DOT__data_ram[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v3] 
            = ((0xff00ffffU & vlSelfRef.soc_tb__DOT__dut__DOT__data_ram
                [vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v3]) 
               | ((IData)(vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__data_ram__v3) 
                  << 0x10U));
    }
    if (vlSelfRef.__VdlySet__soc_tb__DOT__dut__DOT__data_ram__v4) {
        vlSelfRef.soc_tb__DOT__dut__DOT__data_ram[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v4] 
            = ((0xffffffU & vlSelfRef.soc_tb__DOT__dut__DOT__data_ram
                [vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__data_ram__v4]) 
               | ((IData)(vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__data_ram__v4) 
                  << 0x18U));
    }
}

VL_INLINE_OPT void Vsoc_tb___024root___nba_comb__TOP__0(Vsoc_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_tb___024root___nba_comb__TOP__0\n"); );
    Vsoc_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__flush_en) {
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__1__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__2__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__3__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__4__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__5__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__6__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__7__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__8__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__9__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__10__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__11__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__12__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__13__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__14__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__15__KET____DOT__genblk1__DOT__delay_line[0U] = 0U;
    } else {
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__1__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[0U] 
                        >> 8U));
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__2__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[0U] 
                        >> 0x10U));
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__3__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[0U] 
               >> 0x18U);
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__4__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[1U]);
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__5__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[1U] 
                        >> 8U));
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__6__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[1U] 
                        >> 0x10U));
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__7__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[1U] 
               >> 0x18U);
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__8__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[2U]);
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__9__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[2U] 
                        >> 8U));
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__10__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[2U] 
                        >> 0x10U));
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__11__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[2U] 
               >> 0x18U);
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__12__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[3U]);
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__13__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[3U] 
                        >> 8U));
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__14__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[3U] 
                        >> 0x10U));
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__15__KET____DOT__genblk1__DOT__delay_line[0U] 
            = (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[3U] 
               >> 0x18U);
    }
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[0U] 
        = ((((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__3__KET____DOT__genblk1__DOT__dff__BRA__2__KET____DOT__q) 
             << 0x18U) | ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__2__KET____DOT__genblk1__DOT__dff__BRA__1__KET____DOT__q) 
                          << 0x10U)) | (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__1__KET____DOT__genblk1__DOT__dff__BRA__0__KET____DOT__q) 
                                         << 8U) | ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__flush_en)
                                                    ? 0U
                                                    : 
                                                   (0xffU 
                                                    & vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__ibuf_rd_data[0U]))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[1U] 
        = (IData)((((QData)((IData)(((((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__11__KET____DOT__genblk1__DOT__dff__BRA__10__KET____DOT__q) 
                                       << 0x18U) | 
                                      ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__10__KET____DOT__genblk1__DOT__dff__BRA__9__KET____DOT__q) 
                                       << 0x10U)) | 
                                     (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__9__KET____DOT__genblk1__DOT__dff__BRA__8__KET____DOT__q) 
                                       << 8U) | (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__8__KET____DOT__genblk1__DOT__dff__BRA__7__KET____DOT__q))))) 
                    << 0x20U) | (QData)((IData)(((((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__7__KET____DOT__genblk1__DOT__dff__BRA__6__KET____DOT__q) 
                                                   << 0x18U) 
                                                  | ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__6__KET____DOT__genblk1__DOT__dff__BRA__5__KET____DOT__q) 
                                                     << 0x10U)) 
                                                 | (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__5__KET____DOT__genblk1__DOT__dff__BRA__4__KET____DOT__q) 
                                                     << 8U) 
                                                    | (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__4__KET____DOT__genblk1__DOT__dff__BRA__3__KET____DOT__q)))))));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[2U] 
        = (IData)(((((QData)((IData)(((((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__11__KET____DOT__genblk1__DOT__dff__BRA__10__KET____DOT__q) 
                                        << 0x18U) | 
                                       ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__10__KET____DOT__genblk1__DOT__dff__BRA__9__KET____DOT__q) 
                                        << 0x10U)) 
                                      | (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__9__KET____DOT__genblk1__DOT__dff__BRA__8__KET____DOT__q) 
                                          << 8U) | (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__8__KET____DOT__genblk1__DOT__dff__BRA__7__KET____DOT__q))))) 
                     << 0x20U) | (QData)((IData)(((
                                                   ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__7__KET____DOT__genblk1__DOT__dff__BRA__6__KET____DOT__q) 
                                                    << 0x18U) 
                                                   | ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__6__KET____DOT__genblk1__DOT__dff__BRA__5__KET____DOT__q) 
                                                      << 0x10U)) 
                                                  | (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__5__KET____DOT__genblk1__DOT__dff__BRA__4__KET____DOT__q) 
                                                      << 8U) 
                                                     | (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__4__KET____DOT__genblk1__DOT__dff__BRA__3__KET____DOT__q)))))) 
                   >> 0x20U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[3U] 
        = ((((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__15__KET____DOT__genblk1__DOT__dff__BRA__14__KET____DOT__q) 
             << 0x18U) | ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__14__KET____DOT__genblk1__DOT__dff__BRA__13__KET____DOT__q) 
                          << 0x10U)) | (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__13__KET____DOT__genblk1__DOT__dff__BRA__12__KET____DOT__q) 
                                         << 8U) | (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_skew_act__DOT__skew_row__BRA__12__KET____DOT__genblk1__DOT__dff__BRA__11__KET____DOT__q)));
    vlSelfRef.soc_tb__DOT__dut__DOT__dma_rd_valid = 
        ((0U != (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__state)) 
         & (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__dram_rvalid_reg));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__obuf_write_en 
        = ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__pool_en)
            ? (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__pool_valid_out)
            : (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__act_valid_out));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[0U][0U] 
        = (0xffU & vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[0U]);
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[1U][0U] 
        = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[0U] 
                    >> 8U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[2U][0U] 
        = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[0U] 
                    >> 0x10U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[3U][0U] 
        = (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[0U] 
           >> 0x18U);
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[4U][0U] 
        = (0xffU & vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[1U]);
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[5U][0U] 
        = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[1U] 
                    >> 8U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[6U][0U] 
        = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[1U] 
                    >> 0x10U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[7U][0U] 
        = (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[1U] 
           >> 0x18U);
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[8U][0U] 
        = (0xffU & vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[2U]);
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[9U][0U] 
        = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[2U] 
                    >> 8U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[0xaU][0U] 
        = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[2U] 
                    >> 0x10U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[0xbU][0U] 
        = (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[2U] 
           >> 0x18U);
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[0xcU][0U] 
        = (0xffU & vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[3U]);
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[0xdU][0U] 
        = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[3U] 
                    >> 8U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[0xeU][0U] 
        = (0xffU & (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[3U] 
                    >> 0x10U));
    vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_array__DOT__act_wire[0xfU][0U] 
        = (vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__skewed_act[3U] 
           >> 0x18U);
    vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__next_state 
        = vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__state;
    if ((0U == (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__state))) {
        if (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__start) 
             & (0U < vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__transfer_len))) {
            vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__next_state = 1U;
        }
    } else if ((1U == (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__state))) {
        if (vlSelfRef.soc_tb__DOT__dut__DOT__dma_rd_valid) {
            vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__next_state = 2U;
        }
    } else if ((2U == (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__state))) {
        if (vlSelfRef.soc_tb__DOT__dut__DOT__dma_wr_req) {
            vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__next_state 
                = ((1U == vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__words_left)
                    ? 0U : 1U);
        }
    } else {
        vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__next_state = 0U;
    }
}

VL_INLINE_OPT void Vsoc_tb___024root___nba_sequent__TOP__4(Vsoc_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_tb___024root___nba_sequent__TOP__4\n"); );
    Vsoc_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0) {
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][0U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][1U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[1U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][2U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[2U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][3U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[3U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][4U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[4U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][5U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[5U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][6U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[6U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][7U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[7U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][8U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[8U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][9U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[9U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][0xaU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xaU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][0xbU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xbU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][0xcU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xcU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][0xdU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xdU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][0xeU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xeU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0][0xfU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v0[0xfU];
    }
    if (vlSelfRef.__VdlySet__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1) {
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][0U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[0U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][1U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[1U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][2U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[2U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][3U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[3U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][4U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[4U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][5U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[5U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][6U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[6U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][7U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[7U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][8U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[8U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][9U] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[9U];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][0xaU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[0xaU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][0xbU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[0xbU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][0xcU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[0xcU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][0xdU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[0xdU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][0xeU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[0xeU];
        vlSelfRef.soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem[vlSelfRef.__VdlyDim0__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1][0xfU] 
            = vlSelfRef.__VdlyVal__soc_tb__DOT__dut__DOT__i_accelerator__DOT__i_pbuf__DOT__pbuf_mem__v1[0xfU];
    }
    if ((0U != (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__state))) {
        vlSelfRef.soc_tb__DOT__dut__DOT__bus_wdata 
            = vlSelfRef.soc_tb__DOT__dut__DOT__dma_wr_data;
        vlSelfRef.soc_tb__DOT__dut__DOT__bus_we = vlSelfRef.soc_tb__DOT__dut__DOT__dma_wr_req;
        vlSelfRef.soc_tb__DOT__dut__DOT__bus_req = 
            ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__dma_rd_req) 
             | (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__dma_wr_req));
        vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr = 
            ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__dma_rd_req)
              ? vlSelfRef.soc_tb__DOT__dut__DOT__dma_rd_addr
              : vlSelfRef.soc_tb__DOT__dut__DOT__dma_wr_addr);
    } else {
        vlSelfRef.soc_tb__DOT__dut__DOT__bus_wdata 
            = vlSelfRef.soc_tb__DOT__dut__DOT__data_wdata;
        vlSelfRef.soc_tb__DOT__dut__DOT__bus_we = vlSelfRef.soc_tb__DOT__dut__DOT__data_we;
        vlSelfRef.soc_tb__DOT__dut__DOT__bus_req = vlSelfRef.soc_tb__DOT__dut__DOT__data_req;
        vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr = vlSelfRef.soc_tb__DOT__dut__DOT__data_addr;
    }
    vlSelfRef.soc_tb__DOT__dut__DOT____VdfgRegularize_ha81a4cf2_1_2 
        = ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__bus_req) 
           & (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__bus_we));
    vlSelfRef.soc_tb__DOT__dut__DOT____Vcellinp__i_spi__bus_req 
        = ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__bus_req) 
           & (8U == (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                     >> 0x1cU)));
}

VL_INLINE_OPT void Vsoc_tb___024root___nba_comb__TOP__1(Vsoc_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_tb___024root___nba_comb__TOP__1\n"); );
    Vsoc_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.soc_tb__DOT__dut__DOT__data_rvalid = 
        ((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__dma_cfg_req) 
         | (((IData)(vlSelfRef.soc_tb__DOT__dut__DOT__data_req) 
             & ((0U == (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__i_dma__DOT__state)) 
                & (1U == (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                          >> 0x1cU)))) ? (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__dram_rvalid_reg)
             : (IData)(vlSelfRef.soc_tb__DOT__dut__DOT__cpu_accel_rvalid_reg)));
    vlSelfRef.soc_tb__DOT__dut__DOT__data_rdata = (
                                                   (6U 
                                                    == 
                                                    (vlSelfRef.soc_tb__DOT__dut__DOT__data_addr 
                                                     >> 0x1cU))
                                                    ? vlSelfRef.soc_tb__DOT__dut__DOT__dma_cfg_rdata
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                                                      >> 0x1cU))
                                                     ? vlSelfRef.soc_tb__DOT__dut__DOT__dram_rdata_reg
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                                                       >> 0x1cU))
                                                      ? 
                                                     vlSelfRef.soc_tb__DOT__dut__DOT__obuf_rd_data[0U]
                                                      : 
                                                     ((8U 
                                                       == 
                                                       (vlSelfRef.soc_tb__DOT__dut__DOT__bus_addr 
                                                        >> 0x1cU))
                                                       ? vlSelfRef.soc_tb__DOT__dut__DOT__spi_rdata
                                                       : 0U))));
}

void Vsoc_tb___024root___eval_triggers__act(Vsoc_tb___024root* vlSelf);
void Vsoc_tb___024root___eval_act(Vsoc_tb___024root* vlSelf);

bool Vsoc_tb___024root___eval_phase__act(Vsoc_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_tb___024root___eval_phase__act\n"); );
    Vsoc_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsoc_tb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsoc_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vsoc_tb___024root___eval_nba(Vsoc_tb___024root* vlSelf);

bool Vsoc_tb___024root___eval_phase__nba(Vsoc_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_tb___024root___eval_phase__nba\n"); );
    Vsoc_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsoc_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_tb___024root___dump_triggers__nba(Vsoc_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_tb___024root___dump_triggers__act(Vsoc_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vsoc_tb___024root___eval(Vsoc_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_tb___024root___eval\n"); );
    Vsoc_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsoc_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("soc_tb.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsoc_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("soc_tb.v", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsoc_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsoc_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsoc_tb___024root___eval_debug_assertions(Vsoc_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_tb___024root___eval_debug_assertions\n"); );
    Vsoc_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
