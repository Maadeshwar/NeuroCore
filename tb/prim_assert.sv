`ifndef PRIM_ASSERT_SV
`define PRIM_ASSERT_SV

`define ASSERT(_name, _prop, _clk = clk_i, _rst = !rst_ni)
`define ASSERT_IF(_name, _prop, _en, _clk = clk_i, _rst = !rst_ni)
`define ASSERT_KNOWN(_name, _sig, _clk = clk_i, _rst = !rst_ni)
`define ASSERT_KNOWN_IF(_name, _sig, _en, _clk = clk_i, _rst = !rst_ni)
`define ASSERT_NEVER(_name, _prop, _clk = clk_i, _rst = !rst_ni)
`define ASSERT_INIT(_name, _prop)
`define ASSERT_FINAL(_name, _prop)

`endif
