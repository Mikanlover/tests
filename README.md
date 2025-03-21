# Minilibc

The objective of this project is to create a dynamic ELF library to replace (to a certain extent) the
standard C library you use every day on your system

## How to compil the library

```bash
make
```

## How to compil with unit tests

```bash
make tests_run
```

## Archievement

| Test Name        | Type    | Pourcentage | Description      |
|------------------|---------|-------------|------------------|
| `Preliminaries`  | Require | 100%        | preliminaries    |
| `Strlen`         | Require | 100%        | man strlen       |
| `Strchr`         | Require | 100%        | man strchr       |
| `Memset`         | Require | 100%        | man memset       |
| `Memcpy`         | Require | 100%        | man memcpy       |
| `Strcmp`         | Require | 100%        | man strcmp       |
| `Memmove`        | Require | 100%        | man memmove      |
| `Strncmp`        | Require | 100%        | man strncmp      |
| `Strcasecmp`     | Require | 100%        | man strcasecmp   |
| `Strrchr`        | Require | 100%        | man strrchr      |
| `Strstr`         | Require | 100%        | man strstr       |
| `Strpbrk`        | Require | 100%        | man strpbrk      |
| `Strcspn`        | Require | 100%        | man strcspn      |
| `Boni Functions` | Require | 100%        | bonus            |
| `Ffs`            | Bonus   | 100%        | man ffs          |
| `Index/rindex`   | Bonus   | 100%        | man index/rindex |
| `Strfry`         | Bonus   | 0%          | man strfry       |
| `Memfrob`        | Bonus   | 100%        | man memfrob      |
| `Syscall`        | Bonus   | 0%          | man syscall      |

Be aware of -42 Epitech Students !!!
