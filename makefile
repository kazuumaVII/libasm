NAME = libasm.a

SRC = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s \
		ft_read.s ft_strdup.s

PATHSRCS	=	srcs
PATHTMP		=	tmp

FLAGS		=	-Wall -Wextra -Werror

NA			=	nasm
NA_FLAGS	=	-felf64

SRCS		=	$(addprefix $(PATHSRCS)/,$(SRC))
OBJS		=	$(addprefix $(PATHTMP)/,$(SRC:.s=.o))

all: $(NAME)

$(PATHTMP)/%.o:		$(PATHSRCS)/%.s
	@mkdir -p $(PATHTMP)
	@($(NA) $(NA_FLAGS) -o $@ -s $<)

$(NAME):	$(OBJS)
	@echo "Compilation..."
	@(ar rcs $(NAME) $(OBJS))
	@(ranlib $(NAME))
	@(echo "Compilation terminée")

clean:
	@echo "Clean"
	@(rm -rf $(PATHTMP))

fclean:	clean
	@echo "Fclean"
	@(rm -rf a.out)
	@(rm -rf $(NAME))

show:
	@echo "SRCS = $(SRCS)\n"
	@echo "OBJS = $(OBJS)\n"


re:	fclean all

.PHONY:	all clean fclean re