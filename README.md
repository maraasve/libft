# 📚 libft

`libft` is a personal implementation of standard C library functions, created as part of the 42 curriculum. It includes commonly used functions for memory handling, string manipulation, character checks, list handling, and more. Everything is written from scratch in C.

---

## 🛠️ Features

- Standard C library functions (e.g. `strlen`, `memcpy`, `strchr`, etc.)
- Additional utility functions (e.g. `ft_itoa`, `ft_split`)
- Linked list operations (bonus part)
- Additional utility functions that proved useful in other projects

---

## 📦 How to Use

### 🧪 Build the library
To compile the static library:

```bash
make
```

To compile with bonus functions:
```bash
make bonus
```

### 🧹 Cleanup
Remove object files and build directories:

```bash
make clean
```

Remove everything, including libft.a:
```bash
make fclean
```

### Rebuild
Rebuild everything from scratch:
```bash
make re
```

---

## 🧠 Included Functions

##### Character checks
ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

##### Memory
ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp

##### Strings
ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_strdup, ft_substr, ft_strjoin, ft_strtrim, ft_split

##### Conversion
ft_atoi, ft_itoa

##### Allocation
ft_calloc

##### Function application
ft_strmapi, ft_striteri

##### Output
ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

##### Bonus (Linked List)
ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap