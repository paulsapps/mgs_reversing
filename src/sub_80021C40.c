

extern void GV_Free_80016230(void *ptr);

void sub_80021C40(unsigned int param_1)

{
    if (param_1 != 0)
    {
        GV_Free_80016230(param_1);
    }
    return;
}
