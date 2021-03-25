typedef struct lista Lista;

Lista *lst_cria(void);
int lst_vazia(Lista *);
void lst_insIni(Lista *, void *);
void lst_insFin(Lista *,void *);
void *lst_retIni(Lista *);
void *lst_retFin(Lista *);
void lst_posIni(Lista *);
void lst_posFin(Lista *);
void *lst_prox(Lista *);
void *lst_ant(Lista *);
void lst_libera(Lista *);
