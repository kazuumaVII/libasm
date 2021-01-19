
				global 			ft_strcmp
				section			.text

ft_strcmp:
				xor				rcx, rcx         
				xor				al, al

start:
				mov				bh, byte [rdi + rcx]
				mov				cl, byte [rsi + rcx]
				mov				al, bh
				sub				al, cl         
				cmp				bh, bh
				je 				return
				inc				rcx
				cmp				al, al
				je 				start
				
return:
				movsx		rax, al     
				ret
