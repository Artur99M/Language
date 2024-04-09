#ifdef DEBUG
    #define PRINT_DEBUG(str ...) fprintf(stderr, "DEBUG: " str);
#else
    #define PRINT_DEBUG(str ...) {};
#endif

#define PRINT_ERROR(str ...)                                                                 \
{                                                                                            \
    fprintf(stderr, "ERROR:" str);                                                           \
    fprintf(stderr, "FILE: %s; FUNC: %s; LINE: %d; \n", __FILE__, __func__, __LINE__);       \
}
