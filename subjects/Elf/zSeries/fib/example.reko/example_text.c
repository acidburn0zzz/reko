// example_text.c
// Generated by decompiling example
// using Reko decompiler version 0.10.2.0.

#include "example.h"

// 0000000000000600: void _start(Register word64 r14)
void _start(word64 r14)
{
	struct Eq_n * r15_n = fp - 0x00A0 & ~0x0F;
	r15_n->bFFFFFF50 = 0x00;
	r15_n->qwFFFFFFF0 = r14;
	r15_n->ptrFFFFFFF8 = r15_n - 0x00B0;
	__libc_start_main();
}

// 0000000000000648: void deregister_tm_clones(Register (ptr64 code) r14)
// Called from:
//      __do_global_dtors_aux
void deregister_tm_clones(<anonymous> * r14)
{
	if (8303 - 0x2068 > g_qw08C8)
	{
		<anonymous> * r1_n = g_ptr2030;
		if (r1_n != null)
		{
			word64 r14_n;
			r1_n();
		}
		else
			r14();
	}
	else
		r14();
}

// 0000000000000680: void register_tm_clones(Register (ptr64 code) r14)
// Called from:
//      frame_dummy
void register_tm_clones(<anonymous> * r14)
{
	int64 r3_n = 0x2068 - 0x2068;
	if ((r3_n >> 3) + ((r3_n >> 3) >>u 63) >> 1 != 0x00)
	{
		<anonymous> * r1_n = g_ptr2050;
		if (r1_n != null)
		{
			word64 r14_n;
			r1_n();
		}
		else
			r14();
	}
	else
		r14();
}

// 00000000000006C8: void __do_global_dtors_aux(Register word64 r11, Register word64 r12, Register word64 r13, Register (ptr64 code) r14)
void __do_global_dtors_aux(word64 r11, word64 r12, word64 r13, <anonymous> * r14)
{
	if (g_b2068 == 0x00)
	{
		if (g_b08D0 != g_b2028)
			__cxa_finalize();
		deregister_tm_clones(&g_t070E);
		g_b2068 = 0x01;
	}
	word64 r4_n;
	r14();
}

<anonymous> g_t070E = <code>; // 000000000000070E
// 0000000000000720: void frame_dummy()
void frame_dummy()
{
	ptr64 r13_n = 0x08D8;
	ptr64 r15_n = fp - 320;
	Eq_n CC_n = g_b08D8 > g_b1E18;
	if (g_b08D8 == g_b1E18)
	{
l0000000000000740:
		Mem17 = Mem10;
		struct Eq_n * v8_n = r15_n + 264;
		r13_n = v8_n->ptr0000;
		<anonymous> * r14_n = v8_n->ptr0008;
		r15_n = v8_n->ptr0010;
		if (CC_n)
		{
			register_tm_clones(r14_n);
			return;
		}
	}
	<anonymous> * r1_n = g_ptr2048;
	CC_n = r1_n > null;
	if (r1_n != null)
		r1_n();
	goto l0000000000000740;
}

// 0000000000000768: Register Eq_n fib(Register Eq_n r2, Register out ptr64 r10Out, Register out ptr64 r11Out)
// Called from:
//      fib
//      main
Eq_n fib(Eq_n r2, ptr64 & r10Out, ptr64 & r11Out)
{
	Eq_n r1_n;
	struct Eq_n * r11_n = fp - 328;
	word32 dwLocA4_n = (word32) r2;
	if (r2 <= 0x01)
		r1_n = r2;
	else
	{
		struct Eq_n * r11_n;
		word64 r10_n;
		fib((int64) (dwLocA4_n - 1), out r10_n, out r11_n);
		word64 r10_n;
		word64 r2_n = fib((int64) (r11_n->dw00A4 - 2), out r10_n, out r11_n);
		r1_n = SEQ(SLICE(r2_n, word32, 32), (int32) (r2_n + r10_n));
	}
	ptr64 v28_n = (char *) r11_n + 0x00F8;
	ptr64 r10_n;
	ptr64 r11_n;
	Eq_n r2_n;
	r11_n->ptr0118();
	r10Out = r10_n;
	r11Out = r11_n;
	return r2_n;
}

// 00000000000007E0: void main(Register word64 r3)
void main(word64 r3)
{
	struct Eq_n * r11_n;
	word64 r10_n;
	word64 r1_n = fib(0x0A, out r10_n, out r11_n);
	r11_n->ptr0120();
}

// 0000000000000820: void __libc_csu_init(Register word64 r2, Register word64 r3, Register word64 r4, Register word64 r6, Register word64 r7, Register word64 r11, Register word64 r13)
void __libc_csu_init(word64 r2, word64 r3, word64 r4, word64 r6, word64 r7, word64 r11, word64 r13)
{
	int64 r11_n = 0x1E10 - 7688;
	struct Eq_n * r15_n = fp - 320;
	word64 r8_n;
	word64 r9_n;
	word64 r10_n;
	word64 r12_n;
	word64 r13_n;
	word64 r6_n = _init(r6, r7, r4, r3, r2, r11, r13, out r8_n, out r9_n, out r10_n, out r12_n, out r13_n);
	int64 r11_n = r11_n >> 3;
	if (r11_n >> 3 != 0x00)
	{
		<anonymous> ** r7_n = &g_ptr1E08;
		do
		{
			word64 r11_n;
			(*r7_n)();
			r11_n = r11_n - 1;
		} while (r11_n != 0x01);
	}
	ptr64 v17_n = (char *) r15_n + 0x00D8;
	<anonymous> * r4_n = r15_n->ptr0110;
	r4_n();
}

// 0000000000000888: void __libc_csu_fini(Register (ptr64 code) r14)
void __libc_csu_fini(<anonymous> * r14)
{
	r14();
}

