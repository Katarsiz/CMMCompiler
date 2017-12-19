#include "./list.h"
// Estructura para pila de tabla de simbolos
struct pila_t_simb{
	struct list * pila;
};
//Estructura para tabla de simbolos;
struct tabla_simb{
	struct list_elem elem;
	struct list * ren;
};
//Estructura para tabla de tipos
struct tabla_tipos{
	struct list * tipos;
};
//Estructura para renglon de tabla de simbolos
struct ren_simb{
	int pos;
	char * lexema;
	int tipo;
	char * tipovar;
	long dir;
	int args;
	struct list_elem elem;
	struct list * tipos_arg;
};
//Estructura para lista de tipos de argumentos
struct tipo_arg{
	int tipo;
	struct list_elem elem;
};
//Estructura para renglon de tabla de tipos
struct ren_tipos{
	int pos;
	char * tipo;
	int tipo_base;
	long tam;
	struct list_elem elem;
};

void inicia_pila(struct pila_t_simb *);
void inicia_ts(struct tabla_simb *);
void inicia_tt(struct tabla_tipos *);
void push_pila(struct pila_t_simb *, struct tabla_simb *);
struct tabla_simb * pop_pila(struct pila_t_simb *);
void agrega_tabla_simb(struct tabla_simb *, struct ren_simb *);
void agrega_tabla_tipos(struct tabla_tipos *, struct ren_tipos *);
int existe_en_ts(struct tabla_simb *, char *);
int existe_en_tt(struct tabla_tipos *, char *);
struct ren_simb * obten_ren_ts(struct tabla_simb *, char *);
struct ren_tipos * obten_ren_tt(struct tabla_tipos *, char *);
void free_ts(struct list *);
void free_tt(struct tabla_tipos *);
void free_pila(struct pila_t_simb *);