/* ************************************************************************ */
/* Opcode GroupN */

static BxDisasmOpcodeTable_t BxDisasmGroupG1EbIb[8] = {
  /* 0 */ { 0, &Ia_addb_Eb_Ib },
  /* 1 */ { 0, &Ia_orb_Eb_Ib  },
  /* 2 */ { 0, &Ia_adcb_Eb_Ib },
  /* 3 */ { 0, &Ia_sbbb_Eb_Ib },
  /* 4 */ { 0, &Ia_andb_Eb_Ib },
  /* 5 */ { 0, &Ia_subb_Eb_Ib },
  /* 6 */ { 0, &Ia_xorb_Eb_Ib },
  /* 7 */ { 0, &Ia_cmpb_Eb_Ib }
};

static BxDisasmOpcodeTable_t BxDisasmGroupG1EwIw[8] = {
  /* 0 */ { 0, &Ia_addw_Ew_Iw },
  /* 1 */ { 0, &Ia_orw_Ew_Iw  },
  /* 2 */ { 0, &Ia_adcw_Ew_Iw },
  /* 3 */ { 0, &Ia_sbbw_Ew_Iw },
  /* 4 */ { 0, &Ia_andw_Ew_Iw },
  /* 5 */ { 0, &Ia_subw_Ew_Iw },
  /* 6 */ { 0, &Ia_xorw_Ew_Iw },
  /* 7 */ { 0, &Ia_cmpw_Ew_Iw }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG1EwIb[8] = {
  /* 0 */ { 0, &Ia_addw_Ew_sIb },	// sign-extend byte 
  /* 1 */ { 0, &Ia_orw_Ew_sIb  },
  /* 2 */ { 0, &Ia_adcw_Ew_sIb },
  /* 3 */ { 0, &Ia_sbbw_Ew_sIb },
  /* 4 */ { 0, &Ia_andw_Ew_sIb },
  /* 5 */ { 0, &Ia_subw_Ew_sIb },
  /* 6 */ { 0, &Ia_xorw_Ew_sIb },
  /* 7 */ { 0, &Ia_cmpw_Ew_sIb }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG2Eb[8] = {
  /* 0 */ { 0, &Ia_rolb_Eb_Ib },
  /* 1 */ { 0, &Ia_rorb_Eb_Ib },
  /* 2 */ { 0, &Ia_rclb_Eb_Ib },
  /* 3 */ { 0, &Ia_rcrb_Eb_Ib },
  /* 4 */ { 0, &Ia_shlb_Eb_Ib },
  /* 5 */ { 0, &Ia_shrb_Eb_Ib },
  /* 6 */ { 0, &Ia_shlb_Eb_Ib },
  /* 7 */ { 0, &Ia_sarb_Eb_Ib }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG2EbI1[8] = {
  /* 0 */ { 0, &Ia_rolb_Eb_I1 },
  /* 1 */ { 0, &Ia_rorb_Eb_I1 },
  /* 2 */ { 0, &Ia_rclb_Eb_I1 },
  /* 3 */ { 0, &Ia_rcrb_Eb_I1 },
  /* 4 */ { 0, &Ia_shlb_Eb_I1 },
  /* 5 */ { 0, &Ia_shrb_Eb_I1 },
  /* 6 */ { 0, &Ia_shlb_Eb_I1 },
  /* 7 */ { 0, &Ia_sarb_Eb_I1 }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG2EbCL[8] = {
  /* 0 */ { 0, &Ia_rolb_Eb_CL },
  /* 1 */ { 0, &Ia_rorb_Eb_CL },
  /* 2 */ { 0, &Ia_rclb_Eb_CL },
  /* 3 */ { 0, &Ia_rcrb_Eb_CL },
  /* 4 */ { 0, &Ia_shlb_Eb_CL },
  /* 5 */ { 0, &Ia_shrb_Eb_CL },
  /* 6 */ { 0, &Ia_shlb_Eb_CL },
  /* 7 */ { 0, &Ia_sarb_Eb_CL }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG2Ew[8] = {
  /* 0 */ { 0, &Ia_rolw_Ew_Ib },
  /* 1 */ { 0, &Ia_rorw_Ew_Ib },
  /* 2 */ { 0, &Ia_rclw_Ew_Ib },
  /* 3 */ { 0, &Ia_rcrw_Ew_Ib },
  /* 4 */ { 0, &Ia_shlw_Ew_Ib },
  /* 5 */ { 0, &Ia_shrw_Ew_Ib },
  /* 6 */ { 0, &Ia_shlw_Ew_Ib },
  /* 7 */ { 0, &Ia_sarw_Ew_Ib }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG2EwI1[8] = {
  /* 0 */ { 0, &Ia_rolw_Ew_I1 },
  /* 1 */ { 0, &Ia_rorw_Ew_I1 },
  /* 2 */ { 0, &Ia_rclw_Ew_I1 },
  /* 3 */ { 0, &Ia_rcrw_Ew_I1 },
  /* 4 */ { 0, &Ia_shlw_Ew_I1 },
  /* 5 */ { 0, &Ia_shrw_Ew_I1 },
  /* 6 */ { 0, &Ia_shlw_Ew_I1 },
  /* 7 */ { 0, &Ia_sarw_Ew_I1 }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG2EwCL[8] = {
  /* 0 */ { 0, &Ia_rolw_Ew_CL },
  /* 1 */ { 0, &Ia_rorw_Ew_CL },
  /* 2 */ { 0, &Ia_rclw_Ew_CL },
  /* 3 */ { 0, &Ia_rcrw_Ew_CL },
  /* 4 */ { 0, &Ia_shlw_Ew_CL },
  /* 5 */ { 0, &Ia_shrw_Ew_CL },
  /* 6 */ { 0, &Ia_shlw_Ew_CL },
  /* 7 */ { 0, &Ia_sarw_Ew_CL }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG3Eb[8] = {
  /* 0 */ { 0, &Ia_testb_Eb_Ib },
  /* 1 */ { 0, &Ia_testb_Eb_Ib },
  /* 2 */ { 0, &Ia_notb_Eb     },
  /* 3 */ { 0, &Ia_negb_Eb     },
  /* 4 */ { 0, &Ia_mulb_AL_Eb  },
  /* 5 */ { 0, &Ia_imulb_AL_Eb },
  /* 6 */ { 0, &Ia_divb_AL_Eb  },
  /* 7 */ { 0, &Ia_idivb_AL_Eb }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG3Ew[8] = {
  /* 0 */ { 0, &Ia_testw_Ew_Iw },
  /* 1 */ { 0, &Ia_testw_Ew_Iw },
  /* 2 */ { 0, &Ia_notw_Ew     },
  /* 3 */ { 0, &Ia_negw_Ew     },
  /* 4 */ { 0, &Ia_mulw_AX_Ew  },
  /* 5 */ { 0, &Ia_imulw_AX_Ew },
  /* 6 */ { 0, &Ia_divw_AX_Ew  },
  /* 7 */ { 0, &Ia_idivw_AX_Ew }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG4[8] = {
  /* 0 */ { 0, &Ia_incb_Eb },
  /* 1 */ { 0, &Ia_decb_Eb },
  /* 2 */ { 0, &Ia_Invalid },
  /* 3 */ { 0, &Ia_Invalid },
  /* 4 */ { 0, &Ia_Invalid },
  /* 5 */ { 0, &Ia_Invalid },
  /* 6 */ { 0, &Ia_Invalid },
  /* 7 */ { 0, &Ia_Invalid }
}; 

static BxDisasmOpcodeTable_t BxDisasmGroupG5w[8] = {
  /* 0 */ { 0, &Ia_incw_Ew  },
  /* 1 */ { 0, &Ia_decw_Ew  },
  /* 2 */ { 0, &Ia_call_Ew  },
  /* 3 */ { 0, &Ia_lcall_Mp },
  /* 4 */ { 0, &Ia_jmp_Ew   },
  /* 5 */ { 0, &Ia_ljmp_Mp  },
  /* 6 */ { 0, &Ia_pushw_Ew },
  /* 7 */ { 0, &Ia_Invalid  }
}; 

/* ************************************************************************ */
/* 16-bit operand size */

static BxDisasmOpcodeTable_t BxDisasmOpcodes16[256*2] = {
  // 256 entries for single byte opcodes
  /* 00 */ { 0, &Ia_addb_Eb_Gb },
  /* 01 */ { 0, &Ia_addw_Ew_Gw },
  /* 02 */ { 0, &Ia_addb_Gb_Eb },
  /* 03 */ { 0, &Ia_addw_Gw_Ew },
  /* 04 */ { 0, &Ia_addb_AL_Ib },
  /* 05 */ { 0, &Ia_addw_AX_Iw },
  /* 06 */ { 0, &Ia_pushw_ES   },
  /* 07 */ { 0, &Ia_popw_ES    },
  /* 08 */ { 0, &Ia_orb_Eb_Gb  },
  /* 09 */ { 0, &Ia_orw_Ew_Gw  },
  /* 0A */ { 0, &Ia_orb_Gb_Eb  },
  /* 0B */ { 0, &Ia_orw_Gw_Ew  },
  /* 0C */ { 0, &Ia_orb_AL_Ib  },
  /* 0D */ { 0, &Ia_orw_AX_Iw  },
  /* 0E */ { 0, &Ia_pushw_CS   },
  /* 0F */ { 0, &Ia_error      },   // 2 byte escape
  /* 10 */ { 0, &Ia_adcb_Eb_Gb },
  /* 11 */ { 0, &Ia_adcw_Ew_Gw },
  /* 12 */ { 0, &Ia_adcb_Gb_Eb },
  /* 13 */ { 0, &Ia_adcw_Gw_Ew },
  /* 14 */ { 0, &Ia_adcb_AL_Ib },
  /* 15 */ { 0, &Ia_adcw_AX_Iw },
  /* 16 */ { 0, &Ia_pushw_SS   },
  /* 17 */ { 0, &Ia_popw_SS    },
  /* 18 */ { 0, &Ia_sbbb_Eb_Gb },
  /* 19 */ { 0, &Ia_sbbw_Ew_Gw },
  /* 1A */ { 0, &Ia_sbbb_Gb_Eb },
  /* 1B */ { 0, &Ia_sbbw_Gw_Ew },
  /* 1C */ { 0, &Ia_sbbb_AL_Ib },
  /* 1D */ { 0, &Ia_sbbw_AX_Iw },
  /* 1E */ { 0, &Ia_pushw_DS   },
  /* 1F */ { 0, &Ia_popw_DS    },
  /* 20 */ { 0, &Ia_andb_Eb_Gb },
  /* 21 */ { 0, &Ia_andw_Ew_Gw },
  /* 22 */ { 0, &Ia_andb_Gb_Eb },
  /* 23 */ { 0, &Ia_andw_Gw_Ew },
  /* 24 */ { 0, &Ia_andb_AL_Ib },
  /* 25 */ { 0, &Ia_andw_AX_Iw },
  /* 26 */ { 0, &Ia_prefix_es  },   // ES:
  /* 27 */ { 0, &Ia_daa        },
  /* 28 */ { 0, &Ia_subb_Eb_Gb },
  /* 29 */ { 0, &Ia_subw_Ew_Gw },
  /* 2A */ { 0, &Ia_subb_Gb_Eb },
  /* 2B */ { 0, &Ia_subw_Gw_Ew },
  /* 2C */ { 0, &Ia_subb_AL_Ib },
  /* 2D */ { 0, &Ia_subw_AX_Iw },
  /* 2E */ { 0, &Ia_prefix_cs  },   // CS:
  /* 2F */ { 0, &Ia_das        },
  /* 30 */ { 0, &Ia_xorb_Eb_Gb },
  /* 31 */ { 0, &Ia_xorw_Ew_Gw },
  /* 32 */ { 0, &Ia_xorb_Gb_Eb },
  /* 33 */ { 0, &Ia_xorw_Gw_Ew },
  /* 34 */ { 0, &Ia_xorb_AL_Ib },
  /* 35 */ { 0, &Ia_xorw_AX_Iw },
  /* 36 */ { 0, &Ia_prefix_ss  },   // SS:
  /* 37 */ { 0, &Ia_aaa        },
  /* 38 */ { 0, &Ia_cmpb_Eb_Gb },
  /* 39 */ { 0, &Ia_cmpw_Ew_Gw },
  /* 3A */ { 0, &Ia_cmpb_Gb_Eb },
  /* 3B */ { 0, &Ia_cmpw_Gw_Ew },
  /* 3C */ { 0, &Ia_cmpb_AL_Ib },
  /* 3D */ { 0, &Ia_cmpw_AX_Iw },
  /* 3E */ { 0, &Ia_prefix_ds  },   // DS:
  /* 3F */ { 0, &Ia_aas        },
  /* 40 */ { 0, &Ia_incw_RX    },
  /* 41 */ { 0, &Ia_incw_RX    },
  /* 42 */ { 0, &Ia_incw_RX    },
  /* 43 */ { 0, &Ia_incw_RX    },
  /* 44 */ { 0, &Ia_incw_RX    },
  /* 45 */ { 0, &Ia_incw_RX    },
  /* 46 */ { 0, &Ia_incw_RX    },
  /* 47 */ { 0, &Ia_incw_RX    },
  /* 48 */ { 0, &Ia_decw_RX    },
  /* 49 */ { 0, &Ia_decw_RX    },
  /* 4A */ { 0, &Ia_decw_RX    },
  /* 4B */ { 0, &Ia_decw_RX    },
  /* 4C */ { 0, &Ia_decw_RX    },
  /* 4D */ { 0, &Ia_decw_RX    },
  /* 4E */ { 0, &Ia_decw_RX    },
  /* 4F */ { 0, &Ia_decw_RX    },
  /* 50 */ { 0, &Ia_pushw_RX   },
  /* 51 */ { 0, &Ia_pushw_RX   },
  /* 52 */ { 0, &Ia_pushw_RX   },
  /* 53 */ { 0, &Ia_pushw_RX   },
  /* 54 */ { 0, &Ia_pushw_RX   },
  /* 55 */ { 0, &Ia_pushw_RX   },
  /* 56 */ { 0, &Ia_pushw_RX   },
  /* 57 */ { 0, &Ia_pushw_RX   },
  /* 58 */ { 0, &Ia_popw_RX    },
  /* 59 */ { 0, &Ia_popw_RX    },
  /* 5A */ { 0, &Ia_popw_RX    },
  /* 5B */ { 0, &Ia_popw_RX    },
  /* 5C */ { 0, &Ia_popw_RX    },
  /* 5D */ { 0, &Ia_popw_RX    },
  /* 5E */ { 0, &Ia_popw_RX    },
  /* 5F */ { 0, &Ia_popw_RX    },
  /* 60 */ { 0, &Ia_pushaw     },
  /* 61 */ { 0, &Ia_popaw      },
  /* 62 */ { 0, &Ia_boundw_Gw_Ma },
  /* 63 */ { 0, &Ia_Invalid    },
  /* 64 */ { 0, &Ia_Invalid    },   // FS:
  /* 65 */ { 0, &Ia_Invalid    },
  /* 66 */ { 0, &Ia_Invalid    },
  /* 67 */ { 0, &Ia_Invalid    },
  /* 68 */ { 0, &Ia_pushw_Iw   },
  /* 69 */ { 0, &Ia_imulw_Gw_Ew_Iw  },
  /* 6A */ { 0, &Ia_pushw_sIb   },
  /* 6B */ { 0, &Ia_imulw_Gw_Ew_sIb },
  /* 6C */ { 0, &Ia_insb_Yb_DX  },
  /* 6D */ { 0, &Ia_insw_Yw_DX  },
  /* 6E */ { 0, &Ia_outsb_DX_Xb },
  /* 6F */ { 0, &Ia_outsw_DX_Xw },
  /* 70 */ { 0, &Ia_jo_Jb       },
  /* 71 */ { 0, &Ia_jno_Jb      },
  /* 72 */ { 0, &Ia_jb_Jb       },
  /* 73 */ { 0, &Ia_jnb_Jb      },
  /* 74 */ { 0, &Ia_jz_Jb       },
  /* 75 */ { 0, &Ia_jnz_Jb      },
  /* 76 */ { 0, &Ia_jbe_Jb      },
  /* 77 */ { 0, &Ia_jnbe_Jb     },
  /* 78 */ { 0, &Ia_js_Jb       },
  /* 79 */ { 0, &Ia_jns_Jb      },
  /* 7A */ { 0, &Ia_jp_Jb       },
  /* 7B */ { 0, &Ia_jnp_Jb      },
  /* 7C */ { 0, &Ia_jl_Jb       },
  /* 7D */ { 0, &Ia_jnl_Jb      },
  /* 7E */ { 0, &Ia_jle_Jb      },
  /* 7F */ { 0, &Ia_jnle_Jb     },
  /* 80 */ { GRPN(G1EbIb)       },
  /* 81 */ { GRPN(G1EwIw)       },
  /* 82 */ { GRPN(G1EbIb)       },
  /* 83 */ { GRPN(G1EwIb)       },
  /* 84 */ { 0, &Ia_testb_Eb_Gb },
  /* 85 */ { 0, &Ia_testw_Ew_Gw },
  /* 86 */ { 0, &Ia_xchgb_Eb_Gb },
  /* 87 */ { 0, &Ia_xchgw_Ew_Gw },
  /* 88 */ { 0, &Ia_movb_Eb_Gb  },
  /* 89 */ { 0, &Ia_movw_Ew_Gw  },
  /* 8A */ { 0, &Ia_movb_Gb_Eb  },
  /* 8B */ { 0, &Ia_movw_Gw_Ew  },
  /* 8C */ { 0, &Ia_movw_Ew_Sw  },
  /* 8D */ { 0, &Ia_leaw_Gw_Mw  },
  /* 8E */ { 0, &Ia_movw_Sw_Ew  },
  /* 8F */ { 0, &Ia_popw_Ew     },
  /* 90 */ { 0, &Ia_nop         },
  /* 91 */ { 0, &Ia_xchgw_RX_AX },
  /* 92 */ { 0, &Ia_xchgw_RX_AX },
  /* 93 */ { 0, &Ia_xchgw_RX_AX },
  /* 94 */ { 0, &Ia_xchgw_RX_AX },
  /* 95 */ { 0, &Ia_xchgw_RX_AX },
  /* 96 */ { 0, &Ia_xchgw_RX_AX },
  /* 97 */ { 0, &Ia_xchgw_RX_AX },
  /* 98 */ { 0, &Ia_cbw         },
  /* 99 */ { 0, &Ia_cwd         },
  /* 9A */ { 0, &Ia_lcall_Apw   },
  /* 9B */ { 0, &Ia_poll        },
  /* 9C */ { 0, &Ia_pushfw      },
  /* 9D */ { 0, &Ia_popfw       },
  /* 9E */ { 0, &Ia_sahf        },
  /* 9F */ { 0, &Ia_lahf        },
  /* A0 */ { 0, &Ia_movb_AL_Ob  },
  /* A1 */ { 0, &Ia_movw_AX_Ow  },
  /* A2 */ { 0, &Ia_movb_Ob_AL  },
  /* A3 */ { 0, &Ia_movw_Ow_AX  },
  /* A4 */ { 0, &Ia_movsb_Yb_Xb },
  /* A5 */ { 0, &Ia_movsw_Yw_Xw },
  /* A6 */ { 0, &Ia_cmpsb_Yb_Xb },
  /* A7 */ { 0, &Ia_cmpsw_Yw_Xw },
  /* A8 */ { 0, &Ia_testb_AL_Ib },
  /* A9 */ { 0, &Ia_testw_AX_Iw },
  /* AA */ { 0, &Ia_stosb_Yb_AL },
  /* AB */ { 0, &Ia_stosw_Yw_AX },
  /* AC */ { 0, &Ia_lodsb_AL_Xb },
  /* AD */ { 0, &Ia_lodsw_AX_Xw },
  /* AE */ { 0, &Ia_scasb_Yb_AL },
  /* AF */ { 0, &Ia_scasw_Yw_AX },
  /* B0 */ { 0, &Ia_movb_R8_Ib  },
  /* B1 */ { 0, &Ia_movb_R8_Ib  },
  /* B2 */ { 0, &Ia_movb_R8_Ib  },
  /* B3 */ { 0, &Ia_movb_R8_Ib  },
  /* B4 */ { 0, &Ia_movb_R8_Ib  },
  /* B5 */ { 0, &Ia_movb_R8_Ib  },
  /* B6 */ { 0, &Ia_movb_R8_Ib  },
  /* B7 */ { 0, &Ia_movb_R8_Ib  },
  /* B8 */ { 0, &Ia_movw_RX_Iw  },
  /* B9 */ { 0, &Ia_movw_RX_Iw  },
  /* BA */ { 0, &Ia_movw_RX_Iw  },
  /* BB */ { 0, &Ia_movw_RX_Iw  },
  /* BC */ { 0, &Ia_movw_RX_Iw  },
  /* BD */ { 0, &Ia_movw_RX_Iw  },
  /* BE */ { 0, &Ia_movw_RX_Iw  },
  /* BF */ { 0, &Ia_movw_RX_Iw  },
  /* C0 */ { GRPN(G2Eb)         },
  /* C1 */ { GRPN(G2Ew)         },
  /* C2 */ { 0, &Ia_ret_Iw      },
  /* C3 */ { 0, &Ia_ret         },
  /* C4 */ { 0, &Ia_lesw_Gw_Mp  },
  /* C5 */ { 0, &Ia_ldsw_Gw_Mp  },
  /* C6 */ { 0, &Ia_movb_Eb_Ib  },
  /* C7 */ { 0, &Ia_movw_Ew_Iw  },
  /* C8 */ { 0, &Ia_enter       },
  /* C9 */ { 0, &Ia_leave       },
  /* CA */ { 0, &Ia_lret_Iw     },
  /* CB */ { 0, &Ia_lret        },
  /* CC */ { 0, &Ia_int3        },
  /* CD */ { 0, &Ia_int_Ib      },
  /* CE */ { 0, &Ia_into        },
  /* CF */ { 0, &Ia_iretw       },
  /* D0 */ { GRPN(G2EbI1)       },
  /* D1 */ { GRPN(G2EwI1)       },
  /* D2 */ { GRPN(G2EbCL)       },
  /* D3 */ { GRPN(G2EwCL)       },
  /* D4 */ { 0, &Ia_aam         },
  /* D5 */ { 0, &Ia_aad         },
  /* D6 */ { 0, &Ia_salc        },
  /* D7 */ { 0, &Ia_xlat        },
  /* D8 */ { 0, &Ia_fpo1	},
  /* D9 */ { 0, &Ia_fpo1        },
  /* DA */ { 0, &Ia_fpo1        },
  /* DB */ { 0, &Ia_fpo1        },
  /* DC */ { 0, &Ia_fpo1        },
  /* DD */ { 0, &Ia_fpo1        },
  /* DE */ { 0, &Ia_fpo1        },
  /* DF */ { 0, &Ia_fpo1        },
  /* E0 */ { 0, &Ia_loopne_Jb   },
  /* E1 */ { 0, &Ia_loope_Jb    },
  /* E2 */ { 0, &Ia_loop_Jb     },
  /* E3 */ { 0, &Ia_jcxz_Jb     },
  /* E4 */ { 0, &Ia_inb_AL_Ib   },
  /* E5 */ { 0, &Ia_inw_AX_Ib   },
  /* E6 */ { 0, &Ia_outb_Ib_AL  },
  /* E7 */ { 0, &Ia_outw_Ib_AX  },
  /* E8 */ { 0, &Ia_call_Jw     },
  /* E9 */ { 0, &Ia_jmp_Jw      },
  /* EA */ { 0, &Ia_ljmp_Apw    },
  /* EB */ { 0, &Ia_jmp_Jb      },
  /* EC */ { 0, &Ia_inb_AL_DX   },
  /* ED */ { 0, &Ia_inw_AX_DX   },
  /* EE */ { 0, &Ia_outb_DX_AL  },
  /* EF */ { 0, &Ia_outw_DX_AX  },
  /* F0 */ { 0, &Ia_prefix_lock },   // LOCK:
  /* F1 */ { 0, &Ia_Invalid     },
  /* F2 */ { 0, &Ia_prefix_repne },  // REPNE:
  /* F3 */ { 0, &Ia_prefix_rep  },   // REP:
  /* F4 */ { 0, &Ia_hlt         },
  /* F5 */ { 0, &Ia_cmc         },
  /* F6 */ { GRPN(G3Eb)         },
  /* F7 */ { GRPN(G3Ew)         },
  /* F8 */ { 0, &Ia_clc         },
  /* F9 */ { 0, &Ia_stc         },
  /* FA */ { 0, &Ia_cli         },
  /* FB */ { 0, &Ia_sti         },
  /* FC */ { 0, &Ia_cld         },
  /* FD */ { 0, &Ia_std         },
  /* FE */ { GRPN(G4)           },
  /* FF */ { GRPN(G5w)          },

  // 256 entries for two byte opcodes
  /* 0F 00 */ { 0, &Ia_Invalid    },
  /* 0F 01 */ { 0, &Ia_Invalid    },
  /* 0F 02 */ { 0, &Ia_Invalid    },
  /* 0F 03 */ { 0, &Ia_Invalid    },
  /* 0F 04 */ { 0, &Ia_Invalid    },
  /* 0F 05 */ { 0, &Ia_Invalid    },
  /* 0F 06 */ { 0, &Ia_Invalid    },
  /* 0F 07 */ { 0, &Ia_Invalid    },
  /* 0F 08 */ { 0, &Ia_Invalid    },
  /* 0F 09 */ { 0, &Ia_Invalid    },
  /* 0F 0A */ { 0, &Ia_Invalid    },
  /* 0F 0B */ { 0, &Ia_Invalid    },
  /* 0F 0C */ { 0, &Ia_Invalid    },
  /* 0F 0D */ { 0, &Ia_Invalid    },
  /* 0F 0E */ { 0, &Ia_Invalid    },
  /* 0F 0F */ { 0, &Ia_Invalid    },
  /* 0F 10 */ { 0, &Ia_Invalid    },
  /* 0F 11 */ { 0, &Ia_Invalid    },
  /* 0F 12 */ { 0, &Ia_Invalid    },
  /* 0F 13 */ { 0, &Ia_Invalid    },
  /* 0F 14 */ { 0, &Ia_Invalid    },
  /* 0F 15 */ { 0, &Ia_Invalid    },
  /* 0F 16 */ { 0, &Ia_Invalid    },
  /* 0F 17 */ { 0, &Ia_Invalid    },
  /* 0F 18 */ { 0, &Ia_Invalid    },
  /* 0F 19 */ { 0, &Ia_Invalid    },
  /* 0F 1A */ { 0, &Ia_Invalid    },
  /* 0F 1B */ { 0, &Ia_Invalid    },
  /* 0F 1C */ { 0, &Ia_Invalid    },
  /* 0F 1D */ { 0, &Ia_Invalid    },
  /* 0F 1E */ { 0, &Ia_Invalid    },
  /* 0F 1F */ { 0, &Ia_Invalid    },
  /* 0F 20 */ { 0, &Ia_Invalid    },
  /* 0F 21 */ { 0, &Ia_Invalid    },
  /* 0F 22 */ { 0, &Ia_Invalid    },
  /* 0F 23 */ { 0, &Ia_Invalid    },
  /* 0F 24 */ { 0, &Ia_Invalid    },
  /* 0F 25 */ { 0, &Ia_Invalid    },
  /* 0F 26 */ { 0, &Ia_Invalid    },
  /* 0F 27 */ { 0, &Ia_Invalid    },
  /* 0F 28 */ { 0, &Ia_Invalid    },
  /* 0F 29 */ { 0, &Ia_Invalid    },
  /* 0F 2A */ { 0, &Ia_Invalid    },
  /* 0F 2B */ { 0, &Ia_Invalid    },
  /* 0F 2C */ { 0, &Ia_Invalid    },
  /* 0F 2D */ { 0, &Ia_Invalid    },
  /* 0F 2E */ { 0, &Ia_Invalid    },
  /* 0F 2F */ { 0, &Ia_Invalid    },
  /* 0F 30 */ { 0, &Ia_Invalid    },
  /* 0F 31 */ { 0, &Ia_Invalid    },
  /* 0F 32 */ { 0, &Ia_Invalid    },
  /* 0F 33 */ { 0, &Ia_Invalid    },
  /* 0F 34 */ { 0, &Ia_Invalid    },
  /* 0F 35 */ { 0, &Ia_Invalid    },
  /* 0F 36 */ { 0, &Ia_Invalid    },
  /* 0F 37 */ { 0, &Ia_Invalid    },
  /* 0F 38 */ { 0, &Ia_Invalid    },
  /* 0F 39 */ { 0, &Ia_Invalid    },
  /* 0F 3A */ { 0, &Ia_Invalid    },
  /* 0F 3B */ { 0, &Ia_Invalid    },
  /* 0F 3C */ { 0, &Ia_Invalid    },
  /* 0F 3D */ { 0, &Ia_Invalid    },
  /* 0F 3E */ { 0, &Ia_Invalid    },
  /* 0F 3F */ { 0, &Ia_Invalid    },
  /* 0F 40 */ { 0, &Ia_Invalid    },
  /* 0F 41 */ { 0, &Ia_Invalid    },
  /* 0F 42 */ { 0, &Ia_Invalid    },
  /* 0F 43 */ { 0, &Ia_Invalid    },
  /* 0F 44 */ { 0, &Ia_Invalid    },
  /* 0F 45 */ { 0, &Ia_Invalid    },
  /* 0F 46 */ { 0, &Ia_Invalid    },
  /* 0F 47 */ { 0, &Ia_Invalid    },
  /* 0F 48 */ { 0, &Ia_Invalid    },
  /* 0F 49 */ { 0, &Ia_Invalid    },
  /* 0F 4A */ { 0, &Ia_Invalid    },
  /* 0F 4B */ { 0, &Ia_Invalid    },
  /* 0F 4C */ { 0, &Ia_Invalid    },
  /* 0F 4D */ { 0, &Ia_Invalid    },
  /* 0F 4E */ { 0, &Ia_Invalid    },
  /* 0F 4F */ { 0, &Ia_Invalid    },
  /* 0F 50 */ { 0, &Ia_Invalid    },
  /* 0F 51 */ { 0, &Ia_Invalid    },
  /* 0F 52 */ { 0, &Ia_Invalid    },
  /* 0F 53 */ { 0, &Ia_Invalid    },
  /* 0F 54 */ { 0, &Ia_Invalid    },
  /* 0F 55 */ { 0, &Ia_Invalid    },
  /* 0F 56 */ { 0, &Ia_Invalid    },
  /* 0F 57 */ { 0, &Ia_Invalid    },
  /* 0F 58 */ { 0, &Ia_Invalid    },
  /* 0F 59 */ { 0, &Ia_Invalid    },
  /* 0F 5A */ { 0, &Ia_Invalid    },
  /* 0F 5B */ { 0, &Ia_Invalid    },
  /* 0F 5C */ { 0, &Ia_Invalid    },
  /* 0F 5D */ { 0, &Ia_Invalid    },
  /* 0F 5E */ { 0, &Ia_Invalid    },
  /* 0F 5F */ { 0, &Ia_Invalid    },
  /* 0F 60 */ { 0, &Ia_Invalid    },
  /* 0F 61 */ { 0, &Ia_Invalid    },
  /* 0F 62 */ { 0, &Ia_Invalid    },
  /* 0F 63 */ { 0, &Ia_Invalid    },
  /* 0F 64 */ { 0, &Ia_Invalid    },
  /* 0F 65 */ { 0, &Ia_Invalid    },
  /* 0F 66 */ { 0, &Ia_Invalid    },
  /* 0F 67 */ { 0, &Ia_Invalid    },
  /* 0F 68 */ { 0, &Ia_Invalid    },
  /* 0F 69 */ { 0, &Ia_Invalid    },
  /* 0F 6A */ { 0, &Ia_Invalid    },
  /* 0F 6B */ { 0, &Ia_Invalid    },
  /* 0F 6C */ { 0, &Ia_Invalid    },
  /* 0F 6D */ { 0, &Ia_Invalid    },
  /* 0F 6E */ { 0, &Ia_Invalid    },
  /* 0F 6F */ { 0, &Ia_Invalid    },
  /* 0F 70 */ { 0, &Ia_Invalid    },
  /* 0F 71 */ { 0, &Ia_Invalid    },
  /* 0F 72 */ { 0, &Ia_Invalid    },
  /* 0F 73 */ { 0, &Ia_Invalid    },
  /* 0F 74 */ { 0, &Ia_Invalid    },
  /* 0F 75 */ { 0, &Ia_Invalid    },
  /* 0F 76 */ { 0, &Ia_Invalid    },
  /* 0F 77 */ { 0, &Ia_Invalid    },
  /* 0F 78 */ { 0, &Ia_Invalid    },
  /* 0F 79 */ { 0, &Ia_Invalid    },
  /* 0F 7A */ { 0, &Ia_Invalid    },
  /* 0F 7B */ { 0, &Ia_Invalid    },
  /* 0F 7C */ { 0, &Ia_Invalid    },
  /* 0F 7D */ { 0, &Ia_Invalid    },
  /* 0F 7E */ { 0, &Ia_Invalid    },
  /* 0F 7F */ { 0, &Ia_Invalid    },
  /* 0F 80 */ { 0, &Ia_Invalid    },
  /* 0F 81 */ { 0, &Ia_Invalid    },
  /* 0F 82 */ { 0, &Ia_Invalid    },
  /* 0F 83 */ { 0, &Ia_Invalid    },
  /* 0F 84 */ { 0, &Ia_Invalid    },
  /* 0F 85 */ { 0, &Ia_Invalid    },
  /* 0F 86 */ { 0, &Ia_Invalid    },
  /* 0F 87 */ { 0, &Ia_Invalid    },
  /* 0F 88 */ { 0, &Ia_Invalid    },
  /* 0F 89 */ { 0, &Ia_Invalid    },
  /* 0F 8A */ { 0, &Ia_Invalid    },
  /* 0F 8B */ { 0, &Ia_Invalid    },
  /* 0F 8C */ { 0, &Ia_Invalid    },
  /* 0F 8D */ { 0, &Ia_Invalid    },
  /* 0F 8E */ { 0, &Ia_Invalid    },
  /* 0F 8F */ { 0, &Ia_Invalid    },
  /* 0F 90 */ { 0, &Ia_Invalid    },
  /* 0F 91 */ { 0, &Ia_Invalid    },
  /* 0F 92 */ { 0, &Ia_Invalid    },
  /* 0F 93 */ { 0, &Ia_Invalid    },
  /* 0F 94 */ { 0, &Ia_Invalid    },
  /* 0F 95 */ { 0, &Ia_Invalid    },
  /* 0F 96 */ { 0, &Ia_Invalid    },
  /* 0F 97 */ { 0, &Ia_Invalid    },
  /* 0F 98 */ { 0, &Ia_Invalid    },
  /* 0F 99 */ { 0, &Ia_Invalid    },
  /* 0F 9A */ { 0, &Ia_Invalid    },
  /* 0F 9B */ { 0, &Ia_Invalid    },
  /* 0F 9C */ { 0, &Ia_Invalid    },
  /* 0F 9D */ { 0, &Ia_Invalid    },
  /* 0F 9E */ { 0, &Ia_Invalid    },
  /* 0F 9F */ { 0, &Ia_Invalid    },
  /* 0F A0 */ { 0, &Ia_Invalid    },
  /* 0F A1 */ { 0, &Ia_Invalid    },
  /* 0F A2 */ { 0, &Ia_Invalid    },
  /* 0F A3 */ { 0, &Ia_Invalid    },
  /* 0F A4 */ { 0, &Ia_Invalid    },
  /* 0F A5 */ { 0, &Ia_Invalid    },
  /* 0F A6 */ { 0, &Ia_Invalid    },
  /* 0F A7 */ { 0, &Ia_Invalid    },
  /* 0F A8 */ { 0, &Ia_Invalid    },
  /* 0F A9 */ { 0, &Ia_Invalid    },
  /* 0F AA */ { 0, &Ia_Invalid    },
  /* 0F AB */ { 0, &Ia_Invalid    },
  /* 0F AC */ { 0, &Ia_Invalid    },
  /* 0F AD */ { 0, &Ia_Invalid    },
  /* 0F AE */ { 0, &Ia_Invalid    },
  /* 0F AF */ { 0, &Ia_Invalid    },
  /* 0F B0 */ { 0, &Ia_Invalid    },
  /* 0F B1 */ { 0, &Ia_Invalid    },
  /* 0F B2 */ { 0, &Ia_Invalid    },
  /* 0F B3 */ { 0, &Ia_Invalid    },
  /* 0F B4 */ { 0, &Ia_Invalid    },
  /* 0F B5 */ { 0, &Ia_Invalid    },
  /* 0F B6 */ { 0, &Ia_Invalid    },
  /* 0F B7 */ { 0, &Ia_Invalid    },
  /* 0F B8 */ { 0, &Ia_Invalid    },
  /* 0F B9 */ { 0, &Ia_Invalid    },
  /* 0F BA */ { 0, &Ia_Invalid    },
  /* 0F BB */ { 0, &Ia_Invalid    },
  /* 0F BC */ { 0, &Ia_Invalid    },
  /* 0F BD */ { 0, &Ia_Invalid    },
  /* 0F BE */ { 0, &Ia_Invalid    },
  /* 0F BF */ { 0, &Ia_Invalid    },
  /* 0F C0 */ { 0, &Ia_Invalid    },
  /* 0F C0 */ { 0, &Ia_Invalid    },
  /* 0F C2 */ { 0, &Ia_Invalid    },
  /* 0F C3 */ { 0, &Ia_Invalid    },
  /* 0F C4 */ { 0, &Ia_Invalid    },
  /* 0F C5 */ { 0, &Ia_Invalid    },
  /* 0F C6 */ { 0, &Ia_Invalid    },
  /* 0F C7 */ { 0, &Ia_Invalid    },
  /* 0F C8 */ { 0, &Ia_Invalid    },
  /* 0F C9 */ { 0, &Ia_Invalid    },
  /* 0F CA */ { 0, &Ia_Invalid    },
  /* 0F CB */ { 0, &Ia_Invalid    },
  /* 0F CC */ { 0, &Ia_Invalid    },
  /* 0F CD */ { 0, &Ia_Invalid    },
  /* 0F CE */ { 0, &Ia_Invalid    },
  /* 0F CF */ { 0, &Ia_Invalid    },
  /* 0F D0 */ { 0, &Ia_Invalid    },
  /* 0F D1 */ { 0, &Ia_Invalid    },
  /* 0F D2 */ { 0, &Ia_Invalid    },
  /* 0F D3 */ { 0, &Ia_Invalid    },
  /* 0F D4 */ { 0, &Ia_Invalid    },
  /* 0F D5 */ { 0, &Ia_Invalid    },
  /* 0F D6 */ { 0, &Ia_Invalid    },
  /* 0F D7 */ { 0, &Ia_Invalid    },
  /* 0F D8 */ { 0, &Ia_Invalid    },
  /* 0F D9 */ { 0, &Ia_Invalid    },
  /* 0F DA */ { 0, &Ia_Invalid    },
  /* 0F DB */ { 0, &Ia_Invalid    },
  /* 0F DC */ { 0, &Ia_Invalid    },
  /* 0F DD */ { 0, &Ia_Invalid    },
  /* 0F DE */ { 0, &Ia_Invalid    },
  /* 0F DF */ { 0, &Ia_Invalid    },
  /* 0F E0 */ { 0, &Ia_Invalid    },
  /* 0F E1 */ { 0, &Ia_Invalid    },
  /* 0F E2 */ { 0, &Ia_Invalid    },
  /* 0F E3 */ { 0, &Ia_Invalid    },
  /* 0F E4 */ { 0, &Ia_Invalid    },
  /* 0F E5 */ { 0, &Ia_Invalid    },
  /* 0F E6 */ { 0, &Ia_Invalid    },
  /* 0F E7 */ { 0, &Ia_Invalid    },
  /* 0F E8 */ { 0, &Ia_Invalid    },
  /* 0F E9 */ { 0, &Ia_Invalid    },
  /* 0F EA */ { 0, &Ia_Invalid    },
  /* 0F EB */ { 0, &Ia_Invalid    },
  /* 0F EC */ { 0, &Ia_Invalid    },
  /* 0F ED */ { 0, &Ia_Invalid    },
  /* 0F EE */ { 0, &Ia_Invalid    },
  /* 0F EF */ { 0, &Ia_Invalid    },
  /* 0F F0 */ { 0, &Ia_Invalid    },
  /* 0F F1 */ { 0, &Ia_Invalid    },
  /* 0F F2 */ { 0, &Ia_Invalid    },
  /* 0F F3 */ { 0, &Ia_Invalid    },
  /* 0F F4 */ { 0, &Ia_Invalid    },
  /* 0F F5 */ { 0, &Ia_Invalid    },
  /* 0F F6 */ { 0, &Ia_Invalid    },
  /* 0F F7 */ { 0, &Ia_Invalid    },
  /* 0F F8 */ { 0, &Ia_Invalid    },
  /* 0F F9 */ { 0, &Ia_Invalid    },
  /* 0F FA */ { 0, &Ia_Invalid    },
  /* 0F FB */ { 0, &Ia_Invalid    },
  /* 0F FC */ { 0, &Ia_Invalid    },
  /* 0F FD */ { 0, &Ia_Invalid    },
  /* 0F FE */ { 0, &Ia_Invalid    },
  /* 0F FF */ { 0, &Ia_Invalid    }
};
