
				global			ft_strlen
				section			.text

ft_strlen:
				mov				rax, -1   

start:
				inc				rax                  
				cmp				byte [rdi + rax], 0  
				jne				start        
				        
return:
				ret


