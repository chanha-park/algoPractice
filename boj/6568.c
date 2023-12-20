#include <stdio.h>

enum {
    STA,
    LDA,
    BEQ,
    NOP,
    DEC,
    INC,
    JMP,
    HLT,
    INSTRUCTION_SET_SIZE
};

#define PROGRAM_SIZE 32
#define BYTE_SIZE 8
#define OPERAND_SIZE 5
#define OPERAND_MASK ((1 << (OPERAND_SIZE)) - 1)

typedef int (*instruction_t
)(unsigned char, unsigned char*, unsigned char*, unsigned char*);

int
sta(unsigned char operand,
    unsigned char* adder,
    unsigned char* pc,
    unsigned char* memory) {
    (void)pc;
    memory[operand] = *adder;
    return 1;
}

int
lda(unsigned char operand,
    unsigned char* adder,
    unsigned char* pc,
    unsigned char* memory) {
    (void)pc;
    *adder = memory[operand];
    return 1;
}

int
beq(unsigned char operand,
    unsigned char* adder,
    unsigned char* pc,
    unsigned char* memory) {
    (void)memory;
    if (*adder == 0) {
        *pc = operand;
    }
    return 1;
}

int
nop(unsigned char operand,
    unsigned char* adder,
    unsigned char* pc,
    unsigned char* memory) {
    (void)operand;
    (void)adder;
    (void)pc;
    (void)memory;
    return 1;
}

int
dec(unsigned char operand,
    unsigned char* adder,
    unsigned char* pc,
    unsigned char* memory) {
    (void)operand;
    (void)pc;
    (void)memory;
    --*adder;
    return 1;
}

int
inc(unsigned char operand,
    unsigned char* adder,
    unsigned char* pc,
    unsigned char* memory) {
    (void)operand;
    (void)pc;
    (void)memory;
    ++*adder;
    return 1;
}

int
jmp(unsigned char operand,
    unsigned char* adder,
    unsigned char* pc,
    unsigned char* memory) {
    (void)adder;
    (void)memory;
    *pc = operand;
    return 1;
}

int
hlt(unsigned char operand,
    unsigned char* adder,
    unsigned char* pc,
    unsigned char* memory) {
    (void)operand;
    (void)adder;
    (void)pc;
    (void)memory;
    return 0;
}

instruction_t instruction_set[INSTRUCTION_SET_SIZE]
    = {sta, lda, beq, nop, dec, inc, jmp, hlt};

unsigned char
decode_input(char* input) {
    unsigned char result = 0;

    while (*input) {
        result = (result << 1) + (*input - '0');
        ++input;
    }
    return result;
}

void
print_output(unsigned char value) {
    unsigned char ouput_buffer[9];
    int i = BYTE_SIZE;

    ouput_buffer[i] = '\0';
    while (i-- > 0) {
        ouput_buffer[i] = '0' + (value & 1);
        value >>= 1;
    }
    printf("%s\n", ouput_buffer);
}

int
read_program(unsigned char* memory) {
    int i;
    char input[BYTE_SIZE + 1];

    for (i = 0; i < PROGRAM_SIZE; ++i) {
        if (scanf("%s", input) != 1) {
            return 0;
        }
        memory[i] = decode_input(input);
    }
    return 1;
}

void
execute_program(unsigned char* memory) {
    unsigned char adder = 0;
    unsigned char pc = 0;

    while (1) {
        instruction_t instruction = instruction_set[memory[pc] >> OPERAND_SIZE];
        unsigned char operand = memory[pc] & OPERAND_MASK;

        pc = (pc + 1) % PROGRAM_SIZE;
        if (!instruction(operand, &adder, &pc, memory)) {
            break;
        }
    }
    print_output(adder);
}

int
main(void) {
    unsigned char memory[PROGRAM_SIZE];

    while (read_program(memory)) {
        execute_program(memory);
    }
    return 0;
}
