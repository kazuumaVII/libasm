
				global			ft_strdup
				section			.text
				extern			malloc
				extern			ft_strlen
				extern			ft_strcpy

ft_strdup:
				call			ft_strlen		
				push			rdi				
				inc				rax
				mov				rdi, rax
				call			malloc
				test			eax, eax		
				jz				if_error			

				pop				rdi				
				mov				rsi, rdi
				mov				rdi, rax
				call			ft_strcpy
				ret

if_error:
				mov				rax, 0
				pop				rdi
				ret
