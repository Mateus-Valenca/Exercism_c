#include "rna_transcription.h"


char *to_rna(const char *dna)
{
    if (!dna) return NULL;
    int len = strlen(dna);
    char *rna = malloc((len + 1) * sizeof(char));
    if (!rna) return NULL;  // sempre verificar malloc
    for(int i = 0; i < len; i ++)
    {
        //if (*dna != 'G' && *dna != 'C' && *dna != 'T' && *dna != 'A') return INVALID;
        switch(dna[i])
        {
            case 'G': rna[i] = 'C'; break;
            case 'C': rna[i] = 'G'; break;
            case 'T': rna[i] = 'A'; break;
            case 'A': rna[i] = 'U'; break;
            default: break;
        }
    }
    rna[len] = '\0';
    return rna;
}