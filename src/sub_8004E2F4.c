

void sub_8004E2F4(int param_1, unsigned int param_2)

{
    *(unsigned int *)(param_1 + 0x894) = *(unsigned int *)(param_1 + 0x894) | param_2;
    return;
}
