//Estructuras sacadas del codigo de 3 direcciones de Louden
//tipo de operacion
typedef enum{
	suma,
	asig,// =
	rest,
	mult,
	div,
	mod, // %
	etq,
	eq, //==
	lt, // <
	gt, // >
	if_f, // if_false
	if_t, //if normal
	neg, // !
	eqlt, // <=
	eqgt, // >=
	l_or, // ||
	l_and, // &&
} Operacion;

//tipo de direccion
typedef enum {Empty,IntConst,String} TipoAddr;
//estructura direccion
typedef struct 
{
	TipoAddr kind; 
	union 
	{ 
		int val;
		char * name; 
	} contenido; 
} Direccion; 
//cuadrupla para generacion de codigo de 3 direcciones
typedef struct {
	Operacion op;
	Direccion ad1,ad2,ad3; 
} Cuadrupla; 