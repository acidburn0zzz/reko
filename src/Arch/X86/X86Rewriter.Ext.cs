#region License
/* 
 * Copyright (C) 1999-2021 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Expressions;
using Reko.Core.Types;

namespace Reko.Arch.X86
{
    /// <summary>
    /// Rewriter support for "extended" instructions of the x86 architecture.
    /// Basically, anything SSE or post-Pentium goes here.
    /// </summary>
    public partial class X86Rewriter
    {
        public void RewriteAesimc()
        {
            var dst = SrcOp(0);
            var src = SrcOp(1);
            m.Assign(dst, host.Intrinsic("__aesimc", true, dst.DataType, src));
        }

        public void RewriteClts()
        {
            var cr0 = binder.EnsureRegister(arch.GetControlRegister(0)!);
            m.Assign(cr0, host.Intrinsic("__clts", true, cr0.DataType, cr0));
        }

        public void RewriteEmms()
        {
            m.SideEffect(host.Intrinsic("__emms", true, VoidType.Instance));
        }

        private void RewriteGetsec()
        {
            //$TODO: this is not correct; actual function
            // depends on EAX.
            var arg = binder.EnsureRegister(Registers.eax);
            var result = binder.EnsureSequence(PrimitiveType.Word64, Registers.edx, Registers.ebx);
            m.Assign(result, host.Intrinsic("__getsec", true, result.DataType, arg));
        }

        private void RewriteInvd()
        {
            m.SideEffect(host.Intrinsic("__invd", true, VoidType.Instance));
        }

        private void RewriteInvlpg()
        {
            var op = SrcOp(0);
            m.SideEffect(host.Intrinsic("__invlpg", true, VoidType.Instance,
                op));

        }

        private void RewriteLar()
        {
            m.Assign(
                SrcOp(0),
                host.Intrinsic(
                    "__lar",
                    true,
                    instrCur.Operands[0].Width,
                    SrcOp(1)));
            m.Assign(
                binder.EnsureFlagGroup(Registers.Z),
                Constant.True());
        }

        private void RewriteLmsw()
        {
            m.SideEffect(host.Intrinsic("__lmsw", true, VoidType.Instance, SrcOp(0)));
        }

        private void RewriteLsl()
        {
            m.Assign(
                SrcOp(0),
                host.Intrinsic(
                    "__lsl",
                    true,
                    instrCur.Operands[0].Width,
                    SrcOp(1)));
        }

        private void RewriteLxdt(string intrinsicName)
        {
            m.SideEffect(
                host.Intrinsic(
                    intrinsicName,
                    true,
                    VoidType.Instance,
                    SrcOp(0)));
        }

        private void RewriteSxdt(string intrinsicName)
        {
            m.Assign(
                SrcOp(0),
                host.Intrinsic(
                    intrinsicName,
                    true,
                    instrCur.Operands[0].Width));
        }

        public void RewriteLfence()
        {
            m.SideEffect(host.Intrinsic("__lfence", true, VoidType.Instance));
        }

        public void RewriteMfence()
        {
            m.SideEffect(host.Intrinsic("__mfence", true, VoidType.Instance));
        }

        public void RewritePause()
        {
            m.SideEffect(host.Intrinsic("__pause", true, VoidType.Instance));
        }

        public void RewritePrefetch(string name)
        {
            m.SideEffect(host.Intrinsic(name, true, VoidType.Instance, SrcOp(0)));
        }

        private void RewriteSmsw()
        {
            var dst = SrcOp(0);
            m.Assign(dst, host.Intrinsic("__smsw", true, dst.DataType));
        }

        public void RewriteSfence()
        {
            m.SideEffect(host.Intrinsic("__sfence", true, VoidType.Instance));
        }

        public void RewriteVmread()
        {
            m.Assign(
                SrcOp(0),
                host.Intrinsic("__vmread", true, instrCur.Operands[0].Width, SrcOp(1)));
        }

        public void RewriteVmwrite()
        {
            m.SideEffect(host.Intrinsic("__vmwrite", true, VoidType.Instance,
                SrcOp(0),
                SrcOp(1)));
        }


        private void RewriteWbinvd()
        {
            m.SideEffect(host.Intrinsic("__wbinvd", true, VoidType.Instance));
        }

        public void RewriteWrsmr()
        {
            var edx_eax = binder.EnsureSequence(PrimitiveType.Word64, Registers.edx, Registers.eax);
            var ecx = binder.EnsureRegister(Registers.ecx);
            m.SideEffect(host.Intrinsic("__wrmsr", true, VoidType.Instance, ecx, edx_eax));
        }

        private void RewriteXsaveopt()
        {
            m.SideEffect(host.Intrinsic("__xsaveopt", true, VoidType.Instance, m.AddrOf(arch.PointerType, SrcOp(0))));
        }

    }
}
