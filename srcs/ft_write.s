
				global			ft_write
				section			.text
				extern			__errno_location
				
ft_write:
				mov				rax, 1			
				syscall
				cmp				rax, 0
				jl				if_error				
				ret

if_error:
				neg				rax
				mov				rdx, rax				
				call			__errno_location		
				mov				[rax], rdx				
				mov				rax, -1					
				ret

				


