require_extension('S');
require_impl(IMPL_MMU);
if (STATE.v) {
  if (STATE.prv == PRV_U || get_field(STATE.hstatus->read(), HSTATUS_VTVM))
    require_novirt();
} else {
  require_privilege(get_field(STATE.mstatus->read(), MSTATUS_TVM) ? PRV_M : PRV_S);
}
MMU.flush_tlb_on_sfence_vma();
