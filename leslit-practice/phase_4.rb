0x000000000040100c <+0>:	sub    $0x18,%rsp
0x0000000000401010 <+4>:	lea    0xc(%rsp),%rcx
0x0000000000401015 <+9>:	lea    0x8(%rsp),%rdx
=> 0x000000000040101a <+14>:	mov    $0x4025cf,%esi                 %d %d
0x000000000040101f <+19>:	mov    $0x0,%eax                          eax to 0
0x0000000000401024 <+24>:	callq  0x400bf0 <__isoc99_sscanf@plt>
0x0000000000401029 <+29>:	cmp    $0x2,%eax                          check for 2 %d inputs
0x000000000040102c <+32>:	jne    0x401035 <phase_4+41>
0x000000000040102e <+34>:	cmpl   $0xe,0x8(%rsp)                     input 1 < 14
0x0000000000401033 <+39>:	jbe    0x40103a <phase_4+46>
0x0000000000401035 <+41>:	callq  0x40143a <explode_bomb>
0x000000000040103a <+46>:	mov    $0xe,%edx                          edx = 14
0x000000000040103f <+51>:	mov    $0x0,%esi                          esi = 0
0x0000000000401044 <+56>:	mov    0x8(%rsp),%edi                     edi = input 1
0x0000000000401048 <+60>:	callq  0x400fce <func4>
0x000000000040104d <+65>:	test   %eax,%eax                          if eax is 0
0x000000000040104f <+67>:	jne    0x401058 <phase_4+76>              explode bomb
0x0000000000401051 <+69>:	cmpl   $0x0,0xc(%rsp)                     if 0xc(%rsp) is 0
0x0000000000401056 <+74>:	je     0x40105d <phase_4+81>              diffuse phase_4
0x0000000000401058 <+76>:	callq  0x40143a <explode_bomb>
0x000000000040105d <+81>:	add    $0x18,%rsp
0x0000000000401061 <+85>:	retq
