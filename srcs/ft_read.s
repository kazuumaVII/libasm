
				global			ft_read
				section			.text
				extern			__errno_location
				
ft_read:	
				mov				rax, 0				
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

			


